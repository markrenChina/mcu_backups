#include "lcd1602.h"


/*******************************************************************************
* 函 数 名       : lcd1602_write_cmd
* 函数功能		 : LCD1602写命令
* 输    入       : cmd：指令
* 输    出    	 : 无
*******************************************************************************/
#if (LCD1602_4OR8_DATA_INTERFACE==0)//8位LCD
void lcd1602_write_cmd(u8 cmd)
{
	LCD1602_RS=0;//选择命令
	LCD1602_RW=0;//选择写
	LCD1602_E=0;
	LCD1602_DATAPORT=cmd;//准备命令
	delay_ms(1);
	LCD1602_E=1;//使能脚E先上升沿写入
	delay_ms(1);
	LCD1602_E=0;//使能脚E后负跳变完成写入	
}
#else	//4位LCD
void lcd1602_write_cmd(u8 cmd)
{
	LCD1602_RS=0;//选择命令
	LCD1602_RW=0;//选择写
	LCD1602_E=0;
	LCD1602_DATAPORT=cmd;//准备命令
	delay_ms(1);
	LCD1602_E=1;//使能脚E先上升沿写入
	delay_ms(1);
	LCD1602_E=0;//使能脚E后负跳变完成写入
	
	LCD1602_DATAPORT=cmd<<4;//准备命令
	delay_ms(1);
	LCD1602_E=1;//使能脚E先上升沿写入
	delay_ms(1);
	LCD1602_E=0;//使能脚E后负跳变完成写入	
}
#endif

/*******************************************************************************
* 函 数 名       : lcd1602_write_data
* 函数功能		 : LCD1602写数据
* 输    入       : dat：数据
* 输    出    	 : 无
*******************************************************************************/
#if (LCD1602_4OR8_DATA_INTERFACE==0)//8位LCD
void lcd1602_write_data(u8 dat) 
{
	LCD1602_RS=1;//选择数据
	LCD1602_RW=0;//选择写
	LCD1602_E=0;
	LCD1602_DATAPORT=dat;//准备数据
	delay_ms(1);
	LCD1602_E=1;//使能脚E先上升沿写入
	delay_ms(1);
	LCD1602_E=0;//使能脚E后负跳变完成写入		
}
#else
void lcd1602_write_data(u8 dat) 
{
	LCD1602_RS=1;//选择数据
	LCD1602_RW=0;//选择写
	LCD1602_E=0;
	LCD1602_DATAPORT=dat;//准备数据
	delay_ms(1);
	LCD1602_E=1;//使能脚E先上升沿写入
	delay_ms(1);
	LCD1602_E=0;//使能脚E后负跳变完成写入
	
	LCD1602_DATAPORT=dat<<4;//准备数据
	delay_ms(1);
	LCD1602_E=1;//使能脚E先上升沿写入
	delay_ms(1);
	LCD1602_E=0;//使能脚E后负跳变完成写入		
}
#endif

/*******************************************************************************
* 函 数 名       : lcd1602_init
* 函数功能		 : LCD1602初始化
* 输    入       : 无
* 输    出    	 : 无
*******************************************************************************/
#if (LCD1602_4OR8_DATA_INTERFACE==0)//8位LCD
void lcd1602_init(void)
{
	lcd1602_write_cmd(0x38);//数据总线8位，显示2行，5*7点阵/字符
	lcd1602_write_cmd(0x0c);//显示功能开，无光标，光标闪烁
	lcd1602_write_cmd(0x06);//写入新数据后光标右移，显示屏不移动
	lcd1602_write_cmd(0x01);//清屏	
}
#else
void lcd1602_init(void)
{
	lcd1602_write_cmd(0x28);//数据总线4位，显示2行，5*7点阵/字符
	lcd1602_write_cmd(0x0c);//显示功能开，无光标，光标闪烁
	lcd1602_write_cmd(0x06);//写入新数据后光标右移，显示屏不移动
	lcd1602_write_cmd(0x01);//清屏	
}
#endif

/*******************************************************************************
* 函 数 名       : lcd1602_clear
* 函数功能		 : LCD1602清屏
* 输    入       : 无
* 输    出    	 : 无
*******************************************************************************/
void lcd1602_clear(void)
{
	lcd1602_write_cmd(0x01);	
}

void lcd1602_show_char(u8 x,u8 y,char c){
	y = y%2;
	lcd1602_write_cmd(0x40*y+0x80+x);
	lcd1602_write_data(c);//显示内容
}

/*******************************************************************************
* 函 数 名       : lcd1602_show_string
* 函数功能		 : LCD1602显示字符
* 输    入       : x,y：显示坐标，x=0~15，y=0~1;
				   str：显示字符串
* 输    出    	 : 无
*******************************************************************************/
void lcd1602_show_string(u8 x,u8 y,u8 *str)
{
	u8 i=0;
	if(y>1||x>15)return;//行列参数不对则强制退出
	
	while(*str!='\0')//字符串是以'\0'结尾，只要前面有内容就显示
	{
		if(i<16-x)//如果字符长度超过第一行显示范围，则在第二行继续显示
		{
			lcd1602_show_char(x+i,y,*str);//第y行显示地址设置	
		}
		else
		{
			lcd1602_show_char(x+i-16,y+1,*str);//第二行显示地址设置	
		}
		str++;//指针递增
		i++;	
	}					
}
