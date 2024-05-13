#ifndef __C9DMA_H
#define __C9DMA_H

#include "stm32f10x.h"                  // Device header


typedef struct {
	uint16_t size;
	DMA_Channel_TypeDef * channel;
}	C9DMA;

void C9DMA_init(C9DMA* dma,uint32_t* src_ptr,uint32_t* dst_ptr);

void C9DMA_transfer_sync(C9DMA* dma);

#endif
