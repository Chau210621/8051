#include"main.h"


unsigned char t = 10;


int main (void)
{
	TMOD &= 0xF0;
	TMOD |= 0x01;
	
	TH0 = 0x3C;
	TL0 = 0XB0;
	
	ET0 = 1; // CHO PHEP NGAT TIMER 0
	EA = 1; // cho phep ngat toan cuc
	TR0 = 1;
	
	while(1)
	{
		
		
	}
	
}


void Timer0Overflow(void) interrupt 1
{
	
		TH0 = 0x3C;
		TL0 = 0XB0;
		t--;
		if(t == 0)
		{
			t = 10;
			P2 = ~P2;
		}
	
}