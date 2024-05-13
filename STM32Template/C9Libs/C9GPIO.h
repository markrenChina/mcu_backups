#ifndef __LED_H
#define __LED_H

#include "stm32f10x.h"                  // Device header
#include "C9public.h"

typedef struct{
	GPIO_TypeDef* GPIOx;
	uint16_t GPIO_Pin;
}C9GPIO;

#define C9GPIO_INIT_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME

#define C9GPIO_INIT(...) C9GPIO_INIT_MACRO(__VA_ARGS__, C9GPIO_init_Speed, C9GPIO_init_Mode, C9GPIO_init_Pin, C9GPIO_init_ALL,)(__VA_ARGS__)


void C9GPIO_init_ALL(C9GPIO* self,GPIO_TypeDef* GPIOx);
void C9GPIO_init_Pin(C9GPIO* self,GPIO_TypeDef* GPIOx,
	uint16_t GPIO_Pin);
void C9GPIO_init_Mode(C9GPIO* self,GPIO_TypeDef* GPIOx,
	uint16_t GPIO_Pin,GPIOMode_TypeDef GPIO_Mode);
void C9GPIO_init_Speed(C9GPIO* self,GPIO_TypeDef* GPIOx,
	uint16_t GPIO_Pin,GPIOMode_TypeDef GPIO_Mode,GPIOSpeed_TypeDef GPIO_Speed);
void C9GPIO_on(C9GPIO* self);
void C9GPIO_off(C9GPIO* self);
void C9GPIO_turn(C9GPIO* self);
uint8_t C9GPIO_read(C9GPIO* self);

#endif
