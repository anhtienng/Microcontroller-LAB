#include "LED.h"
#include "project.h"

void initLED() {
    LATD = 0x00;  // clear output latch
    TRISD = 0x00; // make PORTD pin an output
}
