#include"main.h"
#include"..\Lib\Delay.h"


// phat xung clock 38kHz

void GuiBit(bit b)
{
	if(b)
	{
		TR2 = 1;
		Delay_ms(1);
		TR2 = 0;
		// tat chan P1_0 de tiet kiem nang luong
		P1_0 = 1;
		Delay_ms(3);
		
	}else
	{
		TR2 = 1;
		Delay_ms(3);
		TR2 = 0;
		// tat chan P1_0 de tiet kiem nang luong
		P1_0 = 1;
		Delay_ms(1);
	}
}

void GuiByte(unsigned char b)
{
	unsigned char i;
	
	for(i = 0; i < 8; i++)
	{
		GuiBit(b&0x80);
		b <<= 1;
	}
	
	
}

int main(void)
{
	unsigned char cnt;
	
	T2CON = 0x00;
	T2MOD = 0x02;
	
	RCAP2H = 0xFF;
	RCAP2L = 0xB1;
	
	TH2 = 0xFF;
	TL2 = 0xB1;
	
	
	while(1)
	{
		GuiByte(cnt);
		cnt++;
		Delay_ms(200);
	}
	
}