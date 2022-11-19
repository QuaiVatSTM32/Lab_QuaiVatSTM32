/*
 * fsm_1mode.c
 *
 *  Created on: Nov 4, 2022
 *      Author: PC
 */
#include "fsm_1mode.h"



void fsm_1mode_run(){
	switch(status){
	case INIT:
		setTimer1(50);
		status = MODE_2;

		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);

		break;
	case MODE_2:
		if(timer1_flag==1){
			HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);

			setTimer1(50);
		}
		duration_red_1 = duration_red;
		if(is_button_pressed(1)==1){
			duration_red_1++;
		}
		if(is_button_pressed(2)==1){
			duration_red = duration_red_1;
		}
		if(is_button_pressed(0) == 1){
			status = MODE_3;
			setTimer1(50);
		}
		break;

	case MODE_3:
		if(timer1_flag==1){
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);
			HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
			setTimer1(50);

		}


		duration_yellow_1 = duration_yellow;
		if(is_button_pressed(1)==1){
			duration_yellow_1++;
		}
		if(is_button_pressed(2) == 1){
			duration_yellow = duration_yellow_1;
		}
		if(is_button_pressed(0)==1){
			status = MODE_4;
			setTimer1(50);
		}


		break;

	case MODE_4:
		if(timer1_flag==1){

			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
			HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin);
			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
			setTimer1(50);
		}

		duration_green_1 = duration_green;
		if(is_button_pressed(1) == 1){
			duration_green_1++;
		}
		if(is_button_pressed(2) == 1){
			duration_green = duration_green_1;
		}
		if(is_button_pressed(0) == 1){
			status = AUTO_RED;
		}

		break;


	default:
		break;

	}
	switch(status_1){
	case INIT:
		HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, SET);

		setTimer2(50);
		status_1 = MODE_2;

		break;
		case MODE_2:
			if(timer2_flag==1){
				HAL_GPIO_TogglePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin);
				HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, SET);
				HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, SET);
				setTimer2(50);

			}

			duration_red_1 = duration_red;
			if(is_button_pressed(1)==1){
				duration_red_1++;

			}
			if(is_button_pressed(2)==1){
				duration_red = duration_red_1;
			}
			if(is_button_pressed(0) == 1){
				status_1 = MODE_3;
				setTimer2(50);
			}

			break;

		case MODE_3:
			if(timer2_flag==1){
				HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, SET);
				HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, SET);
				HAL_GPIO_TogglePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin);
				setTimer2(50);

			}

			duration_yellow_1 = duration_yellow;
			if(is_button_pressed(1)==1){
				duration_yellow_1++;
			}
			if(is_button_pressed(2) == 1){
				duration_yellow = duration_yellow_1;
			}
			if(is_button_pressed(0)==1){
				status_1 = MODE_4;
				setTimer2(50);
			}


			break;

		case MODE_4:
			if(timer2_flag==1){
				HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, SET);
				HAL_GPIO_TogglePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin);
				HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, SET);
				setTimer2(50);

			}

			duration_green_1 = duration_green;
			if(is_button_pressed(1) == 1){
				duration_green_1++;
			}
			if(is_button_pressed(2) == 1){
				duration_green = duration_green_1;
			}
			if(is_button_pressed(0) == 1){
				status_1 = AUTO_RED;
			}

			break;


		default:
			break;

		}

}


