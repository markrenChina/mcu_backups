#ifndef __XPT2046_H_
#define __XPT2046_H_

#include <REGX52.H>
#include "public.h"

#define APT2046_XP  	0x9C
#define APT2046_YP  	0xDC
#define APT2046_VBAT  0xAC
#define APT2046_AUX   0xEC

sbit XPT2046_CS=P3^5;
sbit XPT2046_DCLK=P3^6;
sbit XPT2046_DIN=P3^4;
sbit XPT2046_DOUT=P3^7;

u16 XPT2046_readAD(u8 cmd);


#endif