#include "public.h"

/*******************************************************************************
* 函 数 名       : delay_10us
* 函数功能		 : 延时函数，ten_us=1时，大约延时10us
* 输    入       : ten_us
* 输    出    	 : 无
*******************************************************************************/
void delay_10us(u16 ten_us)
{
	while(ten_us--);	
}

/*******************************************************************************
* 函 数 名       : delay_ms
* 函数功能		 : ms延时函数，ms=1时，大约延时1ms
* 输    入       : ms：ms延时时间
* 输    出    	 : 无
*******************************************************************************/
void delay_ms(u16 ms)
{
	u16 i,j;
	for(i=ms;i>0;i--)
		for(j=110;j>0;j--);
}


void u8ToChar(unsigned char value, char *str) {
    str[0] = value / 100 + '0';     // 百位数字
    str[1] = (value / 10) % 10 + '0';// 十位数字
    str[2] = value % 10 + '0';       // 个位数字
    str[3] = '\0';                   // 字符串终止符
}

void u16ToChar(u16 value, char *str){
	u16 temp,divisor;
	u8 i = 0;
	for(divisor=10000;divisor>0;divisor = divisor/10){
		temp = value / divisor;
		if(i > 0 || temp > 0){
			str[i] = temp % 10 + '0';
			i++;
		}
	}
  str[i] = '\0';                   			// 字符串终止符
}

void u8ToHexChar(unsigned char value, char *str){
	str[0] = ((value >> 4 )&0x0F) + '0'; 
	str[1] = (value&0x0F) + '0'; 
	str[2] = '\0'; 
}


u8 bcdToDec(u8 bcd){
	return (bcd/16*10 + bcd%16);
}
u8 decToBcd(u8 dec){
	return (dec/10*16 + dec%10);
}
