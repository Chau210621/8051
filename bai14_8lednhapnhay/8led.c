#include"main.h"
#include"..\Lib\Delay.h"

#define LED_PORT P2

void SangDanTatDan8LED()
{
	unsigned char i;
	LED_PORT = 0x00;
	
	for(i = 0; i < 8; i++)
	{
		 LED_PORT = (LED_PORT << 1) | 0x01;
		 Delay_ms(200);
	}
	LED_PORT = 0x00;
	for(i =0 ; i < 8 ; i++)
	{
		LED_PORT = (LED_PORT >> 1) | 0x80;
		Delay_ms(200);
	}
}
/// 1010// 0101
void ChopTatXenKe()
{
	unsigned char i;
	for(i = 0; i < 7; i++)
	{
		LED_PORT = 0xAA;
		Delay_ms(200);
		LED_PORT = 0x55;
		Delay_ms(200);
	}
}



void main()
{
	
	while(1)
	{
		SangDanTatDan8LED();	
		ChopTatXenKe();
	}
}
