#include "pin.h"
#include "system.h"
#include <pic18f8722.h>

void pin_init(void)
{
    TRISD = 0x00;
    LATD = 0x00;
    ADCON1 = 0x0F;
}

