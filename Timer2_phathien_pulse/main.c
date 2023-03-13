#include"main.h"



int main(void)
{
	T2CON = 0x08;  
	T2MOD = 0x00;
	
	ET2 =1;
	EA = 1;
	
	RCAP2H = 0x3C;
	RCAP2L = 0XB0;
	
	TH2 = 0x3C;
	TL2 = 0XB0;
	
	P2 = 0x00;
	while(1)
	{
		
	}
	
}

void InterrupTimer2() interrupt 5
{
	if(1 == TF2)
	{
		TR2 = 0;
		TF2 = 0;
		P2 ++;
	}else if(1 == EXF2)
	{
		TR2 = 1;
		EXF2 = 0;
	}
	
}