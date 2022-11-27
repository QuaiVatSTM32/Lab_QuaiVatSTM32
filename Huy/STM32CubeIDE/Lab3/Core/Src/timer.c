/*
 * timer.c
 *
 *  Created on: Nov 14, 2022
 *      Author: Admin
 */

#include "timer.h"

void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef * htim ){
	if(htim -> Instance == TIM2 ){
		button_reading();
	}
	timerRun();
}
