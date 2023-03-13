#include"main.h"
#include"..\Lib\Uart_Mode1.h"
#include"..\Lib\Delay.h"

sbit led = P1^0;

void main(void)
{
	led = 0;
	
	Uart_Init();
	
	while(1)
	{
		if(Uart_Data_Ready() == 1)
		{
			if(Uart_Read() == 0x01)
				led = 1;
			if(Uart_Read() == 0x00)
				led = 0;
		}
	}
	
}