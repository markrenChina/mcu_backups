#include "C9IC.h"


void C9IC_init(TIM_TypeDef* TIMx,C9GPIO* gpiox,uint16_t TIM_Channel
	,uint16_t TIM_ICPolarity){
	C9GPIO_INIT(gpiox,gpiox->GPIOx,gpiox->GPIO_Pin,GPIO_Mode_IPU);
	C9Timer_init(TIMx,65536-1,72-1); 		//1MHz
		
	//初始化输入捕获单元
	TIM_ICInitTypeDef TIM_ICInitStruct;
	TIM_ICInitStruct.TIM_Channel = TIM_Channel;
	TIM_ICInitStruct.TIM_ICFilter = 0xF;
	TIM_ICInitStruct.TIM_ICPolarity = TIM_ICPolarity;
	TIM_ICInitStruct.TIM_ICPrescaler = TIM_ICPSC_DIV1;
	TIM_ICInitStruct.TIM_ICSelection = TIM_ICSelection_DirectTI;
	TIM_ICInit(TIMx,&TIM_ICInitStruct);
	// 用 TIM_PWMIConfig 可以快速配置 相反配置的另一个通道
		
	//触发源选择
	TIM_SelectInputTrigger(TIMx,TIM_TS_TI1FP1);

	//配置从模式
	TIM_SelectSlaveMode(TIMx,TIM_SlaveMode_Reset);
}
	
void C9Encoder_init(TIM_TypeDef* TIMx,C9GPIO* gpiox){
	C9GPIO_INIT(gpiox,gpiox->GPIOx,gpiox->GPIO_Pin,GPIO_Mode_IPU);
	C9Timer_init(TIMx,65535,0); 		
	
	//初始化输入捕获单元
	TIM_ICInitTypeDef TIM_ICInitStruct;
	TIM_ICStructInit(&TIM_ICInitStruct);
	TIM_ICInitStruct.TIM_Channel = TIM_Channel_1;
	TIM_ICInitStruct.TIM_ICFilter = 0xF;
	TIM_ICInit(TIMx,&TIM_ICInitStruct);
	
	TIM_ICInitStruct.TIM_Channel = TIM_Channel_2;
	TIM_ICInit(TIMx,&TIM_ICInitStruct);
	
	TIM_EncoderInterfaceConfig(TIMx,TIM_EncoderMode_TI12,TIM_ICPolarity_Rising,TIM_ICPolarity_Rising);
	TIM_SetCounter(TIMx,0);
}

