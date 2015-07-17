#include "unity.h"
#include "led.h"

#include "inc/tm4c123gh6pm.h"
#include "inc/hw_memmap.h"
#include "driverlib/pin_map.h"

#include "mock_sysctl.h"
#include "mock_gpio.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_whenLedsAreInitialized_thenGpioPortFIsEnabledAndLedPinsAreSetAsOutputs(void)
{
    //Set up the expected call chain.
    SysCtlPeripheralEnable_Expect(SYSCTL_PERIPH_GPIOF);
    GPIOPinTypeGPIOOutput_Expect(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);

    //Call the function under test.
    LedInit();
}

void test_whenLedSetToGreen_thenGreenPinIsSetHighAndOtherSignalsAreSetLow(void)
{
    //Expect to set the green pin high.
    GPIOPinWrite_Expect(GPIO_PORTF_BASE, GPIO_PIN_3, GPIO_PIN_3);

    //Expect to set the red and blue pins low.
    GPIOPinWrite_Expect(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2, 0);

    //Call the function under test.
	LedSetGreen();
}

void test_whenLedSetToBlue_thenBluePinIsSetHighAndOtherSignalsAreSetLow(void)
{
    //Expect to set the blue pin high.
    GPIOPinWrite_Expect(GPIO_PORTF_BASE, GPIO_PIN_2, GPIO_PIN_2);

    //Expect to set the red and green pins low.
    GPIOPinWrite_Expect(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_3, 0);

    //Call the function under test.
    LedSetBlue();
}

void test_whenLedSetToRed_thenRedPinIsSetHighAndOtherSignalsAreSetLow(void)
{
    //Expect to set the red pin high.
    GPIOPinWrite_Expect(GPIO_PORTF_BASE, GPIO_PIN_1, GPIO_PIN_1);

    //Expect to set the green and blue pins low.
    GPIOPinWrite_Expect(GPIO_PORTF_BASE, GPIO_PIN_2 | GPIO_PIN_3, 0);

    //Call the function under test.
    LedSetRed();
}

void test_whenLedTurnedOff_thenAllLedPinsAreSetLow(void)
{
    //Expect to set all the pins low.
    GPIOPinWrite_Expect(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, 0);

    //Call the function under test.
    LedSetOff();
}