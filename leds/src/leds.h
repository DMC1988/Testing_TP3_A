#ifndef _LEDS_H_
#define _LEDS_H_

#include <stdint.h>

void LedsInit( uint16_t* puerto);

void LedsTurnOn(int led);

void LedsTurnOff(int led);

_Bool isLedOn(int led);

_Bool isLedOff(int led);

void AllLedsOn(uint16_t* puerto);

void AllLedsOff(uint16_t* puerto);

#endif