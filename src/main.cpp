#include <Arduino.h>
#include <ArduinoJson.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <IPAddress.h>
#include <painlessMesh.h>

#include "alarm\functions.h"

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

/*
 * Einstellungen für Melder
 */
boolean melder_digital = true;
unsigned int melder_analog_ton = 52112;
unsigned int melder_digital_ton = 16;

/*
 * Derzeitiger laufender Alarm
 */
unsigned int alarm_plz = 0;
unsigned int alarm_city = 0;
unsigned int alarm_street = 0;
unsigned int alarm_number = 0;
String alarm_addition = "";

void notFound(AsyncWebServerRequest *request)
{
  request->send(404, "text/plain", "Not found");
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
    adress = getAlarmStreetText(street) + " " + String(number) + addition + ", " + getAlarmPLZText(plz) + " " + getAlarmCityText(city);
  }

  doc["adress"] = adress;
  doc["comment"] = comment;

  alarm_plz = plz;
  alarm_city = city;
  alarm_street = street;
  alarm_number = number;
  alarm_addition = addition;

  doc["from"] = mesh.getNodeId();

  serializeJson(doc, msg);
  char *end;
  int str_len = nodeIdString.length() + 1;
  char char_array[str_len];
  nodeIdString.toCharArray(char_array, str_len);
  unsigned long int nodeId = strtoul(char_array, &end, 10);

  mesh.sendBroadcast(msg);
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
  unsigned int messageType = 3;
  doc["message"] = messageType;
  doc["cmd"] = command;
  doc["from"] = mesh.getNodeId();
  serializeJson(doc, msg);
  mesh.sendSingle(nodeId, msg);
}

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML>
<html lang="de">
<head>
<meta charset="utf-8">
<title>FME Controller</title>
<style>
.tab {
overflow: hidden;
border: 1px solid #ccc;
background-color: #f1f1f1;
}
.tab button {
background-color: inherit;
float: left;
border: none;
outline: none;
cursor: pointer;
padding: 14px 16px;
transition: 0.3s;
}
.tab button:hover {
background-color: #ddd;
}
.tab button.active {
background-color: #ccc;
}
.tabcontent {
display: none;
padding: 6px 12px;
border: 1px solid #ccc;
border-top: none;
}
fieldset p{
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
function openTab(evt, tabName) {
var i, tabcontent, tablinks;
tabcontent = document.getElementsByClassName("tabcontent");
for (i = 0; i < tabcontent.length; i++) {
tabcontent[i].style.display = "none";
}
tablinks = document.getElementsByClassName("tablinks");
for (i = 0; i < tablinks.length; i++) {
tablinks[i].className = tablinks[i].className.replace(" active", "");
}
document.getElementById(tabName).style.display = "block";
evt.currentTarget.className += " active";
}
</script>

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
var currentSub = document.getElementById('currentSub').value;
var currentPLZ = document.getElementById('currentPLZ').value;
var currentCity = document.getElementById('currentCity').value;
var currentStreet = document.getElementById('currentStreet').value;
var currentHouseNumber = document.getElementById('currentHouseNumber').value;
var currentHouseAdddition = document.getElementById('currentHouseAdddition').value;
var currentAddress = document.getElementById('currentAddress').value;
var currentComment = document.getElementById('currentComment').value;
var link = 'http://controller/send?currentType=' + currentType + 'currentSub=' + currentSub + 'currentPLZ=' + currentPLZ + 'currentCity=' + currentCity + 'currentStreet=' + currentStreet + 'currentHouseNumber=' + currentHouseNumber + 'currentHouseAddition=' + currentHouseAddition + '&currentAddress=' + currentAddress + '&currentComment=' + currentComment + '&nodeId=' + nodeId;
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
<div class="tab">
<button class="tablinks" onclick="openTab(event, 'StatusD')">Status</button>
<button class="tablinks" onclick="openTab(event, 'AlarmD')">Alarm</button>
<button class="tablinks" onclick="openTab(event, 'EinstellungenD')">Einstellungen</button>
<button class="tablinks" onclick="openTab(event, 'SonstigesD')">Sonstiges</button>
</div>
<div id="StatusD" class="tabcontent">
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
</div>
<div id="AlarmD" class="tabcontent">
<form id="alarm" action="send" target="hidden">
<fieldset>
<legend>Alarm</legend>
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
<option value=501>THW</option>
<option value=502>THW SEG</option>
<option value=503>THW FB</option>
<option value=504>THW BEL</option>
<option value=505>THW BRB</option>
<option value=506>THW E</option>
<option value=507>THW FK</option>
<option value=508>THW WV</option>
<option value=509>THW HÖRG</option>
<option value=510>THW I</option>
<option value=511>THW LOG V</option>
<option value=512>THW LOG M</option>
<option value=513>THW ORT</option>
<option value=514>THW ÖL</option>
<option value=515>THW R</option>
<option value=516>THW TW</option>
<option value=517>THW SPR</option>
<option value=518>THW WASSER</option>
<option value=519>THW WP</option>
<option value=520>THW EGS</option>
<option value=521>THW ASH</option>
<option value=601>P BR</option>
<option value=602>P BOMBE</option>
<option value=603>P USBV</option>
<option value=604>P GEISEL</option>
<option value=605>P SEK</option>
<option value=606>P LEBEL</option>
<option value=0>UNKLAR</option>
<option value=1>FME Test</option>
</select></p>
<p><label class="field" for="currentSub">Unterpunkt:</label>
<select class="layout" id="currentSub" name="currentSub" required>
<option value=0></option>
<optgroup label="F 1">
<option value=30>Mülltonne</option>
<option value=35>PKW</option>
<option value=17>Gerümpel im Freien</option>
<option value=61>gelöschtes Feuer</option>
<option value=76>Nachschau</option>
</optgroup>
<optgroup label="F 2">
<option value=117>Wohnungsbrand</option>
<option value=57>Dachstuhlbrand</option>
<option value=66>Kellerbrand</option>
<option value=118>Zimmerbrand</option>
<option value=65>Kaminbrand</option>
<option value=99>Rauchentwicklung</option>
</optgroup>
<optgroup label="F 2 Y">
<option value=0>in Wohngebäuden</option>
</optgroup>
<optgroup label="F 3">
<option value=23>Hochhaus</option>
<option value=18>Gewerbebetrieb</option>
<option value=40>Schreinerei</option>
<option value=25>Kfz-Werkstatt</option>
<option value=31>Pension</option>
<option value=0>Lagerplatz</option>
<option value=36>Produktions- und/oder Lagergebäude</option>
</optgroup>
<optgroup label="F 3 Y">
<option value=0>in Sondergebäuden</option>
</optgroup>
<optgroup label="F 4">
</optgroup>
<optgroup label="F BMA">
<option value=0>Meldung einer Brandmeldeanlage</option>
</optgroup>
<optgroup label="F BUS Y">
<option value=38>Reisebus</option>
<option value=7>Bus des ÖPNV</option>
<option value=41>Schulbus</option>
</optgroup>
<optgroup label="F FLUG 1 Y">
<option value=26>Kleinflugzeug</option>
<option value=46>Sportmaschine</option>
<option value=43>Segelflieger / Paraglider</option>
<option value=24>Hubschrauber</option>
<option value=22>Heißluftballons</option>
<option value=29>Militärmaschine</option>
</optgroup>
<optgroup label="F FLUG 2 Y">
<option value=19>Großflugzeug</option>
</optgroup>
<optgroup label="F GAS 1">
<option value=12>einzelner Gasflaschen</option>
<option value=14>einer Gasleitung</option>
</optgroup>
<optgroup label="F GAS 2">
<option value=15>Gastanks</option>
<option value=16>Gastankfahrzeugs</option>
<option value=13>Gaskesselwagens</option>
</optgroup>
<optgroup label="F LKW">
<option value=28>LKW</option>
<option value=8>Busses ohne Personen</option>
<option value=27>landwirtschaftliche Arbeitsmaschine</option>
</optgroup>
<optgroup label="F ZUG">
<option value=39>Schienenfahrzeugs</option>
<option value=48>Triebfahrzeugs</option>
<option value=50>Waggon</option>
<option value=34>Personenzug</option>
<option value=49>U- / S-Bahn-Zug</option>
<option value=21>Güterzugs</option>
</optgroup>
<optgroup label="F ZUG Y">
<option value=39>Schienenfahrzeugs</option>
<option value=48>Triebfahrzeugs</option>
<option value=50>Waggon</option>
<option value=34>Personenzug</option>
<option value=49>U- / S-Bahn-Zug</option>
<option value=21>Güterzugs</option>
</optgroup>
<optgroup label="F RWM">
<option value=0>Meldung eines ausgelösten (Heim-) Rauchwarnmelders</option>
</optgroup>
<optgroup label="F SCHIFF 1">
<option value=45>Sportboots</option>
<option value=42>Segelboots</option>
<option value=54>Yacht</option>
</optgroup>
<optgroup label="F SCHIFF 2">
<option value=11>Frachtschiffes</option>
</optgroup>
<optgroup label="F SCHIFF 2 Y">
<option value=33>Personenschiffes</option>
<option value=32>Personen- oder Fahrzeugfähre</option>
</optgroup>
<optgroup label="F SCHIFF 2 GEFAHR">
<option value=47>Tankschiff</option>
<option value=9>Containerschiff</option>
<option value=11>Frachtschiff</option>
</optgroup>
<optgroup label="F WALD 1">
<option value=51>Wald</option>
<option value=52>Wiese</option>
<option value=10>Feldes</option>
<option value=0>Unbekannte Lage</option>
<option value=53>Windenergieanlage</option>
</optgroup>
<optgroup label="F WALD 2">
<option value=51>Wald</option>
<option value=52>Wiese</option>
<option value=10>Feldes</option>
<option value=0>Unbekannte Lage</option>
<option value=53>Windenergieanlage</option>
</optgroup>
<optgroup label="H 1">
<option value=115>Wasser im Keller</option>
<option value=116>Wasserrohrbruch</option>
<option value=106>Tür- und Fenstersicherung</option>
<option value=1>Baum oder Gegenstand auf der Straße</option>
<option value=104>Tier in Not oder Unfall mit Tier</option>
<option value=0>Einfache technische Hilfeleistung an Bächen, Seen oder in Hafenbereichen</option>
<option value=87>Ölspur</option>
<option value=68>Kleine Mengen Betriebsstoffe aufnehmen</option>
</optgroup>
<optgroup label="H 1 Y">
<option value=82>Notfall-Türöffnung</option>
<option value=91>Person im Aufzug</option>
<option value=105>Tragehilfe für den Rettungsdienst</option>
</optgroup>
<optgroup label="H 2">
<option value=58>Fahrzeug umgestürzt</option>
<option value=3>Bauunfall</option>
<option value=62>Gerüsteinsturz</option>
<option value=71>Kran umgestürzt</option>
<option value=109>Unfall mit Einsturz von beteiligten Objekten</option>
</optgroup>
<optgroup label="H ABST Y">
<option value=90>Person in Absturzgefahr</option>
<option value=88>Person droht zu springen</option>
</optgroup>
<optgroup label="H ELEK">
<option value=108>Unfall in großen elektrischen Anlagen / Hochspannungsanlagen</option>
</optgroup>
<optgroup label="H EINST Y">
<option value=60>Gebäudeeinsturz</option>
<option value=3>Bauunfall</option>
<option value=62>Gerüsteinsturz</option>
<option value=71>Kran umgestürzt</option>
<option value=109>Unfall mit Einsturz von beteiligten Objekten</option>
<option value=97>Person verschüttet</option>
</optgroup>
<optgroup label="H FLUSS">
<option value=0>Einfache technische Hilfeleistung auf Flüssen</option>
</optgroup>
<optgroup label="H FLUSS Y">
<option value=93>Person in Fluss</option>
</optgroup>
<optgroup label="H WASS Y">
<option value=92>Person in Bach</option>
<option value=95>Person in See</option>
<option value=94>Person in Hafenbereich</option>
</optgroup>
<optgroup label="H GAS 1">
<option value=59>Gasgeruch</option>
</optgroup>
<optgroup label="H GAS 2">
<option value=0>Beschädigung einer Gasleitung</option>
<option value=0>Beschädigung eines Gastanks</option>
<option value=0>Beschädigung eines Gastankfahrzeugs</option>
<option value=0>Beschädigung eines Gaskesselwagen</option>
</optgroup>
<optgroup label="H GEFAHR 1">
<option value=111>Einzelne Gebinde von Chemikalien (Säure o.ä.)</option>
<option value=111>Einzelne Gebinde von Kraftstoffen (Benzin o.ä.)</option>
<option value=111>Größeren Mengen Öl</option>
<option value=111>Gefahrstoff im begrenzten Umfang</option>
<option value=111>Chlorgas im Schwimmbad</option>
</optgroup>
<optgroup label="H GEFAHR 2">
<option value=111>Tankfahrzeug</option>
<option value=111>Tankcontainer</option>
<option value=111>Kesselwaggon</option>
<option value=111>Gefahrstoff in großen Mengen</option>
</optgroup>
<optgroup label="H KLEMM 1 Y">
<option value=89>PKW / LKW nach VU</option>
<option value=89>Kfz / Maschine</option>
<option value=89>eCall-Notruf</option>
<option value=97>Person verschüttet</option>
</optgroup>
<optgroup label="H KLEMM 2 Y">
<option value=89>Bus nach VU</option>
<option value=89>Kfz / Maschine</option>
<option value=97>Mehrere Personen verschüttet</option>
</optgroup>
<optgroup label="H ÖL FLUSS">
<option value=84>Öl auf Fluss</option>
</optgroup>
<optgroup label="H ÖL WASS">
<option value=83>Öl auf Bach</option>
<option value=86>Öl auf See</option>
<option value=85>Öl auf Hafenbereich</option>
</optgroup>
<optgroup label="H RADIOAKTIV">
<option value=112>Unfall mit radioaktiven Stoffen</option>
</optgroup>
<optgroup label="H SCHIFF">
<option value=63>Havarie oder Kollision eines Personen- oder Frachtschiffes oder einer Fähre</option>
<option value=63>Schiff auf Grund gelaufen oder droht zu sinken</option>
<option value=63>größerer Wassereintritt in Boot / Schiff</option>
</optgroup>
<optgroup label="H SCHIFF Y">
<option value=63>Havarie oder Kollision eines Personen- oder Frachtschiffes oder einer Fähre</option>
<option value=63>Schiff auf Grund gelaufen oder droht zu sinken</option>
<option value=63>größerer Wassereintritt in Boot / Schiff</option>
</optgroup>
<optgroup label="H ZUG 1 Y">
<option value=96>Person unter Zug / U- / S-Bahn / Straßenbahn</option>
<option value=69>Kollision eines Zuges mit einem Straßenfahrzeug</option>
</optgroup>
<optgroup label="H ZUG 2 Y">
<option value=107>Unfall eines Zuges / einer U- / S-Bahn / Straßenbahn</option>
<option value=70>Kollision zweier Züge</option>
</optgroup>
<optgroup label="U Unwetter Sturm">
<option value=2>Baum umgestürzt</option>
<option value=56>Dach abgedeckt/eingestürzt</option>
<option value=100>Schäden durch umhergewehte Gegenstände</option>
<option value=101>Sicherung von Gebäudeteilen und Gegenständen</option>
<option value=4>Befreiung von Schneelasten</option>
</optgroup>
<optgroup label="U Unwetter Wasser">
<option value=114>Wasser im Keller, in Tiefgaragen und Unterführungen</option>
<option value=102>Straße überflutet</option>
<option value=67>Kfz steckt im Wasser fest</option>
</optgroup>
</select></p>
</fieldset>
<fieldset>
<legend>Adresse</legend>
<p><label class="field" for="currentPLZ">PLZ:</label>
<select class="layout" id="currentPLZ" name="currentPLZ" required>
<option value=1>35390</option>
<option value=2>35392</option>
<option value=3 selected="selected">35394</option>
<option value=4>35396</option>
<option value=5>35398</option>
</select></p>
<p><label class="field" for="currentCity">Ort:</label>
<select class="layout" id="currentCity" name="currentCity" required>
<option value=1>Allendorf</option>
<option value=2>Gießen</option>
<option value=3>Kleinlinden</option>
<option value=4>Lützellinden</option>
<option value=5 selected="selected">Rödgen</option>
<option value=6>Wieseck</option>
</select></p>
<p><label class="field" for="currentStreet">Straße:</label>
<select class="layout" id="currentStreet" name="currentStreet" required>
<option value=800>Außerhalb</option>
<option value=801>Koordinaten</option>
<optgroup label="Allendorf">
<option value=21>Altes Gericht</option>
<option value=25>Am Alten Steinbruch</option>
<option value=33>Am Gallichten</option>
<option value=38>Am Kasimir</option>
<option value=41>Am Sportplatz</option>
<option value=52>Am Weinberg</option>
<option value=53>Am Zehntfrei</option>
<option value=77>Aubach</option>
<option value=100>Bergstrasse</option>
<option value=178>Ehrsamer Weg</option>
<option value=218>Friedhofstrasse</option>
<option value=243>Gerichtsspitz</option>
<option value=309>Hintergasse</option>
<option value=311>Hochstrasse</option>
<option value=324>Hoppensteinstrasse</option>
<option value=332>Hüttenbergstrasse</option>
<option value=339>Im Kleefeld</option>
<option value=345>In der Lache</option>
<option value=366>Kahlweg</option>
<option value=395>Kleebachstrasse</option>
<option value=398>Kleinlindener Strasse</option>
<option value=406>Krautgarten</option>
<option value=412>Lahnparkstrasse</option>
<option value=504>Obergasse</option>
<option value=585>Schneiderhenn</option>
<option value=639>Teilgärtenweg</option>
<option value=649>Triebstrasse</option>
<option value=656>Über der Seife</option>
<option value=662>Untergasse</option>
</optgroup>
<optgroup label="Gießen">
<option value=1>Adalbert-Stifter-Strasse</option>
<option value=2>Adam-Scheurer-Strasse</option>
<option value=3>Adolph-Kolping-Strasse</option>
<option value=4>Ahornweg</option>
<option value=6>Albert-Schweitzer-Strasse</option>
<option value=7>Alfred-Bock-Strasse</option>
<option value=8>Alicenstrasse</option>
<option value=11>Altarasstrasse</option>
<option value=12>Alte Gerberei</option>
<option value=14>Altenbergweg</option>
<option value=17>Altenfeldsweg</option>
<option value=18>Alter Krofdorfer Weg</option>
<option value=19>Alter Steinbacher Weg</option>
<option value=20>Alter Wetzlarer Weg</option>
<option value=22>Am Alten Flughafen</option>
<option value=23>Am Alten Friedhof</option>
<option value=24>Am Alten Gaswerk</option>
<option value=28>Am Bergwerkswald</option>
<option value=29>Am Brennofen</option>
<option value=34>Am Güterbahnhof</option>
<option value=43>Am Steg</option>
<option value=46>Am Stockhaus</option>
<option value=47>Am Throms Garten</option>
<option value=48>Am Unteren Rain</option>
<option value=54>Am Zollstock</option>
<option value=55>Amselweg</option>
<option value=59>An der Alten Post</option>
<option value=60>An der Automeile</option>
<option value=61>An der Hessenhalle</option>
<option value=62>An der Johanneskirche</option>
<option value=63>An der Kaserne</option>
<option value=64>An der Liebigshöhe</option>
<option value=67>An der Volkshalle</option>
<option value=68>An Steins Garten</option>
<option value=70>Anger</option>
<option value=71>Anna-Mettbach-Strasse</option>
<option value=72>Anne-Frank-Strasse</option>
<option value=73>Anneröder Weg</option>
<option value=74>Annette-Kolb-Weg</option>
<option value=75>Arndtstrasse</option>
<option value=76>Asterweg</option>
<option value=81>Auf der Bach</option>
<option value=83>August-Balzer-Weg</option>
<option value=85>August-Hermann-Francke-Weg</option>
<option value=86>August-Messer-Strasse</option>
<option value=87>Aulweg</option>
<option value=92>Bahnhofstrasse</option>
<option value=93>Bänningerstrasse</option>
<option value=94>Bantzerweg</option>
<option value=96>Barresgraben</option>
<option value=97>Baumgarten</option>
<option value=99>Beethovenstrasse</option>
<option value=102>Bergwerk</option>
<option value=103>Berliner Platz</option>
<option value=105>Bernhard-Itzel-Strasse</option>
<option value=107>Bertha-von-Suttner-Weg</option>
<option value=111>Bismarckstrasse</option>
<option value=113>Bleichstrasse</option>
<option value=114>Böcklinstrasse</option>
<option value=115>Bodelschwinghweg</option>
<option value=116>Bonifatiusweg</option>
<option value=117>Bootshausstrasse</option>
<option value=118>Börneweg</option>
<option value=119>Brahmsstrasse</option>
<option value=120>Brandgasse</option>
<option value=121>Brandplatz</option>
<option value=123>Braugasse</option>
<option value=125>Bromberger Strasse</option>
<option value=126>Bruchstrasse</option>
<option value=128>Brumlikweg</option>
<option value=131>Buchenweg</option>
<option value=132>Buchnerstrasse</option>
<option value=133>Bückingstrasse</option>
<option value=134>Buddestrasse</option>
<option value=139>Burggraben</option>
<option value=142>Carl-Franz-Strasse</option>
<option value=143>Carl-Maria-von-Weber-Strasse</option>
<option value=144>Carlo-Mierendorff-Strasse</option>
<option value=146>Carl-Vogt-Strasse</option>
<option value=148>Christian-Rinck-Strasse</option>
<option value=149>Christoph-Rübsamen-Steg</option>
<option value=150>Clementiastrasse</option>
<option value=151>Clevelandstrasse</option>
<option value=152>Colemanstrasse</option>
<option value=153>Cranachstrasse</option>
<option value=154>Crednerstrasse</option>
<option value=155>Curtmannstrasse</option>
<option value=156>Dahlienweg</option>
<option value=157>Dammstrasse</option>
<option value=158>Danziger Strasse</option>
<option value=161>Dietrich-Bonhöffer-Strasse</option>
<option value=162>Diezstrasse</option>
<option value=163>Döringstrasse</option>
<option value=164>Domäne Schiffenberg</option>
<option value=166>Drosselweg</option>
<option value=168>Dünsbergstrasse</option>
<option value=169>Dürerstrasse</option>
<option value=171>Ebelstrasse</option>
<option value=173>Ederstrasse</option>
<option value=174>Editha-Klipstein-Weg</option>
<option value=175>Edlef-Köppen-Weg</option>
<option value=177>Egerländer Strasse</option>
<option value=179>Eichendorffring</option>
<option value=181>Eichgärten</option>
<option value=182>Eichgärtenallee</option>
<option value=186>Elly-Heuss-Knapp-Weg</option>
<option value=187>Elsa-Brandström-Strasse</option>
<option value=188>Erdkauter Weg</option>
<option value=190>Erlengasse</option>
<option value=192>Ernst-Eckstein-Strasse</option>
<option value=193>Ernst-Leitz-Strasse</option>
<option value=194>Ernst-Toller-Weg</option>
<option value=195>Eulenkopf</option>
<option value=196>Europastrasse</option>
<option value=197>Falkweg</option>
<option value=199>Fasanenweg</option>
<option value=200>Felsenweg</option>
<option value=201>Ferniestrasse</option>
<option value=202>Feuerbachstrasse</option>
<option value=203>Feulgenstrasse</option>
<option value=204>Fichtestrasse</option>
<option value=205>Finkenweg</option>
<option value=206>Fliednerweg</option>
<option value=208>Flutgraben</option>
<option value=209>Fockestrasse</option>
<option value=211>Forsthausweg</option>
<option value=214>Franzensbader Strasse</option>
<option value=215>Freiligrathstrasse</option>
<option value=216>Friedensstrasse</option>
<option value=217>Friedhofsallee</option>
<option value=221>Friedrich-List-Strasse</option>
<option value=222>Friedrich-Naumann-Strasse</option>
<option value=223>Friedrich-Schwarz-Strasse</option>
<option value=224>Friedrichstrasse</option>
<option value=225>Fröbelstrasse</option>
<option value=227>Fuchsgraben</option>
<option value=228>Fuldastrasse</option>
<option value=229>Gabelsbergerstrasse</option>
<option value=230>Gaffkystrasse</option>
<option value=232>Gartenstrasse</option>
<option value=233>Gartfeld</option>
<option value=235>Georg-Büchner-Strasse</option>
<option value=237>Georg-Elser-Strasse</option>
<option value=238>Georg-Haas-Strasse</option>
<option value=239>Georg-Philipp-Gail-Strasse</option>
<option value=240>Georg-Schlosser-Strasse</option>
<option value=242>Geranienweg</option>
<option value=246>Glaubrechtstrasse</option>
<option value=247>Gleiberger Weg</option>
<option value=249>Gnauthstrasse</option>
<option value=250>Göthestrasse</option>
<option value=252>Gottfried-Arnold-Strasse</option>
<option value=253>Gottlieb-Daimler-Strasse</option>
<option value=255>Graudenzer Strasse</option>
<option value=258>Grenzborn</option>
<option value=261>Grosser Morgen</option>
<option value=262>Grosser Steinweg</option>
<option value=263>Grünberger Strasse</option>
<option value=264>Grüner Weg</option>
<option value=265>Günthersgraben</option>
<option value=266>Gustav-Krüger-Strasse</option>
<option value=268>Gutenbergstrasse</option>
<option value=269>Gutfleischstrasse</option>
<option value=271>Hammstrasse</option>
<option value=272>Händelstrasse</option>
<option value=275>Hannah-Arendt-Strasse</option>
<option value=276>Hardtallee</option>
<option value=277>Hasenköppel</option>
<option value=278>Hasenpfad</option>
<option value=280>Häuser Born</option>
<option value=281>Haydnstrasse</option>
<option value=282>Hedwig-Burgheim-Ring</option>
<option value=283>Heegstrauchweg</option>
<option value=287>Hein-Heckroth-Strasse</option>
<option value=288>Heinrich-Buff-Ring</option>
<option value=289>Heinrich-Fourier-Strasse</option>
<option value=291>Heinrich-Will-Strasse</option>
<option value=292>Helene-Weber-Weg</option>
<option value=294>Henriette-Fürth-Strasse</option>
<option value=295>Henriette-Hezel-Strasse</option>
<option value=296>Henselstrasse</option>
<option value=297>Herderweg</option>
<option value=298>Hermann-Levi-Strasse</option>
<option value=301>Hessenstrasse</option>
<option value=302>Heuchelheimer Strasse</option>
<option value=303>Heyerweg</option>
<option value=304>Hillebrandstrasse</option>
<option value=305>Hindemithstrasse</option>
<option value=307>Hinter der Ostanlage</option>
<option value=308>Hinter der Westanlage</option>
<option value=312>Hochwarte</option>
<option value=313>Hofacker</option>
<option value=314>Hofmannstrasse</option>
<option value=317>Hoher Rain</option>
<option value=319>Holbeinring</option>
<option value=321>Hollerweg</option>
<option value=323>Holzweg</option>
<option value=325>Hornackerring</option>
<option value=328>Hugo-von-Ritgen-Strasse</option>
<option value=329>Hultschiner Strasse</option>
<option value=330>Humboldtstrasse</option>
<option value=331>Hunfeld</option>
<option value=333>Hüttenweg</option>
<option value=334>Iheringstrasse</option>
<option value=338>Im Kalten Grund</option>
<option value=346>In der Lechenau</option>
<option value=350>Jacksonstrasse</option>
<option value=351>Jahnstrasse</option>
<option value=352>Jefferson Street</option>
<option value=354>Joachimstaler Strasse</option>
<option value=355>Johann-Bernhard-Wilbrand-Strasse</option>
<option value=356>Johannesbader Strasse</option>
<option value=358>Johannesstrasse</option>
<option value=359>Johannette-Lein-Gasse</option>
<option value=360>Johann-Sebastian-Bach-Strasse</option>
<option value=361>John-F.-Kennedy-Platz</option>
<option value=362>Joseph-Kreuter-Weg</option>
<option value=363>Julius-Höpfner-Strasse</option>
<option value=365>Junkersstrasse</option>
<option value=368>Kantstrasse</option>
<option value=369>Kanzleiberg</option>
<option value=370>Kapellenstrasse</option>
<option value=371>Kaplansgasse</option>
<option value=373>Karl-Benz-Strasse</option>
<option value=374>Karl-Follen-Strasse</option>
<option value=375>Karl-Glöckner-Strasse</option>
<option value=376>Karl-Keller-Strasse</option>
<option value=378>Karl-Reuter-Weg</option>
<option value=379>Karl-Sack-Strasse</option>
<option value=380>Karlsbader Strasse</option>
<option value=382>Katharinengasse</option>
<option value=383>Katharinenplatz</option>
<option value=385>Keplerstrasse</option>
<option value=386>Kerkrader Strasse</option>
<option value=389>Kirchenplatz</option>
<option value=394>Kirschbaumweg</option>
<option value=397>Kleine Mühlgasse</option>
<option value=399>Klingelbachweg</option>
<option value=400>Klinikstrasse</option>
<option value=401>Klosterweg</option>
<option value=403>Königgrätzer Strasse</option>
<option value=404>Konstantinbader Strasse</option>
<option value=407>Kreuzplatz</option>
<option value=408>Krofdorfer Strasse</option>
<option value=409>Kropbacher Weg</option>
<option value=411>Kugelberg</option>
<option value=413>Lahnstrasse</option>
<option value=414>Landgrafenstrasse</option>
<option value=415>Landgraf-Philipp-Platz</option>
<option value=416>Landmannstrasse</option>
<option value=419>Langhansstrasse</option>
<option value=420>Lärchenwäldchen</option>
<option value=421>Läufertsröder Weg</option>
<option value=422>Launsbacher Weg</option>
<option value=423>Lausköppel</option>
<option value=424>Lehmweg</option>
<option value=425>Leihgesterner Weg</option>
<option value=426>Leimenkauter Weg</option>
<option value=427>Lessingstrasse</option>
<option value=428>Licher Strasse</option>
<option value=430>Liebigstrasse</option>
<option value=431>Lilienthalstrasse</option>
<option value=432>Lilienweg</option>
<option value=433>Lincolnstrasse</option>
<option value=434>Lindengasse</option>
<option value=435>Lindenplatz</option>
<option value=437>Löbers Hof</option>
<option value=438>Löberstrasse</option>
<option value=439>Lonystrasse</option>
<option value=440>Louis-Frech-Strasse</option>
<option value=441>Löwengasse</option>
<option value=442>Ludwig-Richter-Strasse</option>
<option value=443>Ludwig-Schneider-Weg</option>
<option value=444>Ludwigsplatz</option>
<option value=445>Ludwigstrasse</option>
<option value=446>Lufthansastrasse</option>
<option value=447>Lutherberg</option>
<option value=449>Maigasse</option>
<option value=450>Marburger Strasse</option>
<option value=451>Margarete-Bieber-Weg</option>
<option value=452>Margaretenhütte</option>
<option value=453>Maria-Birnbaum-Weg</option>
<option value=454>Marie-Curie-Weg</option>
<option value=455>Marie-Juchacz-Weg</option>
<option value=456>Marienbader Strasse</option>
<option value=457>Marktlaubenstrasse</option>
<option value=458>Marktplatz</option>
<option value=459>Marktstrasse</option>
<option value=461>Marshallstrasse</option>
<option value=463>Martin-Luther-King-Strasse</option>
<option value=464>Mäusburg</option>
<option value=465>Max-Eyth-Strasse</option>
<option value=466>Max-Reger-Strasse</option>
<option value=467>Meerweinstrasse</option>
<option value=469>Meisenbornweg</option>
<option value=471>Memeler Strasse</option>
<option value=472>Menzelstrasse</option>
<option value=473>Mildred-Harnack-Weg</option>
<option value=474>Minna-Naumann-Weg</option>
<option value=475>Mittelweg</option>
<option value=476>Mittermaierstrasse</option>
<option value=477>Mohrunger Weg</option>
<option value=478>Moltkestrasse</option>
<option value=479>Monroestrasse</option>
<option value=482>Mozartstrasse</option>
<option value=485>Mühlstrasse</option>
<option value=486>Nahrungsberg</option>
<option value=487>Narzissenweg</option>
<option value=488>Nelkenweg</option>
<option value=489>Nelly-Sachs-Weg</option>
<option value=490>Netanyastrasse</option>
<option value=492>Neuen Bäue</option>
<option value=493>Neuenweg</option>
<option value=494>Neustadt</option>
<option value=497>Nonnenweg</option>
<option value=498>Nordanlage</option>
<option value=500>Oberauweg</option>
<option value=501>Oberer Gleiberger Weg</option>
<option value=502>Oberer Hardthof</option>
<option value=506>Oberlinweg</option>
<option value=508>Ohlebergsweg</option>
<option value=509>Ostanlage</option>
<option value=510>Oswaldsgarten</option>
<option value=511>Otto-Behaghel-Strasse</option>
<option value=512>Pater-Delp-Strasse</option>
<option value=513>Paul-Meimberg-Strasse</option>
<option value=514>Paul-Schneider-Strasse</option>
<option value=515>Paul-Zipp-Strasse</option>
<option value=516>Pestalozzistrasse</option>
<option value=517>Petersweiher</option>
<option value=518>Pfarrgarten</option>
<option value=520>Philipp-Reis-Strasse</option>
<option value=523>Philosophenwald</option>
<option value=524>Pistorstrasse</option>
<option value=525>Platz der Deutschen Einheit</option>
<option value=526>Plockstrasse</option>
<option value=527>Pohlheimer Strasse</option>
<option value=528>Posener Strasse</option>
<option value=529>Professorenweg</option>
<option value=531>Rabenweg</option>
<option value=532>Raiffeisenstrasse</option>
<option value=533>Rambachweg</option>
<option value=534>Rathenaustrasse</option>
<option value=536>Rehschneise</option>
<option value=538>Reichenberger Strasse</option>
<option value=539>Reichensand</option>
<option value=542>Richard-Schirrmann-Weg</option>
<option value=543>Richard-Wagner-Strasse</option>
<option value=544>Riegelpfad</option>
<option value=546>Ringallee</option>
<option value=547>Rittergasse</option>
<option value=548>Riversplatz</option>
<option value=549>Robert-Bosch-Strasse</option>
<option value=550>Robert-Sommer-Strasse</option>
<option value=551>Röderring</option>
<option value=552>Rödgener Strasse</option>
<option value=553>Rodheimer Strasse</option>
<option value=554>Rodtbergstrasse</option>
<option value=555>Rodtgärten</option>
<option value=556>Rodthohl</option>
<option value=557>Röntgenstrasse</option>
<option value=558>Roonstrasse</option>
<option value=559>Rooseveltstrasse</option>
<option value=561>Rosenpfad</option>
<option value=563>Rudolf-Buchheim-Strasse</option>
<option value=564>Rudolf-Diesel-Strasse</option>
<option value=567>Salomestrasse</option>
<option value=568>Salzböder Weg</option>
<option value=570>Sandfeld</option>
<option value=571>Sandgasse</option>
<option value=572>Sandkauter Weg</option>
<option value=573>Schäferbrunnen</option>
<option value=574>Schanzenstrasse</option>
<option value=575>Schiessgärten</option>
<option value=576>Schiffenberger Weg</option>
<option value=578>Schillerstrasse</option>
<option value=579>Schlachthofstrasse</option>
<option value=580>Schlangenzahl</option>
<option value=582>Schlesische Strasse</option>
<option value=583>Schlossgasse</option>
<option value=587>Schottstrasse</option>
<option value=588>Schubertstrasse</option>
<option value=589>Schulstrasse</option>
<option value=590>Schuppstrasse</option>
<option value=592>Schützenstrasse</option>
<option value=593>Schwalbachacker</option>
<option value=594>Schwarzacker</option>
<option value=596>Schwarzlachweg</option>
<option value=600>Seltersweg</option>
<option value=601>Senckenbergstrasse</option>
<option value=602>Sieboldstrasse</option>
<option value=603>Siegmund-Heichelheim-Strasse</option>
<option value=604>Siemensstrasse</option>
<option value=605>Sommerberg</option>
<option value=606>Sonnenstrasse</option>
<option value=608>Spenerweg</option>
<option value=609>Spitzwegring</option>
<option value=610>Spörhasestrasse</option>
<option value=613>Stadtwald</option>
<option value=614>Starenweg</option>
<option value=616>Stefan-Bellof-Strasse</option>
<option value=618>Steinberger Weg</option>
<option value=621>Steinkaute</option>
<option value=622>Steinstrasse</option>
<option value=623>Stephanstrasse</option>
<option value=624>Sternmark</option>
<option value=626>Stolzenmorgen</option>
<option value=630>Studentensteg</option>
<option value=631>Südanlage</option>
<option value=632>Sudetenlandstrasse</option>
<option value=633>Südhang</option>
<option value=634>Talstrasse</option>
<option value=635>Tannenweg</option>
<option value=636>Taubenweg</option>
<option value=640>Teufelslustgärtchen</option>
<option value=641>Thärstrasse</option>
<option value=642>Theodor-Storm-Weg</option>
<option value=643>Therese-Kalbfleisch-Strasse</option>
<option value=644>Thielmannweg</option>
<option value=645>Thomastrasse</option>
<option value=646>Tiefenweg</option>
<option value=648>Trieb</option>
<option value=650>Trillergässchen</option>
<option value=652>Troppauer Strasse</option>
<option value=653>Tulpenweg</option>
<option value=655>Ubbelohdeweg</option>
<option value=658>Uferweg</option>
<option value=659>Uhlandstrasse</option>
<option value=660>Ulner Dreieck</option>
<option value=661>Unterer Hardthof</option>
<option value=663>Unterhof</option>
<option value=664>Unterm Hardtwäldchen</option>
<option value=666>Versailler Strasse</option>
<option value=667>Vetzberger Weg</option>
<option value=672>Waagengasse</option>
<option value=674>Waldbrunnenweg</option>
<option value=678>Walltorstrasse</option>
<option value=679>Walter-Süskind-Strasse</option>
<option value=680>Wartweg</option>
<option value=681>Washingtonstrasse</option>
<option value=682>Watzenborner Weg</option>
<option value=683>Weidengasse</option>
<option value=686>Weilburger Grenze</option>
<option value=689>Weisserde</option>
<option value=690>Welckerstrasse</option>
<option value=693>Werrastrasse</option>
<option value=694>Weserstrasse</option>
<option value=695>Westanlage</option>
<option value=696>Wettenberger Weg</option>
<option value=699>Wetzsteinstrasse</option>
<option value=700>Wichernweg</option>
<option value=701>Wiesecker Weg</option>
<option value=702>Wiesenstrasse</option>
<option value=704>Wilhelm-Leuschner-Strasse</option>
<option value=706>Wilhelm-Pfeiffer-Strasse</option>
<option value=707>Wilhelmstrasse</option>
<option value=708>Wilsonstrasse</option>
<option value=709>Winchester Strasse</option>
<option value=712>Wingertshecke</option>
<option value=713>Wissmarer Weg</option>
<option value=714>Wolfstrasse</option>
<option value=715>Wolkengasse</option>
<option value=716>Zeppelinstrasse</option>
<option value=717>Zinzendorfweg</option>
<option value=718>Zu den Mühlen</option>
<option value=723>Zum Waldsportplatz</option>
<option value=726>Zur Grossen Bleiche</option>
</optgroup>
<optgroup label="Kleinlinden">
<option value=5>Albert-Bossler-Strasse</option>
<option value=10>Allendorfer Strasse</option>
<option value=57>An den Birken</option>
<option value=58>An den Schulgärten</option>
<option value=69>Andreasteich</option>
<option value=82>Auf der Wann</option>
<option value=88>Bachweg</option>
<option value=98>Bechsteinweg</option>
<option value=101>Bergwaldstrasse</option>
<option value=106>Bernhardtstrasse</option>
<option value=109>Bettina-von-Arnim-Strasse</option>
<option value=122>Brandweg</option>
<option value=127>Brüder-Grimm-Strasse</option>
<option value=137>Bürgermeister-Jung-Weg</option>
<option value=138>Burggartenstrasse</option>
<option value=210>Fontaneweg</option>
<option value=212>Frankfurter Strasse</option>
<option value=219>Friedhofsweg</option>
<option value=236>Georg-Edward-Strasse</option>
<option value=245>Ginsterbusch</option>
<option value=256>Gregor-Mendel-Strasse</option>
<option value=279>Hauffstrasse</option>
<option value=284>Heerweg</option>
<option value=285>Hegweg</option>
<option value=286>Heide</option>
<option value=299>Hermann-Löns-Strasse</option>
<option value=300>Hermann-Rau-Strasse</option>
<option value=318>Hohl</option>
<option value=322>Holunderweg</option>
<option value=327>Hügelstrasse</option>
<option value=384>Katzenbach</option>
<option value=391>Kirchpfad</option>
<option value=448>Lützellindener Strasse</option>
<option value=460>Markwald</option>
<option value=480>Moosweg</option>
<option value=495>Niebergallweg</option>
<option value=519>Pfingstweide</option>
<option value=545>Riehlweg</option>
<option value=566>Saarlandstrasse</option>
<option value=577>Schildberg</option>
<option value=581>Schlehdorn</option>
<option value=611>Sportfeld</option>
<option value=673>Wacholderbusch</option>
<option value=677>Waldweide</option>
<option value=685>Weigelstrasse</option>
<option value=698>Wetzlarer Strasse</option>
<option value=703>Wilhelm-Jung-Strasse</option>
<option value=722>Zum Maiplatz</option>
<option value=724>Zum Weiher</option>
</optgroup>
<optgroup label="Lützellinden">
<option value=9>Allendörfer Au</option>
<option value=26>Am Backhaus</option>
<option value=32>Am Faltergarten</option>
<option value=35>Am Hellerpfad</option>
<option value=36>Am Hügel</option>
<option value=42>Am Steckelchen</option>
<option value=45>Am Steinrück</option>
<option value=51>Am Weiher</option>
<option value=66>An der Schule</option>
<option value=104>Berliner Strasse</option>
<option value=108>Beskidenstrasse</option>
<option value=110>Birkenweg</option>
<option value=112>Bitzenstrasse</option>
<option value=124>Breslauer Strasse</option>
<option value=170>Dutenhofener Strasse</option>
<option value=198>Falltorstrasse</option>
<option value=207>Flugplatz</option>
<option value=213>Franzen Garten</option>
<option value=226>Fröschen Weiher</option>
<option value=259>Grethenstrasse</option>
<option value=306>Hinter dem Steinrücken</option>
<option value=310>Hochelheimer Weg</option>
<option value=326>Hörnsheimer Strasse</option>
<option value=335>Im Gässchen</option>
<option value=340>Im Sporn</option>
<option value=343>In den Gärten</option>
<option value=367>Kaiserstrasse</option>
<option value=377>Karl-Kling-Strasse</option>
<option value=393>Kirchweg</option>
<option value=396>Kleebergstrasse</option>
<option value=418>Langer Strich</option>
<option value=436>Lindenstrasse</option>
<option value=535>Rechtenbacher Hohl</option>
<option value=541>Rheinfelser Strasse</option>
<option value=562>Rosenweg</option>
<option value=595>Schwarze Hohl</option>
<option value=597>Schwimmbadweg</option>
<option value=607>Sonnenweg</option>
<option value=612>Sportplatzstrasse</option>
<option value=620>Steinhohl</option>
<option value=637>Taunusstrasse</option>
<option value=670>Vogelsang</option>
<option value=676>Waldstrasse</option>
<option value=688>Weingartenstrasse</option>
<option value=720>Zum Dorfplatz</option>
<option value=721>Zum Kolbengraben</option>
</optgroup>
<optgroup label="Rödgen">
<option value=27>Am Bergwald</option>
<option value=39>Am Kirschenberg</option>
<option value=65>An der Schillerlinde</option>
<option value=78>Auf dem Freistück</option>
<option value=95>Bärner Strasse</option>
<option value=130>Brunnenweg</option>
<option value=136>Bürgerhausstrasse</option>
<option value=140>Burgwiesenweg</option>
<option value=141>Canonstrasse</option>
<option value=165>Dreieck</option>
<option value=220>Friedrich-Ebert-Strasse</option>
<option value=260>Grossen-Busecker Strasse</option>
<option value=293>Helgenstockstrasse</option>
<option value=336>Im Hopfengarten</option>
<option value=341>Im Uderborn</option>
<option value=347>In der Roos</option>
<option value=348>Industriestrasse</option>
<option value=390>Kirchenring</option>
<option value=417 selected="selected">Lange Ortsstrasse</option>
<option value=560>Rosengasse</option>
<option value=565>Ruhbanksweg</option>
<option value=598>Seewiesenstrasse</option>
<option value=617>Steinacker</option>
<option value=629>Struthstrasse</option>
<option value=651>Troher Strasse</option>
<option value=657>Udersbergstrasse</option>
<option value=671>Vor dem Hegwald</option>
<option value=719>Zum Bahnhof</option>
<option value=725>Zur Alten Eiche</option>
<option value=727>Zur Kastanie</option>
</optgroup>
<optgroup label="Wieseck">
<option value=13>Alte Schulstrasse</option>
<option value=15>Altenburger Strasse</option>
<option value=16>Alten-Busecker-Strasse</option>
<option value=30>Am Eichelbaum</option>
<option value=31>Am Erlenberg</option>
<option value=37>Am Kaiserberg</option>
<option value=40>Am Siegborn</option>
<option value=44>Am Steinkreuz</option>
<option value=49>Am Urnenfeld</option>
<option value=50>Am Wallborn</option>
<option value=56>An dem Trieb</option>
<option value=79>Auf dem Kaisersberg</option>
<option value=80>Auf dem Krohplatz</option>
<option value=84>August-Bramm-Weg</option>
<option value=89>Backhausstrasse</option>
<option value=90>Badenburg Blockstelle</option>
<option value=91>Badenburger Hohl</option>
<option value=129>Brunnengasse</option>
<option value=135>Burgenring</option>
<option value=145>Carl-Ulrich-Strasse</option>
<option value=147>Chamissoweg</option>
<option value=159>Der Lustgarten</option>
<option value=160>Diebweg</option>
<option value=167>Dünsbergring</option>
<option value=172>Ecke</option>
<option value=176>Eduard-David-Strasse</option>
<option value=180>Eichenröder Weg</option>
<option value=183>Eichgasse</option>
<option value=184>Eisenacher Strasse</option>
<option value=185>Eisenstein</option>
<option value=189>Erfurter Strasse</option>
<option value=191>Ermelgasse</option>
<option value=231>Gänsmühle</option>
<option value=234>Gellertweg</option>
<option value=241>Geraer Strasse</option>
<option value=244>Giessener Strasse</option>
<option value=248>Gleibergring</option>
<option value=251>Gothaer Strasse</option>
<option value=254>Grabenstrasse</option>
<option value=257>Greizer Strasse</option>
<option value=267>Gustav-Stresemann-Ring</option>
<option value=270>Hagstrasse</option>
<option value=273>Hangelsteinring</option>
<option value=274>Hangelsteinstrasse</option>
<option value=290>Heinrich-Ritzel-Strasse</option>
<option value=315>Hohensteinring</option>
<option value=316>Höhenweg</option>
<option value=320>Hölderlinweg</option>
<option value=337>Im Kaisersgrund</option>
<option value=342>In den Erlen</option>
<option value=344>In der Hunsbach</option>
<option value=349>Inselweg</option>
<option value=353>Jenaer Strasse</option>
<option value=357>Johannesberg</option>
<option value=364>Jungfernstrasse</option>
<option value=372>Karl-Benner-Strasse</option>
<option value=381>Karlstrasse</option>
<option value=387>Kesslerstrasse</option>
<option value=388>Kiesweg</option>
<option value=392>Kirchstrasse</option>
<option value=402>Kohlweg</option>
<option value=405>Kornblumenstrasse</option>
<option value=410>Krumstück</option>
<option value=429>Lichtenauer Weg</option>
<option value=442>Ludwig-Richter-Strasse</option>
<option value=450>Marburger Strasse</option>
<option value=462>Martha-Mendel-Weg</option>
<option value=468>Meininger Weg</option>
<option value=470>Meissingerweg</option>
<option value=481>Möserstrasse</option>
<option value=483>Mühläckerring</option>
<option value=484>Mühlhäuser Strasse</option>
<option value=491>Neue Strasse</option>
<option value=496>Niederfeldstrasse</option>
<option value=499>Nordhäuser Weg</option>
<option value=503>Obergarten</option>
<option value=505>Oberlachweg</option>
<option value=507>Ockerweg</option>
<option value=521>Philipp-Scheidemann-Strasse</option>
<option value=522>Philosophenstrasse</option>
<option value=530>Rabenauer Strasse</option>
<option value=537>Reichelsberg</option>
<option value=540>Reinhard-Strecker-Weg</option>
<option value=569>Sandacker</option>
<option value=584>Schmalkaldener Weg</option>
<option value=586>Schöne Aussicht</option>
<option value=591>Schustergasse</option>
<option value=599>Sellnberg</option>
<option value=615>Staufenbergring</option>
<option value=619>Steinerne Brücke</option>
<option value=625>Stiegel</option>
<option value=627>Struppmühle</option>
<option value=628>Struppmühlenweg</option>
<option value=638>Teichweg</option>
<option value=647>Treiser Weg</option>
<option value=654>Turnstrasse</option>
<option value=665>Ursulum</option>
<option value=668>Vetzbergring</option>
<option value=669>Vixröder Strasse</option>
<option value=675>Waldfrieden</option>
<option value=684>Weidigstrasse</option>
<option value=687>Weimarer Strasse</option>
<option value=691>Wellersburgring</option>
<option value=692>Wellerscheid</option>
<option value=697>Wettenbergring</option>
<option value=705>Wilhelm-Liebknecht-Strasse</option>
<option value=710>Winckelmannstrasse</option>
<option value=711>Wingert</option>
</optgroup>
</select></p>
<p><label class="field" for="currentHouseNumber">Hausnummer:</label>
<input class="layout" type="number" id="currentHouseNumber" name="currentHouseNumber" min="1" max="999" value="1"/></p>
<p><label class="field" for="currentHouseAdddition">Zusatz:</label>
<input class="layout" type="text" id="currentHouseAdddition" name="currentHouseAdddition" pattern="[A-Za-z]{0,3}"/></p>
<p hidden><label class="field" for="currentAddress">Freie Adresse:</label><input class="layout" type='text' id='currentAddress' name='currentAddress'/></p>
</fieldset>
<fieldset>
<legend>Sonstiges</legend>
<p><label class="field" for="currentComment">Kommentar:</label><input class="layout" type='text' id='currentComment' name='currentComment'/></p>
</fieldset>
<p><input type="submit" value="Alarmieren"></p>
</form>
</div>
<div id="EinstellungenD" class="tabcontent">
<form id="einstellungen" action="send" target="hidden">
<fieldset>
<legend>Einstellungen</legend>
<p><label class="field" for="currentLang">Sprache:</label>
<select class="layout" id="currentLang" name="currentLang" required>
<option value="de">Deutsch</option>
<option value="en">Englisch</option>
</select></p>
<p><label class="field" for="isDebug">Debug Modus:</label>
<input class="layout" type="checkbox" id="isDebug" name="isDebug"/></p>
<p><label class="field" for="isGiessen">Gießen Modus:</label>
<input class="layout" type="checkbox" id="isGiessen" name="isGiessen"/></p>
</fieldset>
<fieldset>
<legend>Display</legend>
<p><label class="field" for="isLandscape">Landscape:</label>
<input class="layout" type="checkbox" id="isLandscape" name="isLandscape" checked/></p>
<p><label class="field" for="showTime">Uhr anzeigen:</label>
<input class="layout" type="checkbox" id="showTime" name="showTime" checked/></p>
<p><label class="field" for="theme">Theme:</label>
<select class="layout" id="theme" name="theme" required>
<option value="color">Farbe</option>
<option value="blackwhite">Schwarz/Weiß</option>
</select></p>
<p><label class="field" id="brightnessLabel" for="toneAnalog">Helligkeit:</label>
<input class="layout" type="number" id="brightness" name="brightness" min="10" max="100" value="100"/></p>
</fieldset>
<fieldset>
<legend>Ton</legend>
<p><label class="field" for="isDigital">Digitaler Ton:</label>
<input class="layout" type="checkbox" id="isDigital" name="isDigital" checked/></p>
<p><label class="field" id="toneDigitalLabel" for="toneDigital">Digital Ton:</label>
<input class="layout" type="number" id="toneDigital" name="toneDigital" min="1" max="54" value="16"/></p>
<p><label class="field" id="toneAnalogLabel" for="toneAnalog">Analog Ton:</label>
<input class="layout" type="number" id="toneAnalog" name="toneAnalog" min="10000" max="99999" value="52112"/></p>
<input type="hidden" id="nodeId" name="nodeId" value="0"/>
</fieldset>
<p><input type="submit" value="Speichern"></p>
</form>
</div>
<div id="SonstigesD" class="tabcontent">
</div>
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
  server.begin();
}

void loop()
{
  mesh.update();

  if (myIP != getlocalIP())
  {
    myIP = getlocalIP();
    // Serial.println("My IP is " + myIP.toString());
  }
}