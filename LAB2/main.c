#include "project.h"

void main(void) {
    
    // Initialization
    initTmr();
    initLED();
    initButton();
    initOsc();
    // Main loop    
    while (1) {
        switch(state) {
            case INIT:  // initial state
                initState();
                break;
                
            case NORMAL_INCREASE:  // increase per pressing 
                normalIncrease();
                break;
                
            case SLOW_INCREASE: // continuous slow increasing
                slowDecrease();
                break;
                
            case FAST_INCREASE: // continuous fast increasing
                fastIncrease();
                break;
                
            case NORMAL_DECREASE:  // decrease per pressing
                normalDecrease();
                break;
                
            case SLOW_DECREASE: // continuous slow decreasing 
                slowDecrease();
                break;
                
            case FAST_DECREASE: // continuous fast decreasing
                fastDecrease();
                break;
        }
    }
}
