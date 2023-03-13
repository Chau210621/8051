#include <REGX52.h>

//unsigned int 2byte so duong( > 0)
void delay_ms(unsigned int t){
	unsigned int x, y;
	for(x = 0; x < t; x++)
	{
		for(y = 0; y < 123; y++);
	}
}

void main(){
	
	unsigned char i ; //unsigned char 1byte
	
	while(1)
	{
		P0 = 0x00;
		for(i =0;i <8;i++)
		{
			delay_ms(300);
			P0 <<= 1;
			P0 |= 0x01;
		}	
		delay_ms(300);
		
		P0 = 0x00;
		for(i = 0; i < 8 ; i++)
		{
			delay_ms(300);
			P0 >>= 1;
			P0 |= 0x80;
		}
		delay_ms(300);
	}
}