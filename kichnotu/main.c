#include"main.h"
#include"..\Lib\Delay.h"

unsigned char code Code7seg[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
sbit pnp = P2^0;
sbit button = P1^0;

#define led P0

void main()
{
	unsigned char i ;
	while(1)
	{
		if(button == 0)
		{
			delay(20);
			if(button == 0)
			{
				for(i = 0; i < 10; i++)
				{
					led = Code7seg[i];
					delay(500);
				}
				pnp = 0;
			}
		}
	}
}
