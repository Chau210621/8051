#include"main.h"
#include"..\Lib\Delay.h"
#include"..\Lib\Uart_Mode1.h"

sbit BNT_ON = P1^0;
sbit BNT_OFF = P1^1;

void main(void)
{
	Uart_Init();
	
	while(1)
	{
		if(BNT_ON == 0)
		{
			Delay_ms(20);
			Uart_Send(0x01);
			while(BNT_ON == 0);
		}
		
		if(BNT_OFF == 0)
		{
			Delay_ms(20);
			Uart_Send(0x00);
			while(BNT_OFF == 0);
		}
	}
	
}