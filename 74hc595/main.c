#include"main.h"
#include"..\Lib\Delay.h"

//dich 0x56 0101 0110  
sbit shift_clock = P2^0;
sbit latch_clock = P2^2;
sbit serial_data = P2^1;

void shiftOut(unsigned char *p, unsigned char n)
{
	unsigned char i, j, b;
	for(j = 0; j < n; j++)
	{
		b = *(p+n-j-1); //Lay byte cao nhat truoc
	
		for(i = 0; i < 8; i++)
		{
			serial_data = b & (0x80 >> i);
			
			shift_clock = 0;
			shift_clock = 1;
		}
	}
	latch_clock = 0;
	latch_clock = 1;
}

void main()
{
	// shiftOut(0x56);
	unsigned char buffer[2], i;
	while(1)
	{ 
		for(i = 0; i < 2; i++)
		{
			buffer[i] = 0;
		}
		shiftOut(buffer, 2);
		delay(500);
		
		for(i =0; i < 2; i++)
		{
			buffer[i] = 0xff;
		}
		shiftOut(buffer, 2);
		delay(500);
	}
}
