/*
 * i2c.h
 *
 * Created: 04-10-2015 14:45:45
 *  Author: HP-
 */ 


#ifndef I2C_H_
#define I2C_H_

void init_i2c();
unsigned char read_i2c();
void write_i2c(char ch);
void start();
void stop();



#endif /* I2C_H_ */