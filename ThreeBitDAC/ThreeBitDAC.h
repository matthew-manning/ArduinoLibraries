/*
 *Matthew Manning 30-08-2015
 *
 *initDac() takes three pins to use for a 2R-R DAC, pin 0 is the one
 *connected to gnd through a 2R resistor.
 *updateDac() takes a new DAC level from 0-7 and sets the pins to create the desiried level;
 *it is NOT prtected against out of range level being used, which could cause crashes oe damaging/eratic effects.
 */

#ifndef __THREEBITDAC_H__
#define __THREEBITDAC_H__

#ifdef __cplusplus
extern "C" {
#endif

void initDac(int pin1, int pin2, int pin3);
void updateDac(int level);
#ifdef __cplusplus
}
#endif

#endif

