#ifndef interrupt_h
#define interrupt_h

#include <stdio.h>
#define interrupt 10    // 10 ms

int setInterrupt(void);
void __interrupt() ITR(void);

#endif /* interrupt_h */
