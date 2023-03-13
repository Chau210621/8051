#include"main.h"
#include"..\Lib\Delay.h"

sbit relay = P2^0;
sbit button = P1^0;

void main(){
	relay = 0;
	while(1){
		if(button == 0){
			Delay_ms(20);
			if(button == 0)
			{
				relay = !relay;
				while(button==0);
			}
		}
	}
}
	