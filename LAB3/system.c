#include "system.h"

void system_init(void){
    osc_init();
    pin_init();
    interrupt_init();
    timer_init();
    mOPEN_LCD;
}
