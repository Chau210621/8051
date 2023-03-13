#include"..\Lib\THU_VIEN_LCD_I2C.H"
#include"main.h"
unsigned char lcd_slave_1 = 0X4E;
unsigned char lcd_slave_2 = 0X70;

void main(void)
{
	LCD_Slave(lcd_slave_1);
	LCD_Init();
	LCD_Gotoxy(2, 1);
	LCD_Send_String("Le Hong Chau");
	LCD_Gotoxy(2, 0);
	LCD_Send_String("Embedded");
}
