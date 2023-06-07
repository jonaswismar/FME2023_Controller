#include <Arduino.h>
#include <ArduinoJson.h>
#include <AsyncTCP.h>
#include <ESP32Time.h>
#include <ESPAsyncWebServer.h>
#include <IPAddress.h>
#include <MFRC522.h>
#include <painlessMesh.h>
#include <SPI.h>
#include <time.h>

#include "alarm\functions.h"
#include "filesystem\functions.h"
#include "html\functions.h"

#include "variables.h"

#define MESH_PREFIX "FMEMesh"
#define MESH_PASSWORD "somethingSneaky"
#define MESH_PORT 5555

#define STATION_SSID "HighSecurity"
#define STATION_PASSWORD "1337leet"
#define STATION_PORT 80
uint8_t STATION_IP[4] = {192, 168, 1, 112};

#define HOSTNAME "controller"

#define RFID_RST_PIN 3
#define RFID_SS_PIN 10

MFRC522 mfrc522(RFID_SS_PIN, RFID_RST_PIN);

painlessMesh mesh;
AsyncWebServer server(80);
IPAddress myIP(0, 0, 0, 0);
IPAddress myAPIP(0, 0, 0, 0);

/*
 *Einstellungen Controller
 */
boolean spiffs_active = true;
boolean littlefs_active = false;

/*
 * Einstellungen für Melder
 */
boolean melder_digital = true;
unsigned int melder_analog_ton = 52112;
unsigned int melder_digital_ton = 16;
String melder_i18n = "de";
boolean melder_debug = false;
boolean melder_giessen = false;
boolean melder_landscape = true;
boolean melder_uhrzeit = true;
String melder_theme = "color";
unsigned int melder_helligkeit = 100;

/*
 * Derzeitiger laufender Alarm
 */
unsigned int alarm_plz = 0;
unsigned int alarm_city = 0;
unsigned int alarm_street = 0;
unsigned int alarm_number = 0;
String alarm_addition = "";
int alarm_current_id = 1;

/*
 *
 */
unsigned int save_type = 0;
unsigned int save_sub = 0;
unsigned int save_plz = 0;
unsigned int save_city = 0;
unsigned int save_street = 0;
unsigned int save_number = 0;
String save_addition = "";
String save_adress = "";
String save_comment = "";
String save_nodeIdString = "";

/*
 *RFID Zeug
 */
String rfid_lastUID = "";

/*
 * Zeit  Zeugs
 */
const char *ntpServer = "pool.ntp.org";
const long gmtOffset_sec = 0;
const int daylightOffset_sec = 3600;
ESP32Time rtc(daylightOffset_sec);

void cleanCurrentAlarm()
{
  alarm_plz = 0;
  alarm_city = 0;
  alarm_street = 0;
  alarm_number = 0;
  alarm_addition = "";
}

void deleteAlarm()
{
  String filename = "/" + rfid_lastUID + ".json";
  int filename_len = filename.length() + 1;
  char char_array[filename_len];
  filename.toCharArray(char_array, filename_len);
  deleteFile(char_array);
}
String getCombinedAdress(int plz, int city, int street, int number, String addition)
{
  return getAlarmStreetText(street) + " " + String(number) + addition + ", " + getAlarmPLZText(plz) + " " + getAlarmCityText(city);
}
void sendAlarm(int type, int sub, int plz, int city, int street, int number, String addition, String adress, String comment, String nodeIdString)
{
  if (!adress.endsWith(" "))
  {
    adress = adress + " ";
  }
  if (!comment.endsWith(" "))
  {
    comment = comment + " ";
  }
  StaticJsonDocument<384> doc;
  String msg;
  unsigned int messageType = 1;
  doc["id"] = alarm_current_id;
  doc["message"] = messageType;
  doc["digital"] = melder_digital;
  if (melder_digital == true)
  {
    doc["sound"] = melder_digital_ton;
  }
  else
  {
    doc["sound"] = melder_analog_ton;
  }
  doc["type"] = type;
  doc["sub"] = sub;
  doc["plz"] = plz;
  doc["city"] = city;
  doc["street"] = street;
  doc["number"] = number;
  doc["addition"] = addition;

  if (adress.isEmpty())
  {
    adress = getCombinedAdress(plz, city, street, number, addition);
  }

  doc["adress"] = adress;
  doc["comment"] = comment;

  alarm_plz = plz;
  alarm_city = city;
  alarm_street = street;
  alarm_number = number;
  alarm_addition = addition;
  alarm_current_id = alarm_current_id + 1;
  doc["from"] = mesh.getNodeId();

  serializeJson(doc, msg);
  if (nodeIdString.isEmpty())
  {
    mesh.sendBroadcast(msg);
  }
  else
  {
    char *end;
    int str_len = nodeIdString.length() + 1;
    char char_array[str_len];
    nodeIdString.toCharArray(char_array, str_len);
    unsigned long int nodeId = strtoul(char_array, &end, 10);
    mesh.sendSingle(nodeId, msg);
  }
}

void resetAlarm()
{
  save_type = 0;
  save_sub = 0;
  save_plz = 0;
  save_city = 0;
  save_street = 0;
  save_number = 0;
  save_addition = "";
  save_adress = "";
  save_comment = "";
  save_nodeIdString = "";
}
void saveAlarm(int type, int sub, int plz, int city, int street, int number, String addition, String adress, String comment, String nodeIdString)
{
  save_type = type;
  save_sub = sub;
  save_plz = plz;
  save_city = city;
  save_street = street;
  save_number = number;
  save_addition = addition;
  if (adress.isEmpty())
  {
    adress = getCombinedAdress(plz, city, street, number, addition);
  }
  save_adress = adress;
  save_comment = comment;
  save_nodeIdString = nodeIdString;
  writeAlarm();
  resetAlarm();
}

void readAndSendAlarm()
{
  resetAlarm();
  readAlarm();
  if (save_type > 0 && save_plz > 0 && save_city > 0 && save_street > 0)
  {
    sendAlarm(save_type, save_sub, save_plz, save_city, save_street, save_number, save_addition, save_adress, save_comment, save_nodeIdString);
  }
  resetAlarm();
}

void sendCommand(String command, String nodeIdString)
{

  StaticJsonDocument<256> doc;
  String msg;
  unsigned int messageType = 3;
  doc["message"] = messageType;
  doc["cmd"] = command;
  doc["from"] = mesh.getNodeId();
  serializeJson(doc, msg);

  if (nodeIdString.isEmpty())
  {
    mesh.sendBroadcast(msg);
  }
  else
  {
    char *end;
    int str_len = nodeIdString.length() + 1;
    char char_array[str_len];
    nodeIdString.toCharArray(char_array, str_len);
    unsigned long int nodeId = strtoul(char_array, &end, 10);
    if (nodeId == mesh.getNodeId())
    {
      if (command.equalsIgnoreCase("reset"))
      {
        esp_restart();
      }
    }
    mesh.sendSingle(nodeId, msg);
  }
}

void notFound(AsyncWebServerRequest *request)
{
  request->send(404, "text/plain", "Not found");
}

String getNodeTable()
{
  String tableCode = "<tr><td>" + String(mesh.getNodeId()) + "</td><td>Controller</td><td>Online</td><td><button type=\"button\" onclick=\"resetFME(" + String(mesh.getNodeId()) + ")\">Neustart</button><button type=\"button\" disabled>Alarmieren</button></td></tr>";
  SimpleList<uint32_t> nodes = mesh.getNodeList();
  SimpleList<uint32_t>::iterator node = nodes.begin();
  while (node != nodes.end())
  {
    tableCode = tableCode + "<tr><td>" + String(*node) + "</td><td>Client</td><td>Online</td><td><button type=\"button\" onclick=\"resetFME(" + String(*node) + ")\">Neustart</button><button type=\"button\" onclick=\"sendSingle(" + String(*node) + ")\">Alarmieren</button></td></tr>";
    node++;
  }
  return tableCode;
}

IPAddress getlocalIP()
{
  return IPAddress(mesh.getStationIP());
}

void receivedCallback(const uint32_t &from, const String &msg)
{
  // Serial.printf("bridge: Received from %u msg=%s\n", from, msg.c_str());
}

void setup()
{
  Serial.begin(115200);

  SPI.begin();
  mfrc522.PCD_Init();
  // mesh.setDebugMsgTypes( ERROR | STARTUP |MESH_STATUS | CONNECTION | SYNC | COMMUNICATION | GENERAL | MSG_TYPES | REMOTE ); // all types on
  mesh.setDebugMsgTypes(ERROR | STARTUP | CONNECTION); // set before init() so that you can see startup messages

  // Channel set to 6. Make sure to use the same channel for your mesh and for you other
  // network (STATION_SSID)
  mesh.init(MESH_PREFIX, MESH_PASSWORD, MESH_PORT, WIFI_AP_STA, 6);
  mesh.onReceive(&receivedCallback);

  mesh.stationManual(STATION_SSID, STATION_PASSWORD, STATION_PORT, STATION_IP);
  mesh.setHostname(HOSTNAME);

  // Bridge node, should (in most cases) be a root node. See [the wiki](https://gitlab.com/c_Type_PainlessMesh/c_Type_PainlessMesh/wikis/c_Type_Possible-challenges-in-mesh-formation) for some background
  mesh.setRoot(true);
  // This node and all other nodes should ideally know the mesh contains a root, so call this on all nodes
  mesh.setContainsRoot(true);
  mesh.initOTAReceive("otaServer");

  myAPIP = IPAddress(mesh.getAPIP());
  // Serial.println("My AP IP is " + myAPIP.toString());

  server.onNotFound(notFound);

 server.on("/jquery-3.7.0.min.js", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/jquery-3.7.0.min.js", "text/javascript"); });
			
 server.on("/c_Coat_000_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Coat_000_24.jpg", "image/jpg"); });
 server.on("/c_Coat_001_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Coat_001_24.jpg", "image/jpg"); });
 server.on("/c_Coat_002_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Coat_002_24.jpg", "image/jpg"); });
 server.on("/c_Coat_003_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Coat_003_24.jpg", "image/jpg"); });
 server.on("/c_Coat_004_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Coat_004_24.jpg", "image/jpg"); });
 server.on("/c_Coat_005_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Coat_005_24.jpg", "image/jpg"); });
 server.on("/c_Coat_006_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Coat_006_24.jpg", "image/jpg"); });
 server.on("/c_Coat_007_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Coat_007_24.jpg", "image/jpg"); });
 server.on("/c_Coat_008_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Coat_008_24.jpg", "image/jpg"); });
 server.on("/c_Coat_009_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Coat_009_24.jpg", "image/jpg"); });
 server.on("/c_Coat_010_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Coat_010_24.jpg", "image/jpg"); });
 server.on("/c_Coat_011_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Coat_011_24.jpg", "image/jpg"); });
 server.on("/c_Coat_012_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Coat_012_24.jpg", "image/jpg"); });
 server.on("/c_Coat_013_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Coat_013_24.jpg", "image/jpg"); });
 server.on("/c_Coat_014_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Coat_014_24.jpg", "image/jpg"); });
 server.on("/c_Coat_015_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Coat_015_24.jpg", "image/jpg"); });
 server.on("/c_Coat_016_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Coat_016_24.jpg", "image/jpg"); });
 server.on("/c_Coat_017_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Coat_017_24.jpg", "image/jpg"); });
 server.on("/c_Coat_018_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Coat_018_24.jpg", "image/jpg"); });
			
 server.on("/c_Type_D000_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_D000_24.jpg", "image/jpg"); });
 server.on("/c_Type_D001_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_D001_24.jpg", "image/jpg"); });
 server.on("/c_Type_F001_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_F001_24.jpg", "image/jpg"); });
 server.on("/c_Type_F002_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_F002_24.jpg", "image/jpg"); });
 server.on("/c_Type_F003_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_F003_24.jpg", "image/jpg"); });
 server.on("/c_Type_F004_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_F004_24.jpg", "image/jpg"); });
 server.on("/c_Type_F005_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_F005_24.jpg", "image/jpg"); });
 server.on("/c_Type_F006_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_F006_24.jpg", "image/jpg"); });
 server.on("/c_Type_F007_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_F007_24.jpg", "image/jpg"); });
 server.on("/c_Type_F008_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_F008_24.jpg", "image/jpg"); });
 server.on("/c_Type_F009_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_F009_24.jpg", "image/jpg"); });
 server.on("/c_Type_F010_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_F010_24.jpg", "image/jpg"); });
 server.on("/c_Type_F011_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_F011_24.jpg", "image/jpg"); });
 server.on("/c_Type_F012_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_F012_24.jpg", "image/jpg"); });
 server.on("/c_Type_F013_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_F013_24.jpg", "image/jpg"); });
 server.on("/c_Type_F014_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_F014_24.jpg", "image/jpg"); });
 server.on("/c_Type_F015_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_F015_24.jpg", "image/jpg"); });
 server.on("/c_Type_F016_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_F016_24.jpg", "image/jpg"); });
 server.on("/c_Type_F017_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_F017_24.jpg", "image/jpg"); });
 server.on("/c_Type_F018_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_F018_24.jpg", "image/jpg"); });
 server.on("/c_Type_F019_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_F019_24.jpg", "image/jpg"); });
 server.on("/c_Type_F020_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_F020_24.jpg", "image/jpg"); });
 server.on("/c_Type_F021_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_F021_24.jpg", "image/jpg"); });
 server.on("/c_Type_F022_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_F022_24.jpg", "image/jpg"); });

 server.on("/c_Type_H001_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_H001_24.jpg", "image/jpg"); });
 server.on("/c_Type_H002_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_H002_24.jpg", "image/jpg"); });
 server.on("/c_Type_H003_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_H003_24.jpg", "image/jpg"); });
 server.on("/c_Type_H004_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_H004_24.jpg", "image/jpg"); });
 server.on("/c_Type_H005_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_H005_24.jpg", "image/jpg"); });
 server.on("/c_Type_H006_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_H006_24.jpg", "image/jpg"); });
 server.on("/c_Type_H007_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_H007_24.jpg", "image/jpg"); });
 server.on("/c_Type_H008_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_H008_24.jpg", "image/jpg"); });
 server.on("/c_Type_H009_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_H009_24.jpg", "image/jpg"); });
 server.on("/c_Type_H010_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_H010_24.jpg", "image/jpg"); });
 server.on("/c_Type_H011_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_H011_24.jpg", "image/jpg"); });
 server.on("/c_Type_H012_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_H012_24.jpg", "image/jpg"); });
 server.on("/c_Type_H013_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_H013_24.jpg", "image/jpg"); });
 server.on("/c_Type_H014_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_H014_24.jpg", "image/jpg"); });
 server.on("/c_Type_H015_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_H015_24.jpg", "image/jpg"); });
 server.on("/c_Type_H016_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_H016_24.jpg", "image/jpg"); });
 server.on("/c_Type_H017_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_H017_24.jpg", "image/jpg"); });
 server.on("/c_Type_H018_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_H018_24.jpg", "image/jpg"); });
 server.on("/c_Type_H019_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_H019_24.jpg", "image/jpg"); });
 server.on("/c_Type_H020_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_H020_24.jpg", "image/jpg"); });
 server.on("/c_Type_H021_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_H021_24.jpg", "image/jpg"); });
 server.on("/c_Type_H022_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_H022_24.jpg", "image/jpg"); });

 server.on("/c_Type_P000_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_P000_24.jpg", "image/jpg"); });
 server.on("/c_Type_P001_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_P001_24.jpg", "image/jpg"); });
 server.on("/c_Type_P002_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_P002_24.jpg", "image/jpg"); });
 server.on("/c_Type_P003_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_P003_24.jpg", "image/jpg"); });
 server.on("/c_Type_P004_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_P004_24.jpg", "image/jpg"); });
 server.on("/c_Type_P005_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_P005_24.jpg", "image/jpg"); });
 server.on("/c_Type_P006_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_P006_24.jpg", "image/jpg"); });

 server.on("/c_Type_R001_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_R001_24.jpg", "image/jpg"); });
 server.on("/c_Type_R002_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_R002_24.jpg", "image/jpg"); });
 server.on("/c_Type_R003_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_R003_24.jpg", "image/jpg"); });
 server.on("/c_Type_R004_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_R004_24.jpg", "image/jpg"); });
 server.on("/c_Type_R005_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_R005_24.jpg", "image/jpg"); });
 server.on("/c_Type_R006_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_R006_24.jpg", "image/jpg"); });
 server.on("/c_Type_R007_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_R007_24.jpg", "image/jpg"); });
 server.on("/c_Type_R008_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_R008_24.jpg", "image/jpg"); });

 server.on("/c_Type_T000_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_T000_24.jpg", "image/jpg"); });
 server.on("/c_Type_T001_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_T001_24.jpg", "image/jpg"); });
 server.on("/c_Type_T002_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_T002_24.jpg", "image/jpg"); });
 server.on("/c_Type_T003_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_T003_24.jpg", "image/jpg"); });
 server.on("/c_Type_T004_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_T004_24.jpg", "image/jpg"); });
 server.on("/c_Type_T005_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_T005_24.jpg", "image/jpg"); });
 server.on("/c_Type_T006_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_T006_24.jpg", "image/jpg"); });
 server.on("/c_Type_T007_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_T007_24.jpg", "image/jpg"); });
 server.on("/c_Type_T008_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_T008_24.jpg", "image/jpg"); });
 server.on("/c_Type_T009_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_T009_24.jpg", "image/jpg"); });
 server.on("/c_Type_T010_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_T010_24.jpg", "image/jpg"); });
 server.on("/c_Type_T011_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_T011_24.jpg", "image/jpg"); });
 server.on("/c_Type_T012_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_T012_24.jpg", "image/jpg"); });
 server.on("/c_Type_T013_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_T013_24.jpg", "image/jpg"); });
 server.on("/c_Type_T014_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_T014_24.jpg", "image/jpg"); });
 server.on("/c_Type_T015_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_T015_24.jpg", "image/jpg"); });
 server.on("/c_Type_T016_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_T016_24.jpg", "image/jpg"); });
 server.on("/c_Type_T017_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_T017_24.jpg", "image/jpg"); });
 server.on("/c_Type_T018_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_T018_24.jpg", "image/jpg"); });
 server.on("/c_Type_T019_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_T019_24.jpg", "image/jpg"); });
 server.on("/c_Type_T020_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_T020_24.jpg", "image/jpg"); });
 server.on("/c_Type_T021_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_T021_24.jpg", "image/jpg"); });

 server.on("/c_Type_U001_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_U001_24.jpg", "image/jpg"); });
 server.on("/c_Type_U002_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/c_Type_U002_24.jpg", "image/jpg"); });

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(200, "text/html", index_html); });

  server.on("/getFMEList", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(200, "text/html", getNodeTable()); });

  server.on("/cmd", HTTP_GET, [](AsyncWebServerRequest *request)
            {
            
    const char* PARAM_INPUT_1 = "cmd";
    const char* PARAM_INPUT_2 = "nodeId";
    if (request->hasParam(PARAM_INPUT_1)&&request->hasParam(PARAM_INPUT_2))
    {
      String command = request->getParam(PARAM_INPUT_1)->value();
      String nodeId = request->getParam(PARAM_INPUT_2)->value();
      sendCommand(command, nodeId);
    } });

  server.on("/sendAlarm", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    const char* PARAM_INPUT_1 = "currentType";
    const char* PARAM_INPUT_2 = "currentSub";
    const char* PARAM_INPUT_3 = "currentPLZ";
    const char* PARAM_INPUT_4 = "currentCity";
    const char* PARAM_INPUT_5 = "currentStreet";
    const char* PARAM_INPUT_6 = "currentHouseNumber";
    const char* PARAM_INPUT_7 = "currentHouseAddition";
    const char* PARAM_INPUT_8 = "currentAddress";
    const char* PARAM_INPUT_9 = "currentComment";
    const char* PARAM_INPUT_10 = "nodeId";
    if (request->hasParam(PARAM_INPUT_1)&&request->hasParam(PARAM_INPUT_2)&&request->hasParam(PARAM_INPUT_3)&&request->hasParam(PARAM_INPUT_4)&&request->hasParam(PARAM_INPUT_5)&&request->hasParam(PARAM_INPUT_6)&&request->hasParam(PARAM_INPUT_7)&&request->hasParam(PARAM_INPUT_8)&&request->hasParam(PARAM_INPUT_9)&&request->hasParam(PARAM_INPUT_10))
    {
      int currentType = request->getParam(PARAM_INPUT_1)->value().toInt();
      int currentSub = request->getParam(PARAM_INPUT_2)->value().toInt();
      int currentPLZ = request->getParam(PARAM_INPUT_3)->value().toInt();
      int currentCity = request->getParam(PARAM_INPUT_4)->value().toInt();
      int currentStreet = request->getParam(PARAM_INPUT_5)->value().toInt();
      int currentHouseNumber = request->getParam(PARAM_INPUT_6)->value().toInt();
      String currentHouseAddition = request->getParam(PARAM_INPUT_7)->value();
      String currentAddress = request->getParam(PARAM_INPUT_8)->value();
      String currentComment = request->getParam(PARAM_INPUT_9)->value();
      String currentNodeId = request->getParam(PARAM_INPUT_10)->value();
     sendAlarm(currentType, currentSub, currentPLZ, currentCity, currentStreet, currentHouseNumber, currentHouseAddition, currentAddress, currentComment, currentNodeId);
     request->send(200);
    } });

  server.on("/saveAlarm", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    const char* PARAM_INPUT_1 = "currentType";
    const char* PARAM_INPUT_2 = "currentSub";
    const char* PARAM_INPUT_3 = "currentPLZ";
    const char* PARAM_INPUT_4 = "currentCity";
    const char* PARAM_INPUT_5 = "currentStreet";
    const char* PARAM_INPUT_6 = "currentHouseNumber";
    const char* PARAM_INPUT_7 = "currentHouseAddition";
    const char* PARAM_INPUT_8 = "currentAddress";
    const char* PARAM_INPUT_9 = "currentComment";
    const char* PARAM_INPUT_10 = "nodeId";
    if (request->hasParam(PARAM_INPUT_1)&&request->hasParam(PARAM_INPUT_2)&&request->hasParam(PARAM_INPUT_3)&&request->hasParam(PARAM_INPUT_4)&&request->hasParam(PARAM_INPUT_5)&&request->hasParam(PARAM_INPUT_6)&&request->hasParam(PARAM_INPUT_7)&&request->hasParam(PARAM_INPUT_8)&&request->hasParam(PARAM_INPUT_9)&&request->hasParam(PARAM_INPUT_10))
    {
      int currentType = request->getParam(PARAM_INPUT_1)->value().toInt();
      int currentSub = request->getParam(PARAM_INPUT_2)->value().toInt();
      int currentPLZ = request->getParam(PARAM_INPUT_3)->value().toInt();
      int currentCity = request->getParam(PARAM_INPUT_4)->value().toInt();
      int currentStreet = request->getParam(PARAM_INPUT_5)->value().toInt();
      int currentHouseNumber = request->getParam(PARAM_INPUT_6)->value().toInt();
      String currentHouseAddition = request->getParam(PARAM_INPUT_7)->value();
      String currentAddress = request->getParam(PARAM_INPUT_8)->value();
      String currentComment = request->getParam(PARAM_INPUT_9)->value();
      String currentNodeId = request->getParam(PARAM_INPUT_10)->value();
     saveAlarm(currentType, currentSub, currentPLZ, currentCity, currentStreet, currentHouseNumber, currentHouseAddition, currentAddress, currentComment, currentNodeId);
     request->send(200);
    } });

  server.begin();

  struct tm timeinfo;
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  if (getLocalTime(&timeinfo))
  {
    rtc.setTimeStruct(timeinfo);
  }
}

void loop()
{
  mesh.update();

  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial())
  {
    String newUID;
    for (byte i = 0; i < mfrc522.uid.size; i++)
    {
      newUID += String(mfrc522.uid.uidByte[i], HEX);
    }
    if (!newUID.isEmpty())
    {
      if (!rfid_lastUID.equals(newUID))
      {
        Serial.println(newUID);
        rfid_lastUID = newUID;
      }
    }
  }
  if (myIP != getlocalIP())
  {
    myIP = getlocalIP();
  }
}