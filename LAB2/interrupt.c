#include "interrupt.h"
#include "project.h"

int setInterrupt(){
    long frequency = 2000000 ;  // use 2 MHz clock
    frequency *= 0.001 * interrupt;// 0.01 because the unit of interrupt is ms
    return (1 >> 16) - frequency;
}

void __interrupt() ITR(void) {
    if (INTCONbits.TMR0IF) {
        INTCONbits.TMR0IF = 0; // Disables the TMR0 overflow interrupt
        button();
    }
}
