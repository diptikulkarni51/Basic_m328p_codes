/*
 * serial.h
 *
 * Created: 8/4/2015 1:00:14 AM
 *  Author: DipTi
 */ 


#ifndef SERIAL_H_
#define SERIAL_H_

#include <avr/io.h>
#include <stdbool.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define fosc 16000000
#define baud 9600
#define myubrr fosc/16/baud-1

typedef enum {fail=0,success=1} decision;
	


void serial_init(uint8_t ubrr);
decision serial_tx(char tx);
decision serial_rx(char *rx);



#endif /* SERIAL_H_ */