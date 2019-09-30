#include "timer.h"
#include "project.h"

void initTmr() {
    INTCONbits.TMR0IE = 1;     // Enables the TMR0 overflow interrupt
    INTCONbits.GIE = 1;        // Enables interrupts
    T0CON = 0b10001110;
    TMR0L = setInterrupt();                // Timer0 Register Low Byte
}

/*
 ----------- T0CON = 0b11000110 -------------
 bit 7: 1 = Enables Timer0
 bit 6: 0 = Timer0 is configured as an 16-bit timer/counter
 bit 5: 0 = Select Internal instruction cycle clock (CLKO) as Clock Source
 bit 4: 0 = Increment on low-to-high transition on T0CKI pin (rising edge)
 bit 3: 1 = Timer0 prescaler is not assigned.
 bit 2-0: xxx
 */


