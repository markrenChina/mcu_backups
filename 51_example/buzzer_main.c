#include <REGX52.H>
#include "public.h"
#include "Nixie.h"
#include "button.h"
#include "Buzzer.h"
#include "Timer0.h"

unsigned char keyNum=0;
sbit m_buzzer= P2^5;

#define  music_len 42
unsigned char code music_freq[2][music_len] = {
{12,12,19,19, 21,21,19,    17,17,16,16, 14,14,12,    19,19,17,17, 16,16,14,   
 19,19,17,17, 16,16,14,    12,12,19,19, 21,21,19,    17,17,16,16, 14,14,12   },
{4,4,4,4, 4,4,8, 4,4,4,4, 4,4,8, 4,4,4,4, 4,4,8,
 4,4,4,4, 4,4,8, 4,4,4,4, 4,4,8, 4,4,4,4, 4,4,8}};

//@ 12 MHz
u16 code freq_reload[37] =  
{0,63628,63731,63835,63928,64021,64103,64185,64260,64331,64400,64463,64524,
   64580,64633,64684,64732,64777,64820,64860,64898,64934,64968,65000,65030,
   65058,65085,65110,65134,65157,65178,65198,65217,65235,65252,65268,65283};

u8 freq_select = 0;
u8 music_select = 0;

void test_key_buzzer(){
	NixieTube(1,keyNum);
	
	while(1){
		keyNum=key();
		if(keyNum){
			Buzzer_time(1000);
			NixieTube(1,keyNum);
		}
	}
}

void Timer0_per_second_callback(){
	//Buzzer=!Buzzer;
	//因为修改了，不准了
}
void Timer0_per_millsecond_callback(){
	u16 count;
	if(freq_reload[freq_select]){
		count = freq_reload[freq_select] + (freq_reload[freq_select] / 5000);
		TH0 = count >> 8;
		TL0 = count & 0xFF;
		m_buzzer=!m_buzzer;
	}
}


void main(){
	Timer0_Init();
	while(1){
		freq_select = music_freq[0][music_select];
		delay_ms(125*music_freq[1][music_select]);
		music_select++;
		TR0 = 0;
		delay_ms(5);
		TR0 = 1;
		
		if(music_select >= music_len){
			music_select = 0;
		}
		
	}
}


