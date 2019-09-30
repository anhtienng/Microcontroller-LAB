#include "button.h"
#include "project.h"


int readButtonDecrease() {
    firstReadRB0 = secondReadRB0;
    secondReadRB0 = PORTBbits.RB0;
    if(secondReadRB0 == firstReadRB0) {
        if (secondReadRB0 == 0)
            return 2;
        else
            return 1;
    }
    return 0;
}

int readButtonIncrease() {
    firstReadRA5 = secondReadRA5;
    secondReadRA5 = PORTAbits.RA5;
    if(secondReadRA5 == firstReadRA5) {
        if (secondReadRA5 == 0)
            return 2;
        else
            return 1;
    }
    return 0;
}

void initButton() {
    TRISAbits.TRISA5 = 1;
    TRISBbits.TRISB0 = 1;
    ADCON1 = 0b00001111; // 10-BIT ANALOG-TO-DIGITAL CONVERTER MODULE, channel 3
}

void button() {
    int checkIncrease = readButtonIncrease();
    int checkDecrease = readButtonDecrease();
    if (checkIncrease == 2) {  // press I-button
        countIncrease++;
        if (countIncrease > shortHold)
            slowCount++;
        if (countIncrease > longHold)
            fastCount++;
    }
    else if (checkDecrease == 2) {   // press D-button
        countDecrease++;
        if (countDecrease > shortHold)
            slowCount++;
        if (countDecrease > longHold)
            fastCount++;
    }
    else if (checkIncrease == 1 || checkDecrease == 1) { // release buttons
        countIncrease = 0;
        countDecrease = 0;
    }
}

void initState(){
    slowCount = 0;
    fastCount = 0;
    if (countIncrease > 0) {
        LATD++;
        state = NORMAL_INCREASE;
    }
    else if (countDecrease > 0 && countIncrease == 0) {
        LATD--;
        state = NORMAL_DECREASE;
    }
}

void normalIncrease(){  // increase per pressing 
    if (countIncrease == 0) 
        state = INIT;
    if (countIncrease > shortHold)
        state = SLOW_INCREASE;
}

void slowIncrease(){ // continuous slow increasing
    if (countIncrease == 0) 
        state = INIT;
    if (countIncrease > longHold)
        state = FAST_INCREASE;
    if (slowCount > slowChange) {
        LATD++;
        slowCount = 0;
    }
}

void fastIncrease(){// continuous fast increasing
    if (countIncrease == 0) 
        state = INIT;
    if (fastCount > fastChange) {
        LATD++;
        fastCount = 0;
    }
}

void normalDecrease(){  // decrease per pressing
    if (countDecrease == 0 || countIncrease > 0)  
        state = INIT;
    if (countDecrease > shortHold)
        state = SLOW_DECREASE;
}

void slowDecrease(){ // continuous slow decreasing 
    if (countDecrease == 0 || countIncrease > 0) 
        state = INIT;
    if (countDecrease > longHold)
        state = FAST_DECREASE;
    if (slowCount > slowChange) {
        LATD--;
        slowCount = 0;
    }
}

void fastDecrease(){ // continuous fast decreasing
    if (countDecrease == 0 || countIncrease > 0) 
        state = INIT;
    if (fastCount > fastChange) {
        LATD--;
        fastCount = 0;
    }
}