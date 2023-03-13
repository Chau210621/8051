#include"main.h"
#include"..\Lib\Uart_Mode1.h"


int main()
{
	char a;
	Uart_Init();
	
	
	while(1)
	{
		
			Uart_Send_String("Nhap vao ky tu in thuong: ");
			while(Uart_Data_Ready() == 0);
			
			a =  Uart_Read();
			a -= 32;
			Uart_Send_String("-->>");
			Uart_Send(a);
			Uart_Send_String("\r\n");
			
		}
		
	
	
}