#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "C9GPIO.h"
#include "C9PWM.h"
#include "C9IC.h"
#include "C9Timer.h"
#include "Delay.h"
#include "C9AD.h"
#include "C9DMA.h"

uint8_t dataA[] = {0x01,0x02,0x03,0x04};
uint8_t dataB[] = {0x00,0x00,0x00,0x00};

C9DMA dma1;

int main(void){
	OLED_Init();
	dma1.channel = DMA1_Channel1;
	dma1.size = 4;
	
	OLED_ShowString(1,1,"dataA[]");
	
	OLED_ShowHexNum(2,1,dataA[0],2);
	OLED_ShowHexNum(2,4,dataA[1],2);
	OLED_ShowHexNum(2,7,dataA[2],2);
	OLED_ShowHexNum(2,10,dataA[3],2);
	
	C9DMA_init(&dma1,&dataA[0],&dataB[0]);
	
	
	OLED_ShowString(3,1,"dataB[]");
	OLED_ShowHexNum(4,1,dataB[0],2);
	OLED_ShowHexNum(4,4,dataB[1],2);
	OLED_ShowHexNum(4,7,dataB[2],2);
	OLED_ShowHexNum(4,10,dataB[3],2);
	while(1){
		dataA[0]++;dataA[1]++;dataA[2]++;dataA[3]++;
		OLED_ShowHexNum(2,1,dataA[0],2);
		OLED_ShowHexNum(2,4,dataA[1],2);
		OLED_ShowHexNum(2,7,dataA[2],2);
		OLED_ShowHexNum(2,10,dataA[3],2);
		C9DMA_transfer_sync(&dma1);
		OLED_ShowHexNum(4,1,dataB[0],2);
		OLED_ShowHexNum(4,4,dataB[1],2);
		OLED_ShowHexNum(4,7,dataB[2],2);
		OLED_ShowHexNum(4,10,dataB[3],2);
		Delay_s(1);
		
		
	}
}

