#include "oneWire.h"


sbit OneWire_DQ = P3^7;

u8 OneWire_init(){
	u8 i,ack;
	OneWire_DQ = 1;
	OneWire_DQ = 0;
	i = 228;while (--i);  //Delay 500us
	OneWire_DQ = 1;
	i = 31;while (--i);		//Delay 70us
	ack = OneWire_DQ;
	i = 228;while (--i);  //Delay 500us
	return ack;
}

void OneWire_SendBit(u8 var){
	u8 i;
	OneWire_DQ = 0;
	i=4; while(--i);			//Delay 10us
	OneWire_DQ=var;
	i=22; while(--i);			//Delay 50us
	OneWire_DQ = 1;
}

u8 OneWire_ReceiveBit(){
	u8 var,i;
	OneWire_DQ = 0;
	i=2; while(--i);			//Delay 5us
	OneWire_DQ = 1;
	i=2; while(--i);			//Delay 5us
	var = OneWire_DQ;
	i=22; while(--i);			//Delay 50us
	return var;
}

void OneWire_SendByte(u8 var){
#define XX(Bit) OneWire_SendBit(var&Bit);
	BIT_LOW_TO_HIGHT(XX);
#undef XX
}

u8 OneWire_ReceiveByte(){
	u8 var = 0x00;
#define XX(Bit) if(OneWire_ReceiveBit()) var|= Bit;
	BIT_LOW_TO_HIGHT(XX);
#undef XX
	return var;

}
