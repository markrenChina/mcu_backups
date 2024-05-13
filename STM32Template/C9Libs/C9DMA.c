#include "C9DMA.h"

void C9DMA_init(C9DMA* dma,uint32_t* src_ptr,uint32_t* dst_ptr){
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
	
	DMA_InitTypeDef  DMA_InitStructure;
	DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)src_ptr;    //源地址
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Enable;
	DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)dst_ptr;
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
	DMA_InitStructure.DMA_BufferSize = dma->size;
	DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
	DMA_InitStructure.DMA_M2M = DMA_M2M_Enable;
	DMA_InitStructure.DMA_Priority = DMA_Priority_Medium;
	DMA_Init(dma->channel,&DMA_InitStructure);
	
	//DMA_Cmd(dma->channel,DISABLE);
}

void C9DMA_transfer_sync(C9DMA* dma) {
	DMA_Cmd(dma->channel,DISABLE);
	DMA_SetCurrDataCounter(dma->channel,dma->size);
	DMA_Cmd(dma->channel,ENABLE);
	while(DMA_GetFlagStatus(DMA1_FLAG_TC1) == RESET);
	DMA_ClearFlag(DMA1_FLAG_TC1);
}
