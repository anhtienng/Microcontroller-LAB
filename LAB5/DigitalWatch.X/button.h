#ifndef BUTTON_H
#define	BUTTON_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>
#include <pic18f8722.h>
#include "BBSPI_LCD.h"

    
int countPressed = 0;   
int countAuto= 0;
int RA5Pressed = 0;
int RB0Pressed = 0;
int increaseTime = 0;
char firstReadRA5 = 1;
char secondReadRA5 = 1;
char firstReadRB0 = 1;
char secondReadRB0 = 1;

int countRA5 = 0;
int countRB0 = 0;


int readRA5Button (void);
int readRB0Button (void);
void button (void);

#ifdef	__cplusplus
}
#endif

#endif	/* BUTTON_H */

