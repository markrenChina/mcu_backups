#ifndef __SERIAL_H
#define __SERIAL_H

//#include "gd32e23x.h"
//#include "gd32e23x_usart.h"

#include "stm32f10x.h"                  // Device header

#define BSP_USART_RCU              	RCC_APB2Periph_USART1
#define BSP_USART_TX_RCU          	RCC_APB2Periph_GPIOA
#define BSP_USART_RX_RCU          	RCC_APB2Periph_GPIOA

#define BSP_USART_TX_PORT      			GPIOA
#define BSP_USART_TX_PIN        		GPIO_Pin_9
#define BSP_USART_RX_PORT       		GPIOA
#define BSP_USART_RX_PIN        		GPIO_Pin_10
#define BSP_USART_AF        				GPIO_AF_1  // 据手册的第33页 串口是引脚复用功能1

#define BSP_USART    								USART1


void serial_begin();

void serial_send_byte(uint8_t ucch);
void serial_send_String(char* ucstr);

#endif 