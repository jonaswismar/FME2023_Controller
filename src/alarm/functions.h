#include <Arduino.h>

#include "filesystem\functions.h"

#include "variables.h"

String getAlarmPLZText(unsigned int);
String getAlarmCityText(unsigned int);
String getAlarmStreetText(unsigned int);
String getAlarmSubText(unsigned int);
String getAlarmTypeText(unsigned int);
String getAlarmCategoryText(unsigned int);
int getAlarmCategory(unsigned int);
String getCombinedAdress(int, int, int, int, String);
void resetAlarm();
void saveAlarm(int, int, int, int, int, int, String, String, String, String);
void cleanCurrentAlarm();