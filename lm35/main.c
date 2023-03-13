#include"main.h"
#include"..\Lib\ADC0804.h"
#include"..\Lib\LCD4.h"
#include"..\Lib\Port.h"
#include"..\Lib\Delay.h"

/* t = D*1.961 */

int main()
{
	unsigned char t, D;
	Lcd_Init();
	
	while(1)
	{
		D = ADC0804_Read();
		t = D*1.961f + 0.5f; // + 0.5 vi kieu int thi no lam tron xuong
		
		Lcd_Chr(1, 1, t/100 +  0x30);
		Lcd_Chr_Cp(t%100/10 + 0x30);
		Lcd_Chr_Cp(t%10 + 0x30);
		Delay_ms(200);
	}
	
}