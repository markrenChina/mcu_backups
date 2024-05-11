#include "AT24C02.h"

void AT24C02_writeByte(u8 address,u8 var){
	//bit ack;
	I2C_start();
	I2C_sendByte(AT24C02_ADDRESS);
	I2C_recvAck();
	I2C_sendByte(address);
	I2C_recvAck();
	I2C_sendByte(var);
	I2C_recvAck();
	I2C_stop();
}

u8 AT24C02_readByte(u8 address){
	u8 var = 0;
	I2C_start();
	I2C_sendByte(AT24C02_ADDRESS);
	I2C_recvAck();
	I2C_sendByte(address);
	I2C_recvAck();
	I2C_start();
	I2C_sendByte(AT24C02_ADDRESS | 0x01);
	I2C_recvAck();
	var = I2C_recvByte();
	I2C_sendAck(0);
	I2C_stop();
	return var;
}