/*
 * uart.h
 *
 * Created: 8/27/2015 7:34:32 PM
 *  Author: DipTi
 */ 


#ifndef UART_H_
#define UART_H_

#include "util/delay.h"
#include "avr/io.h"
#include "string.h"
#include "stdbool.h"
#include "avr/interrupt.h"

#define DELIM1	0x0D
#define DELIM2	'\n'

typedef enum  {success=1,fail=0} State;  
	
#define FOSC 16000000 // Clock Speed
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1


State uart_tx(char tx);
State uart_rx(char *rx);
void uart_init(int UBRR);
void send_to_debug(char c);
void vRcvByte(char cByte);


#endif /* UART_H_ */