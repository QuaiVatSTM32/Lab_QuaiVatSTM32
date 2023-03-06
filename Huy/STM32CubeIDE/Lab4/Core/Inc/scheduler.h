/*
 * scheduler.h
 *
 *  Created on: Nov 30, 2022
 *      Author: Admin
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_
#include <stdint.h>

typedef struct{
	void (*pTask) (void);	// Pointer to the task (must be a ’ void ( void ) ’ function )
	uint32_t Delay;			// Delay (ticks) until the function will ( next ) be run
	uint32_t Period;		// Interval (ticks) between subsequent runs .
	uint8_t  RunMe;			// Incremented (by scheduler) when task i s due to execute
	uint32_t TaskID;		//This is a hint to solve the question below .
} sTask;

// MUST BE ADJUSTED FOR EACH NEW PROJECT
#define SCH_MAX_TASKS 	40
#define NO_TASK_ID 		0

void SCH_Init(void);

void SCH_Add_Task(void 	    (*pFunction)(),
				  uint32_t 	DELAY,
				  uint32_t 	PERIOD);

void SCH_Update(void);

void SCH_Dispatch_Tasks(void);

#endif /* INC_SCHEDULER_H_ */
