#include "DS18B20.h"

void DS118B20_ConverT(){
	OneWire_init();
	OneWire_SendByte(DS18B20_SKIP_ROM);
	OneWire_SendByte(DS18B20_CONVER_T);
}

float DS118B20_ReadT(){
	u8 TLSB,TMSB;
	int Temp;
	float T;
	OneWire_init();
	OneWire_SendByte(DS18B20_SKIP_ROM);
	OneWire_SendByte(DS18B20_READ_SCRATCHPAD);
	TLSB = OneWire_ReceiveByte();
	TMSB = OneWire_ReceiveByte();
	Temp = (TMSB << 8) | TLSB;
	T = Temp / 16.0;
	return T;
}