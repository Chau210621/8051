#include"main.h"
#include"..\Lib\Delay.h"

/* -----------------------------
		UART Che do mode 0
		application: mo rong ngo ra 
	----------------------------------- */
sbit Pin_Clock = P3^2;

void Uart_Write_Data(unsigned char dat)
{
	SBUF = dat;
	
	while( TI == 0 );
	TI = 0;
	
	Pin_Clock = 0;
	Pin_Clock = 1;
}


int main(void)
{
	/* CHE DO 0 */
	unsigned char i, j,b;
	SM0 = SM1 = 0;
	while(1)
	{
		for(i = 0; i < 5; i++)
		{
			Uart_Write_Data(0xff);
			Delay_ms(300);
			Uart_Write_Data(0x00);
			Delay_ms(400);
		}
		for(j = 0; j < 5; j++)
		{
			Uart_Write_Data(0xAA);//1010
			Delay_ms(300);
			Uart_Write_Data(0x55);//0101
			Delay_ms(300);
		}
		for(j = 0; j < 8; j++)
		{
			b = 0x01;
			b <<= j;
			Uart_Write_Data(b);//1010
			Delay_ms(300);
		}
		for(j = 0; j < 8; j++)
		{
			b = 0x80;
			b >>= j;
			Uart_Write_Data(b);//1010
			Delay_ms(300);
		}
		for(j = 0; j < 8; j++)
		{
			b = (b << 1) | 0x01;
			Uart_Write_Data(b);//1010
			Delay_ms(300);
		}
		b = 0;
		for(j = 0; j < 8; j++)
		{
			b = (b >> 1) | 0x80;
			Uart_Write_Data(b);//1010
			Delay_ms(300);
		}
		
	}
	
}



// 0000 0000 >>>> 0000 0001