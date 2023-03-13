#include"main.h"
#include"../Lib/Delay.h"



int main()
{
	unsigned char cnt = 0;
	while(1)
	{
		do
		{
			cnt++;
			P2 = cnt;
			Delay_ms(10);
		}
		while(cnt != 255);
		
		do
		{
			cnt--;
			P2 = cnt;
			Delay_ms(10);
		}
		while(cnt != 0);
	}
	
}