#include <REGX52.H>
#include "pulic.h"
#include "lcd1602.h"
#include "Timer0.h"

unsigned char sec = 0;
char secStr[4];

void main(){
	Timer0_Init();
	lcd1602_init();
	lcd1602_show_string(0,0,"Clock:");
	while(1){
		u8ToChar(sec,secStr);
		lcd1602_show_string(0,1,&secStr[1]);
		delay_ms(10);
	}
}

void Timer0_Callback() {	
	sec++;
}
