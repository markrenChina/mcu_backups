#include "button.h"
#include "public.h"


unsigned char key(){
	unsigned char keyNumber = 0;
	
	if(P3_1 == 0) { delay_ms(20); while(P3_1==0) delay_ms(20); keyNumber=1;}
	if(P3_0 == 0) { delay_ms(20); while(P3_0==0) delay_ms(20); keyNumber=2;}
	if(P3_2 == 0) { delay_ms(20); while(P3_2==0) delay_ms(20); keyNumber=3;}
	if(P3_3 == 0) { delay_ms(20); while(P3_3==0) delay_ms(20); keyNumber=4;}
	
	return keyNumber;
}