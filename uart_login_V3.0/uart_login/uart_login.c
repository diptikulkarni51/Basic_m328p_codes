/*
 * uart_login.c
 *
 * Created: 8/27/2015 7:31:59 PM
 *  Author: DipTi
 */ 


#include <avr/io.h>
#include <string.h>
#include "stdio.h"
#include "lib/uart.h"
#include "lib/led.h"
#include "avr/eeprom.h"

extern char rx_byte;
extern volatile bool is_rx_done;


#define USERPW_ADDRESS	23

void vStringSend(char *str);
void vRcvString(char *str);
void over_write_eeprom();

uint8_t USRPW[15]="password1";
char readblock[15];

int main(void) {
	char col_user[15];
	char dec[5];
	unsigned char s[15]="\r\npassword:\0";
	
	//init
	uart_init(MYUBRR);
	port_init();
	
	//eeprom init
	eeprom_write_block((const void *)USRPW, (void *)USERPW_ADDRESS, 10);
	eeprom_read_block((void*)readblock, (const void*)USERPW_ADDRESS, 10);
	readblock[9] = '\0';
	while(1){
		
		//memset(col_user,'\0',15);
		
		vStringSend((char *)s);
		vRcvString(col_user);
		vStringSend("\r\n");
		//compare
		if(strcmp(col_user,readblock) ==0){
			vStringSend  ("access granted\r\n");
			authorised();
			vStringSend ("change password?\r\n");
			vRcvString(dec);
			vStringSend("\r\n");
			if(strcmp(dec,"yes") ==0){
				over_write_eeprom ();
			}
			else
			authorised();
		}
		else{
			vStringSend  ("accesss denied\r\n");
			access_denied();
		}
		
	}
}

void vStringSend(char *str){
	
	uint8_t count=0;
	
	while( str[count] != '\0' ){
		
		send_to_debug(str[count]);
		_delay_ms(25);
		count++;
	}
}

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
}

void over_write_eeprom(){
	char c[15];
	//uint8_t count=0;
	vStringSend("new pw:");
	vRcvString(c);
	vStringSend("\r\n");
	eeprom_update_block((const void *)c, (void *)USERPW_ADDRESS, 10);
	eeprom_read_block((void*)readblock, (const void*)USERPW_ADDRESS, 10);
	
}