#include <Arduino.h>
#include <ArduinoJson.h>
#include <IPAddress.h>
#include <painlessMesh.h>

#include "alarm\functions.h"

#include "variables.h"

#define MESH_PREFIX "FMEMesh"
#define MESH_PASSWORD "somethingSneaky"
#define MESH_PORT 5555

#define STATION_SSID "HighSecurity"
#define STATION_PASSWORD "1337leet"
#define STATION_PORT 80
uint8_t STATION_IP[4] = {192, 168, 1, 112};

#define HOSTNAME "controller"



painlessMesh mesh;

void receivedCallback(const uint32_t &from, const String &msg)
{
  // Serial.printf("bridge: Received from %u msg=%s\n", from, msg.c_str());
}

void initMesh()
{
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

}

void updateMesh()
{
  mesh.update();
}

IPAddress getMeshStationIP()
{
  return IPAddress(mesh.getStationIP());
}
IPAddress getMeshAPIP()
{
  return IPAddress(mesh.getAPIP());
}

String getMeshNodeId(){
  return String(mesh.getNodeId());
}
SimpleList<uint32_t> getMeshNodesIds(){
  return mesh.getNodeList();
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
  doc["digital"] = sound_isDigital;
  if (sound_isDigital == true)
  {
    doc["sound"] = sound_digital;
  }
  else
  {
    doc["sound"] = sound_analog;
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