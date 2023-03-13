#include"main.h"
#include"port.h"
#include "..\Lib\Delay.h"
//Chong doi phim

unsigned char QuetPhimTrongDelay(){
	unsigned char i;
	for (i = 0; i <100; i++){
		Delay_ms(10);
		if(button_off == 0)
		{
			led = 0x00;
			return 1;//nhan phim stop
		}
	}
	return 0;
}


void main(){
	led = 0x00;
	while(1)
		{
			if(button_on == 0)
			{
				while(1)
				{
						led = ~led;
						if(QuetPhimTrongDelay())
						{
							break;
						}
				}
			}
		}
}

