/*
 * timers.c
 *
 * Created: 8/22/2015 4:16:17 PM
 *  Author: DipTi
 */ 


#include "avr/io.h"
#include "util/delay.h"
#include "avr/interrupt.h"

// global variable to count the number of overflows
volatile uint8_t tot_overflow;


void timer0_init(){
	// set up timer with prescaler = 256
	TCCR0B |= (1 << CS02)|(1 << CS00);
	
	// initialize counter
	TCNT0 = 0;
	
	// enable overflow interrupt
	TIMSK0 |= (1 << TOIE0);
	
	// enable global interrupts
	sei();
	
	// initialize overflow counter variable
	tot_overflow = 0;
}
// TIMER0 overflow interrupt service routine
// called whenever TCNT0 overflows

ISR(TIMER0_OVF_vect){
	// keep a track of number of overflows
	tot_overflow++;
}

int main(void){
	// connect led to pin PC0
	DDRB |= (1 << PORTB0)|(1<< PORTB1);
	
	// initialize timer
	timer0_init();
	
	// loop forever
	while(1){
		// check if no. of overflows = 12
		if (tot_overflow >= 24){
			// check if the timer count reaches 53
			if (TCNT0 >= 53){
				PORTB ^= (1 << PORTB0)|(1 << PORTB1);    // toggles the led
				TCNT0 = 0;            // reset counter
				tot_overflow = 0;     // reset overflow counter
			}
		}
	}
}
