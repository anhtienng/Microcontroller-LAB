#include "button.h"

int readRA5Button(void) {
    firstReadRA5 = secondReadRA5;
    secondReadRA5 = PORTAbits.RA5;
    int check = 0;
    if (firstReadRA5 == secondReadRA5) {
        if (firstReadRA5 == 0) {
            check = 1;
        }
    }
   return check; 
}

int readRB0Button (void) {
    firstReadRB0 = secondReadRB0;
    secondReadRB0 = PORTBbits.RB0;
    int check = 0;
    if (firstReadRB0 == secondReadRB0) {
        if (firstReadRB0 == 0) {
            check = 1;
        }
    }
    return check;
}

void button (void) {
    int checkRA5 = readRA5Button();
    int checkRB0 = readRB0Button();
    if (checkRA5 == 1) {
        RA5Pressed = 1;
    }
    else if (checkRB0 == 1) {
        countPressed++;
        RB0Pressed = 1;
        if (countPressed >= 100) {
            countAuto++;
            if (countAuto > 20) {
                increaseTime = 1;
                countAuto = 0;
            }       
        }
    }
    else {
        countPressed = 0;
        countAuto = 0;
        RA5Pressed = 0;
        RB0Pressed = 0;
        increaseTime = 0;
    }
}