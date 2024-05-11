#include <REGX52.H>

#include "lcd1602.h"
#include "MatrixKey.h"


void main(){
	unsigned char keyNum = 0;
	unsigned char keyNumEnd = '\0';
	lcd1602_init();
	lcd1602_show_string(0,0,"MatrixKey:");
	while(1){
		keyNum = MatrixKey();
		if(keyNum){
			keyNum +='0';
			lcd1602_show_string(0,1,&keyNum);
		}
	}
}