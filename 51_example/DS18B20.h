#ifndef __DS18B20_H_
#define __DS18B20_H_

#include <REGX52.H>
#include "OneWire.h"

#define DS18B20_SKIP_ROM 					0xCC
#define DS18B20_CONVER_T 					0x44
#define DS18B20_READ_SCRATCHPAD 	0xBE

void DS118B20_ConverT();
float DS118B20_ReadT();


#endif