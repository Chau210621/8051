#include"main.h"
#include"..\Lib\Delay.h"
#include"..\Lib\74hc595.h"

unsigned char code Code7seg[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};



void main()
{
	unsigned char i , buffer[2];
	while(1)
	{
		for(i = 0; i < 99; i++)
		{ 
			buffer[0] = Code7seg[i%10];
			buffer[1] = Code7seg[i/10];
			ShiftOut(buffer,2);
			delay(500);
		}
		
	}
}