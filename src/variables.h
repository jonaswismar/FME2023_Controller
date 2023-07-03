#include <Arduino.h>
#include <AxisJoystick.h>
#include <Joystick.h>
#include <painlessMesh.h>

extern boolean spiffs_active;
extern boolean littlefs_active;

extern String rfid_lastUID;

extern unsigned int save_type;
extern unsigned int save_sub;
extern unsigned int save_plz;
extern unsigned int save_city;
extern unsigned int save_street;
extern unsigned int save_number;
extern String save_addition;
extern String save_adress;
extern String save_comment;
extern String save_nodeIdString;

/*
 * Derzeitiger laufender Alarm
 */
extern unsigned int alarm_plz;
extern unsigned int alarm_city;
extern unsigned int alarm_street;
extern unsigned int alarm_number;
extern String alarm_addition;
extern int alarm_current_id;

/*
 *Globale Variablen für WLAN
 */
extern String wlan_ssid;
extern String wlan_password;
extern unsigned int wlan_port;
extern String wlan_hostname;

/*
 *Globale Variablen für Mesh
 */
extern String mesh_prefix;
extern String mesh_password;
extern unsigned int mesh_port;
extern unsigned int mesh_channel;
extern boolean mesh_containsRoot;
extern boolean mesh_isRoot;

/*
 *Globale Variablen für Zeit
 */
extern unsigned int wake_hour;
extern unsigned int wake_minute;

/*
 * Globale Variablen für Konfiguration
 */
// Sprache
extern String i18n;
// Sound
extern boolean menu_sound_active;
extern unsigned int sound_digital;
extern unsigned int sound_analog;
extern boolean sound_isDigital;
// Display
extern boolean display_time;
extern boolean display_landscape;
extern String display_theme;
extern unsigned int display_level;
// Debug
extern boolean debug_mode;
// Special Modes
extern boolean giessen_mode;
extern boolean closed_mode;
// Standort
extern unsigned int cityId;

/*
 * Globale Variablen für Alarm
 */
extern unsigned long time_page_1;
extern unsigned long time_page_2;
extern unsigned long time_page_3;