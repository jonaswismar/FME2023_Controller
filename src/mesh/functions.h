#include <Arduino.h>
#include <ArduinoJson.h>
#include <IPAddress.h>
#include <painlessMesh.h>

#include "alarm\functions.h"

#include "variables.h"

void receivedCallback(const uint32_t &, const String &);
void initMesh();
void updateMesh();
IPAddress getMeshStationIP();
IPAddress getMeshAPIP();
String getMeshNodeId();
SimpleList<uint32_t> getMeshNodesIds();

void sendAlarm(int, int, int, int, int, int, String, String, String, String);
void sendCommand(String, String);
void readAndSendAlarm();