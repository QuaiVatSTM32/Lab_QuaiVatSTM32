/*
 * fsm_4mode.c
 *
 *  Created on: Nov 4, 2022
 *      Author: PC
 */
#include "fsm_4mode.h"
//TIMER0 - LED BRLINKY
void fsm_4mode_run(){
	switch(status_2){
	case 0:
		if(duration[0]!=duration[1]+duration[2]){
			duration[0] = 500;
			duration[1] = 300;
			duration[2]= 200;
		}
		status_2 = 1;
	case 1: //	AUTO MODE

		fsm_mode1_run();

		if(is_button_pressed(0)==1){
			clearAll();

			DisplayNumAutoMode[0] = 0;
			DisplayNumAutoMode[1] = 2;
			DisplayNumAutoMode[2] = (duration_update[0]/100)/10;
			DisplayNumAutoMode[3] = duration[0]/100;


			status_2 = 2;
		}
		break;
	case 2: // ALL LED_RED blink, 7SEG display mode and time for led_red

		LedRedAll();

		DisplayNumAutoMode[0] = 0;
		DisplayNumAutoMode[1] = 2;
		DisplayNumAutoMode[2] = (duration_update[0]/100)/10;
		DisplayNumAutoMode[3] = (duration_update[0]/100)%10;

		Display7SEGwithNum(DisplayNumAutoMode);


		if(is_button_pressed(1)==1){
			DisplayNumAutoMode[0] = 0;
			DisplayNumAutoMode[1] = 2;
			duration_update[0] = duration_update[0] + 100;

		}
		if(is_button_pressed(2)==1){
			duration[0] = duration_update[0];

		}
		if(is_button_pressed(0)==1){
			clearAll();
			clearEnBuffer();
			DisplayNumAutoMode[0] = 0;
			DisplayNumAutoMode[1] = 3;
			DisplayNumAutoMode[2] = 0;
			DisplayNumAutoMode[3] = duration[2]/100;


			status_2 = 3;

		}

		break;
	case 3:  // ALL LED_YELLOW blink, 7SEG display mode and time for led_yellow
		LedYellowAll();
		DisplayNumAutoMode[0] = 0;
		DisplayNumAutoMode[1] = 3;
		DisplayNumAutoMode[2] = (duration_update[2]/100)/10;
		DisplayNumAutoMode[3] = (duration_update[2]/100)%10;

		Display7SEGwithNum(DisplayNumAutoMode);


		if(is_button_pressed(1)==1){
			DisplayNumAutoMode[0] = 0;
			DisplayNumAutoMode[1] = 3;
			duration_update[2] = duration_update[2] + 100;

		}
		if(is_button_pressed(2)==1){
			duration[2] = duration_update[2];

		}
		if(is_button_pressed(0)==1){
			clearAll();
			DisplayNumAutoMode[0] = 0;
			DisplayNumAutoMode[1] = 4;
			DisplayNumAutoMode[2] = 0;
			DisplayNumAutoMode[3] = duration[1]/100;

			status_2 = 4;

		}
		break;
	case 4:  // ALL LED_GREEN blink, 7SEG display mode and time for led_green
		LedGreenAll();
		DisplayNumAutoMode[0] = 0;
		DisplayNumAutoMode[1] = 4;
		DisplayNumAutoMode[2] = (duration_update[1]/100)/10;
		DisplayNumAutoMode[3] = (duration_update[1]/100)%10;

		Display7SEGwithNum(DisplayNumAutoMode);


		if(is_button_pressed(1)==1){
			DisplayNumAutoMode[0] = 0;
			DisplayNumAutoMode[1] = 2;
			duration_update[1] = duration_update[1] + 100;

		}
		if(is_button_pressed(2)==1){
			duration[1] = duration_update[1];
			if(duration_update[0] == duration_update[1]+duration_update[2]){
				duration[0] = duration_update[0];
				duration[1] = duration_update[1];
				duration[2]= duration_update[2];
			}
			else{
				duration[0] = 500;
				duration[1] = 300;
				duration[2]= 200;
			}
		}
		if(is_button_pressed(0)==1){
			clearAll();
			status_2 = 1;

		}
		break;
	default:
		break;
	}
}

