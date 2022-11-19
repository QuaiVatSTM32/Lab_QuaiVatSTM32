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
	HAL_Delay(1000);
}

void LedGreenAll(){
	HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, RESET);
	HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, RESET);
	HAL_Delay(1000);

}
void LedYellowAll(){
	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, RESET);
	HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, RESET);
	HAL_Delay(1000);
}
void clearAll(){
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, SET);
}

void fsm_mode1_run(){
	switch(status){
	case INIT:
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, RESET);
		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);

		status = AUTO_RED;
		setTimer1(duration_red);
		break;
	case AUTO_RED:
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, RESET);
		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);

		if(timer1_flag == 1){
			status = AUTO_GREEN;
			setTimer1(duration_green);
		}

		break;
	case AUTO_GREEN:
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, RESET);
		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);

		if(timer1_flag == 1){
			status = AUTO_YELLOW;
			setTimer1(duration_yellow);
		}

		break;
	case AUTO_YELLOW:
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, RESET);


		if(timer1_flag == 1){
			setTimer1(duration_red);
			status = AUTO_RED;
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

		status_1 = AUTO_GREEN;
		setTimer2(duration_green);
		break;
	case AUTO_GREEN:
		HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, RESET);
		HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, SET);

		if(timer2_flag == 1){
			status_1 = AUTO_YELLOW;
			setTimer2(duration_yellow);
		}

		break;
	case AUTO_YELLOW:
		HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, RESET);

		if(timer2_flag == 1){
			status_1 = AUTO_RED;
			setTimer2(duration_red);

		}

		break;
	case AUTO_RED:
		HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, RESET);
		HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, SET);

		if(timer2_flag == 1){
			setTimer2(duration_green);
			status_1 = AUTO_GREEN;
		}

		break;
	default:
		break;
	}

}
