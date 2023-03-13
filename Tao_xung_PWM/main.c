#include"main.h"
#include"..\Lib\Delay.h"

#define UP 0
#define DOWN 1


sbit PWM_PIN = P2^0;

unsigned int T, Ton, Toff;
unsigned char Ton_h_reload, Ton_l_reload, Toff_h_reload ,Toff_l_reload;

// ck (us)
void PWM_Init(unsigned int ck)
{
	PWM_PIN = 1;
	
	TMOD &= 0xF0;
	TMOD |= 0x01;
	
	ET0 = 1;
	EA = 1;
	
	T = ck; 
	Ton = T/2; // Duty cycle =  50%
	Toff = T - Ton;
	
	Ton_h_reload = (65536 - Ton) >> 8;
	Ton_l_reload = (65536 - Ton) & 0x00FF;
	
	Toff_h_reload = (65536 - Toff) >> 8;
	Toff_l_reload = (65536 - Toff) & 0x00FF;
	
	TH0 = (65536 - Ton) >> 8; 
	TL0 = (65536 - Ton) & 0x00FF;
}

void PWM_Start()
{
	TR0 = 1;
}

void PWM_Stop()
{
	TR0 = 0;
}

// :duty 0 - 100%
void PWM_Set_Duty(unsigned char duty)
{
	if(duty == 0)
	{
		PWM_PIN = 0;
		ET0 = 0;
		
	}
	else if(duty == 100)
	{
		PWM_PIN = 1;
		ET0 = 0;
	}
	else
	{
		Ton = (unsigned long)T*duty/100; //ép ki?u
		Toff = T - Ton;
		
		Ton_h_reload = (65536 - Ton) >> 8;
		Ton_l_reload = (65536 - Ton) & 0x00FF;
		
		Toff_h_reload = (65536 - Toff) >> 8;
		Toff_l_reload = (65536 - Toff) & 0x00FF;
		
		ET0 = 1;
	}
	
}

int main()
{
	
	unsigned char dir = UP, duty = 0;
	PWM_Init(1000);
	
	PWM_Set_Duty(0);
	PWM_Start();
	
	while(1)
	{
		Delay_ms(500);
		if (dir == UP)
		{
			duty += 2;
			if(duty == 100)
			{
				dir = DOWN;
			}
		}
		else
		{
			duty -= 2;
			if(duty == 0)
			{
				dir = UP;
			}
		}
		PWM_Set_Duty(duty);
		
	}
	
}


void Timer0Overflow() interrupt 1
{
	PWM_PIN = !PWM_PIN ;
	
	if(PWM_PIN == 0)
	{
		TH0 = Toff_h_reload;
		TL0 = Toff_l_reload;
	}
	else
	{ 
		TH0 = Ton_h_reload;
		TL0 = Ton_l_reload;
	}
	
}