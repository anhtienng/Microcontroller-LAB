#include "DHT.h"

char getByteData (void) {
    char result;
    char i, j;
    unsigned int timeOut;
    for (j = 0; j < 8; j++) {
        while (DHT_IN == 0) { 
            if (timeOut == 0) { 
                return 0;
            }
            timeOut--;
        }//wait for going to 1
        __delay_us(30);
        if (DHT_IN == 0) {
            i &= ~(1 << (7 - j)); //Clear bit (7-b)
        } else {
            //LATD++;
            i |= (1 << (7 - j)); //Set bit (7-b)
            timeOut = TIME_OUT;
            while (DHT_IN == 1) {
                if (timeOut == 0) { 
                return 0;
                }
                timeOut--;
            }//wait for going to 0
        }
    }
    return i;
}

int readDHT (void) {
    unsigned int timeOut = TIME_OUT;
    DHT_DIRECTION = 0;
    DHT_OUT = 0;
    __delay_ms(20);
    
    DHT_OUT = 1;
    __delay_us(20);
    DHT_DIRECTION = 1;
    
    while(DHT_IN & 1) {
        if(timeOut == 0) {
            return 0;
        }
        timeOut--;
    }
    
    
    timeOut = TIME_OUT;
    while(!DHT_IN & 1) {
        if(timeOut == 0) {
            return 0;
        }
        timeOut--;
    }
    
    timeOut = TIME_OUT;
    while(DHT_IN & 1) {
        if(timeOut == 0) {
            return 0;
        }
        timeOut--;
    }
    dhtData[0] = getByteData();
    dhtData[1] = getByteData();
    dhtData[2] = getByteData();
    dhtData[3] = getByteData();
    dhtData[4] = getByteData();
    
    if( (char)(dhtData[0] + dhtData[1] + dhtData[2] + dhtData[3]) & 0xFF != dhtData[4] )
        return 0;
    return 1;  
}

void readTempAndHumid (void) {
    int check = readDHT();
    realTemp = (int)dhtData[2];
    realHumid = (int)dhtData[0];
}

