#ifndef SYSTEM_H
#define	SYSTEM_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <xc.h>
#include <pic18f8722.h>
    
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
 
    
void oscillationInitialize (void);
void timerInitialize (void);
void buttonInitialize (void);
void pin_init(void);

#ifdef	__cplusplus
}
#endif

#endif	/* SYSTEM_H */

