/*
 * uart_login.c
 *
 * Created: 8/27/2015 7:31:59 PM
 *  Author: DipTi
 */ 


#include <avr/io.h>
#include "stdio.h"
#include "lib/uart.h"
#include "lib/led.h"
#include "avr/eeprom.h"

extern char rx_byte;
extern volatile bool is_rx_done;


#define DEFPW  'a'
#define USERPW_ADDRESS	23

int main(void) {
	
	uint8_t count=0,x=15;
	uint8_t readbyte;
	
	
	unsigned char s[15]="\r\npassword:\0";
	uart_init(MYUBRR);
	port_init();
	eeprom_write_byte ((uint8_t*) USERPW_ADDRESS, DEFPW);
	readbyte = eeprom_read_byte((uint8_t*)USERPW_ADDRESS);

	while(1){
		
		
		while( s[count] != '\0' ){
			
			send_to_debug(s[count]);
			_delay_ms(25);
			count++;
		}
		count=0;
		
		while(is_rx_done != true);
		
		
		is_rx_done = false;
		
		
		
		if(rx_byte == readbyte){
			
			authorised(x);
		}
		else
			access_denied(x);
		
// 		switch(rx_byte){
// 		
// 			case readbyte: 
// 				authorised(x);
// 				break;
// 			
// 			default:
// 				access_denied(x);
// 				break;
// 		 
// 			}
	}
}

