#ifndef __TIMER0_H_
#define __TIMER0_H_
#include <REGX52.H>

void Timer0_per_second_callback();
void Timer0_per_millsecond_callback();
void Timer0_per_count_callback();

void Timer0_Init();

#endif