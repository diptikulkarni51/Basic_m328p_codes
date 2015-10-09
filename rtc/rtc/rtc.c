/*
 * rtc.c
 *
 * Created: 03-10-2015 10:38:50
 *  Author: HP-
 */ 


# include <avr/io.h>
# include <util/delay.h>
#include "lib/uart.h"
#include "lib/i2c.h"
#include "lib/ds.h"


void set_time(){
	rtc_write(0xd0,0x00,0x00);
	rtc_write(0xd0,0x01,0x59);
	rtc_write(0xd0,0x02,0x23);
}

void set_date(){
	rtc_write(0xD0,0x04,0x08);
	rtc_write(0xD0,0x05,0x09);
	rtc_write(0xD0,0x06,0x15);
}

int main()
{
	
	init_i2c();
	init_serial();
	set_time();
	set_date();

	_delay_ms(1000);


	while(1)
	{
		disp_time_date();
		_delay_ms(1000);
	}

}