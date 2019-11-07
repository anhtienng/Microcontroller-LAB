#include "timer.h"
#include "system.h"
#include <math.h>

void calculate() {
    T0CON = 0b11000100;
    int count = INTERRUPT * 2 * 1000;
    int count_scaled = count / 32;
    if(count_scaled < 256) {
        counter_low = 255 - count_scaled;
    } 
    else {
        T0CONbits.T08BIT = 0;
        unsigned int temp = 65535 - count_scaled;
        counter_low = (unsigned short int)temp;
        counter_high = (unsigned short int)(temp >> 8);
    }
}

void timer_init() {
    calculate();
    TMR0L = counter_low;
    TMR0H = counter_high;
}
