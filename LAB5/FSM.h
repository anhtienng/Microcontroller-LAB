#ifndef FSM_H
#define	FSM_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "system.h"
#include "button.h"
#include "interrupt.h"

int temp = 30;
int humid = 50;

//#define MAX_TEMP 40
//#define MAX_HUMID 60
#define MIN_HUMID 40

#define LED1 LATD0
#define LED2 LATD1
#define LED3 LATD2
#define LED4 LATD3
#define LED5 LATD4
#define LED6 LATD5
#define LED7 LATD6
#define LED8 LATD7


int state_FSM = 0;

void FSM(void);

#ifdef	__cplusplus
}
#endif

#endif	/* FSM_H */

