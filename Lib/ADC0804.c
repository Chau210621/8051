#include"main.h"
#include"ADC0804.h"
#include"port.h"

unsigned char ADC0804_Read()
{
	unsigned char kq;
	// chon chip
	ADC0804_CS = 0;
	
	//Tao xung bat dau chuyen doi
	ADC0804_WR = 0;
	ADC0804_WR = 1;
	
	// Doi cho den khi chuyen doi xong
	while(ADC0804_INTR);
	
	ADC0804_RD = 0;
	kq = ADC0804_DATA;
	ADC0804_RD = 1;
		
	return kq;
}
