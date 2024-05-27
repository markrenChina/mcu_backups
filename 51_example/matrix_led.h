#ifndef __MATRIX_LED_H_
#define __MATRIX_LED_H_

#include <REGX52.H>
#include "public.h"

sbit RCK = P3^5;   //RCLK
sbit SCK = P3^6;		//SRCLK
sbit SER = P3^4;		//SER

#define MATRTX_LED_PORT  P0

void _74HC595_WriteByte(unsigned char byte);
void MatrixLED_ShowColumn(unsigned char column,val);

#endif