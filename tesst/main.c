#include"regx52.h"
#include"..\Lib\Delay.h"

void main(){
	while(1)
	{
		P2 = !P2;
		delay(1000);
	}
}