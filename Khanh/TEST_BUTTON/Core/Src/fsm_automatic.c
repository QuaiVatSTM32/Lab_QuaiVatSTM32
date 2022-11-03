/*
 * fsm_automatic.c
 *
 *  Created on: Nov 1, 2022
 *      Author: PC
 */
#include "fsm_automatic.h"
#include "fsm_manual.h"

//using for state
void fsm_automatic_run(){
	switch(status){
	case INIT:
		//TODO
		HAL_GPIO_WritePin(LED_RED_GPIO_Port,LED_RED_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port,LED_GREEN_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port,LED_YELLOW_Pin, GPIO_PIN_SET);

		if(isButton1Pressed()==1){
			status = MAN_RED;
			fsm_manual_run();
		}
		else{
			status = AUTO_RED;
			setTimer(500);
		}
		break;
	case AUTO_RED:
		HAL_GPIO_WritePin(LED_RED_GPIO_Port,LED_RED_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port,LED_GREEN_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port,LED_YELLOW_Pin, GPIO_PIN_SET);

		if(timer1_flag == 1){
			status = AUTO_GREEN;
			setTimer(300);
		}
		if(timer1_flag != 1 && isButton1Pressed()==1){
			status = MAN_RED;
			fsm_manual_run();
		}
		break;
	case AUTO_GREEN:
		HAL_GPIO_WritePin(LED_RED_GPIO_Port,LED_RED_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port,LED_GREEN_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port,LED_YELLOW_Pin, GPIO_PIN_SET);

		if(timer1_flag == 1){
			status = AUTO_YELLOW;
			setTimer(200);
		}
		if(timer1_flag != 1 && isButton1Pressed()==1){
			status = MAN_RED;
			fsm_manual_run();
		}
		break;
	case AUTO_YELLOW:

		HAL_GPIO_WritePin(LED_RED_GPIO_Port,LED_RED_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port,LED_GREEN_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port,LED_YELLOW_Pin, GPIO_PIN_RESET);

		if(timer1_flag == 1){
			status = AUTO_RED;
			setTimer(500);
		}
		if(timer1_flag != 1 && isButton1Pressed()==1){
			status = MAN_RED;
			fsm_manual_run();
		}
		break;
	default:
		break;

	}
}

