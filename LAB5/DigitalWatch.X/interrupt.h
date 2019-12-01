#ifndef INTERRUPT_H
#define	INTERRUPT_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>
#include <pic18f8722.h>
#include <stdint.h>
#include <stdbool.h>
#include "system.h"
#include "button.h"
#include "FSM.h"
#include "DHT.h"
    
int count10ms = 0;    
int flag = 0;
int count10MS = 0;
int count_UV = 0;
int count_heater = 0;
int count_heatpump = 0;

void __interrupt () deviceInterrupt(void);  


#ifdef	__cplusplus
}
#endif

#endif	/* CLOCK_H */

