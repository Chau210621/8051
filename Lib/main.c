#include"main.h"
#include"Delay.h"


void main()
{
    P1_0 = 0x00;
    Delay_ms(1000);
    P1_0 = 0xff;
}