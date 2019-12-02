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

#include <xc.h>
#include <stdbool.h>
#include <stdint.h>


typedef unsigned long int timestamp_t;
typedef void timer_callback_t;

void system_init(void);

unsigned long timestamp = 0;
