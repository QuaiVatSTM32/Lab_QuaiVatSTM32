/*
 * timer.h
 *
 *  Created on: Nov 4, 2022
 *      Author: PC
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include "main.h"
#include "input_reading.h"
#include "software_timer.h"

void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef * htim );


#endif /* INC_TIMER_H_ */
