/*
 * led.c
 *
 * Created: 8/2/2015 5:37:47 PM
 *  Author: DipTi
 */ 


#include <avr/io.h>
#include "lib/pattern.h"

int main(void){
	port_init();
    while(1){
		patten1();
		_delay_ms(100);
		pattern2();
		_delay_ms(100);
		pattern3();
		_delay_ms(100);
		pattern4();
		_delay_ms(100);
    }
}