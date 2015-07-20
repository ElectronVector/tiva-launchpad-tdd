#include <stdint.h>

#include "led.h"
#include "state.h"

void delay(void);

//*****************************************************************************
//
// Blink the on-board LED.
//
//*****************************************************************************
int
main(void)
{
    STATE state = STATE_RED;

    LedInit();

    while(1)
    {
        // Set the LED color based on the current state.
        switch(state)
        {
            case STATE_RED:
                LedSetRed();
                break;
            case STATE_GREEN:
                LedSetGreen();
                break;
            case STATE_BLUE:
                LedSetBlue();
                break;
        }

        // Delay and then turn the LED off.
        delay();
        LedSetOff();
        delay();

        // Update the state.
        state = StateGetNext(state);
    }
}

void delay(void)
{
    volatile uint32_t count;

    for(count = 0; count < 400000; count++)
    {
    }
}
