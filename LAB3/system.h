#include <xc.h>
#include "interrupt.h"
#include "button.h"
#include "oscillator.h"
#include "BBSPI_LCD.h"
#include "timer.h"
#include "pin.h"
//#include "stateClock.h"
//#include "stateSet.h"
//#include "stateStopWatch.h"
    
#ifdef _18F8722
#pragma config  OSC = HSPLL
#pragma config 	FCMEN = OFF
#pragma config 	IESO = OFF
#pragma config 	PWRT = OFF
#pragma config 	BOREN = OFF
#pragma config 	WDT = OFF
#pragma config 	MCLRE = ON
#pragma config 	LVP = OFF
#pragma config 	XINST = OFF
#endif  
    
#define _XTAL_FREQ  8000000
#define INTERRUPT 10
#define TIME_PRESS 1000 / INTERRUPT

typedef unsigned char tBYTE;
typedef unsigned short int tHALFWORD;
typedef unsigned int tWORD;

enum State{CLOCK, SET_HOUR, SET_MIN, SET_SEC, STOP_WATCH} state;

void system_init(void);
void state_clock(void);
void state_set_hour(void);
void state_set_min(void);
void state_set_sec(void);
void state_stop_watch(void);

tHALFWORD counter_low = 0;
tHALFWORD counter_high = 0;

tBYTE changeMode = 0;

tBYTE firstReadRA5 = 1;
tBYTE secondReadRA5 = 1;
tBYTE firstReadRB0 = 1;
tBYTE secondReadRB0 = 1;

tBYTE stateRB0 = 0;
tWORD countNormal = 0;
tWORD countFast = 0;