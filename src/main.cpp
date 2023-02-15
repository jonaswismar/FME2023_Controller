#include <Arduino.h>
#include <ArduinoJson.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <IPAddress.h>
#include <MFRC522.h>
#include <painlessMesh.h>
#include <SPI.h>

#include "alarm\functions.h"
#include "filesystem\functions.h"
#include "html\functions.h"

#include "variables.h"

#define MESH_PREFIX "FMEMesh"
#define MESH_PASSWORD "somethingSneaky"
#define MESH_PORT 5555

#define STATION_SSID "HighSecurity"
#define STATION_PASSWORD "1337leet"
#define STATION_PORT 5555

#define HOSTNAME "controller"

#define RFID_RST_PIN 5
#define RFID_SS_PIN 53

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

void cleanAlarm()
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
}

void readAndSendAlarm()
{
  readAlarm();
  sendAlarm(save_type, save_sub, save_plz, save_city, save_street, save_number, save_addition, save_adress, save_comment, save_nodeIdString);
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
  String tableCode = "<tr><td>" + String(mesh.getNodeId()) + "</td><td>Controller</td><td>Online</td><td><button type=\"button\" onclick=\"resetFME(" + String(mesh.getNodeId()) + ")\">Reset</button><button type=\"button\" disabled>Alarmieren</button></td></tr>";
  SimpleList<uint32_t> nodes = mesh.getNodeList();
  SimpleList<uint32_t>::iterator node = nodes.begin();
  while (node != nodes.end())
  {
    tableCode = tableCode + "<tr><td>" + String(*node) + "</td><td>Client</td><td>Online</td><td><button type=\"button\" onclick=\"resetFME(" + String(*node) + ")\">Reset</button><button type=\"button\" onclick=\"sendSingle(" + String(*node) + ")\">Alarmieren</button></td></tr>";
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
  mesh.setDebugMsgTypes(ERROR | STARTUP | CONNECTION); // set before init() so that you can see startup messages

  // Channel set to 6. Make sure to use the same channel for your mesh and for you other
  // network (STATION_SSID)
  mesh.init(MESH_PREFIX, MESH_PASSWORD, MESH_PORT, WIFI_AP_STA, 6);
  mesh.onReceive(&receivedCallback);

  mesh.stationManual(STATION_SSID, STATION_PASSWORD);
  mesh.setHostname(HOSTNAME);

  // Bridge node, should (in most cases) be a root node. See [the wiki](https://gitlab.com/painlessMesh/painlessMesh/wikis/Possible-challenges-in-mesh-formation) for some background
  mesh.setRoot(true);
  // This node and all other nodes should ideally know the mesh contains a root, so call this on all nodes
  mesh.setContainsRoot(true);
  mesh.initOTAReceive("otaServer");

  myAPIP = IPAddress(mesh.getAPIP());
  // Serial.println("My AP IP is " + myAPIP.toString());

  server.onNotFound(notFound);
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