#include "led.h"

#include <stdint.h>
#include <stdbool.h>

#include "inc/tm4c123gh6pm.h"
#include "inc/hw_memmap.h"

#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"

/**
    Define the LED signals used on the board.
*/
#define LED_PERIPHERAL  SYSCTL_PERIPH_GPIOF
#define LED_PORT        GPIO_PORTF_BASE
#define RED_PIN         GPIO_PIN_1
#define BLUE_PIN        GPIO_PIN_2
#define GREEN_PIN       GPIO_PIN_3

void LedInit()
{
    //Enable the peripheral.
    SysCtlPeripheralEnable(LED_PERIPHERAL);

    //Set the pins as outputs.
    GPIOPinTypeGPIOOutput(LED_PORT, RED_PIN | BLUE_PIN | GREEN_PIN);
}

void LedSetGreen()
{
    //Turn on the green LED.
    GPIOPinWrite(LED_PORT, GREEN_PIN, GREEN_PIN);

    //Turn off the other LEDs.
    GPIOPinWrite(LED_PORT, RED_PIN | BLUE_PIN, 0);
}

void LedSetBlue()
{
    //Turn on the blue LED.
    GPIOPinWrite(LED_PORT, BLUE_PIN, BLUE_PIN);

    //Turn off the other LEDs.
    GPIOPinWrite(LED_PORT, RED_PIN | GREEN_PIN, 0);
}

void LedSetRed()
{
    //Turn on the blue LED.
    GPIOPinWrite(LED_PORT, RED_PIN, RED_PIN);

    //Turn off the other LEDs.
    GPIOPinWrite(LED_PORT, BLUE_PIN | GREEN_PIN, 0);
}

void LedSetOff()
{
    GPIOPinWrite(LED_PORT, RED_PIN | BLUE_PIN | GREEN_PIN, 0);
}