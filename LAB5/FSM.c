#include "system.h"
#include "button.h"
#include "interrupt.h"
#include "FSM.h"

void FSM(void)
{
    switch(state_FSM){
        case 0:
            LATD = 0b00000001;
            mCURSOR_LINE2;
            LCDPutStr("Select UV Mode");
            if (RA5Pressed)
                state_FSM = 1;
            if (RB0Pressed)
                state_FSM = 2;
            break;
            
        case 1:
            LATD = 0b00000010;
            mCURSOR_LINE2;
            LCDPutStr("Turn on UV light");
            if (count_UV >= 500){
                state_FSM = 2;
                count_UV = 0;
            }
            break;
            
        case 2:
            LATD = 0b00000100;
            mCURSOR_LINE2;
            LCDPutStr("IDLE state      ");
            if (RA5Pressed)
                state_FSM = 3;
            break;
            
        case 3:
            LATD = 0b00001000;
            mCURSOR_LINE2;
            LCDPutStr("Turn on heater  ");
            if (realHumid > 50)
                state_FSM = 4;
            if (count_heater >= 6000)
                state_FSM = 2;
            break;
            
        case 4:
            LATD = 0b00010000;
            mCURSOR_LINE2;
            LCDPutStr("Turn on fan1    ");
            if (temp > 30)
                state_FSM = 5;
            break;
            
        case 5:
            LATD = 0b00100000;
            mCURSOR_LINE2;
            LCDPutStr("Turn on heatpump");
            if (humid < 40)
                state_FSM = 6;
            if (count_heatpump >= 6000)
                state_FSM = 2;
            break;
            
        case 6:
            LATD = 0b01000000;
            LCDPutStr("Turn off fan1   ");
            state_FSM = 3;
            break;            
    }               
}

/*
void FSM1(void){
    switch (state) {
        case idle:
            stateDevices();
            read = 1;
            if (RA5Pressed == 1) {
                if (changeMod == 0) {
                    state = chooseTemp;
                    modTempVal = MAX_TEMP;
                    modHumidVal = MAX_HUMID;
                    changeMod = 1;
                    mLCD_CLEAR;
                    read = 0;
                }
            }
            break;
        case chooseTemp:
            modifyMaxTemp();
            display();
            if (RA5Pressed == 1) {
                if (changeMod == 0) {
                    state = chooseHumid;
                    changeMod = 1;
                    MAX_TEMP = modTempVal;
                    mLCD_CLEAR;
                }
            }
            break;
        case chooseHumid:
            modifyMaxHumid();
            display();
            if (RA5Pressed == 1) {
                if (changeMod == 0) {
                    state = idle;
                    changeMod = 1;
                    MAX_HUMID = modHumidVal;
                    mLCD_CLEAR;
                    read = 1;
                }
            }
            break;
    }
}
 */