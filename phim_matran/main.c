#include"main.h"
#include"..\Lib\Delay.h"
#include"..\Lib\Keypad4x4.h"
#include"port.h"

unsigned char code Code7seg[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};


void main()
{
	unsigned char key, tmp, donvi, chuc;
	while(1)
	{
		key = KeyPress();
		if(key!=0)
		{
			tmp = key;
			donvi = tmp%10;
			chuc = tmp/10;
		}
		led = Code7seg[donvi];
		port_1 = 0;
		delay(1);
		port_1 = 1;
		led = Code7seg[chuc];
		port_2 = 0;
		delay(1);
		port_2 = 1;
	}
}