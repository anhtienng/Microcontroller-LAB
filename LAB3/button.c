#include "button.h"
#include "system.h"

char readButtonRA5() {
    firstReadRA5 = secondReadRA5;
    secondReadRA5 = PORTAbits.RA5;
    if(secondReadRA5 == firstReadRA5) {
        return (secondReadRA5 == 0) ? 2 : 1;
    }
    return 0;
}

char readButtonRB0() {
    firstReadRB0 = secondReadRB0;
    secondReadRB0 = PORTBbits.RB0;
    if(secondReadRB0 == firstReadRB0) {
        return (secondReadRB0 == 0) ? 2 : 1;
    }
    return 0;
}

void button (void) { 
    char checkRA5 = readButtonRA5(); 
    char checkRB0 = readButtonRB0(); 
    
    if (checkRB0 == 2){
        switch(stateRB0){
            case 0:
                stateRB0 = 1;
            case 1:
                countNormal ++;
                if (countNormal > TIME_PRESS){
                    stateRB0 = 2;
                }
            case 2:
                countFast++;
        }
    } 
    
    else if (checkRA5 == 2){
        changeMode = 1;
    }
    
    else {
        countNormal = 0;
        countFast = 0;
        stateRB0 = 0;
        changeMode = 0;
    }
}
