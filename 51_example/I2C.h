#ifndef __I2C_H_
#define __I2C_H_

#include <REGX52.H>
#include "public.h"

//I2C 开始
void I2C_start();
//I2C 停止
void I2C_stop();


//发送一个字节
void I2C_sendByte(unsigned char byte);
//接收一个字节
u8 I2C_recvByte();
//发送应答
void I2C_sendAck(bit ack);
//接受应答 ack 0 表示成功应答
bit I2C_recvAck();

#endif