#include "C9GPIO.h"


void C9GPIO_init_ALL(C9GPIO* self,GPIO_TypeDef* GPIOx){
	C9GPIO_init_Speed(self,GPIOx,GPIO_Pin_All,GPIO_Mode_IN_FLOATING,GPIO_Speed_2MHz);
}

void C9GPIO_init_Pin(C9GPIO* self,GPIO_TypeDef* GPIOx,
	uint16_t GPIO_Pin){
	C9GPIO_init_Speed(self,GPIOx,GPIO_Pin,GPIO_Mode_IN_FLOATING,GPIO_Speed_2MHz);
}

void C9GPIO_init_Mode(C9GPIO* self,GPIO_TypeDef* GPIOx,
	uint16_t GPIO_Pin,GPIOMode_TypeDef GPIO_Mode){
	C9GPIO_init_Speed(self,GPIOx,GPIO_Pin,GPIO_Mode,GPIO_Speed_2MHz);
}

void C9GPIO_init_Speed(C9GPIO* self,GPIO_TypeDef* GPIOx,
	uint16_t GPIO_Pin,GPIOMode_TypeDef GPIO_Mode,GPIOSpeed_TypeDef GPIO_Speed){
	self->GPIOx = GPIOx;
	self->GPIO_Pin = GPIO_Pin;
		
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
		
	/*开启时钟*/
	uint32_t RCC_APB2Periph = C9_Address_to_RCC_APB2Periph((uint32_t)GPIOx);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph, ENABLE);		//开启GPIOA的时钟
	GPIO_Init(GPIOx, &GPIO_InitStruct);
}

/**
  * 函    数：GPIO 拉高
  * 参    数：无
  * 返 回 值：无
  */
void C9GPIO_on(C9GPIO* self){
	GPIO_ResetBits(self->GPIOx, self->GPIO_Pin);		//设置PA1引脚为低电平
}

/**
  * 函    数：GPIO关闭
  * 参    数：无
  * 返 回 值：无
  */
void C9GPIO_off(C9GPIO* self){
	GPIO_SetBits(self->GPIOx, self->GPIO_Pin);		//设置PA1引脚为高电平
}

/**
  * 函    数：GPIO状态翻转
  * 参    数：无
  * 返 回 值：无
  */
void C9GPIO_turn(C9GPIO* self){
	if (GPIO_ReadOutputDataBit(self->GPIOx, self->GPIO_Pin) == 0)		//获取输出寄存器的状态，如果当前引脚输出低电平
	{
		GPIO_SetBits(self->GPIOx, self->GPIO_Pin);					//则设置PA1引脚为高电平
	}
	else													//否则，即当前引脚输出高电平
	{
		GPIO_ResetBits(self->GPIOx, self->GPIO_Pin);					//则设置PA1引脚为低电平
	}
}


uint8_t C9GPIO_read(C9GPIO* self){
	return GPIO_ReadInputDataBit(self->GPIOx,self->GPIO_Pin);
}

