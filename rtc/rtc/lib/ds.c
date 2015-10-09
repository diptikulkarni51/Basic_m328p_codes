/*
 * ds.c
 *
 * Created: 04-10-2015 15:02:21
 *  Author: HP-
 */ 

#include "i2c.h"
#include "ds.h"
#include "util/delay.h"
#include "uart.h"

void rtc_write(char dev_addr,char dev_loc,char dev_data)
{
	start();
	write_i2c(dev_addr);
	write_i2c(dev_loc);
	write_i2c(dev_data);
	stop();
	_delay_ms(10);
}

unsigned char rtc_read(char dev_addr,char dev_loc)
{
	char ch;

	start();

	write_i2c(dev_addr);
	write_i2c(dev_loc);

	start();
	write_i2c(dev_addr|0x01);
	ch = read_i2c();

	stop();
	return ch;
}



void disp_time_date()
{
	char ch;

	tx(254);
	tx(128);

	str_serial("Time: ");

	ch = rtc_read(0xd0 , 0x02);
	tx(ch/16+48);
	tx(ch%16+48);
	tx('-');
	

	ch = rtc_read(0xd0 , 0x01);
	tx(ch/16+48);
	tx(ch%16+48);
	tx('-');
	

	ch = rtc_read(0xd0 , 0x00);
	tx(ch/16+48);
	tx(ch%16+48);

	tx(254);
	tx(192);

	str_serial("Date: ");

	ch = rtc_read(0xd0 , 0x04);
	tx(ch/16+48);
	tx(ch%16+48);
	tx('-');

	ch = rtc_read(0xd0 , 0x05);
	tx(ch/16+48);
	tx(ch%16+48);
	tx('-');

	ch = rtc_read(0xd0 , 0x06);
	tx(ch/16+48);
	tx(ch%16+48);

	
	str_serial("\r\n");	

}