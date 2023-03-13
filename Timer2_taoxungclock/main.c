#include"main.h"
 // tao xung 1kHz
 

int main(void)
{
	/*
	T2CON = 0x00;
	T2MOD = 0X02;
	//Tao tan so 1kHz
	RCAP2H = 0xF4;
	RCAP2L = 0x48;
	
	TR2 = 1;
	*/
	// tao xung thu phat hong ngo?i 38khz
	T2CON = 0x00;
	T2MOD = 0X02;
	//Tao tan so 1kHz
	RCAP2H = 0xFF;
	RCAP2L = 0xB1;
	
	TH2 = 0xFF;
	TL2 = 0xB1;
	
	TR2 = 1;
	
	while(1)
	{
		
		
	}
	
}