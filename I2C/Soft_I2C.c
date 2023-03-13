#include"main.h"
#include"port.h"
#include"intrins.h"


Soft_I2c_Delay()
{
	/* delay 1 chu ky may */
	_nop_(); _nop_(); _nop_(); _nop_();  _nop_();	
}

void Soft_I2C_Init()
{
	SOFT_I2C_SCL = 1;
	SOFT_I2C_SDA = 1;
}

void Soft_I2c_Start()
{
	SOFT_I2C_SCL = 1;
	Soft_I2c_Delay();
	SOFT_I2C_SDA = 0;
	Soft_I2c_Delay();
	SOFT_I2C_SCL = 0;	
}

bit Soft_I2c_Get_Ack()
{
	bit result;

}
