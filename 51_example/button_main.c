#include <REGX52.H>
#include <INTRINS.H>

void Delay1ms(void)	//@11.0592MHz
{
	unsigned char data i, j;

	_nop_();
	i = 2;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
}

void DelayMS(unsigned int time){
	while(time){
		Delay1ms();
		time--;
	}
}

unsigned char LEDNum=0;

void main(){
	P2 = ~0x01;
	while (1){
		if(P3_1==0){
			DelayMS(20);
			while(P3_1==0);
			DelayMS(20);
			LEDNum++;
			if(LEDNum>=8){
				LEDNum=0;
			}
			P2 = ~(0x01 << LEDNum);
		}
	}
}