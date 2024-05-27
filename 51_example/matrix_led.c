#include "matrix_led.h"

void _74HC595_WriteByte(unsigned char byte){
	unsigned char i;  //声明必须放在函数的最前面
	SCK = 0;
	RCK = 0;
	for(i = 0; i < 8 ; i++){
		SER = byte & (0x80 >> i);  //0x80 最高位
		SCK = 1;
		SCK = 0;
	}
	RCK = 1;
}

/*
* 0 列最左边
*/
void MatrixLED_ShowColumn(unsigned char column,val){
	_74HC595_WriteByte(val);
	MATRTX_LED_PORT = ~(0x80 >> column);
	delay_10us(20);
	MATRTX_LED_PORT = 0xFF; //位选清0
}