#ifndef DHT_H
#define	DHT_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>
#include <pic18f8722.h>
//#include "system.h"
#include "BBSPI_LCD.h"
#define MAX_TEMP 30
#define MAX_HUMID 60
#define TIME_OUT 80
    
#define DHT_DIRECTION TRISAbits.TRISA5
#define DHT_IN PORTAbits.RA5
#define DHT_OUT LATAbits.LATA5
#define ERROR -10    
    
int realTemp;
int realHumid;
char dhtData[5];
int error = 0;


char getByteData(void);
int readDHT (void);
void readTempAndHumid(void);


#ifdef	__cplusplus
}
#endif

#endif	/* DHT_H */

