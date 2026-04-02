//
//    FILE: markDownWriter.cpp
//  AUTHOR: Rob Tillaart
//    DATE: 2026-04-02
// VERSION: 0.1.0
// PURPOSE: Arduino library for creating simple mark down content.
//     URL: https://github.com/RobTillaart/markDownWriter



#include "markDownWriter.h"


markDownWriter::markDownWriter(Print* stream)
{
  _stream = stream;
  reset();
}

void markDownWriter::reset()
{
  _bytesOut    = 0;
}


////////////////////////////////////////////////////////////////////
//
// HEADERS
//
void markDownWriter::header(uint8_t level, const char * text)
{
  _stream->println();
  for (int i = 0; i < level; i++) _stream->print('#');
  _stream->print(' ');
  _stream->println(text);
  _stream->println();
}


////////////////////////////////////////////////////////////////////
//
// TABLES
//
void markDownWriter::tableHeader(uint8_t size, const char headers[][12], const char * align)
{
  _tableSize = size;
  //  headers
  _stream->println();
  for (int i = 0; i < _tableSize; i++)
  {
    _stream->print("| ");
    _stream->print(headers[i]);
  }
  _stream->println(" |");
  // alignments
  for (int i = 0; i < _tableSize; i++)
  {
    if (align[i] == 'L') _stream->print("|:-------");
    if (align[i] == 'C') _stream->print("|:------:");
    if (align[i] == 'R') _stream->print("|-------:");
  }
  _stream->println("|");
}

void markDownWriter::tableValues(float values[])
{
  _stream->print("| ");
  for (int i = 0; i < _tableSize; i++)
  {
    _stream->print(values[i]);
    _stream->print(" | ");
  }
  _stream->println();
}


////////////////////////////////////////////////////////////////////
//
//  LINKS
//
void markDownWriter::URL(const char * text, const char * link)
{
  _stream->print("[");
  _stream->print(text);
  _stream->print("](");
  _stream->print(link);
  _stream->print(")");
}

void markDownWriter::link(const char * link)
{
  _stream->print("<");
  _stream->print(link);
  _stream->print(">");
}


///////////////////////////////////////////////
//
//  PRIVATE
//
size_t markDownWriter::write(uint8_t c)
{
  //  no buffering
  return _stream->write(c);
}


//  -- END OF FILE --

