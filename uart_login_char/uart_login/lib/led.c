/*
 * led.c
 *
 * Created: 8/27/2015 7:34:50 PM
 *  Author: DipTi
 */ 
#include "led.h"

void port_init(){
	
	DDRB =0x03;
	PORTB |=(1<<PORTB0)|(1<<PORTB1); 
}

void access_denied(uint8_t count){
	
		PORTB &= ~(1<<PORTB0);
		_delay_ms(500);
		PORTB |= (1<<PORTB0);
		
}

void authorised(uint8_t count){
		
		PORTB &= ~(1<<PORTB1);
		_delay_ms(500);
		PORTB |= (1<<PORTB1);
}

