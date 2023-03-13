#include<regx52.h>

unsigned char code Code7seg[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
#define seg P1
//sbit led = P0^0;
sbit button = P0^0;
bit pressold = 0;

void delay_ms(unsigned int t)
{ 
	unsigned int x, y;
	for(x=0 ; x<t; x++)
	{
		for(y=0 ;y < 123; y++);
	}
}

void Button(){
	if(button == 0){
			delay_ms(100);
			if(button == 0 && pressold == 0){
				//led = !led;
				pressold == 1;
				while(button == 0);
			}
		}
		if(button == 1) pressold == 0;
}

void main()
{
	unsigned char i;
	while(1)
	{
		for(i = 0; i < 10 ;i++){
			seg = Code7seg[i];
			delay_ms(1000);
		}
	}
}