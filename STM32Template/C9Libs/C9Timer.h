#ifndef __C9_TIMER_H
#define __C9_TIMER_H

#include "stm32f10x.h"                  // Device header
#include "C9public.h"
#include "C9EXTI.h"


/* 定时器初始化 只支持 APB1
	TIM_Period ：要计数的值 -1   		(ARR + 1)
	TIM_Prescaler ：要分频的值 -1 	(PSC + 1)
	
Example:
	C9Timer_init(TIM2,10000-1,7200-1);
	C9Timer_enable_IT_Update(TIM2,1,1);
*/
void C9Timer_init(TIM_TypeDef* TIMx,
	uint16_t TIM_Period,uint16_t TIM_Prescaler);

void C9Timer_enable_IT_Update(TIM_TypeDef* TIMx,
	uint8_t preemptionPriority, uint8_t subPriority);

// 定时器调整 时基单元预分频数 
void C9Timer_setPrescaler(TIM_TypeDef* TIMx,uint16_t prescaler);


#endif
