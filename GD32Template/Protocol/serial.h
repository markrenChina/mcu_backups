#ifndef __SERIAL_H
#define __SERIAL_H

#include "gd32e23x.h"
//#include "gd32e23x_usart.h"

void serial_begin();

void usart_send_data(uint8_t ucch);
void usart_send_String(char* ucstr);

#endif 