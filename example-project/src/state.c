#include "state.h"

STATE StateGetNext(STATE current)
{
    STATE next = STATE_RED;

    switch(current)
    {
        case STATE_RED:
            next = STATE_GREEN;
            break;
        case STATE_GREEN:
            next = STATE_BLUE;
            break;
        case STATE_BLUE:
            next = STATE_RED;
            break;
    }
    return next;
}
