/*
 * serial.c
 *
 * Created: 8/4/2015 12:59:58 AM
 *  Author: DipTi
 */ 

#include "serial.h"



void serial_init(uint8_t ubrr){
	cli();
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L =ubrr;
	UCSR0B=(0<<RXCIE0)|(0<<TXCIE0);
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	sei();
}

decision serial_tx(char tx){
	if((UCSR0A)& (1<<UDRE0)){
		UDR0 = tx;
		return success; 	
	}
	else
		return fail;
	
}

decision serial_rx(char *rx){
	if((UCSR0A)& (1<<RXC0)) {
		*rx = UDR0;
		return success;
	}
	else 
		return fail;
}