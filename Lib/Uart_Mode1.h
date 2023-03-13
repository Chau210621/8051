#ifndef _UARTMODE1_H_
#define _UARTMODE1_H_


//Khoi tao Uart Mode 1
void Uart_Init();

//Gui 1 ky tu ra uart
void Uart_Send(char c);

//Kiem tra co nhan duoc byte du lieu chua
//Tra ve 1: thi da nhan 0: chua nhan duoc
char Uart_Data_Ready();

//Doc 1 byte tu uart
char Uart_Read();

//Gui 1 string 
void Uart_Send_String(char *s);

#endif