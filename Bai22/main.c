#include"main.h"
#include"..\Lib\Delay.h"
#include"port.h"

bit PressedFlag = 0;//ep co

unsigned char KiemTraButton()
{
	unsigned char i;
	for(i = 0; i < 50; i++){
		Delay_ms(10);
		if(button == 0)
		{
			if(PressedFlag == 0){
				PressedFlag = 1;
				return 1;
			}
		}
		else
		{
			PressedFlag = 0 ;
		}
	}
	return 0;
}

void main(){
	unsigned char i;
	while(1){
		
		led = 0x00;
		for(i = 0; i < 10 ; i++){
			led = ~led;
			if(KiemTraButton())
				break;
		}
		//Hieu ung 2
		led = 0x55;
		for(i = 0; i < 10; i++){
			if(KiemTraButton())
				break;
			led = ~led;
		}
		//Hieu ung 3
		led = 0x0F;
		for(i =0; i < 10; i++){
			if(KiemTraButton())
				break;
			led = ~led;
		}
	}
}