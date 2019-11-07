#include "interrupt.h"
#include "system.h"

unsigned int count1 = 0;

void interrupt_init() {
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    INTCONbits.TMR0IE = 1;
    INTCONbits.TMR0IF = 0;
}

void __interrupt() myISR(void) {
    if(INTCONbits.TMR0IE && INTCONbits.TMR0IF) {
        INTCONbits.TMR0IF = 0;
        TMR0L = counter_low;
        TMR0H = counter_high;
        // TO DO
        
        button();
    }
}
