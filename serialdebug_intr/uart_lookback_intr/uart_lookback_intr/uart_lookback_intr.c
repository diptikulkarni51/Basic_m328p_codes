/*
 * uart_lookback_intr.c
 *
 * Created: 8/4/2015 2:34:03 PM
 *  Author: DipTi
 */ 


#include <avr/io.h>
#include "lib/serial.h"
#include "string.h"

extern  char rx_byte;
extern volatile bool is_rx_done;
extern char tx_byte;
extern volatile bool is_tx_done;

int main(void){
	int count=0;
	char p[7] = "dipti\0";
	
	serial_init(MYUBRR);

    while(1){
		count=0;
		
		while( arrary[count] != '\0' ){
			
			while(serial_tx(arrary[count]) != success );
			_delay_ms(500);
			count++;
		
			}			 
	
		}	
	
	}
	
}



count = 0;
		while(s[count]!='\0'){
			send_to_debug(s[count]);
			_delay_ms(500);
			count++;

