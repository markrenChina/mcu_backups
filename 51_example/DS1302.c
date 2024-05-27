#include "DS1302.h"


unsigned char DS1302_Time[]={23,10, 28,19,00,59,6};//顺序：年月日时分秒星期

void DS1302_Init(){
	DS1302_CE = 0;
	DS1302_SCLK = 0;
//	DS1302_WriteByte(DS1302_WP,0x00);
}

void DS1302_WriteByte(unsigned char cmd,var){
	unsigned char i;
	DS1302_CE = 1;
	for(i=0;i < 8;i++){
		DS1302_IO = cmd&(0x01 << i);
		DS1302_SCLK = 1;
		DS1302_SCLK = 0;
	}
	for(i=0;i < 8;i++){
		DS1302_IO = var&(0x01 << i);
		DS1302_SCLK = 1;
		DS1302_SCLK = 0;
	}
	DS1302_CE = 0;
}

unsigned char DS1302_ReadByte(unsigned char cmd){
	//读取时是15个脉冲
	unsigned char i,var=0x00;
	cmd |= 0x01;
	DS1302_CE = 1;
	for(i=0;i < 8;i++){
		DS1302_IO = cmd&(0x01 << i);
		DS1302_SCLK = 0;
		DS1302_SCLK = 1;
	}
	for(i=0;i < 8;i++){
		DS1302_SCLK = 1;
		DS1302_SCLK = 0;
		if(DS1302_IO) { var|=(0x01 << i); }
	}
	DS1302_CE = 0;
	DS1302_IO = 0;
	return var;
}

void DS1302_setTime(){
	DS1302_WriteByte(DS1302_WP,0x00);
	DS1302_WriteByte(DS1302_YEAR,decToBcd(DS1302_Time[0]));
	DS1302_WriteByte(DS1302_MON,decToBcd(DS1302_Time[1]));
	DS1302_WriteByte(DS1302_DATE,decToBcd(DS1302_Time[2]));
	DS1302_WriteByte(DS1302_HOUR,decToBcd(DS1302_Time[3]));
	DS1302_WriteByte(DS1302_MIN,decToBcd(DS1302_Time[4]));
	DS1302_WriteByte(DS1302_SEC,decToBcd(DS1302_Time[5]));
	DS1302_WriteByte(DS1302_DAY,decToBcd(DS1302_Time[6]));
	DS1302_WriteByte(DS1302_WP,0x80);
}

void DS1302_syncTime(){
	DS1302_Time[0] = bcdToDec(DS1302_ReadByte(DS1302_YEAR));
	DS1302_Time[1] = bcdToDec(DS1302_ReadByte(DS1302_MON));
	DS1302_Time[2] = bcdToDec(DS1302_ReadByte(DS1302_DATE));
	DS1302_Time[3] = bcdToDec(DS1302_ReadByte(DS1302_HOUR));
	DS1302_Time[4] = bcdToDec(DS1302_ReadByte(DS1302_MIN));
	DS1302_Time[5] = bcdToDec(DS1302_ReadByte(DS1302_SEC));
	DS1302_Time[6] = bcdToDec(DS1302_ReadByte(DS1302_DAY));
}