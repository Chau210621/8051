#include"main.h"
#include"..\Lib\Soft_I2c.h"
#include"..\Lib\Delay.h"
#include <intrins.h>
#include"..\Lib\Port.h"

unsigned char slave_add = 0x4E;


void Lcd_Write_Cmd(unsigned char cmd)
{
	unsigned char cmd_l, cmd_h;
	cmd_l = (cmd << 4) & 0xF0;// dich 4 bit cuoi len, clean 4 bit dau di
	cmd_h = cmd & 0xF0; //clean 4 bit cuoi di
	
	/* Lcd can 1 xung EN de day du lieu vao
	*Voi che do 4 bit thi day 4 bit dau vao trc
	*Voi 1 xung tu EN du lieu tu 4 chan se duoc gui vao
	4 bit data day vao sau  */
	Soft_I2c_Start(); //BL EN RW RS 1 1 0 0
	Soft_I2c_Write(slave_add); //gui dia chi co ic
	Delay_ms(1);
	Soft_I2c_Write(cmd_h | 0x0C); //xxxx 1100:xxxx data muon gui 
	Delay_ms(1);
	Soft_I2c_Write(cmd_h | 0x08);
	Delay_ms(1);
	Soft_I2c_Write(cmd_l | 0x0C); //xxxx 1100:xxxx data muon gui  
	Delay_ms(1);
	Soft_I2c_Write(cmd_l | 0x08);
	Delay_ms(1);
	Soft_I2c_Stop();
}

void Lcd_Write_Data(unsigned char dat)
{
	unsigned char dat_l, dat_h;
	dat_l = (dat << 4) & 0xF0;
	dat_h = (dat & 0xF0);
	
	Soft_I2c_Start(); //BL EN RW RS 1 1 0 1
	Soft_I2c_Write(slave_add); //gui dia chi co ic
	Soft_I2c_Write(dat_h | 0x0D);  
	Soft_I2c_Write(dat_h | 0x09);
	Soft_I2c_Write(dat_l | 0x0D); //xxxx 1100:xxxx data muon gui 
	Soft_I2c_Write(dat_l | 0x09);
	Soft_I2c_Stop();
}

void Lcd_Write_String(unsigned char *p)
{
	while(*p != '\0')
	{
		Lcd_Write_Data(*p++);//*dat++ = dat[i++]
	}
	
}

void Lcd_Clear()
{
	Lcd_Write_Cmd(0x01);
	Delay_ms(1);
}

void Lcd_Init()
{
	Lcd_Write_Cmd(0x02);	// Return home
	Lcd_Write_Cmd(0x28);	// 4 bit mode
	Lcd_Write_Cmd(0x0C);	// Display On , cursor off
	Lcd_Write_Cmd(0x06);	
	Lcd_Write_Cmd(0x01); // clear display
}

void LCD_Gotoxy (int col, int row)
{
	int pos_Addr;
	if(row == 1) 
	{
		pos_Addr = 0x80 + row - 2 + col;
	}
	else
	{
		pos_Addr = 0x80 | (0x40 + col - 1);
	}
	Lcd_Write_Cmd(pos_Addr);
}



void main()
{
	// 1000 0101 // cho phep ngat ngoai 1 va 0
	IE = 0x84;
	//IT0 = 0;//CHO PHEP NGAT THEO SUON AM
	IT1 = 0;
	LED1 = LED2 = LED3 = LED4 = 0;
	Lcd_Init();
	LCD_Gotoxy(1,1);
	Lcd_Write_String("Ngat ngoai 8");
	while(1)
	{
		
		//PCON |= 0x01;//che do ngu
	}
}

/* ngat ngoai 0 */
/*

void ISR0(void) interrupt 0
{
	LED1 = !LED1;
	Lcd_Clear();
	LCD_Gotoxy(1,1);
	Lcd_Write_String("Ngat ngoai 0");
	Delay_ms(2000);
}
*/
void ISR1(void) interrupt 2
{
	LED2 = !LED2;
	Lcd_Clear();
	LCD_Gotoxy(1,1);
	Lcd_Write_String("Ngat ngoai 1");
	Delay_ms(2000);
}
