#include"..\Lib\Delay.h"
#include"MAIN.H"


void main(void)
{
	SM0 = SM1 = 0; // Mode 0 UART
	REN = 1; // Cho phep nhan du lieu
	
	while(1)
	{
		P3_2 = 0; // tao xung chot du lieu ngo vao 74165
		P3_2 = 1
		
		RI = 0;
		while(RI == 0);
		P2 = SBUF;
	}

}

