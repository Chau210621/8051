#include <REGX52.H>

sbit LED_PIN = p0^0;
// int 16 bit 1- 65535
void Delay_ms(unsigned int t){
	unsigned int x, y;
	for(x = 0; x<t; x++)
	{
		for(y = 0; y < 123 ; y++); //t* 123
	}
}

void main()
{
	while(1)
	{
		LED_PIN = !LED_PIN;
		Delay_ms(500);
	}
}	