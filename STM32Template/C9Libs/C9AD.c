#include "C9AD.h"

uint8_t C9_ADC_to_Channel(ADC_TypeDef * ADCx,C9GPIO* gpiox){
	uint8_t pin_source = C9_GPIO_Pin_to_GPIO_PinSource(gpiox->GPIO_Pin);
	if(gpiox->GPIOx == GPIOA){
		return pin_source;
	}
	if(ADCx != ADC3){
		if(gpiox->GPIOx == GPIOC){
			return pin_source + ADC_Channel_10;
		}else {
			return pin_source + ADC_Channel_8;
		}
	}else {
		if(gpiox->GPIOx == GPIOC){
			return pin_source + ADC_Channel_10;
		}else {
			return pin_source - 6 + ADC_Channel_4;
		}
	}
}


void  C9AD_init(ADC_TypeDef * ADCx,C9GPIO* gpiox){
	// 配置ADC时钟
	RCC_APB2PeriphClockCmd(C9_Address_to_RCC_APB2Periph((uint32_t)ADCx),ENABLE);
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);
	
	// 配置GPIO
	C9GPIO_INIT(gpiox,gpiox->GPIOx,gpiox->GPIO_Pin,GPIO_Mode_AIN,GPIO_Speed_10MHz);
	// 配置菜单
	ADC_RegularChannelConfig(ADCx,C9_ADC_to_Channel(ADCx,gpiox),1,ADC_SampleTime_55Cycles5);
	
	//初始化ADC
	ADC_InitTypeDef ADC_InitStruct;
	ADC_InitStruct.ADC_Mode = ADC_Mode_Independent;
	ADC_InitStruct.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_InitStruct.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	ADC_InitStruct.ADC_ContinuousConvMode = DISABLE;  //ENABLR 连续转换，只需要触发一次
	ADC_InitStruct.ADC_ScanConvMode = DISABLE;
	ADC_InitStruct.ADC_NbrOfChannel = 1;
	ADC_Init(ADCx,&ADC_InitStruct);
	
	// ... 中断和看门狗
	
	//使能ADC
	ADC_Cmd(ADCx, ENABLE);
	
	// 校准
	ADC_ResetCalibration(ADCx);
	while(ADC_GetResetCalibrationStatus(ADCx) == SET);
	ADC_StartCalibration(ADCx);
	while(ADC_GetCalibrationStatus(ADCx) == SET);
	
}

uint16_t C9AD_getValue(ADC_TypeDef * ADCx) {
	ADC_SoftwareStartConvCmd(ADCx,ENABLE);
	while(ADC_GetFlagStatus(ADCx,ADC_FLAG_EOC) == RESET);
	return ADC_GetConversionValue(ADCx);
}
