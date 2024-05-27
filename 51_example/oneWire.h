#ifndef __ONEWIRE_H_
#define __ONEWIRE_H_

#include <REGX52.H>
#include "public.h"


u8 OneWire_init();

void OneWire_SendBit(u8 var);
u8 OneWire_ReceiveBit();

void OneWire_SendByte(u8 var);
u8 OneWire_ReceiveByte();

#endif