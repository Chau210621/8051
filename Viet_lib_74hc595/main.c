#include"main.h"
#include"..\Lib\Delay.h"
#include"..\Lib\74hc595.h"

void main()
{
	unsigned char buffer[2];
	unsigned char i, j;
	while(1)
	{
		for(i = 0; i < 2; i++)
		{
			for(j = 0; j < 8;j++)
			{
				buffer[i] = (buffer[i]<<1)|0x01;
				ShiftOut(buffer, 2);
				delay(500);
			}
		}
	}
}
