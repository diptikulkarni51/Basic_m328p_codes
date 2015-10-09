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
#include "stdbool.h"
#include "string.h"

extern char rx_byte;
extern volatile bool is_rx_done;


void vRcvString(char *str){
	uint8_t r_count=0;
	//user input
	while(is_rx_done != true);
	is_rx_done = false;
	//user input logic
	str[r_count] = rx_byte;
	while(str[r_count] != 0x0D){
		while(is_rx_done != true);
		is_rx_done = false;
		r_count++;
		str[r_count]=rx_byte;
	}
	str[r_count] = '\0';
	if(str[1]!='\0'){
		
		if(str[0]=='4'){
			str[0]=str[0]<<4;
			str[0]|=str[1];
	
			str[0]=str[0]-0x30;
			str[1]='\0';
		}
		
		else if(str[0]=='3'){
			str[0]=str[0]<<4;
			str[0]|=str[1];
			str[1]='\0';
		}
		
		else if(str[0]=='2'){
			str[0]=str[0]<<4;
			str[0]|=str[1];
			str[0]=str[0]-0x10;
			str[1]='\0';
		}
		else if(str[0]=='5' || '1'){
			str[0]=str[0]<<4;
			str[0]|=str[1];
			str[0]=str[0]-0x20;
			str[1]='\0';
		}
		
	}
	else{
		str[0]=str[0]-0x30;
		str[1]='\0';
	}
	
}

void set_time(){
	char hrs,min,sec;
	str_serial(" set hrs:");
	vRcvString(&hrs);
	str_serial("\r\n");
	str_serial(" set min:");
	vRcvString(&min);
	str_serial("\r\n");
	str_serial(" set sec:");
	vRcvString(&sec);
	str_serial("\r\n");
	
	rtc_write(0xd0,0x00,sec);
	rtc_write(0xd0,0x01,min);
	rtc_write(0xd0,0x02,hrs);
}

void set_date(){
	char date,mon,yr;
	str_serial(" set date:");
	vRcvString(&date);
	str_serial("\r\n");
	str_serial(" set month:");
	vRcvString(&mon);
	str_serial("\r\n");
	str_serial(" set yr:");
	vRcvString(&yr);
	str_serial("\r\n");
	rtc_write(0xD0,0x04,date);
	rtc_write(0xD0,0x05,mon);
	rtc_write(0xD0,0x06,yr);
}

int main(){
	
	init_i2c();
	init_serial();
	set_time();
	set_date();

	_delay_ms(1000);


	while(1){
		disp_time_date();
		_delay_ms(5000);
	}

}

