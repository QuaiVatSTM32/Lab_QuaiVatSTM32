/*
 * fsm_4mode.c
 *
 *  Created on: Nov 4, 2022
 *      Author: PC
 */
#include "fsm_4mode.h"

void fsm_4mode_run(){
	switch(status_2){
	case MODE_1:
		fsm_mode1_run();
		if(is_button_pressed(0)==1){
			clearAll();
			status_2 = MODE_2;
		}
		break;
	case MODE_2:
		LedRedAll();
		if(is_button_pressed(0)==1){
			clearAll();
			status_2 = MODE_3;
		}

		if(is_button_pressed(1)==1){

		}
		break;
	case MODE_3:
		LedYellowAll();
		if(is_button_pressed(0)==1){
			clearAll();
			status_2 = MODE_4;
		}
		break;
	case MODE_4:
		LedGreenAll();
		if(is_button_pressed(0)==1){
			clearAll();
			status_2 = MODE_1;
		}
		break;
	default:
		break;
	}
}

