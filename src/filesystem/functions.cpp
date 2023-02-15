#include <Arduino.h>
#include <ArduinoJson.h>
#include <FFat.h>
#include <FS.h>
#include <LittleFS.h>
#include <JPEGDecoder.h>
#include <SPIFFS.h>
#include <TFT_eSPI.h>

#include "math\functions.h"

#include "variables.h"

#define FS_NO_GLOBALS
#define FORMAT_FFAT false
#define FORMAT_SPIFFS_IF_FAILED false

String isType()
{
  if (spiffs_active == true)
  {
    return "SPIFFS";
  }
  else if (littlefs_active == true)
  {
    return "SPIFFS";
  }
  else
  {
    return "FAT";
  }
}

int totalBytes()
{
  if (spiffs_active == true)
  {
    return SPIFFS.totalBytes();
  }
  else if (littlefs_active == true)
  {
    return LittleFS.totalBytes();
  }
  else
  {
    FFat.totalBytes();
  }
}

int usedBytes()
{
  if (spiffs_active == true)
  {
    return SPIFFS.usedBytes();
  }
  else
  {
    FFat.usedBytes();
  }
}

void initFileSystem()
{
  if (spiffs_active == true)
  {
    if (!SPIFFS.begin())
    {
    }
  }
  else if (littlefs_active == true)
  {
    if (!LittleFS.begin())
    {
    }
  }
  else
  {
    if (!FFat.begin())
    {
    }
  }
}

uint16_t read16(fs::File &f)
{
  uint16_t result;
  ((uint8_t *)&result)[0] = f.read(); // LSB
  ((uint8_t *)&result)[1] = f.read(); // MSB
  return result;
}

uint32_t read32(fs::File &f)
{
  uint32_t result;
  ((uint8_t *)&result)[0] = f.read(); // LSB
  ((uint8_t *)&result)[1] = f.read();
  ((uint8_t *)&result)[2] = f.read();
  ((uint8_t *)&result)[3] = f.read(); // MSB
  return result;
}

void appendFile(const char *path, const char *message)
{
  fs::File file;
  if (spiffs_active == true)
  {
    file = SPIFFS.open(path, FILE_APPEND);
  }
  else if (littlefs_active == true)
  {
    file = LittleFS.open(path, FILE_APPEND);
  }
  else
  {
    file = FFat.open(path, FILE_APPEND);
  }
  if (!file)
  {
    return;
  }
  if (file.print(message))
  {
  }
  else
  {
  }
  file.close();
}

void deleteFile(const char *path)
{
  if (spiffs_active == true)
  {
    SPIFFS.remove(path);
  }
  else if (littlefs_active == true)
  {
    LittleFS.remove(path);
  }
  else
  {
    FFat.remove(path);
  }
}

boolean existsFile(const char *path)
{
  fs::File file;
  if (spiffs_active == true)
  {
    file = SPIFFS.open(path, FILE_READ);
  }
  else if (littlefs_active == true)
  {
    file = LittleFS.open(path, FILE_READ);
  }
  else
  {
    file = FFat.open(path, FILE_READ);
  }
  if (!file || file.isDirectory())
  {
    file.close();
    return false;
  }
  file.close();
  return true;
}

void renameFile(const char *path1, const char *path2)
{
  if (spiffs_active == true)
  {
    SPIFFS.rename(path1, path2);
  }
  else if (littlefs_active == true)
  {
    LittleFS.rename(path1, path2);
  }
  else
  {
    FFat.rename(path1, path2);
  }
}

void writeFile(const char *path, const char *message)
{
  fs::File file;
  if (spiffs_active == true)
  {
    file = SPIFFS.open(path, FILE_WRITE);
  }
  else if (littlefs_active == true)
  {
    file = LittleFS.open(path, FILE_WRITE);
  }
  else
  {
    file = FFat.open(path, FILE_WRITE);
  }
  if (!file)
  {
    return;
  }
  if (file.print(message))
  {
  }
  else
  {
  }
  file.close();
}

void writeAlarm()
{
  fs::File settingsFS;
  if (spiffs_active == true)
  {
    settingsFS = SPIFFS.open("/" + rfid_lastUID + ".json", FILE_WRITE);
  }
  else if (littlefs_active == true)
  {
    settingsFS = LittleFS.open("/" + rfid_lastUID + ".json", FILE_WRITE);
  }
  else
  {
    settingsFS = FFat.open("/" + rfid_lastUID + ".json", FILE_WRITE);
  }
  if (!settingsFS)
  {
    return;
  }
  StaticJsonDocument<768> settingsDoc;
  settingsDoc["type"] = save_type;
  settingsDoc["sub"] = save_sub;
  settingsDoc["plz"] = save_plz;
  settingsDoc["city"] = save_city;
  settingsDoc["street"] = save_street;
  settingsDoc["number"] = save_number;
  settingsDoc["addition"] = save_addition;
  settingsDoc["adress"] = save_adress;
  settingsDoc["comment"] = save_comment;
  settingsDoc["nodeIdString"] = save_nodeIdString;
  serializeJson(settingsDoc, settingsFS);
  settingsFS.close();
}

void readAlarm()
{
  fs::File settingsFS;
  if (spiffs_active == true)
  {
    settingsFS = SPIFFS.open("/" + rfid_lastUID + ".json", FILE_READ);
  }
  else if (littlefs_active == true)
  {
    settingsFS = LittleFS.open("/" + rfid_lastUID + ".json", FILE_READ);
  }
  else
  {
    settingsFS = FFat.open("/" + rfid_lastUID + ".json", FILE_READ);
  }
  if (!settingsFS)
  {
    return;
  }
  StaticJsonDocument<768> settingsDoc;

  DeserializationError error = deserializeJson(settingsDoc, settingsFS);

  if (error)
  {
    return;
  }
  save_type = settingsDoc["type"];
  save_sub = settingsDoc["sub"];
  save_plz = settingsDoc["plz"];
  save_city = settingsDoc["city"];
  save_street = settingsDoc["street"];
  save_number = settingsDoc["number"];

  String helper1 = settingsDoc["addition"];
  save_addition = helper1;
  String helper2 = settingsDoc["adress"];
  save_adress = helper2;
  String helper3 = settingsDoc["comment"];
  save_comment = helper3;
  String helper4 = settingsDoc["nodeIdString"];
  save_nodeIdString = helper4;

  settingsFS.close();
}

boolean pushJPEGFromFS(const char *filename, int16_t xpos, int16_t ypos, TFT_eSPI &tft)
{
  fs::File jpegFS;
  if (spiffs_active == true)
  {
    jpegFS = SPIFFS.open(filename, FILE_READ);
  }
  else if (littlefs_active == true)
  {
    jpegFS = LittleFS.open(filename, FILE_READ);
  }
  else
  {
    jpegFS = FFat.open(filename, FILE_READ);
  }
  if (!jpegFS)
  {
    return false;
  }

  boolean decoded = JpegDec.decodeFsFile(filename);

  if (decoded)
  {

    bool oldSwapBytes = tft.getSwapBytes();
    tft.setSwapBytes(false);
    // retrieve information about the image
    uint16_t *pImg;
    int16_t mcu_w = JpegDec.MCUWidth;
    int16_t mcu_h = JpegDec.MCUHeight;
    int32_t max_x = JpegDec.width;
    int32_t max_y = JpegDec.height;

    // Jpeg images are draw as a set of image block (tiles) called Minimum Coding Units (MCUs)
    // Typically these MCUs are 16x16 pixel blocks
    // Determine the width and height of the right and bottom edge image blocks
    int32_t min_w = minimum(mcu_w, max_x % mcu_w);
    int32_t min_h = minimum(mcu_h, max_y % mcu_h);

    // save the current image block size
    int32_t win_w = mcu_w;
    int32_t win_h = mcu_h;

    // save the coordinate of the right and bottom edges to assist image cropping
    // to the screen size
    max_x += xpos;
    max_y += ypos;

    // read each MCU block until there are no more
    while (JpegDec.readSwappedBytes())
    { // Swapped byte order read

      // save a pointer to the image block
      pImg = JpegDec.pImage;

      // calculate where the image block should be drawn on the screen
      int mcu_x = JpegDec.MCUx * mcu_w + xpos; // Calculate coordinates of top left corner of current MCU
      int mcu_y = JpegDec.MCUy * mcu_h + ypos;

      // check if the image block size needs to be changed for the right edge
      if (mcu_x + mcu_w <= max_x)
        win_w = mcu_w;
      else
        win_w = min_w;

      // check if the image block size needs to be changed for the bottom edge
      if (mcu_y + mcu_h <= max_y)
        win_h = mcu_h;
      else
        win_h = min_h;

      // copy pixels into a contiguous block
      if (win_w != mcu_w)
      {
        for (int h = 1; h < win_h - 1; h++)
        {
          memcpy(pImg + h * win_w, pImg + (h + 1) * mcu_w, win_w << 1);
        }
      }

      for (int i = 0; i < win_w * win_h; i++)
      {
      }

      // draw image MCU block only if it will fit on the screen
      if (mcu_x < tft.width() && mcu_y < tft.height())
      {
        // Now push the image block to the screen
        tft.pushImage(mcu_x, mcu_y, win_w, win_h, pImg);
      }
      else if ((mcu_y + win_h) >= tft.height())
      {
        JpegDec.abort();
      }
    }
    tft.setSwapBytes(oldSwapBytes);
  }
  return true;
}

boolean pushBMPFromFS(const char *filename, int16_t x, int16_t y, TFT_eSPI &tft)
{
  fs::File bmpFS;
  if (spiffs_active == true)
  {
    bmpFS = SPIFFS.open(filename, FILE_READ);
  }
  else if (littlefs_active == true)
  {
    bmpFS = LittleFS.open(filename, FILE_READ);
  }
  else
  {
    bmpFS = FFat.open(filename, FILE_READ);
  }
  if (!bmpFS)
  {
    return false;
  }

  uint32_t seekOffset;
  uint16_t w, h, row, col;
  uint8_t r, g, b;

  uint32_t startTime = millis();

  if (read16(bmpFS) == 0x4D42)
  {
    read32(bmpFS);
    read32(bmpFS);
    seekOffset = read32(bmpFS);
    read32(bmpFS);
    w = read32(bmpFS);
    h = read32(bmpFS);

    if ((read16(bmpFS) == 1) && (read16(bmpFS) == 24) && (read32(bmpFS) == 0))
    {
      y += h - 1;

      bool oldSwapBytes = tft.getSwapBytes();
      tft.setSwapBytes(true);
      bmpFS.seek(seekOffset);

      uint16_t padding = (4 - ((w * 3) & 3)) & 3;
      uint8_t lineBuffer[w * 3 + padding];

      for (row = 0; row < h; row++)
      {
        bmpFS.read(lineBuffer, sizeof(lineBuffer));
        uint8_t *bptr = lineBuffer;
        uint16_t *tptr = (uint16_t *)lineBuffer;
        // Convert 24 to 16 bit colours
        for (uint16_t col = 0; col < w; col++)
        {
          b = *bptr++;
          g = *bptr++;
          r = *bptr++;
          *tptr++ = ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3);
        }
        // Push the pixel row to screen, pushImage will crop the line if needed
        // y is decremented as the BMP image is drawn bottom up
        tft.pushImage(x, y--, w, 1, (uint16_t *)lineBuffer);
      }
      tft.setSwapBytes(oldSwapBytes);
    }
  }
  bmpFS.close();
  return false;
}

void pushImageFromFS(const char *filename, int16_t x, int16_t y, TFT_eSPI &tft)
{
  if (pushJPEGFromFS(filename, x, y, tft) == false)
  {
    pushBMPFromFS(filename, x, y, tft);
  }
}