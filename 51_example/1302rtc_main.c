#include <REGX52.H>
#include "public.h"
#include "lcd1602.h"
#include "DS1302.h"

unsigned char lcdRow0[17];
unsigned char lcdRow1[17];
u8 sec = 0;

void main(){
	lcd1602_init();
	DS1302_Init();
	//DS1302_Time[5] = 30;
	DS1302_setTime();
	//DS1302_WriteByte(0x8E,0x00);
	//DS1302_WriteByte(0x80,decToBcd(0x30));
	//DS1302_WriteByte(0x80,0x30);
	while(1){
		DS1302_syncTime();
		u8ToChar(DS1302_Time[0],&lcdRow0[0]);
		lcdRow0[3] = '-';
		u8ToChar(DS1302_Time[1],&lcdRow0[4]);
		lcdRow0[7] = '-';
		u8ToChar(DS1302_Time[2],&lcdRow0[8]);
		lcd1602_show_string(0,0,&lcdRow0[0]);
		
		u8ToChar(DS1302_Time[3],&lcdRow1[0]);
		lcdRow1[3] = ':';
		u8ToChar(DS1302_Time[4],&lcdRow1[4]);
		lcdRow1[7] = ':';
		u8ToChar(DS1302_Time[5],&lcdRow1[8]);
		//sec = DS1302_ReadByte(DS1302_SEC);
		//u8ToHexChar(sec,&lcdRow1[8]);
		lcd1602_show_string(0,1,&lcdRow1[0]);
		delay_ms(300);
	}
}