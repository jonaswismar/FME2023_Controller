#include <Arduino.h>
#include <ArduinoJson.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <IPAddress.h>
#include <MFRC522.h>
#include <SPI.h>

#include "alarm\functions.h"
#include "filesystem\functions.h"
#include "html\functions.h"
#include "math\functions.h"
#include "mesh\functions.h"
#include "messages\functions.h"
#include "rfid\functions.h"

#include "variables.h"

#define RFID_RST_PIN 5
#define RFID_SS_PIN 53

MFRC522 mfrc522(RFID_SS_PIN, RFID_RST_PIN);

AsyncWebServer server(80);
IPAddress myIP(0, 0, 0, 0);
IPAddress myAPIP(0, 0, 0, 0);

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

void notFound(AsyncWebServerRequest *);


void setup();

void loop();