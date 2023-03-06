/*
 * scheduler.c
 *
 *  Created on: Nov 30, 2022
 *      Author: Admin
 */
#include "scheduler.h"
#include "main.h"
sTask SCH_tasks_G[SCH_MAX_TASKS] ;
uint8_t current_index_task = 0;
unsigned char Error_code_G = 0;

void SCH_Report_Status ( void );
SCH_Go_To_Sleep();
void SCH_Init ( void ) {
//	unsigned char i ;
//	for ( i = 0; i < SCH_MAX_TASKS; i ++) {
//		SCH_Delete_Task( i ) ;
////	}
//	// Reset the global error variable
//	// − SCH_Delete_Task () w ill generate an error code ,
//	// ( because the task array i s empty)
//	Error_code_G = 0;
//	Timer_init();
//	Watchdog_init() ;
}
void SCH_Update( void ) {
	unsigned char Index ;
	for ( Index = 0; Index < SCH_MAX_TASKS; Index++) {							// NOTE: calculations are in *TICKS* ( not milliseconds )
		if ( SCH_tasks_G[Index].pTask) {										// Check if there is a task at this location
			if ( SCH_tasks_G[Index].Delay == 0) {								// The task is due to run
				SCH_tasks_G[Index].RunMe += 1;									// Inc . the ’RunMe’ flag
				if ( SCH_tasks_G[Index].Period ) {								// Schedule periodic tasks to run again
					SCH_tasks_G[Index].Delay = SCH_tasks_G[Index].Period ;
				}
			} else {
				SCH_tasks_G[Index].Delay -= 1;									// Not yet ready to run: just decrement the delay
			}
		}
	}
}
void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef * htim ) {
	SCH_Update() ;
}

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*−
SCH_Add_Task () Causes a task ( function ) to be executed at regular inter val s
or aft e r a user−defined delay
−*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
unsigned char SCH_Add_Task( void (* pFunction) () , unsigned int DELAY, unsigned int PERIOD){
	unsigned char Index = 0;
	// First find a gap in the array ( if there is one)
	while ( (SCH_tasks_G[ Index ].pTask != 0) && (Index < SCH_MAX_TASKS) )
	{
		Index++;
	}
	// Have we reached the end of the l i s t ?
	if( Index == SCH_MAX_TASKS){
		// Task list is full
		// Set the global error variable
		Error_code_G = ERROR_SCH_TOO_MANY_TASKS;
		// Also return an error code
		return SCH_MAX_TASKS;
	}
	// If we ’re here , there i s a space in the task array
	SCH_tasks_G[Index].pTask = pFunction ;
	SCH_tasks_G[Index].Delay = DELAY;
	SCH_tasks_G[Index].Period = PERIOD;
	SCH_tasks_G[Index].RunMe = 0;
	// return position of task ( to allow l at e r deletion )
	return Index ;
}
void SCH_Dispatch_Tasks( void ){
	unsigned char Index ;
	// Dispatches ( runs ) the next task ( i f one i s ready )
	for ( Index = 0; Index < SCH_MAX_TASKS; Index++) {
		if ( SCH_tasks_G[Index].RunMe > 0) {
			(* SCH_tasks_G[Index].pTask) () ; // Run the task
			SCH_tasks_G[Index].RunMe -= 1; // Reset / reduce RunMe fl a g
			// Periodic tasks will automatically run again
			//−if this is a ’one shot ’ task, remove it from the array
			if ( SCH_tasks_G[Index].Period == 0) SCH_Delete_Task( Index ) ;
		}
	}
	// Report system status
	SCH_Report_Status();
	// The scheduler enters idle mode at this point
	SCH_Go_To_Sleep();
}

unsigned char SCH_Delete_Task(const tByte TASK_INDEX){
	unsigned char Return_code ;
	if ( SCH_tasks_G[TASK_INDEX ] . pTask == 0) {
		// No task at thi s location . . .
		//
		// Set the global error variable
		Error_code_G = ERROR_SCH_CANNOT_DELETE_TASK

		// . . . also return an error code
		Return_code = RETURN_ERROR;
	} else {
		Return_code = RETURN_NORMAL;
	}
	SCH_tasks_G[TASK_INDEX].pTask = 0x0000 ;
	SCH_tasks_G[TASK_INDEX].Delay = 0;
	SCH_tasks_G[TASK_INDEX].Period = 0;
	SCH_tasks_G[TASK_INDEX].RunMe = 0;
	return Return_code ; // return status
}
void SCH_Report_Status ( void ) {
	#ifdef SCH_REPORT_ERRORS
	// ONLY APPLIES IF WE ARE REPORTING ERRORS
	// Check for a new error code
	if ( Error_code_G != Last_error_code_G ) {
		// Negative logic on LEDs assumed
		Error_port = 255 − Error_code_G ;
		Last_error_code_G = Error_code_G ;
		if ( Error_code_G != 0) {
			Error_tick_count_G = 60000;
		} else {
			Error_tick_count_G = 0;
		}
	} else {
		if ( Error_tick_count_G != 0) {
			if (−−Error_tick_count_G == 0) {
				Error_code_G = 0; // Reset error code
			}
		}
	}
	#endif
}
