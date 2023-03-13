#include <REGX52.H>


void delay()
{
     unsigned int i;
        for(i=0;i<1000000;i++);
                
 }
void main(void) 
{
		P1_0= 0x00;	
		delay();
		P1_0 = 0xff;
		delay();
}

