/*
 * i2c.c
 *
 * Created: 04-10-2015 14:44:33
 *  Author: HP-
 */ 
#include "i2c.h"
#include "avr/io.h"
#include "util/delay.h"

void init_i2c(){
	TWSR = 0X00;
	TWBR = 0X47;
	TWCR = (1<<TWEN);
}

unsigned char read_i2c(){
	TWCR = (1<<TWINT)|(1<<TWEN);
	while(!(TWCR & (1<<TWINT)));
	return TWDR;
}

void write_i2c(char ch)
{
	TWDR = ch;
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while(!(TWCR&(1<<TWINT)));
}

void start()
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while((TWCR &(1<<TWINT))==0);
}

void stop()
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
	_delay_ms(50);
}