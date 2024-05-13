#ifndef __C9EXTI_H
#define __C9EXTI_H

#include "stm32f10x.h"                  // Device header
#include "C9GPIO.h"
#include "C9public.h"

#define GLOBAL_NVIC_PRIORITYGROUP  NVIC_PriorityGroup_2

/**
参数：
typedef enum
{
  EXTI_Trigger_Rising = 0x08,
  EXTI_Trigger_Falling = 0x0C,  
  EXTI_Trigger_Rising_Falling = 0x10
}EXTITrigger_TypeDef;
*/
void C9EXTI_init(C9GPIO* gpio,EXTITrigger_TypeDef EXTI_Trigger_mode);


#endif
