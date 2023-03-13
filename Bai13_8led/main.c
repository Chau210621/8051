#include "REGX52.h"
#include "..\Lib\Delay.h"
#indlude "main.h"

#define LED_PORT P2
//0101 0101 => 1010 1010
//0x05    => 0xAA
void main()
{
	LED_PORT = 0x55;
	while(1)
	{
	Delay_ms(200);
	LED_PORT = ~LED_PORT;
	}
}