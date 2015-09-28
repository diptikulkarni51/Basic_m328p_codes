/*
 * serial_tx.c
 *
 * Created: 8/4/2015 2:38:56 PM
 *  Author: DipTi
 */ 


#include "serial.h"

char rx_byte;
volatile bool is_rx_done= false;


//void portinit(){
	//DDRB=0xff;
//}

void UARTWriteStr(char data){
			while(serial_tx(data) != success );
			_delay_ms(100);
			
}

void serial_init(uint8_t myubrr){
	cli();
	UBRR0H = (unsigned char)(myubrr>>8);
	UBRR0L = (unsigned char)myubrr;
	UCSR0B=(0<<RXCIE0)|(0<<TXCIE0);
	//enable tx and rx of uart 0.
	UCSR0B=(1<<TXEN0)|(1<<RXEN0)|(1<<RXCIE0);
	//enable interrupts
	sei();
}

decision serial_tx(char tx){
	if((UCSR0A)&(1<<UDRE0)){
		UDR0=tx;
		return success;
	}
	else
		return fail;
}

decision serial_rx(char *rx){
	if((UCSR0A) & (1<<RXC0)){
		*rx=UDR0;
		return success;
	}
	else 
		return fail;
}

ISR (USART_RX_vect){
	if((UCSR0A) & (1<<RXC0)){
		rx_byte=UDR0;
		is_rx_done= true;
	}
}

