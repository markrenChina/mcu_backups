#include <REGX52.H>
#include "lcd1602.h"

void main(){
	lcd1602_init();
	lcd1602_show_string(0,0,"Hello world");
	while(1){}
}