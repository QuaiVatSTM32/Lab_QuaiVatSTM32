/*
 * scheduler.h
 *
 *  Created on: Dec 5, 2022
 *      Author: PC
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include <stdint.h>
typedef struct{
	void(*pTask)(void);
	uint32_t Delay;
	uint32_t Period;
	uint8_t RunMe; //timer_flag

	uint32_t TaskID;

}sTasks;

#define SCH_MAX_TASKS 		40

void SCH_Reset_Task(const int TASK_IDX);

void SCH_Place_New_Task(int index);

void SCH_Init(void);
void SCH_Add_Task(void(*pFunction)(),
					uint32_t DELAY,
					uint32_t PERIOD);
void SCH_Update(void);
void SCH_Dispatch_Tasks(void);

void SCH_Delete_Tasks(uint32_t taskID);

#endif /* INC_SCHEDULER_H_ */
