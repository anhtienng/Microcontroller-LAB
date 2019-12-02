#include "timer.h"
#include "system.h"
#include <pic18f8722.h>

void timer_init(void)
{
    T1CON = 0b10010100;
    TMR1 = 65535 - 1 / 1000 * 2000000;
    PIR1bits.TMR1IF = 0;
    PIE1bits.TMR1IE = 1;
    T1CONbits.TMR1ON = 1;
}