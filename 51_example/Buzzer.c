#include "Buzzer.h"

sbit Buzzer= P2^5;

void Buzzer_time(u16 ms){
	u32 i;
	for(i=0; i < ms*2; i++){
		Buzzer= !Buzzer;
		delay_10us(50);
	}
}