#include"main.h"
#include"..\Lib\Delay.h"

//Do 20s xanh 15s vang 5s

//Mang phan tu led 7 don luu trong bo nho code(flash) bo nho chuong trinh;
unsigned char code Code7seg[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

sbit Do = P0^0;
sbit xanh = P0^1;
sbit vang = P0^2;
#define led_chuc P2
#define led_donvi P3

void main()
{
	signed char i;// so am
	
	while(1)
	{
		//Den do
		 Do = 0;
		 xanh = 1;
		 vang = 1;
		 for(i = 20; i >= 0; i --)
		 {
				led_chuc = Code7seg[i/10];
				led_donvi= Code7seg[i%10];
				delay(500);
		 }
		 //den xanh
		 Do = 1;
		 xanh = 0;
		 vang = 1;
		 for(i = 15; i>=0; i --)
		 {
				led_chuc = Code7seg[i/10];//15/10 = 1 du 5
				led_donvi = Code7seg[i%10];
				delay(500);
		 }
		 //den vang
		 xanh = 1;
		 vang = 0;
		 Do = 1;
		 for(i = 5; i>=0; i --)
		 {
				led_chuc = Code7seg[i/10];
				led_donvi= Code7seg[i%10];
				delay(500);
		 }
	}
}