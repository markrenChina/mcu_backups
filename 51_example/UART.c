#include <REGX52.H>
#include "UART.h"

void UART_Init(){  
	SCON = 0x50;		//8位数据,可变波特率
	PCON |= 0x80;		//使能波特率倍速位SMOD
	
	// 配置TMOD
	TMOD = TMOD & 0x7F;  //波特率不倍速
	TMOD = TMOD | 0x20;  //8位数据,可变波特率
	// 配置TCON  9600
	TL1 = 0xFD;			//设置定时初始值
	TH1 = 0xFD;			//设置定时重载值
	TR1 = 1;			//定时器1开始计时
	
	//配置中断
	ET1 = 0;			//禁止定时器中断
	EA = 1;
	ES = 1;
}

void UART_SendByte(unsigned char byte){
	SBUF = byte;
	while(TI==0);
	TI=0;
}

void UART_Routine() interrupt 4{
	if(RI == 1){
		UART_RecvByte(SBUF);
		RI=0;
	}
}