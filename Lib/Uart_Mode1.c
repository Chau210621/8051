#include"main.h"
#include"..\Lib\Uart_Mode1.h"

#if(FREQ_OSC != 11059200)
	#error "Thu vien UartMode1 chi ho tro toc do tan so 11059200"
#endif

void Uart_Init()
{
	SM0 = 0;  SM1 = 1;
	
	TMOD &= 0x0F;
	TMOD |= 0x20; // Timer 1 mode 2 8 bit nap lai
	#if(BAUD_RATE == 1200)
		TH1 = 0xE8; 
	#elif(BAUD_RATE == 2400)
		TH1 = 0xF4; 
	#elif(BAUD_RATE == 9600)
		TH1 = 0xFD; 
	#elif(BAUD_RATE == 19200)
		TH1 = 0xFD; 
		PCON |= 0x80;
	#else
		#error "Toc do Baud chi co the la 19200 9600 2400 1200"
	#endif
	
	TR1 = 1; // cho pheps timer chay
	TI = 1; // Co bao gui xong uart
	REN = 1; //Cho phep nhan du lieu
}

void Uart_Send(char c)
{
	while(TI == 0);
	TI = 0;	
	SBUF = c;
}

char Uart_Data_Ready()
{
	return RI; // RI bang 1 nhaan dc du lieu
}

char Uart_Read()
{
	RI = 0;
	return SBUF;
}	
	


void Uart_Send_String(char *s)
{
  char i = 0;
	while(*(s+i) != '\0')
	{
		Uart_Send(*(s+i));
		i++;
	}

}