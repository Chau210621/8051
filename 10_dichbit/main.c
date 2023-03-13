#include<REGX52.h>

delay(unsigned int t)
{
	unsigned int x, y;
	for(x =0 ; x < t; x++)
	{
		for(y = 0; y < 123 ; y ++);
	}
}


void main()
{
	unsigned char a , i;//8bit
	signed char b;//8bit co dau
	
	while(1)
	{
		b = 0x80;//1000 0000
		P0 = b;
		for(i = 0 ; i < 8 ; i ++)
		{
			delay(500);
			b = b >> 1;
			P0 = b;
		}
	}
	
}
