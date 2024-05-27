#ifndef _public_H
#define _public_H

#include <REGX52.H>

#define BIT_HIGHT_TO_LOW(F) \
F(0x80)											\
F(0x40)											\
F(0x20)											\
F(0x10)											\
F(0x08)											\
F(0x04)											\
F(0x02)											\
F(0x01)	

#define BIT_LOW_TO_HIGHT(F) \
F(0x01)											\
F(0x02)											\
F(0x04)											\
F(0x08)											\
F(0x10)											\
F(0x20)											\
F(0x40)											\
F(0x80)

typedef unsigned int u16;	//对系统默认数据类型进行重定义
typedef unsigned char u8;
typedef unsigned long u32;

void delay_10us(u16 ten_us);
void delay_ms(u16 ms);

void u8ToChar(unsigned char value, char *str);
void u16ToChar(u16 value, char *str);
void u8ToHexChar(unsigned char value, char *str);

u8 bcdToDec(u8 bcd);
u8 decToBcd(u8 dec);
#endif
