#include <xc.h>
#include <pic18f8722.h>
#include "interrupt.h"
#include "DHT.h"
#include "FSM.h"

void main(void) {
    oscillationInitialize();
    timerInitialize();
    buttonInitialize();
    pin_init();
    LCDInit();
    while (1)
    {   
        FSM();
        if (count10MS >= 200){
            readTempAndHumid();
            mCURSOR_LINE1;
            LCDPutStr("Temp:");
            LCDPutChar(realTemp/10 +'0');
            LCDPutChar(realTemp%10 +'0');
            LCDPutStr(" Humid:");
            LCDPutChar(realHumid/10 +'0');
            LCDPutChar(realHumid%10 +'0');  
            count10MS = 0;
        }
    }
    return;
} 
        
        