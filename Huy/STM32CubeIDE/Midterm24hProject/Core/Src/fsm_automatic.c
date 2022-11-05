/*
 * fsm_automatic.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Admin
 */

#include "fsm_automatic.h"

void fsm_automatic_run(){

	switch(status){
		case INIT:
			//TODO
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
			status = AUTO_RED;
			setTimer1(500);
			break;
		case AUTO_RED:
			//TODO
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, RESET);
			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);

			if(timer1_flag == 1){
				status = AUTO_GREEN;
				setTimer1(300);
			}

			break;
		case AUTO_GREEN:
			//TODO
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, RESET);
			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);

			if(timer1_flag == 1){
				status = AUTO_YELLOW;
				setTimer1(200);
			}
			break;
		case AUTO_YELLOW:
			//TODO
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, RESET);

			if(timer1_flag == 1){
			status = AUTO_RED;
			setTimer1(200);
			}
			break;
	}
}

