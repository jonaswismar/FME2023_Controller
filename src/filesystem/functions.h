#include <Arduino.h>
#include <ArduinoJson.h>
#include <FFat.h>
#include <FS.h>
#include <LITTLEFS.h>
#include <JPEGDecoder.h>
#include <SPIFFS.h>
#include <TFT_eSPI.h>

#include "math\functions.h"

#include "variables.h"

String isType();

int totalBytes();

int usedBytes();

void initFileSystem();

uint16_t read16(fs::File &);

uint32_t read32(fs::File &);

void appendFile(const char *, const char *);

void deleteFile(const char *);

boolean existsFile(const char *);
void readAlarm();
void writeAlarm();

void renameFile(const char *, const char *);

void writeFile(const char *, const char *);

boolean pushJPEGFromFS(const char *, int16_t, int16_t, TFT_eSPI &);

boolean pushBMPFromFS(const char *, int16_t, int16_t, TFT_eSPI &);

void pushImageFromFS(const char *, int16_t, int16_t, TFT_eSPI &);