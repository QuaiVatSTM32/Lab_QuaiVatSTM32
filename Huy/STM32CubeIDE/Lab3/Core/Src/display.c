/*
 * display.c
 *
 *  Created on: Nov 20, 2022
 *      Author: Admin
 */

#include "display.h"
void toggleLED(){
	if(timer_flag[3] == 1){
		setTimer(1000 , 3);
		HAL_GPIO_TogglePin(TOGGLE_LED_GPIO_Port, TOGGLE_LED_Pin);
	}
}
void traficDisplay1(int index){
	switch (index){
		case RED:
					HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, 0);
					HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, 1);
					HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, 1);
					break;
		case YELLOW:
					HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, 1);
					HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, 0);
					HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, 1);
					break;
		case GREEN:
					HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, 1);
					HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, 1);
					HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, 0);
					break;
		case INIT:
					HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, 1);
					HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, 1);
					HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, 1);
					break;
	}
}
void traficDisplay2(int index){
	switch (index){
		case RED:
					HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, 0);
					HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, 1);
					HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, 1);
					break;
		case YELLOW:
					HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, 1);
					HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, 0);
					HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, 1);
					break;
		case GREEN:
					HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, 1);
					HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, 1);
					HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, 0);
					break;
		case INIT:
					HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, 1);
					HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, 1);
					HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, 1);
					break;
	}
}
