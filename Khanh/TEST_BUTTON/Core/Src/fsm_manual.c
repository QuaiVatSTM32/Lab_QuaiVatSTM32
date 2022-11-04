/*
 * fsm_manual.c
 *
 *  Created on: Nov 1, 2022
 *      Author: PC
 */


#include "fsm_manual.h"
#include "fsm_automatic.h"

void fsm_manual_run(){
	switch(status){
	case MAN_RED:
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, RESET);
		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
		setTimer(500);

		if(isButton1Pressed()==1 && timer1_flag!=1){
			setTimer(300);
			status = MAN_GREEN;
		}
		if(timer1_flag==1){
			status = INIT;
			fsm_automatic_run();

		}
		break;
	case MAN_GREEN:
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, RESET);
		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
		if(isButton1Pressed()==1 && timer1_flag!=1){
			setTimer(200);
			status = MAN_YELLOW;
		}
		if(timer1_flag==1){
			status = INIT;
			fsm_automatic_run();

		}
		break;
	case MAN_YELLOW:
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, RESET);
		if(isButton1Pressed()==1 && timer1_flag!=1){
			status = MAN_RED;
		}
		if(timer1_flag==1){
			status = INIT;
			fsm_automatic_run();

		}
		break;
	default:
		break;
	}
}
