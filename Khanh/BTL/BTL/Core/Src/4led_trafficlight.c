/*
 * 4led_trafficlight.c
 *
 *  Created on: Jan 2, 2023
 *      Author: PC
 */


#include "4led_traficlight.h"
#include "scheduler.h"

void LedRedAll(){
		HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
		HAL_GPIO_TogglePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin);
}

void LedGreenAll(){
		HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin);
		HAL_GPIO_TogglePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin);
}
void LedYellowAll(){
		HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
		HAL_GPIO_TogglePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin);

}
void clearAll(){
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, SET);

}
void Red(){
	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
}
void Red_1(){
	HAL_GPIO_TogglePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin);
}

void Green(){
	HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin);
}
void Green_1(){
	HAL_GPIO_TogglePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin);
}

void Yellow(){
	HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
}
void Yellow_1(){
	HAL_GPIO_TogglePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin);
}
void fsm_mode1_run(){

	 SCH_Add_Task(Red, 0, 500);

	 SCH_Add_Task(Green_1, 0, 300);
	 SCH_Add_Task(Green_1, 300, 0);
	 SCH_Add_Task(Yellow_1, 0, 200);
	 SCH_Add_Task(Yellow_1, 200, 0);


	 SCH_Add_Task(Red_1, 0, 500);
	 SCH_Add_Task(Red, 0, 0);
	 SCH_Add_Task(Green, 0, 300);
	 SCH_Add_Task(Green, 300, 0);
	 SCH_Add_Task(Yellow, 0, 200);
	 SCH_Add_Task(Yellow, 200, 0);

	 SCH_Add_Task(Red_1, 0, 0);
}
