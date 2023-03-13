#include"main.h"
#include"..\Lib\Delay.h"

/*-----------------------------*-
	Khai bao cac lenh cua lcd
*-------------------------------*/
#define _LCD_CLEAR				1   		
#define _LCD_RETURN_HOME		2
#define _LCD_ENTRY_MODE			6
#define _LCD_TURN_OFF			8
#define _LCD_TURN_ON			12
#define _LCD_CURSOR_OFF			12 	  
#define _LCD_UNDERLINE_ON		14
#define _LCD_BLINK_CURSOR_ON	15
#define _LCD_MOVE_CURSOR_LEFT	16
#define _LCD_MOVE_CURSOR_RIGHT	17
#define _LCD_SHIFT_LEFT			24
#define _LCD_SHIFT_RIGHT		28
#define _LCD_4BIT_1LINE_5x7FONT	0x20
#define _LCD_4BIT_2LINE_5x7FONT	0x28
#define _LCD_8BIT_1LINE_5x7FONT	0x30
#define _LCD_8BIT_2LINE_5x7FONT	0x38
#define _LCD_FIRST_ROW			128
#define _LCD_SECOND_ROW			192

/*------------------------------------*
							START LINE
*---------------------------------------*/
void LCD_Write_High_Bit(unsigned char b);
void LCD_Write_Low_Bit(unsigned char b);
void Lcd_Delay_us(unsigned char t);
void Check_Busy();
void LCD_Init();
void Lcd_Cmd(unsigned char cmd);

/*-----------------------*
				END LINE
*-------------------------*/

/* Khai bao chan cho lcd */

sbit LCD_RS = P2^0;
sbit LCD_RW = P2^1;
sbit LCD_E = P2^2;
sbit LCD_D4 = P2^4;
sbit LCD_D5 = P2^5;
sbit LCD_D6 = P2^6;
sbit LCD_D7 = P2^7;

void LCD_Write_High_Bit(unsigned char b)
{
	/* giu nguyen bit trong cao nhat theo thu tu cac bit khac bang 0 */
	
	LCD_D7 = b & 0x80;
	LCD_D6 = b & 0x40;
	LCD_D5 = b & 0x20;
	LCD_D4 = b & 0x10;
						
}

/* LCD write 4 low order bit */

void LCD_Write_Low_Bit(unsigned char b)
{
	/* giu nguyen cac bit trong so thap theo thu tu cac bit khac bang 0 */
	
	LCD_D7 = b & 0x08;
	LCD_D6 = b & 0x04;
	LCD_D5 = b & 0x02;
	LCD_D4 = b & 0x01;
	
}

/* --------------------------*-
	 Delay micros
 -------------------------------*/
void Lcd_Delay_us(unsigned char t)
{
	while(t--);
}

/* Kiem tra co Busy Flag */

void Check_Busy()
{
	bit Busy_Flag;
	LCD_D7 = 1;
	LCD_RS = 0;
	LCD_RW = 1;	
	do
	{
		/* Doc 4 bit cao */
		
		LCD_E = 0;
		LCD_E = 1;
		Busy_Flag = LCD_D7;
		/* Doc 4 bit thap */
		
		LCD_E = 0;
		LCD_E = 1;
		
	}while(Busy_Flag);
	LCD_E = 0;
}

/* Khoi tao man hinh LCD */

void LCD_Init()
{
	LCD_RS = 0;
	LCD_E = 0;
	LCD_RW = 0;
	delay(20);	/* Delay 20 ms */
	
	LCD_Write_Low_Bit(0x03);
	LCD_E = 1;
	LCD_E = 0;
	delay(5); /* Delay 5ms */
	
	LCD_Write_Low_Bit(0x03);
	LCD_E = 1;
	LCD_E = 0;
	Lcd_Delay_us(100);
	
	LCD_Write_Low_Bit(0x03);
	LCD_E = 1;
	LCD_E = 0;
	Check_Busy();
	
	LCD_Write_Low_Bit(0x02);
	LCD_E = 1;
	LCD_E = 0;
	delay(1); 
	
	/* gui lenh khoi tao man hinh */
	Lcd_Cmd(_LCD_4BIT_2LINE_5x7FONT);
	Lcd_Cmd(_LCD_TURN_ON);
	Lcd_Cmd(_LCD_CLEAR);
	Lcd_Cmd(_LCD_ENTRY_MODE);
	
}

/*----------------------*-
	Gui lenh cho LCD
-*-----------------------*/
void Lcd_Cmd(unsigned char cmd)
{
	LCD_RW = 0;
	LCD_RS = 0;
	
	/* 4 bit cao */
	LCD_Write_High_Bit(cmd); 
	LCD_E = 1;
	LCD_E = 0;
	
	/* 4 bit thap */
	LCD_Write_Low_Bit(cmd);
	LCD_E = 1;
	LCD_E = 0;
	
	Check_Busy();
}
	
/* ---------------------
	switch(cmd)
	{
		case _LCD_CLEAR:
		case _LCD_RETURN_HOME:
			delay(2);
			break;
		default:
			Lcd_Delay_us(37);
			break;
	}
-------------------------*/


/*----------------------------*-
	Gui du lieu 1 ky tu cho LCD
*-----------------------------*/
void Lcd_Chr_Cp(unsigned char achar)
{
	LCD_RW = 0;
	LCD_RS =  1;
	LCD_Write_High_Bit(achar);
	LCD_E = 1;
	LCD_E = 0;
	
	LCD_Write_Low_Bit(achar);
	LCD_E = 1;
	LCD_E = 0;
	
	Check_Busy();
}

/*-------------------------------* 
	Gui 1 chuoi kys tu cho LCD
*--------------------------------*/
void Lcd_SetCursor(unsigned char col, unsigned char row,unsigned char achar)
{
	unsigned char Position;
	Position = (col == 1 ? 0x080 : 0xC0);
	Position +=	(row - 1);
	Lcd_Cmd(Position);
	Lcd_Chr_Cp(achar);
}

void Lcd_Out_Cp(unsigned char * str)
{
	unsigned char i = 0;
	while(str[i])
	{
		Lcd_Chr_Cp(str[i]);
	 	i++;
	}
}

void Lcd_Out(unsigned char row, unsigned char column, 
	unsigned char* text)
{
	unsigned char add;
	add = (row==1?0x80:0xC0);
	add += (column - 1);
	Lcd_Cmd(add);
	Lcd_Out_Cp(text); 
}

void main()
{
	
		LCD_Init();

		Lcd_Chr_Cp('A');
		Lcd_SetCursor(2, 1, 'b');
	
	
}