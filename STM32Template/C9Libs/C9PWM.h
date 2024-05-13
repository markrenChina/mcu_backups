#ifndef __C9PWM_H
#define __C9PWM_H

#include "stm32f10x.h"                  // Device header
#include "C9public.h"
#include "C9GPIO.h"
#include "C9Timer.h"


/**
- PWM频率：    		Freq = CK_PSC / (PSC + 1) / (ARR + 1)
- PWM占空比：    	Duty = CCR / (ARR + 1)
- PWM分辨率：    	Reso = 1 / (ARR + 1)
*/

// 重映射需要手动 打开 AFIO 再调用 GPIO _PinRemapConfig

void C9PWM_init(TIM_TypeDef* TIMx,C9GPIO* gpiox,uint8_t oc,uint16_t duty);

// 修改占空比
void C9PWM_changeDuty(TIM_TypeDef* TIMx,uint16_t duty);

// 修改精度
void C9PWM_setPrescaler(TIM_TypeDef* TIMx,uint16_t prescaler);

#endif
