#include <pic18f8722.h>
#include "interrupt.h"

void interrupt_init(void)
{
    RCONbits.IPEN = 1;
    INTCONbits.GIEH = 1;
}

void __interrupt() ISR(void) {
    if (PIE1bits.TMR1IE == 1 && PIR1bits.TMR1IF == 1) {
        timer_ISR();
    }
}