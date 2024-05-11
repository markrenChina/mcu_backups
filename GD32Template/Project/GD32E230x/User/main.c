#include "gd32e23x.h"
#include "systick.h"
#include <stdio.h>
#include "main.h"
#include "serial.h"

#include "OLED.h"


int main(void)
{
	systick_config(); //	初始化滴答定时器
	
	/*OLED初始化*/
	OLED_Init();
	
	delay_1ms(500);
	
	/*在(0, 0)位置显示字符'A'，字体大小为8*16点阵*/
//	OLED_ShowChar(0, 0, 'A', OLED_8X16);
//	OLED_ShowChar(8, 8, 'A', OLED_8X16);
//	OLED_ShowChar(16, 16, 'A', OLED_8X16);
//	OLED_ShowChar(24, 24, 'A', OLED_8X16);
	OLED_DrawCircle(32,32,16,0);
	OLED_Update();
	
	rcu_periph_clock_enable(RCU_GPIOC);
	gpio_mode_set(GPIOC, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO_PIN_13);
	gpio_output_options_set(GPIOC, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_13);
	
	gpio_bit_set(GPIOC,GPIO_PIN_13);
	
	serial_begin();
	
	usart_send_String("hello\r\n");
	
	while(1)
	{
		delay_1ms(1000);
		gpio_bit_reset(GPIOC,GPIO_PIN_13);
		delay_1ms(1000);
		gpio_bit_set(GPIOC,GPIO_PIN_13);
	}
	
	
}
