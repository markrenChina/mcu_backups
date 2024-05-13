#ifndef __C9AD_H
#define __C9AD_H

#include "stm32f10x.h"                  // Device header
#include "C9public.h"
#include "C9GPIO.h"

void C9AD_init(ADC_TypeDef * ADCx,C9GPIO* gpiox);
uint16_t C9AD_getValue(ADC_TypeDef * ADCx);


#endif
