#include <REGX52.H>
#include "matrix_led.h"

unsigned char code Aniamation[]= {
	0xFF,0x08,0x08,0xFF,0x00,0x00,0x1E,0x29,0x29,0x19,0x00,0x00,0xFF,0x01,0x03,0x00,
0x00,0xFF,0x01,0x03,0x00,0x00,0x0E,0x11,0x11,0x0E,0x00,0x00,0x3D,0x00,0x00,0x00};

void main() {
	int i,offset=5,count = 0;
	while(1){
		for(i=0; i< 8; i++){
			MatrixLED_ShowColumn(i,Aniamation[(i + offset) % sizeof(Aniamation)]);
		}
		count++;
		if(count>15){
			count=0;
			offset++;
		}
		if(offset == 200){
			offset -= 180;
		}
	}
}
