#include <main.h>


/* Khoi tao timer0 Mode 1*/
/* Thoi gian tran 1ms */

sbit led = P2^0;


void Delay_ms_Timer0Mode1(unsigned int t)
{
	do
	{
		TL0 = 0x18;
		TH0 = 0xFC;
		TR0 = 1;
		while(!TF0);
		TR0 = 0;
		TF0 = 0;
		t--;
	}
	while(t != 0);
	
}

void main(void)
{
	
	/* chon mode 1 16 bit */
	TMOD &= 0xF0;
	TMOD |= 0x01;
	
	while(1)
	{
		
		led = !led;
		Delay_ms_Timer0Mode1(1000);
		
	}
	
}