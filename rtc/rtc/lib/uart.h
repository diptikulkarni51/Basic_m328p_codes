/*
 * uart.h
 *
 * Created: 04-10-2015 14:40:58
 *  Author: HP-
 */ 


#ifndef UART_H_
#define UART_H_

void tx( unsigned char data );
char rx();
void init_serial();
void str_serial(char *str);



#endif /* UART_H_ */