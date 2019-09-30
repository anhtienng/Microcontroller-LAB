#include "osc.h"
#include "project.h"

void initOsc() {
    OSCCON = 0b01110111;  // OSCILLATOR CONTROL REGISTER, 8 MHz
    OSCTUNE = 0b00001111; // OSCILLATOR TUNING REGISTER, Maximum frequency
}
