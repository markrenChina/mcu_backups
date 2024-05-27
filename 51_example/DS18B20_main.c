#include <REGX52.H>
#include "LCD1602.h"
#include "DS18B20.h"

//u8 ack = 1;
float T;
char temperature[17]= {'0','0','0','0','0','0','0',
'0','0','0','0','0','0','0','0','0','\0'};
void main() {
	DS118B20_ConverT();
	delay_ms(1000);
	lcd1602_init();
	lcd1602_show_string(0,0,"Temperatue");
	//ack = OneWire_init();
	//if(ack == 1) lcd1602_show_string(0,1,"no"); else lcd1602_show_string(0,1,"ack");
	while(1){
		DS118B20_ConverT();
		T=DS118B20_ReadT();
		if(T<0){
			temperature[0] = '-';
			T = -T;
		}else {
			temperature[0] = '+';
		}
		u8ToChar((u8)T,&temperature[1]);
		temperature[4]='.';
		u16ToChar(((u16)(T*1000)%1000),&temperature[5]);
		lcd1602_show_string(0,1,temperature);
	}
}