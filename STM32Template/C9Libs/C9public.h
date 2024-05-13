#ifndef __C9PUBLIC_H
#define __C9PUBLIC_H

#include "stm32f10x.h"                  // Device header

uint32_t C9_Address_to_RCC_APB2Periph(uint32_t registerAddress);
uint32_t C9_Address_to_RCC_APB1Periph(uint32_t registerAddress);
uint8_t  C9_GPIO_Pin_to_GPIO_PinSource(uint16_t GPIO_Pin);

#endif
