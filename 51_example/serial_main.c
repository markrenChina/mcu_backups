#include <REGX52.H>
#include "UART.h"
#include "public.h"

void main(){
	UART_Init();
	while(1){
		//UART_SendByte(0x66);
		//delay_ms(1);
	}
}

void UART_RecvByte(unsigned char byte){
	P2 = ~byte;
}