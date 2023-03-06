/*
 * 4led_trafficlight.c
 *
 *  Created on: Nov 18, 2022
 *      Author: PC
 */

#include "4led_trafficlight.h"

void LedRedAll(){
	if(timer_flag[1]==1){
		HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
		HAL_GPIO_TogglePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin);
		setTimer(50, 1);
	}
}

void LedGreenAll(){
	if(timer_flag[1]==1){
		HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin);
		HAL_GPIO_TogglePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin);
		setTimer(50, 1);
	}
}
void LedYellowAll(){
	if(timer_flag[1]==1){
		HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
		HAL_GPIO_TogglePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin);
		setTimer(50, 1);
	}
}
void clearAll(){
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, SET);
	countdownled = 0;
	countdownled_1 = 0;
	status = INIT;
	status_1 = INIT;
	status_2 = INIT;
	resetIndex7LED();
}

/*

NORMAL MODE


USING STATUS - LED
USING STATUS_1 - LED_1

*/

//USING TIMER2 FOR COUNTDOWN
int countdownled = 0;
int countdownled_1 = 0;
void fsm_mode1_run(){


	DisplayNumAutoMode[0] = countdownled/10;
	DisplayNumAutoMode[1] = countdownled%10;

	DisplayNumAutoMode[2] = countdownled_1/10;
	DisplayNumAutoMode[3] = countdownled_1%10;


	if(timer_flag[2] == 1){
		setTimer(100, 2);
		countdownled--;
		countdownled_1--;
	}

	switch(status){
	case INIT:
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, RESET);
		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);

		if(duration_update[0] != duration_update[1] + duration_update[2]){
			duration[0] = 500;
			duration[2] = 200;
			duration[1] = 300;
		}
//
		if(countdownled<=0){
			status = AUTO_RED;
			countdownled = duration[0]/100;
		}

		break;
	case AUTO_RED:
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, RESET);
		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);

//
		Display7SEGwithNum(DisplayNumAutoMode);
		if(countdownled<=0){
			status = AUTO_GREEN;
			countdownled = duration[1]/100;
		}


		break;
	case AUTO_GREEN:
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, RESET);
		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);



		Display7SEGwithNum(DisplayNumAutoMode);
		if(countdownled<=0){
			status = AUTO_YELLOW;
			countdownled = duration[2]/100;
		}



		break;
	case AUTO_YELLOW:
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, RESET);


		Display7SEGwithNum(DisplayNumAutoMode);
		if(countdownled<=0){
			status = AUTO_RED;
			countdownled = duration[0]/100;
		}


		break;
	default:
		break;
	}


	switch(status_1){
	case INIT:
		HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, RESET);
		HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, SET);

		if(duration_update[0] != duration_update[1] + duration_update[2]){
			duration[0] = 500;
			duration[2] = 200;
			duration[1] = 300;
		}

		status_1 = AUTO_GREEN;

		if(countdownled_1<=0){
			status_1 = AUTO_GREEN;
			countdownled_1 = duration[1]/100;
		}


		break;
	case AUTO_GREEN:
		HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, RESET);
		HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, SET);

		if(countdownled_1<=0){
			status_1 = AUTO_YELLOW;
			countdownled_1 = duration[2]/100;
		}

		break;
	case AUTO_YELLOW:
		HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, RESET);


		if(countdownled_1<=0){
			status_1 = AUTO_RED;
			countdownled_1 = duration[0]/100;
		}

		break;
	case AUTO_RED:
		HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, RESET);
		HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, SET);


		if(countdownled_1<=0){
			status_1 = AUTO_GREEN;
			countdownled_1 = duration[1]/100;
		}
		break;
	default:
		break;
	}

}

