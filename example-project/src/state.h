#ifndef state_H
#define state_H

typedef enum {
    STATE_RED,
    STATE_GREEN,
    STATE_BLUE
} STATE;

/**
    Get the next state based on the current state.
*/
STATE StateGetNext(STATE current);

#endif // state_H
