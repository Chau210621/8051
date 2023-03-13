#include <main.h>
#include <..\Lib\Delay.h>

/* P0 noi vao acbdef
	 P2_0 den P_5 noi vao 123456	*/

unsigned char code code7seg[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};


void Display(unsigned int n)
{
	unsigned char chuc_ngan, ngan, tram, chuc, donvi;
	// eg: 12345
	chuc_ngan = n/10000; // = 1
	n %= 10000; 	   		 // = 2345
	ngan = n/1000;			 // = 2
	n %= 1000;
	tram = n/100;
	n %= 100;
	chuc = n/10;
	donvi = n%10;
	
	/* 0 led sang || 1 led tat (vi dung cong not) */
	P0 = code7seg[chuc_ngan];
	P2_4 = 0;
	Delay_ms(1);
	P2_4 = 1; 
	
	P0 = code7seg[ngan];
	P2_3 = 0;
	Delay_ms(1);
	P2_3 = 1;
	
	P0 = code7seg[tram];
	P2_2 = 0;
	Delay_ms(1);
	P2_2 = 1;
	
	P0 = code7seg[chuc];
	P2_1 = 0;
	Delay_ms(1);
	P2_1 = 1;
	
	P0 = code7seg[donvi];
	P2_0 = 0;
	Delay_ms(1);
	P2_0 = 1;
}


int main(void)
{
	unsigned char high, low;
	unsigned char number;
	
	TMOD &= 0xF0;
	TMOD |= 0x05; // COUNTER == 1
	TR0 = 1;
	
	
	while(1)
	{
		do
		{
		high = TH0;
		low = TL0;
		}
		while(high != TH0);
		
		number = high;
		number <<= 8;
		number |= low;
		
		Display(number);
		
	}
	
}