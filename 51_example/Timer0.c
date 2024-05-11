#include <REGX52.H>
#inclde "Timer0.h"

/*
 * 初始化定时器0
*/
void Timer0_Init(){
	// 配置TMOD
	//TMOD = 0x01;  // 0000 0001
	TMOD = TMOD & 0xF0;  //保持高4位不变
	TMOD = TMOD | 0x01;
	// 配置TCON
	TF0 = 0;
	TR0 = 1;
	TH0 = 0xFC;	//64535/256;
	TL0 = 0x18; //64535%256 + 1;
	//配置中断
	ET0 = 1;
	EA = 1;
	PT0 = 0;
}

void Timer0_Routine() interrupt 1 {
	static unsigned int T0Count = 0;
	TH0 = 0xFC;
	TL0 = 0x18;
	T0Count++;
	Timer0_per_millsecond_callback();
	if(T0Count >= 1000){
		T0Count = 0;
		Timer0_per_second_callback();
	}
}