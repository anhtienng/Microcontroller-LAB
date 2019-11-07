#include <xc.h>
#include "system.h"

void main(void) {
    system_init();
    while (1)
    {
        switch (state) {
            case CLOCK:
                state_clock();
                break;
            case SET_HOUR:
                state_set_hour();
                break;
            case SET_MIN:
                state_set_min();
                break;
            case SET_SEC:
                state_set_sec();
                break; 
            case STOP_WATCH:
                state_stop_watch();
                break;
        }
    }
    return;
}
