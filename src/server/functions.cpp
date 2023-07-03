#include <ESPAsyncWebServer.h>

#include "alarm\functions.h"
#include "filesystem\functions.h"
#include "html\functions.h"
#include "mesh\functions.h"

#include "variables.h"

AsyncWebServer server(80);

void notFound(AsyncWebServerRequest *request)
{
  request->send(404, "text/plain", "Not found");
}

void initServer()
{
  server.onNotFound(notFound);

  server.on("/js/jquery.js", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/js/jquery.js", "text/javascript"); });

  server.on("/js/adresse.js", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/js/adresse.js", "text/javascript"); });
  server.on("/js/alarm.js", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/js/alarm.js", "text/javascript"); });
  server.on("/js/einstellungen.js", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/js/einstellungen.js", "text/javascript"); });

  server.on("/img/c_Coat_000_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Coat_000_24.jpg", "image/jpg"); });
  server.on("/img/c_Coat_001_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Coat_001_24.jpg", "image/jpg"); });
  server.on("/img/c_Coat_002_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Coat_002_24.jpg", "image/jpg"); });
  server.on("/img/c_Coat_003_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Coat_003_24.jpg", "image/jpg"); });
  server.on("/img/c_Coat_004_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Coat_004_24.jpg", "image/jpg"); });
  server.on("/img/c_Coat_005_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Coat_005_24.jpg", "image/jpg"); });
  server.on("/img/c_Coat_006_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Coat_006_24.jpg", "image/jpg"); });
  server.on("/img/c_Coat_007_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Coat_007_24.jpg", "image/jpg"); });
  server.on("/img/c_Coat_008_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Coat_008_24.jpg", "image/jpg"); });
  server.on("/img/c_Coat_009_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Coat_009_24.jpg", "image/jpg"); });
  server.on("/img/c_Coat_010_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Coat_010_24.jpg", "image/jpg"); });
  server.on("/img/c_Coat_011_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Coat_011_24.jpg", "image/jpg"); });
  server.on("/img/c_Coat_012_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Coat_012_24.jpg", "image/jpg"); });
  server.on("/img/c_Coat_013_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Coat_013_24.jpg", "image/jpg"); });
  server.on("/img/c_Coat_014_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Coat_014_24.jpg", "image/jpg"); });
  server.on("/img/c_Coat_015_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Coat_015_24.jpg", "image/jpg"); });
  server.on("/img/c_Coat_016_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Coat_016_24.jpg", "image/jpg"); });
  server.on("/img/c_Coat_017_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Coat_017_24.jpg", "image/jpg"); });
  server.on("/img/c_Coat_018_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Coat_018_24.jpg", "image/jpg"); });

  server.on("/img/c_Type_D000_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_D000_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_D001_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_D001_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_F001_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_F001_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_F002_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_F002_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_F003_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_F003_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_F004_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_F004_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_F005_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_F005_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_F006_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_F006_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_F007_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_F007_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_F008_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_F008_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_F009_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_F009_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_F010_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_F010_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_F011_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_F011_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_F012_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_F012_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_F013_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_F013_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_F014_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_F014_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_F015_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_F015_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_F016_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_F016_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_F017_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_F017_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_F018_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_F018_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_F019_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_F019_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_F020_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_F020_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_F021_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_F021_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_F022_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_F022_24.jpg", "image/jpg"); });

  server.on("/img/c_Type_H001_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_H001_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_H002_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_H002_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_H003_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_H003_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_H004_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_H004_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_H005_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_H005_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_H006_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_H006_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_H007_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_H007_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_H008_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_H008_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_H009_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_H009_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_H010_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_H010_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_H011_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_H011_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_H012_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_H012_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_H013_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_H013_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_H014_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_H014_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_H015_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_H015_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_H016_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_H016_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_H017_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_H017_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_H018_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_H018_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_H019_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_H019_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_H020_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_H020_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_H021_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_H021_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_H022_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_H022_24.jpg", "image/jpg"); });

  server.on("/img/c_Type_P000_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_P000_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_P001_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_P001_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_P002_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_P002_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_P003_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_P003_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_P004_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_P004_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_P005_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_P005_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_P006_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_P006_24.jpg", "image/jpg"); });

  server.on("/img/c_Type_R001_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_R001_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_R002_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_R002_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_R003_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_R003_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_R004_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_R004_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_R005_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_R005_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_R006_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_R006_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_R007_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_R007_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_R008_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_R008_24.jpg", "image/jpg"); });

  server.on("/img/c_Type_T000_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_T000_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_T001_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_T001_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_T002_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_T002_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_T003_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_T003_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_T004_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_T004_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_T005_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_T005_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_T006_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_T006_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_T007_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_T007_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_T008_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_T008_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_T009_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_T009_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_T010_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_T010_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_T011_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_T011_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_T012_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_T012_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_T013_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_T013_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_T014_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_T014_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_T015_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_T015_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_T016_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_T016_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_T017_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_T017_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_T018_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_T018_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_T019_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_T019_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_T020_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_T020_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_T021_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_T021_24.jpg", "image/jpg"); });

  server.on("/img/c_Type_U001_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_U001_24.jpg", "image/jpg"); });
  server.on("/img/c_Type_U002_24.jpg", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/c_Type_U002_24.jpg", "image/jpg"); });

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/index.html", "text/html"); });
  server.on("/index.html", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/index.html", "text/html"); });
  server.on("/monitor.html", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/monitor.html", "text/html"); });

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
