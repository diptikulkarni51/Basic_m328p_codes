/*
 * ds.h
 *
 * Created: 04-10-2015 15:03:45
 *  Author: HP-
 */ 


#ifndef DS_H_
#define DS_H_

void rtc_write(char dev_addr,char dev_loc,char dev_data);
unsigned char rtc_read(char dev_addr,char dev_loc);
void disp_time_date();


#endif /* DS_H_ */