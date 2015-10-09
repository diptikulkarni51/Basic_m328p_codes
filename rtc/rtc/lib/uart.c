/*
 * uart.c
 *
 * Created: 04-10-2015 14:39:21
 *  Author: HP-
 */ 
#include "avr/io.h"
#include "uart.h"
#include "util/delay.h"

void tx( unsigned char data )
{
	while ( !(UCSR0A & (1<<UDRE0)) ); // wait until UDR is empty
	UDR0 = data;
}

char rx()
{
	while ( !(UCSR0A & (1<<RXC0)) ); // wait until UDR is empty
	return UDR0;
}

void init_serial()
{
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	//UCSRC = (1<<UCSZ1)|(1<<UCSZ0);
	UBRR0L = 51;
}

void str_serial(char *str)
{
	while(*str)
	{
		tx(*str++);
		_delay_ms(1);
	}
}