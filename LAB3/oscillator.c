#include "oscillator.h"
#include "system.h"

void osc_init() {
    OSCCON = 0x70; //Internal clock , Freq = 8MHz
}
