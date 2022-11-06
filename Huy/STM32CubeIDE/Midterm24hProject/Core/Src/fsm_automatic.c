/*
 * fsm_automatic.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Admin
 */

#include "fsm_automatic.h"

void fsm_automatic_run(){
	display7SEG(SevenSEGCounter);
	if(timer1_flag == 1) {
		setTimer1(1000);
		//TODO
		HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
		if(timeOut == 0){
			SevenSEGCounter--;
			if(SevenSEGCounter == 0) timeOut = 1;
		}
	}
}

