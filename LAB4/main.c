#include <xc.h>
#include "system.h"

void increaseLED(){
    LATD++;
}
void setLED(){
    LATD = 0xFF;
}

void setLED2(){
    LATD = 0x00;
}

void main(void) {
    system_init();
    register_timer(50, increaseLED, NULL);
    register_timer(170, setLED, NULL);
    register_timer(120, setLED2, NULL);
    while (1){   
    }
}
