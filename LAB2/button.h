#ifndef button_h
#define button_h

#include <stdio.h>

#define shortHold 100   // 1 s
#define longHold 300    // 3 s
#define slowChange 50   // 50 ms
#define fastChange 10   // 10 ms

int readButtonDecrease(void);
int readButtonIncrease(void);
void button(void);
void initButton(void);

#endif /* button_h */
