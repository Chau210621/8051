#include"main.h"
#include"..\Lib\Delay.h"

sbit SPI_SCLK = P2^0;
sbit SPI_MOSI = P2^1;
sbit SPI_MISO = P2^2;
sbit SPI_CS = P2^3;

void Soft_SPI_Init();
unsigned char Soft_SPI_Read();
void Soft_SPI_Write(unsigned char b);
void EEPROM_25LCxxx_Write(unsigned int add, unsigned char b);
unsigned char EEPROM_25LCxxx_Read(unsigned int add);
unsigned char EEPROM_25LCxxx_WIP();

void main(void)
{
	Soft_SPI_Init();

	EEPROM_25LCxxx_Write(0,0x55);
	EEPROM_25LCxxx_Write(1,0xAA);
	
	P1 = EEPROM_25LCxxx_Read(0);
	
	while(1)
	{
		
	}
	
}


void EEPROM_25LCxxx_Write(unsigned int add, unsigned char b)
{
	SPI_CS = 0;
	Soft_SPI_Write(0x06);
	SPI_CS = 1;
	
	SPI_CS = 0;
	Soft_SPI_Write(0x02);
	
	/* Gui 16 address bit dia chi */
	
	 /* Gui 8 bit cao truoc */
	Soft_SPI_Write(add>>8);
	
	/* Gui 8 bit thap */
	Soft_SPI_Write(add & 0x00FF); 
	
	/* Gui 1 byte du lieu */
	Soft_SPI_Write(b);
	SPI_CS = 1;
	/* cho ghi xong roi out */
	while(EEPROM_25LCxxx_WIP());
}

void Soft_SPI_Init()
{
	SPI_CS = 1;
	SPI_SCLK = 0;	
	SPI_MISO = 1;

}

/* Doc thanh ghi trang thai */
unsigned char EEPROM_25LCxxx_WIP()
{
	unsigned char result;
	
	SPI_CS = 0;
	Soft_SPI_Write(0x05);
	result = Soft_SPI_Read();
	SPI_CS = 1;
	return result&0x01;
	
}

unsigned char EEPROM_25LCxxx_Read(unsigned int add)
{
	unsigned char b;
	SPI_CS = 0;
	Soft_SPI_Write(0x03);
	Soft_SPI_Write(add>>8);
	Soft_SPI_Write(add & 0x00FF); 
	
	b = Soft_SPI_Read();
	
	SPI_CS = 1;
	
	
	return b;
}

void Soft_SPI_Write(unsigned char b)
{
	unsigned char i;
	
	for(i=0; i < 8; i++)
	{
		if((b&0x80)==0x80)
			SPI_MOSI = 1;
		else
			SPI_MOSI = 0;
		
		SPI_SCLK = 1;
		b <<= 1;
		SPI_SCLK = 0;
		
	}
}

unsigned char Soft_SPI_Read()
{
	unsigned char i, b;
	
	for(i = 0; i < 8; i++)
	{
		b <<= 1;
		SPI_SCLK = 1;
		if(SPI_MISO)
			b |= 0x01;
		SPI_SCLK = 0;
		
	}
	
	return b;
}