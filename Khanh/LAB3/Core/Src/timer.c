/*
 * timer.c
 *
 *  Created on: Nov 4, 2022
 *      Author: PC
 */

#include "main.h"
#include "input_reading.h"
#include "software_timer.h"
#include "timer.h"

void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef * htim){
	if(htim->Instance == TIM2){
		button_reading();
		timerRun1();
		timerRun2();
	}

}
