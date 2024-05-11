#ifndef __STM32TRANSPLANT_H
#define __STM32TRANSPLANT_H

#include "gd32e23x.h"                   // Device header

#define GPIO_WriteBit(gpio_periph,pin,bit_value) gpio_bit_write(gpio_periph,pin,bit_value)

#define GPIO_Pin_8 GPIO_PIN_8
#define GPIO_Pin_9 GPIO_PIN_9


#define BitAction FlagStatus

#endif