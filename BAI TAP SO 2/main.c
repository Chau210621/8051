#include<reg51.h>
int i, a;
unsigned int t;
sbit LED =P2^0;
sbit START = P1^0;
void delay(int t)
 { while(t--);
 }
 void main()
 {
  while(1){
  	LED =0;
  	if(START ==0){
	 delay(100);
	  if(START ==0);
	  for(a=0; a<=3; a++){
	  LED =1;
	  delay(10000);
	  LED =0;
	  delay(10000);
	  }
	}
	}
	
	if
}
	
