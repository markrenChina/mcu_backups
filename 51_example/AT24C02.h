#ifndef __AT24C02_H_
#define __AT24C02_H_

#include <REGX52.H>
#include "I2C.h"
#include "public.h"

#define AT24C02_ADDRESS 0xA0

void AT24C02_writeByte(u8 address,u8 var);

u8 AT24C02_readByte(u8 address);

#endif