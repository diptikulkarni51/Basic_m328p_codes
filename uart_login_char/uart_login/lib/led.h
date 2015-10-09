/*
 * led.h
 *
 * Created: 8/27/2015 7:35:03 PM
 *  Author: DipTi
 */ 


#ifndef LED_H_
#define LED_H_

#include "avr/io.h"
#include "util/delay.h"
#include "avr/interrupt.h"

void port_init();
void access_denied(uint8_t count);
void authorised(uint8_t count);


#endif /* LED_H_ */