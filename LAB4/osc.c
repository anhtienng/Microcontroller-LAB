#include "osc.h"
#include "system.h"
#include <pic18f8722.h>

void osc_init(void)
{
    OSCCON = 0b0111111;
}