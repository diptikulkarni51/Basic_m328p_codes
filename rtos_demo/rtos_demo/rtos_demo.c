/*
 * rtos_demo.c
 *
 * Created: 24-09-2015 13:02:38
 *  Author: HP-
 */ 

#include <avr/io.h>
#include <stdlib.h>
#include <string.h>

#ifdef GCC_MEGA_AVR
	/* EEPROM routines used only with the WinAVR compiler. */
	#include <avr/eeprom.h>
#endif

/* Scheduler include files. */
#include "FreeRTOS_Sourse/include/FreeRTOS.h"
#include "FreeRTOS_Sourse/include/task.h"
#include "FreeRTOS_Sourse/include/croutine.h"


/* Priority definitions for most of the tasks in the demo application.  Some
tasks just use the idle priority. */
#define mainLED_TASK_PRIORITY		( tskIDLE_PRIORITY + 1 )


/*
 * The idle hook is used to scheduler co-routines.
 */
void vApplicationIdleHook( void );

void vLedBlink1(void *param);
void vLedBlink2(void *param);
/*-----------------------------------------------------------*/

short main( void )
{
	
	/* Create the tasks defined within this file. */
	xTaskCreate( vLedBlink1, "l1", 200, NULL, mainLED_TASK_PRIORITY, NULL );
	xTaskCreate( vLedBlink2, "l2", 200, NULL, mainLED_TASK_PRIORITY, NULL );


	/* In this port, to use preemptive scheduler define configUSE_PREEMPTION
	as 1 in portmacro.h.  To use the cooperative scheduler define
	configUSE_PREEMPTION as 0. */
	vTaskStartScheduler();

// 	return 0;
}
/*-----------------------------------------------------------*/


void vLedBlink1(void *param){

	DDRB |= 0x02;

	for(;;){

		vTaskDelay(500/portTICK_RATE_MS);
		PORTB ^= 0x02;
	}
}


void vLedBlink2(void *param){

	DDRB |= 0x01;

	for(;;){

		vTaskDelay(500/portTICK_RATE_MS);
		PORTB ^= 0x01;
	}
}

void vApplicationIdleHook( void )
{
	for(;;){
		;//vCoRoutineSchedule();
	}
}