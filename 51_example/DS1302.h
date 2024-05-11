#ifndef __DS1302_H_
#define __DS1302_H_

#include <REGX52.H>
#include "public.h"

#define DS1302_SEC			0x80
#define DS1302_MIN			0x82
#define DS1302_HOUR			0x84
#define DS1302_DATE			0x86
#define DS1302_MON			0x88
#define DS1302_DAY			0x8A 
#define DS1302_YEAR			0x8C
#define DS1302_WP				0x8E

extern u8 DS1302_Time[7];

sbit DS1302_SCLK=P3^6;
sbit DS1302_IO = P3^4;
sbit DS1302_CE = P3^5;

void DS1302_Init();

void DS1302_WriteByte(u8 cmd,var);
u8 DS1302_ReadByte(u8 cmd);

void DS1302_setTime();
void DS1302_syncTime();

#endif