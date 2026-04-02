#pragma once
//
//    FILE: markDownWriter.h
//  AUTHOR: Rob Tillaart
//    DATE: 2026-04-02
// VERSION: 0.1.0
// PURPOSE: Arduino library for creating simple mark down content.
//     URL: https://github.com/RobTillaart/markDownWriter


#include "Arduino.h"

#define MARKDOWNWRITER_LIB_VERSION         (F("0.1.0"))


class markDownWriter : public Print
{
public:
  markDownWriter(Print* stream = &Serial);

  void reset();

  //  HEADERS
  void header(uint8_t level, const char * text);
  void title(const char * text)      { header(1, text); };
  void chapter(const char * text)    { header(2, text); };
  void section(const char * text)    { header(2, text); };
  void subSection(const char * text) { header(3, text); };

  //  STYLE
  void boldOn()         { print("**"); };
  void boldOff()        { print("** "); };
  void italicOn()       { print("*"); };
  void italicOff()      { print("* "); };
  void boldItalicOn()   { print("***"); };
  void boldItalicOff()  { print("*** "); };

  void line()           { print("\n\n----\n\n"); };

  //  TABLES
  void tableHeader(uint8_t size, const char headers[][12], const char * align = "CCCCCCCCCC");
  void tableValues(float values[]);

  //  LINKS
  void URL(const char * text, const char * link);
  void link(const char * link);

/* TODO

BulletListOn
BulletListOff
NumberListOn
NumberListOff
Image(uint16_t width, uint16_t height, const char * altText, const char * link)
<img width="391" height="91" alt="image" src="https://github.com/user-attachments/assets/4bbb3c68-ae22-4136-ac89-f76f14d1ee6f" />

*/

//  debug
//  return _bytesOut;

private:
  //  output stream, Print Class
  Print*   _stream;
  size_t   write(uint8_t c);

  //  output admin
  uint32_t _bytesOut;
  uint8_t  _tableSize = 0;
};


//  -- END OF FILE --





