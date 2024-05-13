#include "C9Timer.h"
#include "OLED.h"


uint8_t TIM_TypeDef_to_NVIC_IRQChannel(uint32_t TIMx){
	uint8_t timx = TIM2_IRQn;
	TIMx -= APB1PERIPH_BASE;
	while(TIMx > 0){
		TIMx-=0x400;
		timx++;
	}
	return timx;
}


void C9Timer_init(TIM_TypeDef* TIMx,
	uint16_t TIM_Period,uint16_t TIM_Prescaler){
	// 使能定时器
  uint32_t rcc = C9_Address_to_RCC_APB1Periph((uint32_t)TIMx);
	RCC_APB1PeriphClockCmd(rcc,ENABLE);
	// 配置时钟源 TIM_ETRClockMode2Config 外部时钟信号
	TIM_InternalClockConfig(TIMx);
	
	//配置时基单元
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period = TIM_Period;
	TIM_TimeBaseInitStructure.TIM_Prescaler = TIM_Prescaler;
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIMx, &TIM_TimeBaseInitStructure);
	
	
	//使能定时器
	TIM_Cmd(TIMx,ENABLE);
}
	
void C9Timer_setPrescaler(TIM_TypeDef* TIMx,uint16_t prescaler){
	TIM_PrescalerConfig(TIMx,prescaler,TIM_PSCReloadMode_Immediate);
}

void C9Timer_enable_IT_Update(TIM_TypeDef* TIMx,
	uint8_t preemptionPriority, uint8_t subPriority){
	//清除手动中断
	TIM_ClearFlag(TIMx,TIM_FLAG_Update);
		
	//使能更新中断
	TIM_ITConfig(TIMx,TIM_IT_Update,ENABLE);
	
	//初始化 NVIC
	NVIC_PriorityGroupConfig(GLOBAL_NVIC_PRIORITYGROUP);
	NVIC_InitTypeDef NVIC_InitStruct;
	NVIC_InitStruct.NVIC_IRQChannel = TIM_TypeDef_to_NVIC_IRQChannel((uint32_t)TIMx);
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = preemptionPriority;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = subPriority;
	NVIC_Init(&NVIC_InitStruct);
}
