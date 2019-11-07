#include "pin.h"
#include "system.h"

void pin_init(){
    TRISAbits.TRISA5 = 1;
    TRISBbits.TRISB0 = 1;
    ADCON1 = 0b00001111;
}
