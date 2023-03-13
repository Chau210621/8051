#include"main.h"
#include"..\Lib\Delay.h"

unsigned char code Code7seg[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

#define latch_1 P2_0
#define latch_2 P2_1
#define led P0

void main()
{
	unsigned char i, donvi, chuc;
	latch_1 = latch_2 = 0;
	while(1)
	{
		for(i= 0; i < 99; i++)
		{
			donvi = i%10;
			chuc = i/10;
			
				led = Code7seg[donvi];
				latch_2 = 1;
				latch_2 = 0;
				
				led = Code7seg[chuc];
				latch_1 = 1;
				latch_1 = 0;
				delay(500);
			
		}
	}
}