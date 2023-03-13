#ifndef _PORT_H_
#define _PORT_H_

#define led P2
sbit port_1 = P3^0;
sbit port_2 = P3^1;
//ma tran phim
sbit col_1 = P1^0;
sbit col_2 = P1^1;
sbit col_3 = P1^2;
sbit col_4 = P1^3;
//hang
sbit row_1 = P1^4;
sbit row_2 = P1^5;
sbit row_3 = P1^6;
sbit row_4 = P1^7;

#endif