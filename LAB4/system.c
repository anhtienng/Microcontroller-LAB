#include "system.h"

void system_init(void)
{
    pin_init();
    timer_init();
    interrupt_init();
    osc_init();
}