
[![Arduino CI](https://github.com/RobTillaart/PCA9553/workflows/Arduino%20CI/badge.svg)](https://github.com/marketplace/actions/arduino_ci)
[![Arduino-lint](https://github.com/RobTillaart/PCA9553/actions/workflows/arduino-lint.yml/badge.svg)](https://github.com/RobTillaart/PCA9553/actions/workflows/arduino-lint.yml)
[![JSON check](https://github.com/RobTillaart/PCA9553/actions/workflows/jsoncheck.yml/badge.svg)](https://github.com/RobTillaart/PCA9553/actions/workflows/jsoncheck.yml)
[![License: MIT](https://img.shields.io/badge/license-MIT-green.svg)](https://github.com/RobTillaart/PCA9553/blob/master/LICENSE)
[![GitHub release](https://img.shields.io/github/release/RobTillaart/PCA9553.svg?maxAge=3600)](https://github.com/RobTillaart/PCA9553/releases)


# PCA9553

Arduino library for PCA9553 I2C 8 bit PWM LED driver, 4 channel.


## Description

This library is to control the I2C PCA9553 PWM extender.
This device has two possible I2C addresses 0x62 and 0x63.
If you want to connect more device to a single I2C bus you 
need a I2C multiplexer like https://github.com/RobTillaart/TCA9548.

There are two PWM generators 0 and 1, and one can set the duty cycle
and the frequency by means of a prescaler. 

Every output channel can select to which PWM generator it is connected,
or if it is set to ON or OFF.


#### Related

- https://github.com/RobTillaart/PCA9634 (8 channel)
- https://github.com/RobTillaart/PCA9553 (16 channel)
- https://github.com/RobTillaart/PCA9685_RT (16 channel)
- https://github.com/RobTillaart/PCA9553  (4 channel)


## Interface

```cpp
#include "PCA9553.h"
```


#### Constructor

- **PCA9553(uint8_t deviceAddress, TwoWire \*wire = &Wire)** Constructor with I2C device address,  Address = 0x62 or 0x63.
and optional the Wire interface as parameter.
- **bool begin()** initializes the library after startup.
Returns true if device address is available on I2C bus.
- **bool begin(int sda, int scl)**
idem, ESP32 ESP8266 only.
- **bool isConnected()** checks if address is available on I2C bus.
- **uint8_t channelCount()** returns the number of channels = 4.


#### Input

- **getInput()** read current output levels.


#### Prescalers

- **void setPrescaler0(uint8_t psc = 255)** set prescaler 0, default 255.
- **uint8_t getPrescaler0()** get set value.
- **void setPrescaler1(uint8_t psc = 255)** set prescaler 1, default 255.
- **uint8_t getPrescaler1()** get set value.


#### PWM

- **void setPWM0(uint8_t pwm = 128)** set PWM0, default 128 == 50%.
- **uint8_t getPWM0()** return set PWM.
- **void setPWM1(uint8_t pwm = 128)** set PWM0, default 128 == 50%.
- **uint8_t getPWM1()** return set PWM.


#### ED source selector

- **bool  setLEDSource(uint8_t led, uint8_t source)** set the source of the selected led.
  - led == 0..3, source == 0..3, see table below
- **uint8_t  getLEDSource(uint8_t led)** returns current setting,
see table below.


|  source  |  output              |
|:--------:|:---------------------|
|  00      |  is set LOW (LED on)
|  01      |  is set high-impedance (LED off; default)
|  10      |  blinks at PWM0 rate
|  11      |  blinks at PWM1 rate


#### Error codes

to be elaborated.


|  Error code             |  Value  |  Description           |
|:------------------------|:-------:|:-----------------------|
|  PCA9553_OK             |   0x00  |  Everything went well
|  PCA9553_ERROR          |   0xFF  |  Generic error
|  PCA9553_I2C_ERROR      |   0xFE  |
|  PCA9553_CHANNEL_ERROR  |   0xFD  |
|  PCA9553_SOURCE_ERROR   |   0xFC  |


## Future

#### Must

- improve documentation
- test test test


#### Should

- **reset()**
- GPIO modi pins
  - **pinMode()**
  - **digitalWrite()**
  - **digitalRead()**
- improve error handling
  - return values, where etc.
- **setLEDSource(src0, src1, src2, src3)** one call


#### Could

- default setup in begin (what how)
- alternative interface calls
  - **setPWM(pwm0, pwm1)** one call
  - **setPrescaler(psc0, psc1)** one call
  - **configure(channel, psc0, pwm)**
  - **setPWM(channel, pwm);
  - **setPrescaler(channel, psc1)**
- percent interface for PWM
- time interface for prescaler
- unit tests

#### Wont

- no usage of autoincrement register

