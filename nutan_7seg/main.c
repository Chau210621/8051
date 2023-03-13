#include <REGX52.H>

unsigned char code Code7seg[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
#define led P0
sbit button =  P1^0;

void delay(unsigned int t)
{
	unsigned char x,y;
	for(x =0; x < t; x++)
	{
		for(y = 0; y < 123; y++);
	}
}
void main(){
	random(1, 3);
}
	
