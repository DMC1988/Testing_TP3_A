#include "leds.h"

#define LEDS_ALL_LEDS_OFF 0X0000
#define LEDS_ALL_LEDS_ON 0XFFFF
#define LEDS_INDEX_OFFSET 1
#define LEDS_STATE_ON 1

static uint16_t* puerto;


static uint16_t LedsIndexToMask(int led){

    return (LEDS_STATE_ON << (led - LEDS_INDEX_OFFSET));

}


void LedsInit( uint16_t* direccion){
    
    puerto = direccion; 

    *direccion = LEDS_ALL_LEDS_OFF;

}


void LedsTurnOn(int led){

*puerto |= LedsIndexToMask(led);

}


void LedsTurnOff(int led){
    
    *puerto &= ~ LedsIndexToMask(led);

}


_Bool isLedOn(int led){
    
    if(*puerto && (1 < led)){
        
        return 1;

    }else{
        
        return 0;
    
    }

}


_Bool isLedOff(int led){
    
    return !isLedOn(led);

}


void AllLedsOn(uint16_t* direccion){

    puerto = direccion; 

    *direccion = LEDS_ALL_LEDS_ON;

}


void AllLedsOff(uint16_t* direccion){

    puerto = direccion; 

    *direccion = LEDS_ALL_LEDS_OFF;

}
