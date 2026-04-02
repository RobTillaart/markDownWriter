
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

Not all functionality is perfect but good enough for now.

If needed, improvements will be made.

As always feedback is welcome.


### Print interface

The markDownWriter implements the print interface allowing
to print all data types in theory. However the table interface
does only support floats, default with 2 decimals.

See future section.


### Related

- https://www.markdownguide.org/basic-syntax/
- https://github.com/RobTillaart/XMLWriter ?

[![XML](https://github.com/RobTillaart/XMLWriter)


### Tested

Tested on Arduino UNO R3.



## Interface

```cpp
#include "markDownWriter.h"
```

### Constructor

- **markDownWriter(Print \* stream = &Serial, uint8_t bufferSize = 10)** constructor.
Default Serial and buffer size of 10.
- **bool reset()** reset internal buffer administration.


### Headers

- **void header(uint8_t level, const char \* text);)** header at level n.
- **void title(const char \* str)** wrapper for header level 1.
- **void chapter(const char \* str)** wrapper for header level 2.
- **void section(const char \* str)** wrapper for header level 3.
- **void subSection(const char \* str)** wrapper for header level 4.


### Style

These functions work, but not perfect.
The ...off() functions adds a space after the markup.
These functions do not mix

- **void boldOn()** idem.
- **void boldOff()** idem.
- **void italicOn()** idem.
- **void italicOFF()** idem.
- **void boldItalicOn()** idem.
- **void boldItalicOff()** idem.


### Tables

- **void tableHeader(uint8_t size, char headers[][12], char \* align = "CCCCCCCCCC")**
- **void tableValues(float values[])**


### Links


### Miscellaneous

- **void line()**


## Future

#### Must

- improve documentation
- improve other data types in tables
  - e.g. set nr decimals for all columns?
  - don't make it to configurable.

#### Should

#### Could

- extend functionality (not needed yet)
  - BulletListOn  (unordered list)
  - BulletListOff
  - NumberListOn  (ordered lists) - nesting ?
  - NumberListOff
  - Image(text, link)  ![Tux, the Linux mascot](/assets/images/tux.png)
  - blockQuote - nesting ?
  - code block


#### Wont


## Support

If you appreciate my libraries, you can support the development and maintenance.
Improve the quality of the libraries by providing issues and Pull Requests, or
donate through PayPal or GitHub sponsors.

Thank you,


