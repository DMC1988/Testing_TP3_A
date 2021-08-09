#include "/var/lib/gems/2.5.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"
#include "src/leds.h"


static uint16_t puerto;



void setUp(void){



    LedsInit(&puerto);



}



void tearDown(void){



}





void test_LedsOffAfterCreate(void){

    uint16_t puerto = 0xFFFF;



    LedsInit(&puerto);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0x0000)), (UNITY_INT)(UNITY_UINT16)((puerto)), (

   ((void *)0)

   ), (UNITY_UINT)(43), UNITY_DISPLAY_STYLE_UINT16);

}





void test_prender_un_LED(void){

    const int led = 2;









    LedsTurnOn(led);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((1 <<(led -1))), (UNITY_INT)(UNITY_UINT16)((puerto)), (

   ((void *)0)

   ), (UNITY_UINT)(55), UNITY_DISPLAY_STYLE_UINT16);

}





void test_apagar_un_led(void){

    const int led = 2;









    LedsTurnOn(led);

    LedsTurnOff(led);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0x0000)), (UNITY_INT)(UNITY_UINT16)((puerto)), (

   ((void *)0)

   ), (UNITY_UINT)(68), UNITY_DISPLAY_STYLE_UINT16);

}





void test_prender_y_apagar_varios_leds(void) {

    const int led = 2;

    LedsTurnOn(led);

    LedsTurnOn(5);

    LedsTurnOff(5);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((1 << (led-1))), (UNITY_INT)(UNITY_UINT16)((puerto)), (

   ((void *)0)

   ), (UNITY_UINT)(78), UNITY_DISPLAY_STYLE_UINT16);

}



void test_led_prendido(void){

    _Bool ledState = 0;



    LedsTurnOn(5);



    ledState = isLedOn(5);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((1)), (UNITY_INT)(UNITY_UINT16)((ledState)), (

   ((void *)0)

   ), (UNITY_UINT)(88), UNITY_DISPLAY_STYLE_UINT16);

}



void test_led_apagado(void){

    _Bool ledState = 0;



    LedsTurnOn(5);

    LedsTurnOff(5);



    ledState = isLedOff(5);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((1)), (UNITY_INT)(UNITY_UINT16)((ledState)), (

   ((void *)0)

   ), (UNITY_UINT)(99), UNITY_DISPLAY_STYLE_UINT16);

}



void test_encender_puerto(void){

    AllLedsOn(&puerto);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0x0000)), (UNITY_INT)(UNITY_UINT16)((puerto)), (

   ((void *)0)

   ), (UNITY_UINT)(105), UNITY_DISPLAY_STYLE_UINT16);

}



void test_apagar_puerto(void){

    AllLedsOff(&puerto);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0x0000)), (UNITY_INT)(UNITY_UINT16)((puerto)), (

   ((void *)0)

   ), (UNITY_UINT)(111), UNITY_DISPLAY_STYLE_UINT16);

}
