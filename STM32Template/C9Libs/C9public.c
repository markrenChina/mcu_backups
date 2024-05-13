#include "C9public.h"

uint32_t C9_Address_to_RCC_APB2Periph(uint32_t registerAddress){
	uint32_t rcc = RCC_APB2Periph_AFIO;
	registerAddress -= AFIO_BASE;
	while(registerAddress > 0){
		rcc <<= 1;
		registerAddress-=0x400;
	}
	return rcc;
}

//todo 调用这个函数影响 OLED 显示
uint32_t C9_Address_to_RCC_APB1Periph(uint32_t registerAddress){
	uint32_t rcc = RCC_APB1Periph_TIM2;
	registerAddress -= TIM2_BASE;
	while(registerAddress > 0){
		rcc <<= 1;
		registerAddress-=0x400;
	}
	return rcc;
}

uint8_t C9_GPIO_Pin_to_GPIO_PinSource(uint16_t GPIO_Pin){
	uint8_t pow = GPIO_PinSource0;
	while((GPIO_Pin > 1) && !(GPIO_Pin & 0x0001)){
		GPIO_Pin >>=1 ;
		pow++;
	}
	return pow;
}

