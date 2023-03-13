#include"Keypad4x4.h"
#include"main.h"
#include"port.h"

unsigned char KeyPress()
{
	unsigned char key = 0;
	
	//Cho cot 1 = 0;
	col_1 = 0;
	if (row_1 == 0) key = 13;
	if (row_2 == 0) key = 9;
	if (row_3 == 0) key = 5;
	if (row_4 == 0) key = 1;
	col_1 = 1;
	//cho cot 2 = 0;
	col_2 = 0;
	if (row_1 == 0) key = 14;
	if (row_2 == 0) key = 10;
	if (row_3 == 0) key = 6;
	if (row_4 == 0) key = 2;
	col_2 = 1;
	//cho cot 3 = 0;
	col_3 = 0;
	if (row_1 == 0) key = 15;
	if (row_2 == 0) key = 11;
	if (row_3 == 0) key = 7;
	if (row_4 == 0) key = 3;
	col_3 = 1;
	//cho cot 4  = 0
	col_4 = 0;
	if (row_1 == 0) key = 16;
	if (row_2 == 0) key = 12;
	if (row_3 == 0) key = 8;
	if (row_4 == 0) key = 4;
	col_4 = 1;
	return key;
}