#include"main.h"
#include"..\Lib\Lcd4.h"
#include"..\Lib\Delay.h"


int main()
{
	unsigned char  b;
	unsigned int  V_adc; 
	Lcd_Init();
	
	
	while(1)
	{
		if(P3_0)
		{		
				P2 = 255;
			while(P3_0 != 0)
			{
				--P2 ;
				Delay_ms(10);
			}
		}else
		{
			P2 = 0;
			while(P3_0 == 0)
			{
				++P2;
				Delay_ms(10);
				
			}
		}
			b = P2;
			V_adc = b*1.953125f;
			
			Lcd_Chr(1, 1, V_adc/100+0x30);
			Lcd_Chr_Cp(V_adc%100/10+0x30);
			Lcd_Chr_Cp(V_adc%10+0x30);
			
			
	}

}