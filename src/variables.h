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