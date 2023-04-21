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

  // Bridge node, should (in most cases) be a root node. See [the wiki](https://gitlab.com/painlessMesh/painlessMesh/wikis/Possible-challenges-in-mesh-formation) for some background
  mesh.setRoot(true);
  // This node and all other nodes should ideally know the mesh contains a root, so call this on all nodes
  mesh.setContainsRoot(true);
  mesh.initOTAReceive("otaServer");

  myAPIP = IPAddress(mesh.getAPIP());
  // Serial.println("My AP IP is " + myAPIP.toString());

  server.onNotFound(notFound);

  server.on("/D000.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_D000_96.jpg", "image/jpg"); });
 server.on("/D000.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_D001_96.jpg", "image/jpg"); });
 server.on("/F001.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_F001_96.jpg", "image/jpg"); });
 server.on("/F002.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_F002_96.jpg", "image/jpg"); });
 server.on("/F003.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_F003_96.jpg", "image/jpg"); });
 server.on("/F004.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_F004_96.jpg", "image/jpg"); });
 server.on("/F005.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_F005_96.jpg", "image/jpg"); });
 server.on("/F006.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_F006_96.jpg", "image/jpg"); });
 server.on("/F007.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_F007_96.jpg", "image/jpg"); });
 server.on("/F008.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_F008_96.jpg", "image/jpg"); });
 server.on("/F009.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_F009_96.jpg", "image/jpg"); });
 server.on("/F010.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_F010_96.jpg", "image/jpg"); });
 server.on("/F011.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_F011_96.jpg", "image/jpg"); });
 server.on("/F012.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_F012_96.jpg", "image/jpg"); });
 server.on("/F013.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_F013_96.jpg", "image/jpg"); });
 server.on("/F014.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_F014_96.jpg", "image/jpg"); });
 server.on("/F015.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_F015_96.jpg", "image/jpg"); });
 server.on("/F016.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_F016_96.jpg", "image/jpg"); });
 server.on("/F017.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_F017_96.jpg", "image/jpg"); });
 server.on("/F018.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_F018_96.jpg", "image/jpg"); });
 server.on("/F019.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_F019_96.jpg", "image/jpg"); });
 server.on("/F020.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_F020_96.jpg", "image/jpg"); });
 server.on("/F021.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_F021_96.jpg", "image/jpg"); });
 server.on("/F022.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_F022_96.jpg", "image/jpg"); });

 server.on("/H001.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_H001_96.jpg", "image/jpg"); });
 server.on("/H002.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_H002_96.jpg", "image/jpg"); });
 server.on("/H003.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_H003_96.jpg", "image/jpg"); });
 server.on("/H004.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_H004_96.jpg", "image/jpg"); });
 server.on("/H005.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_H005_96.jpg", "image/jpg"); });
 server.on("/H006.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_H006_96.jpg", "image/jpg"); });
 server.on("/H007.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_H007_96.jpg", "image/jpg"); });
 server.on("/H008.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_H008_96.jpg", "image/jpg"); });
 server.on("/H009.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_H009_96.jpg", "image/jpg"); });
 server.on("/H010.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_H010_96.jpg", "image/jpg"); });
 server.on("/H011.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_H011_96.jpg", "image/jpg"); });
 server.on("/H012.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_H012_96.jpg", "image/jpg"); });
 server.on("/H013.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_H013_96.jpg", "image/jpg"); });
 server.on("/H014.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_H014_96.jpg", "image/jpg"); });
 server.on("/H015.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_H015_96.jpg", "image/jpg"); });
 server.on("/H016.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_H016_96.jpg", "image/jpg"); });
 server.on("/H017.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_H017_96.jpg", "image/jpg"); });
 server.on("/H018.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_H018_96.jpg", "image/jpg"); });
 server.on("/H019.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_H019_96.jpg", "image/jpg"); });
 server.on("/H020.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_H020_96.jpg", "image/jpg"); });
  server.on("/H021.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_H021_96.jpg", "image/jpg"); });
 server.on("/H022.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_H022_96.jpg", "image/jpg"); });

 server.on("/P000.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_P000_96.jpg", "image/jpg"); });
 server.on("/P001.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_P001_96.jpg", "image/jpg"); });
 server.on("/P002.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_P002_96.jpg", "image/jpg"); });
 server.on("/P003.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_P003_96.jpg", "image/jpg"); });
 server.on("/P004.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_P004_96.jpg", "image/jpg"); });
 server.on("/P005.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_P005_96.jpg", "image/jpg"); });
 server.on("/P006.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_P006_96.jpg", "image/jpg"); });

 server.on("/R001.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_R001_96.jpg", "image/jpg"); });
 server.on("/R002.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_R002_96.jpg", "image/jpg"); });
 server.on("/R003.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_R003_96.jpg", "image/jpg"); });
 server.on("/R004.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_R004_96.jpg", "image/jpg"); });
 server.on("/R005.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_R005_96.jpg", "image/jpg"); });
 server.on("/R006.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_R006_96.jpg", "image/jpg"); });
 server.on("/R007.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_R007_96.jpg", "image/jpg"); });
 server.on("/R008.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_R008_96.jpg", "image/jpg"); });

 server.on("/T000.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_T000_96.jpg", "image/jpg"); });
 server.on("/T001.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_T001_96.jpg", "image/jpg"); });
 server.on("/T002.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_T002_96.jpg", "image/jpg"); });
 server.on("/T003.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_T003_96.jpg", "image/jpg"); });
 server.on("/T004.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_T004_96.jpg", "image/jpg"); });
 server.on("/T005.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_T005_96.jpg", "image/jpg"); });
 server.on("/T006.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_T006_96.jpg", "image/jpg"); });
 server.on("/T007.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_T007_96.jpg", "image/jpg"); });
 server.on("/T008.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_T008_96.jpg", "image/jpg"); });
 server.on("/T009.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_T009_96.jpg", "image/jpg"); });
 server.on("/T010.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_T010_96.jpg", "image/jpg"); });
 server.on("/T011.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_T011_96.jpg", "image/jpg"); });
 server.on("/T012.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_T012_96.jpg", "image/jpg"); });
 server.on("/T013.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_T013_96.jpg", "image/jpg"); });
 server.on("/T014.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_T014_96.jpg", "image/jpg"); });
 server.on("/T015.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_T015_96.jpg", "image/jpg"); });
 server.on("/T016.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_T016_96.jpg", "image/jpg"); });
 server.on("/T017.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_T017_96.jpg", "image/jpg"); });
 server.on("/T018.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_T018_96.jpg", "image/jpg"); });
 server.on("/T019.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_T019_96.jpg", "image/jpg"); });
 server.on("/T020.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_T020_96.jpg", "image/jpg"); });
 server.on("/T021.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_T021_96.jpg", "image/jpg"); });

 server.on("/U001.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_U001_96.jpg", "image/jpg"); });
 server.on("/U002.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Type_U002_96.jpg", "image/jpg"); });

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