#include"main.h"
#include"..\Lib\Delay.h"
////Dong ho so don gian
#define led P3
sbit a = P1^0;//gio
sbit b = P1^1;//gio
sbit c = P1^2;//phut
sbit d = P1^3;//phut
sbit e = P1^4;//giay
sbit f = P1^5;//giay 


unsigned char code code7seg[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};


void main(){
	unsigned char  donvi, chuc, giay, phut, gio ;
	unsigned int i;
	while(1)
	{
		giay++;
			for(i = 0; i < 166; i++)
			{
				led = code7seg[giay%10];
				f = 0;
				delay(1);
				f = 1;
				
				led = code7seg[giay/10];
				e = 0;
				delay(1);
				e = 1;
				
				if (giay == 60)
				{
					giay = 0;
					phut++;
				}
				//phut
					led = code7seg[phut%10];
					d = 0;
					delay(1);
					d = 1;
					
					led = code7seg[phut/10];
					c = 0;
					delay(1);
					c = 1;
				
				if (phut == 60)
				{
					phut = 0;
					gio ++;
				}
				// gio
				led = code7seg[gio%10];
					b = 0;
					delay(1);
					b = 1;
					
					led = code7seg[gio/10];
					a = 0;
					delay(1);
					a = 1;
			}	
		
		
					
	}
	
}