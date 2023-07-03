#include <Arduino.h>
#include <ArduinoJson.h>
#include <AsyncTCP.h>
#include <ESP32Time.h>
#include <MFRC522.h>
#include <time.h>

#include "math\functions.h"
#include "mesh\functions.h"
#include "server\functions.h"

#include "variables.h"

#define RFID_RST_PIN 3
#define RFID_SS_PIN 10

MFRC522 mfrc522(RFID_SS_PIN, RFID_RST_PIN);

IPAddress myIP(0, 0, 0, 0);
IPAddress myAPIP(0, 0, 0, 0);

typedef struct
{
  unsigned int id;
  unsigned int deviceType;
  boolean status;
  unsigned int batt;
} MeshDevice;

/*
 *Einstellungen Controller
 */
boolean spiffs_active = true;
boolean littlefs_active = false;

/*
 * Einstellungen für Melder
 */
boolean sound_isDigital = true;
unsigned int sound_analog = 52112;
unsigned int sound_digital = 16;
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

void setup()
{
  Serial.begin(115200);

  SPI.begin();
  mfrc522.PCD_Init();

  initMesh();
  myAPIP = getMeshAPIP();
  // Serial.println("My AP IP is " + myAPIP.toString());

  initServer();

  struct tm timeinfo;
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  if (getLocalTime(&timeinfo))
  {
    rtc.setTimeStruct(timeinfo);
  }
}

void loop()
{
  updateMesh();

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
  if (myIP != getMeshStationIP())
  {
    myIP = getMeshStationIP();
  }
}