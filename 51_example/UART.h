#ifndef __UART_H_
#define __UART_H_

void UART_Init();  //9600bps@11.0592MHz
void UART_SendByte(unsigned char byte);
void UART_RecvByte(unsigned char byte);
#endif