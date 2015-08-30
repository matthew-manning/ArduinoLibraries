/*
 *Matthew Manning 30-08-2015
 *
 *initDac() takes three pins to use for a 2R-R DAC, pin 0 is the one
 *connected to gnd through a 2R resistor.
 *updateDac() takes a new DAC level from 0-7 and sets the pins to create the desiried level;
 *it is NOT prtected against out of range level being used, which could cause crashes oe damaging/eratic effects.
 */

 #include "ThreeBitDAC.h"
 #include <Arduino.h>

 char DacZero, DacOne, DacTwo;//stores pin numbers of DAC pins

void initDac(int pin1, int pin2, int pin3)
{
    DacZero = pin1;
    DacOne = pin2;
    DacTwo = pin3;
    pinMode(pin1,OUTPUT);
    pinMode(pin2,OUTPUT);
    pinMode(pin3,OUTPUT);
}


void updateDac(int level)
{
    digitalWrite(DacZero, bitRead(level, 0));
    digitalWrite(DacOne, bitRead(level, 1));
    digitalWrite(DacTwo, bitRead(level, 2));
}
