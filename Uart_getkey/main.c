#include"main.h"
#include"stdio.h"
#include"..\Lib\Uart_Mode1.h"


void main()
{
	char c;
	
	Uart_Init();
	
	putchar('A');  //Gui 1 ky tu ra cong UART
	
	printf("le hong chau") // gui 1 chuoi ra cong UART
	
	while(1)
	{
		
		c = _getkey(); // cho nhan dc du lieu 
		putchar(c);
	}

}