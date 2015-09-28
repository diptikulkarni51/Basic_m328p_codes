/*
 * uart_lookback.c
 *
 * Created: 8/4/2015 12:43:47 AM
 *  Author: DipTi
 */ 


#include <avr/io.h>
#include "lib/serial.h"

int main(void)
{
	char arrary[] = "Hello";
	uint8_t count;
	
	serial_init(myubrr);
	
	
    while(1)
    {
		count = 0;
		
		while( arrary[count] != '\0' ){
			
			while(serial_tx(arrary[count]) != success );
			_delay_ms(500);
			count++;
		}
		
        
    }
}