/*
Pruebas para testing para TP3

1) Determinar si un LED esta prendido. [X]
2) Determinar si un LED esta apadagado. [X]
3) Prendo todos los LEDs en una operacion. [X]
4) Apago todos los LEDs en una operacion. [X]
*/

#include "leds.h"
#include "unity.h" 

static uint16_t puerto;

void setUp(void){

    LedsInit(&puerto);

}

void tearDown(void){

}


void test_LedsOffAfterCreate(void){
    
    uint16_t puerto = 0xFFFF;   

    LedsInit(&puerto); 

    TEST_ASSERT_EQUAL_UINT16(0x0000, puerto);

}


void test_prender_un_LED(void){
    
    const int led = 2;
    
    LedsTurnOn(led);

    TEST_ASSERT_EQUAL_UINT16(1 <<(led -1), puerto);

}


void test_apagar_un_led(void){
    
    const int led = 2;

    LedsTurnOn(led);
   
    LedsTurnOff(led);
    
    TEST_ASSERT_EQUAL_UINT16(0x0000, puerto);

}


void test_prender_y_apagar_varios_leds(void) {
    const int led = 2;
  
    LedsTurnOn(led);
   
    TEST_ASSERT_EQUAL_UINT16( 1 << (led-1), puerto);

}

void test_led_prendido(void){
   
    _Bool ledState = 0;
    
    LedsTurnOn(5);
        
    ledState = isLedOn(5);

    TEST_ASSERT_EQUAL_UINT16( 1 , ledState);

}

void test_led_apagado(void){

    _Bool ledState = 0;
    
    LedsTurnOn(5);

    LedsTurnOff(5);
    
    ledState = isLedOff(5);

    TEST_ASSERT_EQUAL_UINT16( 1 , ledState);

}


void test_encender_puerto(void){

    AllLedsOn(&puerto);

    TEST_ASSERT_EQUAL_UINT16(0xFFFF, puerto);

}


void test_apagar_puerto(void){

    AllLedsOff(&puerto);

    TEST_ASSERT_EQUAL_UINT16(0x0000, puerto);

}
