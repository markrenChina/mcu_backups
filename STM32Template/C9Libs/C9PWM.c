#include "C9PWM.h"

void C9PWM_init(TIM_TypeDef* TIMx,C9GPIO* gpiox,uint8_t oc,uint16_t duty){
	
	//确保GPIO配置复用
	C9GPIO_INIT(gpiox,gpiox->GPIOx,gpiox->GPIO_Pin,GPIO_Mode_AF_PP);
	// 初始化定时器
	C9Timer_init(TIMx,100-1,720-1);
	
	//配置定时器通道
	TIM_OCInitTypeDef TIM_OCInitStruct;
	TIM_OCStructInit(&TIM_OCInitStruct);
	TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStruct.TIM_Pulse = duty;				//CCR 捕获/比较寄存器
	switch(oc) {
		case 1: TIM_OC1Init(TIM2,&TIM_OCInitStruct); break;
		case 2: TIM_OC2Init(TIM2,&TIM_OCInitStruct); break;
		case 3: TIM_OC3Init(TIM2,&TIM_OCInitStruct); break;
		case 4: TIM_OC4Init(TIM2,&TIM_OCInitStruct); break;
		default: TIM_OC1Init(TIM2,&TIM_OCInitStruct);
	}
	
	
	//使能定时器
	//TIM_Cmd(TIMx,ENABLE);
}

void C9PWM_changeDuty(TIM_TypeDef* TIMx,uint16_t pwm){
	TIM_SetCompare1(TIMx,pwm);
}

void C9PWM_setPrescaler(TIM_TypeDef* TIMx,uint16_t prescaler){
	C9Timer_setPrescaler(TIMx,prescaler);
}
