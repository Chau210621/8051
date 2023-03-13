#include"main.h"
#include"..\Lib\Delay.h"


int main(){
	unsigned int dem = 0;
	unsigned char donvi, chuc, tram, tam;
	while(1){
		donvi = dem%10;
		chuc = (dem%100)/10;
		tram = dem/100;
		
		tam = chuc << 4;
		tam |= donvi;
		P2 = tam;
		P3 = tram;
		delay(300);
		
		dem++;
		dem %= 1000;
	}
	
}