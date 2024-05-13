#include "C9EXTI.h"
#include "C9GPIO.h"


uint8_t GPIO_PinSource_to_NVIC_IRQChannel(uint8_t GPIO_PinSource){
	if(GPIO_PinSource <= 4){
		return EXTI0_IRQn + GPIO_PinSource;
	}else if(GPIO_PinSource <= 9){
		return EXTI9_5_IRQn;
	} else {
		return EXTI15_10_IRQn;
	}
}

uint8_t GPIO_TypeDef_to_GPIO_PortSourceGPIOX(uint32_t GPIOx){
	uint8_t portSource = GPIO_PortSourceGPIOA;
	GPIOx -= GPIOA_BASE;
	while(GPIOx > 0){
		GPIOx-=0x400;
		portSource++;
	}
	return portSource;
}



void C9EXTI_init(C9GPIO* gpio,EXTITrigger_TypeDef EXTI_Trigger_mode){
	//配置 AFIO
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	uint8_t GPIO_PortSource = GPIO_TypeDef_to_GPIO_PortSourceGPIOX((uint32_t)gpio->GPIOx);
	uint8_t GPIO_PinSource = C9_GPIO_Pin_to_GPIO_PinSource(gpio->GPIO_Pin);
	GPIO_EXTILineConfig(GPIO_PortSource,GPIO_PinSource);
	
	//配置 EXTI
	EXTI_InitTypeDef EXTI_InitStructure;
	EXTI_InitStructure.EXTI_Line = (uint32_t)gpio->GPIO_Pin;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_mode;
	EXTI_Init(&EXTI_InitStructure);
	
	//配置NVIC
	NVIC_PriorityGroupConfig(GLOBAL_NVIC_PRIORITYGROUP);
	NVIC_InitTypeDef NVIC_InitStruct;
	NVIC_InitStruct.NVIC_IRQChannel = GPIO_PinSource_to_NVIC_IRQChannel(GPIO_PinSource);
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStruct);
}
