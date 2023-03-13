#include"main.h"
#include"..\Lib\Delay.h"





int main(void)
{
	
	unsigned char b, i;
	
	while(1)
	{
		while(P3_2);
		b = 0;
		
		for(i = 0; i < 8; i++)
		{
			b <<= 1;
			Delay_ms(2);
			if(P3_2)
			{	
				b |= 0x01;
				
			}
			else
			{
				while(P3_2 == 0);	
				
			}
			if(i!=7) while(P3_2);
		}
		P2 = b;
	}
	
}