#ifndef project_h
#define project_h

#ifdef _18F8722
#pragma config OSC = HSPLL
#pragma config FCMEN = OFF
#pragma config IESO = OFF
#pragma config PWRT = OFF
#pragma config BOREN = OFF
#pragma config WDT = OFF
#pragma config MCLRE = ON
#pragma config LVP = OFF
#pragma config XINST = OFF
#endif

#include <xc.h>
#include <pic18f8722.h>
#include "button.h"
#include "interrupt.h"
#include "timer.h"
#include "LED.h"
#include "osc.h"


//Variables Declaration
int firstReadRA5 = 1;
int secondReadRA5 = 1;
int firstReadRB0 = 1;
int secondReadRB0 = 1;
int countIncrease = 0;
int countDecrease = 0;
int slowCount = 0;
int fastCount = 0;

enum State{INIT, NORMAL_INCREASE, SLOW_INCREASE, FAST_INCREASE, NORMAL_DECREASE, 
            SLOW_DECREASE, FAST_DECREASE};
enum State state;

void initState();
void normalIncrease();
void slowIncrease();
void fastIncrease();
void slowDecrease();
void normalDecrease();
void fastDecrease();



#endif /* project_h */
