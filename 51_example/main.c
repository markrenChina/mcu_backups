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

void main(){
//	char flag = 0;
//	while(1){
//		unsigned char mask = ~(1 << flag);
//		P2 = 0xFF & mask; //1111 1110
//		DelayMS(200);
//		P2 = 0xFF; //1111 1110
//		DelayMS(200);
//		flag++;
//		if(flag == 9){
//			flag = 0;
//		}
//	}
	P2 = 0;
	P2_0 = 0;
	while(1){
		P2_1 = 1;
		DelayMS(1000);
		P2_1 = 0;
		P2_2 = 1;
		DelayMS(1000);
		P2_2 = 0;
		P2_3 = 1;
		DelayMS(1000);
		P2_3 = 0;
	}
}