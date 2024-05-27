#include <REGX52.H>
#include "lcd1602.h"

char num = '0';

void main(){
	lcd1602_init();
	lcd1602_show_string(0,0,"hello");
	Int0_init();
	
	while(1){
		lcd1602_show_char(0,1,num);
	}
}

void Int0_Routine() interrupt 0{
	num++;
}