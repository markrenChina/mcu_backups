#include "Serial.h"



void serial_begin(){
	//rcu_periph_clock_enable(RCU_GPIOA);
	
	//1.1 开启时钟
	RCC_APB2PeriphClockCmd(BSP_USART_RCU,ENABLE); // 开启串口时钟
	RCC_APB2PeriphClockCmd(BSP_USART_TX_RCU, ENABLE); // 开启端口时钟
	RCC_APB2PeriphClockCmd(BSP_USART_RX_RCU, ENABLE); // 开启端口时钟
	
	//1.2 配置复用模式
	GPIO_InitTypeDef GPIO_Initstructure;
	GPIO_Initstructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Initstructure.GPIO_Pin = BSP_USART_TX_PIN;
	GPIO_Initstructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(BSP_USART_TX_PORT, &GPIO_Initstructure); 
	GPIO_Initstructure.GPIO_Pin = BSP_USART_RX_PIN;
	GPIO_Init(BSP_USART_RX_PORT,&GPIO_Initstructure); 
	
	//1.5 串口配置  
	USART_InitTypeDef UASRT_InitStruture;
	UASRT_InitStruture.USART_BaudRate = 115200;
	UASRT_InitStruture.USART_HardwareFlowControl= USART_HardwareFlowControl_None;
	UASRT_InitStruture.USART_Mode= USART_Mode_Rx | USART_Mode_Tx;
	UASRT_InitStruture.USART_Parity= USART_Parity_No;
	UASRT_InitStruture.USART_StopBits= USART_StopBits_1;
	UASRT_InitStruture.USART_WordLength= USART_WordLength_8b;
	USART_Init(BSP_USART,&UASRT_InitStruture);
	
	//1.6 使能串口
	USART_Cmd(BSP_USART,ENABLE);
}

void serial_send_byte(uint8_t ucch){
    USART_SendData(BSP_USART, ucch);  
    while(RESET == USART_GetFlagStatus(BSP_USART, USART_FLAG_TXE)); // 等待发送数据缓冲区标志置位
}

void serial_send_String(char* ucstr){   
      while(ucstr && *ucstr)  // 地址为空或者值为空跳出   
      {     
        serial_send_byte(*ucstr++);    
      }
}
