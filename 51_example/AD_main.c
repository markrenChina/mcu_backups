#include <REGX52.H>
#include "lcd1602.h"
#include "XP2046.h"

u16 AdVar;
char lcdRow[17];

void main(){
	lcd1602_init();
	lcdRow[16] = '\0';
	lcd1602_show_string(0,0,"AD");
	while(1){
		AdVar = XPT2046_readAD(APT2046_XP);
		u8ToChar((u8)AdVar,lcdRow);
		lcd1602_show_string(0,1,lcdRow);
		delay_ms(100);
	}
}