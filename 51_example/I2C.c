#include "I2C.h"

sbit I2C_SCL = P2^1;
sbit I2C_SDA = P2^0;

void I2C_start(){
	I2C_SDA = 1;
	I2C_SCL = 1;
	I2C_SDA = 0;
	I2C_SCL = 0;
}

void I2C_stop(){
	I2C_SDA = 0;
	I2C_SCL = 1;
	I2C_SDA = 1;
}

void I2C_sendByte(unsigned char byte){
	//if(I2C_SCL) I2C_SCL = 0;
#define XX(b) 		\
	I2C_SDA=byte&b; \
	I2C_SCL=1;			\
	I2C_SCL=0;
	
	BIT_HIGHT_TO_LOW(XX)
#undef XX	
}

u8 I2C_recvByte(){
	u8 res=0;
	I2C_SDA = 1;
#define XX(b) 		\
	I2C_SCL=1;			\
	if(I2C_SDA){ res |= b;}	\
	I2C_SCL=0;
	
	BIT_HIGHT_TO_LOW(XX)
#undef XX	
	return res;
}

void I2C_sendAck(bit ack){
	I2C_SDA=ack;
	I2C_SCL=1;
	I2C_SCL=0;
}

bit I2C_recvAck(){
	bit ack;
	I2C_SDA=1;
	I2C_SCL=1;
	ack = I2C_SDA;
	I2C_SCL=0;
	return ack;
}
