#include"main.h"
#include"..\Lib\THU_VIEN_LCD_I2C.H"
#include"..\Lib\Delay.h"

unsigned char slave_l = 0X7E;
unsigned char slave_2 = 0X70;

void main()
{
	LCD_Slave(slave_l);
	LCD_Init();
	LCD_Gotoxy(1, 1);
	LCD_Send_Data('A');	
}