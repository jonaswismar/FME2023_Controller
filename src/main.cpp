#include <Arduino.h>
#include <ArduinoJson.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <IPAddress.h>
#include <painlessMesh.h>

#define MESH_PREFIX "FMEMesh"
#define MESH_PASSWORD "somethingSneaky"
#define MESH_PORT 5555

#define STATION_SSID "HighSecurity"
#define STATION_PASSWORD "1337leet"
#define STATION_PORT 5555

#define HOSTNAME "controller"

painlessMesh mesh;
AsyncWebServer server(80);
IPAddress myIP(0, 0, 0, 0);
IPAddress myAPIP(0, 0, 0, 0);

void notFound(AsyncWebServerRequest *request)
{
  request->send(404, "text/plain", "Not found");
}

void sendAlarm(boolean isDigital, int sound, int type, String adress, String comment, String nodeIdString)
{
  if (!adress.endsWith(" "))
  {
    adress = adress + " ";
  }
  if (!comment.endsWith(" "))
  {
    comment = comment + " ";
  }
  StaticJsonDocument<256> doc;
  String msg;
  doc["digital"] = isDigital;
  doc["sound"] = sound;
  doc["type"] = type;
  doc["adress"] = adress;
  doc["comment"] = comment;
  doc["from"] = mesh.getNodeId();

  serializeJson(doc, msg);
  char *end;
  int str_len = nodeIdString.length() + 1;
  char char_array[str_len];
  nodeIdString.toCharArray(char_array, str_len);
  unsigned long int nodeId = strtoul(char_array, &end, 10);

  if (nodeId > 0)
  {
    mesh.sendSingle(nodeId, msg);
  }
  else
  {
    mesh.sendBroadcast(msg);
  }
}
void sendCommand(String command, int nodeId)
{
  if (nodeId == mesh.getNodeId())
  {
    if (command.equalsIgnoreCase("reset"))
    {
      esp_restart();
    }
  }
  StaticJsonDocument<256> doc;
  String msg;
  doc["cmd"] = command;
  doc["from"] = mesh.getNodeId();
  serializeJson(doc, msg);
  mesh.sendSingle(nodeId, msg);
}

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML>
<html>
<head>
<title>FME Controller</title>
<style>fieldset p{
clear: both;
padding: 5px;
}
label.field{
text-align: left;
width: 100px;
float: left;
}
checkbox.layout{
width: 300px;
float: left;
}
input.layout{
width: 300px;
float: left;
}
number.layout{
width: 300px;
float: left;
}
select.layout{
width: 300px;
float: left;
}
table{
border: 3px solid #000000;
border-collapse: collapse;
}
table td, table th{
border: 1px solid #000000;
padding: 5px 4px;
}
table tr:nth-child(even){
background: #F5F5F5;
}
table thead{
background: #CFCFCF;
border-bottom: 3px solid #000000;
}
table thead th{
font-weight: bold;
}
table tfoot td{
font-size: 14px;
}
</style>
<script>
(function loadFMEList(){
var xhttp = new XMLHttpRequest();
xhttp.onreadystatechange = function(){
if (this.readyState == 4 && this.status == 200){
document.getElementById("insertFMEList").innerHTML = this.responseText;
}
};
xhttp.open("GET", "http://controller/getList", true);
xhttp.send();
setTimeout(loadFMEList, 10000);
})()
</script>
<script>
function sendSingle(nodeId){
var currentType = document.getElementById('currentType').value;
var currentAddress = document.getElementById('currentAddress').value;
var currentComment = document.getElementById('currentComment').value;
var isDigital = document.getElementById('isDigital').value;
var toneDigital = document.getElementById('toneDigital').value;
var toneAnalog = document.getElementById('toneAnalog').value;
var link = 'http://controller/send?currentType=' + currentType + '&currentAddress=' + currentAddress + '&currentComment=' + currentComment + '&isDigital=' + isDigital + '&toneDigital=' + toneDigital + '&toneAnalog=' + toneAnalog + '&nodeId=' + nodeId;
var xhttp = new XMLHttpRequest();
xhttp.onreadystatechange = function(){
if (this.readyState == 4 && this.status == 200){
}
};
xhttp.open("GET", link, true);
xhttp.send();
}
</script>
</head>
<body>
<table>
<thead>
<tr>
<th>ID</th>
<th>Rolle</th>
<th>Status</th>
<th>Befehle</th>
</tr>
</thead>
<tbody id="insertFMEList">
</tbody>
</table>
<p><button type="button" onclick="loadFMEList()">Aktualisieren</button></p>
<form id="alarm" action="send" target="hidden">
<fieldset>
<legend>Alarmdaten</legend>
<p><label class="field" for="currentType">Stichwort:</label>
<select class="layout" id="currentType" name="currentType" required>
<option value=101>F 1</option>
<option value=102>F 2</option>
<option value=103>F 2 Y</option>
<option value=104>F 3</option>
<option value=105>F 3 Y</option>
<option value=106>F 4</option>
<option value=107>F BMA</option>
<option value=108>F BUS Y</option>
<option value=109>F FLUG 1 Y</option>
<option value=110>F FLUG 2 Y</option>
<option value=111>F GAS 1</option>
<option value=112>F GAS 2</option>
<option value=113>F LKW</option>
<option value=114>F ZUG</option>
<option value=115>F ZUG Y</option>
<option value=116>F RWM</option>
<option value=117>F SCHIFF 1</option>
<option value=118>F SCHIFF 2</option>
<option value=119>F SCHIFF 2 Y</option>
<option value=120>F SCHIFF 2 GEFAHR</option>
<option value=121>F WALD 1</option>
<option value=122>F WALD 2</option>
<option value=201>H 1</option>
<option value=202>H 1 Y</option>
<option value=203>H 2</option>
<option value=204>H ABST Y</option>
<option value=205>H ELEK</option>
<option value=206>H EINST Y</option>
<option value=207>H FLUSS</option>
<option value=208>H FLUSS Y</option>
<option value=209>H WASS Y</option>
<option value=210>H GAS 1</option>
<option value=211>H GAS 2</option>
<option value=212>H GEFAHR 1</option>
<option value=213>H GEFAHR 2</option>
<option value=214>H KLEMM 1 Y</option>
<option value=215>H KLEMM 2 Y</option>
<option value=216>H OEL FLUSS</option>
<option value=217>H OEL WASS</option>
<option value=218>H RADIOAKTIV</option>
<option value=219>H SCHIFF</option>
<option value=220>H SCHIFF Y</option>
<option value=221>H ZUG 1 Y</option>
<option value=222>H ZUG 2 Y</option>
<option value=301>U Unwetter Sturm</option>
<option value=302>U Unwetter Wasser</option>
<option value=401>K</option>
<option value=402>R 0 K</option>
<option value=403>R 0</option>
<option value=404>R 1</option>
<option value=405>R 2</option>
<option value=406>R 3</option>
<option value=407>R LEBEL</option>
<option value=408>R MANV</option>
<option value=0>UNKLAR</option>
<option value=1>FME Test</option>
</select></p>
<p><label class="field" for="currentAddress">Adresse:</label><input class="layout" type='text' id='currentAddress' name='currentAddress'/></p>
<p><label class="field" for="currentComment">Kommentar:</label><input class="layout" type='text' id='currentComment' name='currentComment'/></p>
<p><input type="submit" value="Alarmieren"></p>
</fieldset>
<fieldset>
<legend>Einstellungen</legend>
<p><label class="field" for="isDigital">FME Digital:</label>
<input class="layout" type="checkbox" id="isDigital" name="isDigital" checked/></p>
<p><label class="field" id="toneDigitalLabel" for="toneDigital">Digital Ton:</label>
<input class="layout" type="number" id="toneDigital" name="toneDigital" min="1" max="54" value="12"/></p>
<p><label class="field" id="toneAnalogLabel" for="toneAnalog">Analog Ton:</label>
<input class="layout" type="number" id="toneAnalog" name="toneAnalog" min="10000" max="99999" value="52112"/></p>
<input type="hidden" id="nodeId" name="nodeId" value="0"/>
</fieldset>
</form>
<iframe name="hidden" href="about:blank" style="display:none"></iframe>
</body>
</html>
)rawliteral";

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

  server.on("/getList", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(200, "text/html", getNodeTable()); });

  server.on("/cmd", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    const char* PARAM_INPUT_1 = "cmd";
    const char* PARAM_INPUT_2 = "nodeId";
    if (request->hasParam(PARAM_INPUT_1)&&request->hasParam(PARAM_INPUT_2))
    {
      String command = request->getParam(PARAM_INPUT_1)->value();
      int nodeId = request->getParam(PARAM_INPUT_2)->value().toInt();
      sendCommand(command, nodeId);
    } });

  server.on("/send", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    const char* PARAM_INPUT_1 = "currentType";
    const char* PARAM_INPUT_2 = "currentAddress";
    const char* PARAM_INPUT_3 = "currentComment";
    const char* PARAM_INPUT_4 = "isDigital";
    const char* PARAM_INPUT_5 = "toneDigital";
    const char* PARAM_INPUT_6 = "toneAnalog";
    const char* PARAM_INPUT_7 = "nodeId";
    if (request->hasParam(PARAM_INPUT_1)&&request->hasParam(PARAM_INPUT_2)&&request->hasParam(PARAM_INPUT_3)&&request->hasParam(PARAM_INPUT_4)&&request->hasParam(PARAM_INPUT_5)&&request->hasParam(PARAM_INPUT_6)&&request->hasParam(PARAM_INPUT_7))
    {
      int currentType = request->getParam(PARAM_INPUT_1)->value().toInt();
      String currentAddress = request->getParam(PARAM_INPUT_2)->value();
      String currentComment = request->getParam(PARAM_INPUT_3)->value();
      String isDigitalStr = request->getParam(PARAM_INPUT_4)->value();
      boolean isDigital = false;
      int currentTone = 12;
      String currentNodeId = request->getParam(PARAM_INPUT_7)->value();
      if(isDigitalStr.equalsIgnoreCase("on"))
      {
        isDigital = true;
        currentTone = request->getParam(PARAM_INPUT_5)->value().toInt();
      }
      else
      {
          currentTone = request->getParam(PARAM_INPUT_6)->value().toInt();
      }      
     sendAlarm(isDigital, currentTone, currentType, currentAddress, currentComment, currentNodeId);
     request->send(200);
    } });

  server.begin();
}

void loop()
{
  mesh.update();

  if (myIP != getlocalIP())
  {
    myIP = getlocalIP();
    Serial.println("My IP is " + myIP.toString());
  }
}