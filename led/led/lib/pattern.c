/*
 * pattern.c
 *
 * Created: 8/2/2015 5:39:02 PM
 *  Author: DipTi
 */ 
#include "pattern.h"


void port_init(){
	DDRB =0xFF;
	//PORTB |=(0<<PORTB1)|(0<<PORTB0);
}

void patten1(){
	PORTB &=(1<<PORTB1)|(0<<PORTB0);
	_delay_ms(100);
	PORTB &=(0<<PORTB1)|(1<<PORTB0);
}

void pattern2(){
	PORTB &=(1<<PORTB1)|(1<<PORTB0);
	_delay_ms(100);
	PORTB &=(0<<PORTB1)|(0<<PORTB0);
}

void pattern3(){
	PORTB &=(0<<PORTB1)|(1<<PORTB0);
	_delay_ms(100);
	PORTB &=(1<<PORTB1)|(0<<PORTB0);
}

void pattern4(){
	PORTB |=(1<<PORTB1)|(1<<PORTB0);
	_delay_ms(100);
	PORTB |=(0<<PORTB1)|(0<<PORTB0);
}