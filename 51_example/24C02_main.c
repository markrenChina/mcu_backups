#include <REGX52.H>
#include "lcd1602.h"
#include "button.h"
#include "AT24C02.h"

u8 d = 0;
char dStr[]= {'1','2','3','\0'};

void main() {
	lcd1602_init();
	//lcd1602_show_string(0,0,"hello");
	//P2 = 0;
	AT24C02_writeByte(1,125);
	delay_ms(6);
	d = AT24C02_readByte(1);
	u8ToChar(d,dStr);
	lcd1602_show_string(0,0,dStr);
	while(1){
		
	};
}