
[![Arduino CI](https://github.com/RobTillaart/markDownWriter/workflows/Arduino%20CI/badge.svg)](https://github.com/marketplace/actions/arduino_ci)
[![Arduino-lint](https://github.com/RobTillaart/markDownWriter/actions/workflows/arduino-lint.yml/badge.svg)](https://github.com/RobTillaart/markDownWriter/actions/workflows/arduino-lint.yml)
[![JSON check](https://github.com/RobTillaart/markDownWriter/actions/workflows/jsoncheck.yml/badge.svg)](https://github.com/RobTillaart/markDownWriter/actions/workflows/jsoncheck.yml)
[![GitHub issues](https://img.shields.io/github/issues/RobTillaart/markDownWriter.svg)](https://github.com/RobTillaart/markDownWriter/issues)

[![License: MIT](https://img.shields.io/badge/license-MIT-green.svg)](https://github.com/RobTillaart/markDownWriter/blob/master/LICENSE)
[![GitHub release](https://img.shields.io/github/release/RobTillaart/markDownWriter.svg?maxAge=3600)](https://github.com/RobTillaart/markDownWriter/releases)
[![PlatformIO Registry](https://badges.registry.platformio.org/packages/robtillaart/library/markDownWriter.svg)](https://registry.platformio.org/libraries/robtillaart/markDownWriter)


# markDownWriter

Arduino library for creating simple mark down content.


## Description

**Experimental, Work In Progress**

This library is written to be able to generate simple mark down reports.

The library supports only a part of the mark down functionality, including headers on several levels, bold and italic styles, the creation of tables 
and external links. 

The markDOwnWriter prints to a stream, default **Serial**, bit other streams
like **file**, **SD**, **socket** are possible (not tested yet).

The library is work in progress and not all functionality works perfect,
but is good enough to get started for now.

Core reason to write this library was to speed up creation of tables
with measurements.

If needed, additional functionality or improvements will be made on request.

As always feedback is welcome.


### Print interface

The markDownWriter implements the print interface allowing
to print all data types in theory. 
However the current table interface (0.1.0) does only support floats, 
default with 2 decimals. This has priority to improve.

See future section.


### Related

- https://www.markdownguide.org/basic-syntax/ reference
- https://github.com/RobTillaart/XMLWriter just a format writer.


### Tested

Tested on Arduino UNO R3, OK only one simple demo sketch.


## Interface

```cpp
#include "markDownWriter.h"
```

### Constructor

- **markDownWriter(Print \* stream = &Serial)** constructor with 
default stream. Other streams e.g. SD
- **bool reset()** reset internals.


### Headers

- **void header(uint8_t level, const char \* text);)** header at level n.
- **void title(const char \* str)** wrapper for header level 1.
- **void chapter(const char \* str)** wrapper for header level 2.
- **void section(const char \* str)** wrapper for header level 3.
- **void subSection(const char \* str)** wrapper for header level 4.


### Style

These functions work, but not perfect.
The ...off() functions add a space after the markup.
These functions do not mix well so use carefully

- **void boldOn()** idem.
- **void boldOff()** idem.
- **void italicOn()** idem.
- **void italicOFF()** idem.
- **void boldItalicOn()** idem.
- **void boldItalicOff()** idem.
- **void line()** draw a line in the report. (splitter).


### Tables

Initial the tables are simple, with headers of max 11 characters.
The align array consist of L=Left, C=Centre, R=Right alignment.
The align array should at least have size elements and is case insensitive.
invalid chars for align are centred (default).

- **void tableHeader(uint8_t size, char headers[][12], char \* align = "CCCCCCCCCC")**
- **void tableValues(float values[])** values must be at least contain **size** elements as defined in **tableHeader()**. 

Tables need improvement.


### Links

- **void URL(const char \* text, const char \* link)** idem.
- **void link(const char \* link)** idem.


## Future

#### Must

- improve documentation
- improve other data types in tables
  - e.g. set number of decimals for all columns?
  - write per column (?)
  - don't make it to configurable (!)

#### Should

- add examples (see XML writer)
  - other streams like SD card or HTTP sockets
  - performance
- investigate internal buffering.
- escaping characters in text fields e.g. \* ?

#### Could

- extend functionality (on request)
  - BulletListOn  (unordered list)
  - BulletListOff
  - NumberListOn  (ordered lists) - nesting ?
  - NumberListOff
  - Image(text, link)  ![Tux, the Linux mascot](/assets/images/tux.png)
  - blockQuote - nesting ?
  - code block and style.


#### Wont


## Support

If you appreciate my libraries, you can support the development and maintenance.
Improve the quality of the libraries by providing issues and Pull Requests, or
donate through PayPal or GitHub sponsors.

Thank you,


