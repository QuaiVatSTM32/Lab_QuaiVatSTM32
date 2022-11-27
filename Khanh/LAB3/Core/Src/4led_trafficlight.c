/*
 * 4led_trafficlight.c
 *
 *  Created on: Nov 18, 2022
 *      Author: PC
 */

#include "4led_trafficlight.h"

void LedRedAll(){
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, RESET);
	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, RESET);
}

void LedGreenAll(){
	HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, RESET);
	HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, RESET);
}
void LedYellowAll(){
	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, RESET);
	HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, RESET);
}
void clearAll(){
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, SET);
}
//NORMAL MODE
void fsm_mode1_run(){
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
		led_1 = INIT_1;
		status = AUTO_RED;
		Display_7SEG_Timer();
		setTimer(duration[0], 0);
		break;
	case AUTO_RED:
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, RESET);
		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);

		choose_duration = 0;

		if(timer_flag[2]==1){
			Display_7SEG_Timer();
		}
		if(timer_flag[0] == 1){
			status = AUTO_GREEN;
			setTimer(duration[1], 0);
		}
		break;
	case AUTO_GREEN:
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, RESET);
		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);

		choose_duration = 1;

		if(timer_flag[0] == 1){
			status = AUTO_YELLOW;
			setTimer(duration[2], 0);
		}
		if(timer_flag[2]==1){
			Display_7SEG_Timer();
		}
		break;
	case AUTO_YELLOW:
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, RESET);

		choose_duration = 2;

		if(timer_flag[0] == 1){
			setTimer(duration[0], 0);
			status = AUTO_RED;
		}
		if(timer_flag[2]==1){
			led_2 = 0;
			Display_7SEG_Timer();
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
		choose_duration_1 = 1;
		status_1 = AUTO_GREEN;
		setTimer(duration[1], 1);
		break;
	case AUTO_GREEN:
		HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, RESET);
		HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, SET);

		choose_duration_1 = 1;

		if(timer_flag[1] == 1){
			status_1 = AUTO_YELLOW;
			setTimer(duration[2], 1);
		}

		break;
	case AUTO_YELLOW:
		HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, RESET);

		choose_duration_1 = 2;

		if(timer_flag[1] == 1){
			status_1 = AUTO_RED;
			setTimer(duration[0], 1);
		}

		break;
	case AUTO_RED:
		HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, RESET);
		HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, SET);

		choose_duration_1 = 0;

		if(timer_flag[1] == 1){
			setTimer(duration[1], 1);
			status_1 = AUTO_GREEN;
		}

		break;
	default:
		break;
	}

}
