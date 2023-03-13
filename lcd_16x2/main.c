#include"main.h"
#include"..\Lib\Delay.h"

sbit RS = P2^0;// 1 ghi  du lieu , 0 ghi lenh
sbit e_lcd = P2^1;
#define data_lcd P3

void lcd_cmd(unsigned char cmd)
{
// ham gui lenh
	RS = 0;
	data_lcd = cmd;
	e_lcd = 0;//tao xung chan e
	e_lcd = 1;
	if(cmd <= 0x02)	delay(2);
	else delay(1);
}

//ghi 1 ky tu
void lcd_chr_cp(char c)    //current position(vi tri hien tai)
{
	RS = 1; /// ghi du lieu
	data_lcd = c;
	e_lcd = 0;
	e_lcd = 1;
	delay(1);
}

// ghi 1 chuoi ki tu
void lcd_Out_cp(char *str)
{
	unsigned char i = 0;
	while(str[i]!=0)
	{
		RS = 1;
		lcd_chr_cp(str[i]);//str[i] se lay ra gia tri vd str[0] = 'H'
												//str + i se lay ra dia chi
		i++;
	}//////
}

void lcd_Setcursor(unsigned char row, unsigned char col, char *str) //cot / hang
{
	unsigned char cmd;
	cmd = (row==1?0x80:0xC0) + col - 1;
	lcd_cmd(cmd);
	lcd_Out_cp(str);
}

//khoi tao lcd
void Lcd_Init()
{
	lcd_cmd(0x30);
	delay(5);
	lcd_cmd(0x30);
	delay(1);
	lcd_cmd(0x30);
	
	lcd_cmd(0x38);//khoi tao 8 bit 2 hang 5x8 diem anh
	
	lcd_cmd(0x01); //xoa noi dung hien thi
	lcd_cmd(0x0C); //bat hien thi va tat con tro
	
}

void main()
{
	Lcd_Init();
	//lcd_chr_cp('A'); 
	lcd_Out_cp("Hello world");
	
	lcd_cmd(0xC0); // dich  con tro ve dau dong 2
	lcd_Out_cp("chau");
	lcd_cmd(0x01);
	lcd_Setcursor(1, 11, "Hello world");

	while(1)
	{
		
	}
}
