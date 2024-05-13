#ifndef __C9IC_H
#define __C9IC_H

#include "stm32f10x.h"                  // Device header
#include "C9GPIO.h"
#include "C9Timer.h"

/*
TIM_Channel;      !< Specifies the TIM channel.
                                  This parameter can be a value of @ref TIM_Channel
TIM_ICPolarity;   !< Specifies the active edge of the input signal.
                                  This parameter can be a value of @ref TIM_Input_Capture_Polarity 

*/
void C9IC_init(TIM_TypeDef* TIMx,C9GPIO* gpiox,uint16_t TIM_Channel,uint16_t TIM_ICPolarity);

void C9Encoder_init(TIM_TypeDef* TIMx,C9GPIO* gpiox);
#endif
