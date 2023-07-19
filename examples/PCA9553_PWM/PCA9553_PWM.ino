//
//    FILE: PCA9553_PWM.ino
//  AUTHOR: Rob Tillaart
//    DATE: 2023-07-18
// PURPOSE: test PCA9553 library
//     URL: https://github.com/RobTillaart/PCA9553
//
//  Connect LEDs from pin 0 and pin 1 with a resistor to 5V
//  See datasheet


#include "Arduino.h"
#include "Wire.h"
#include "PCA9553.h"


PCA9553 leds(0x62);


void setup()
{
  Serial.begin(115200);
  Serial.print("PCA9553_LIB_VERSION: ");
  Serial.println(PCA9553_LIB_VERSION);
  Serial.println();

  if (leds.begin() == false)
  {
    Serial.println("Could not connect.");
    while(1);
  }

  //  not mandatory, just to make it explicit
  leds.pinMode(0, OUTPUT);
  leds.pinMode(1, OUTPUT);

  leds.setLEDSource(0, 2);
  leds.setLEDSource(1, 3);

  leds.setPrescaler(0, 43);  //  1 Hz
  leds.setPWM(0, 128);       //  50% duty cycle
  leds.setPrescaler(1, 21);  //  2 Hz
  leds.setPWM(1, 32);        //  12% duty cycle
}


void loop()
{
}


//  -- END OF FILE --
