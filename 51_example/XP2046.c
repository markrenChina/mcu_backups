#include "XP2046.h"

u16 XPT2046_readAD(u8 cmd){
	u16 varH,varL;
	XPT2046_DCLK=0;
	XPT2046_CS=0;
#define XX(Bit) XPT2046_DIN=cmd&Bit;  \
	XPT2046_DCLK=1; \
	XPT2046_DCLK=0;
	
	BIT_HIGHT_TO_LOW(XX)
#undef XX
	
#define XX(Bit) XPT2046_DCLK=1;  \
	XPT2046_DCLK=0;								\
	if(XPT2046_DOUT) varH|=Bit;
	
	BIT_HIGHT_TO_LOW(XX)
#undef XX
	
#define XX(Bit) XPT2046_DCLK=1;  \
	XPT2046_DCLK=0;								\
	if(XPT2046_DOUT) varL|=Bit;
	
	BIT_HIGHT_TO_LOW(XX)
#undef XX

	XPT2046_CS=1;
	return varH;
//	return (varH << 8)& 0xFF00 + varL;
}