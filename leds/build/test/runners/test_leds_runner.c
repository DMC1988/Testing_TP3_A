/* AUTOGENERATED FILE. DO NOT EDIT. */

/*=======Automagically Detected Files To Include=====*/
#include "unity.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

/*=======External Functions This Runner Calls=====*/
extern void setUp(void);
extern void tearDown(void);
extern void test_LedsOffAfterCreate(void);
extern void test_prender_un_LED(void);
extern void test_apagar_un_led(void);
extern void test_prender_y_apagar_varios_leds(void);
extern void test_led_prendido(void);
extern void test_led_apagado(void);
extern void test_encender_puerto(void);
extern void test_apagar_puerto(void);


/*=======Mock Management=====*/
static void CMock_Init(void)
{
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
  GlobalOrderError = NULL;
}
static void CMock_Verify(void)
{
}
static void CMock_Destroy(void)
{
}

/*=======Test Reset Options=====*/
void resetTest(void);
void resetTest(void)
{
  tearDown();
  CMock_Verify();
  CMock_Destroy();
  CMock_Init();
  setUp();
}
void verifyTest(void);
void verifyTest(void)
{
  CMock_Verify();
}

/*=======Test Runner Used To Run Each Test=====*/
static void run_test(UnityTestFunction func, const char* name, UNITY_LINE_TYPE line_num)
{
    Unity.CurrentTestName = name;
    Unity.CurrentTestLineNumber = line_num;
#ifdef UNITY_USE_COMMAND_LINE_ARGS
    if (!UnityTestMatches())
        return;
#endif
    Unity.NumberOfTests++;
    UNITY_CLR_DETAILS();
    UNITY_EXEC_TIME_START();
    CMock_Init();
    if (TEST_PROTECT())
    {
        setUp();
        func();
    }
    if (TEST_PROTECT())
    {
        tearDown();
        CMock_Verify();
    }
    CMock_Destroy();
    UNITY_EXEC_TIME_STOP();
    UnityConcludeTest();
}

/*=======MAIN=====*/
int main(void)
{
  UnityBegin("test_leds.c");
  run_test(test_LedsOffAfterCreate, "test_LedsOffAfterCreate", 38);
  run_test(test_prender_un_LED, "test_prender_un_LED", 47);
  run_test(test_apagar_un_led, "test_apagar_un_led", 59);
  run_test(test_prender_y_apagar_varios_leds, "test_prender_y_apagar_varios_leds", 72);
  run_test(test_led_prendido, "test_led_prendido", 81);
  run_test(test_led_apagado, "test_led_apagado", 91);
  run_test(test_encender_puerto, "test_encender_puerto", 102);
  run_test(test_apagar_puerto, "test_apagar_puerto", 108);

  return UnityEnd();
}
