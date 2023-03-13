#include"74hc595.h"
#include"main.h"

#define pin_clock P2_0
#define pin_data P2_1
#define pin_latch P2_2

void ShiftOut(unsigned char *p, unsigned char n)
{
	unsigned char i, b, j;
	for(j = 0; j < n; j++)
	{
		b = *(p+n-j-1);//lay tu phan tu cao nhat trong mang
		
		for(i = 0; i < 8; i++)
		{
			pin_data = b & (0x80>>i);//Lay tung bit cao nhat xuat ra truoc
			pin_clock = 0;
			pin_clock = 1;
		}
	}
	pin_latch = 0;
	pin_latch = 1;
}