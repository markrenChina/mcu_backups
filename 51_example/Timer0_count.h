#ifndef __TIMER0_COUNT_H_
#define __TIMER0_COUNT_H_
#include <REGX52.H>


void Timer0_Init(void);
void Timer0_SetCounter(unsigned int Value);
unsigned int Timer0_GetCounter(void);
void Timer0_Run(unsigned char Flag);

#endif