#include"main.h"
#include"..\Lib\Delay.h"
#include"..\Lib\Lcd4.h"
#include"..\Lib\Port.h"
#include"..\Lib\ADC0804.h"

int main()
{
	unsigned char adc_value;
	unsigned int voltage;
	
	Lcd_Init();
	
	while(1)
	{
		// adc_value tra ve 000 - 500 tuong ung voi 0 - 5V
		adc_value = ADC0804_Read();
		
		Lcd_Chr(1, 1, adc_value/100 + 0x30);
		Lcd_Chr_Cp(adc_value%100/10 + 0x30);
		Lcd_Chr_Cp(adc_value%10 + 0x30);
		
		voltage = adc_value * 19.61f;
		
    Lcd_Chr(2, 1, voltage/1000 + 0x30);
		Lcd_Chr_Cp('.');
		Lcd_Chr_Cp(voltage%1000/100 + 0x30);
		Lcd_Chr_Cp(voltage%100/10 + 0x30);
		Lcd_Chr_Cp(voltage%10 + 0x30);
		
		Delay_ms(500);
		
	}
	
}



