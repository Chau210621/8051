#include"main.h"
#include"..\Lib\Delay.h"

#define shift_clock P0_0
#define data_serial P0_1
#define latch_clock P0_2

unsigned char code font5x7[] = {0x0E, 0x11, 0x13, 0x15, 0x19, 0x11, 0x0E};

void ShiftOut(unsigned char n)
{
	unsigned char i;
	for(i = 0; i < 8; i++)
	{
		
		data_serial = n & (0x80 >> i);
		
		shift_clock = 0;
		shift_clock = 1;
	}
	
	latch_clock = 0;
	latch_clock = 1;
}


void main()
{
	unsigned char i ;
	while(1)
	{
		for(i = 0 ; i < 7; i++)
		{
			ShiftOut(font5x7[i]);
			P3 = 0x01<<i; 
			delay(1);
			P3 = 0;
		}
	}
}
