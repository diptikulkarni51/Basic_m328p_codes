/*
 * serial.h
 *
 * Created: 8/4/2015 2:39:22 PM
 *  Author: DipTi
 */ 


#ifndef SERIAL_H_
#define SERIAL_H_

#define FOSC 16000000 // Clock Speed
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1


#include "avr/io.h"
#include "avr/interrupt.h"
#include "util/delay.h"
#include "stdbool.h"



typedef enum {fail=0,success=1} decision;
	
void serial_init(uint8_t myubrr);
decision serial_tx(char tx);
decision serial_rx(char *rx); 
//void portinit();

void UARTWriteStr(char data);

#endif /* SERIAL_H_ */