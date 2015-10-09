/*
 * uart.c
 *
 * Created: 8/27/2015 7:34:07 PM
 *  Author: DipTi
 */ 

#include "uart.h"
#include "led.h"

char rx_byte;
volatile bool is_rx_done= false;

void uart_init(int UBRR){
	cli();
	UBRR0H = (unsigned char)(UBRR>>8);
	UBRR0L = (unsigned char)UBRR;
	UCSR0B=(0<<RXCIE0)|(0<<TXCIE0);
	//enable tx and rx of uart 0.
	UCSR0B=(1<<TXEN0)|(1<<RXEN0)|(1<<RXCIE0);
	//enable interrupts
	sei();
}

State uart_tx(char tx){
	
	if( UCSR0A & (1<<UDRE0)){
		UDR0 =tx;
		return success; 
	}
	else
		return fail;
	
}

// State uart_rx(char *rx){ // we are usng interrupt not polling
// 	
// 	if(UCSR0A & (1<<RXC0)){
// 		rx = UDR0;
// 		return success;
// 	}
// 	else 
// 		return fail;
// }


void send_to_debug(char c){
	while( uart_tx(c) != success);
}


void vRcvCharFromUART(char rxByte){
	
	switch(rxByte){
		
		case DELIM1:	/* 0x0D */
		case DELIM2:	/* \n */
			break;
			
		default:	/* Anything except Delim1 and Delim2 */
			break;
	}
}

ISR (USART_RX_vect){
	
	if((UCSR0A) & (1<<RXC0)){
		
		rx_byte=UDR0;
		is_rx_done= true;
	}
}


