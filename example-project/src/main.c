#include <stdint.h>

#include "led.h"

//*****************************************************************************
//
// Blink the on-board LED.
//
//*****************************************************************************
int
main(void)
{
    volatile uint32_t ui32Loop;

    LedInit();

    while(1)
    {
        LedSetBlue();

        // Delay for a bit.
        for(ui32Loop = 0; ui32Loop < 400000; ui32Loop++)
        {
        }

        LedSetOff();

        // Delay for a bit.
        for(ui32Loop = 0; ui32Loop < 400000; ui32Loop++)
        {
        }
    }
}
