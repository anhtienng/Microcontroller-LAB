#include "interrupt.h"

void __interrupt () deviceInterrupt(void) {
    if (INTCONbits.TMR0IF == 1 && INTCONbits.TMR0IE == 1) {
        INTCONbits.TMR0IF = 0;
        TMR0H = 0xfd;
        TMR0L = 0x5f;
        count10ms++;
        count10MS++;
        if (state_FSM == 1)
            count_UV++;
        if (state_FSM == 3)
            count_heater++;
        if (state_FSM == 5)
            count_heatpump++;
        button();
    }
}
