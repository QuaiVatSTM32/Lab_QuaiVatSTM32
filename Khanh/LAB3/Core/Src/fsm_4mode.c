/*
 * fsm_4mode.c
 *
 *  Created on: Nov 4, 2022
 *      Author: PC
 */
#include "fsm_4mode.h"

void fsm_4mode_run(){
	switch(status_2){
	case 0:
		led_1 = INIT_1;
		setTimer(50, 3);
		status_2 = 1;
	case 1:
		fsm_mode1_run();
		if(is_button_pressed(0)==1){
			clearAll();
			setTimer(50, 3);
			led = INIT_1;
			Display_7SEG_mode();
			status_2 = 2;
		}
		break;
	case 2: // ALL LED_RED blink, 7SEG display mode and time for led_red

		LedRedAll();
		choose_mode = 2;
		choose_duration = 0;
		if(timer_flag[3]==1){
			clearAll();
//			choose_mode = 2;
//			choose_duration = 0;
			Display_7SEG_mode();
		}

		if(is_button_pressed(0)==1){
			clearAll();
			setTimer(50, 3);
			led = INIT_1;
			Display_7SEG_mode();
			status_2 = 3;
		}
//		if(is_button_pressed(1)==1){
//			duration_1[0] = duration_1[0] + 100;
//			choose_mode = 2;
//			choose_duration = 0;
//			if(timer_flag[3]==1){
//				Display_7SEG_mode();
//			}
//		}
//		if(is_button_pressed(2)==1){
//			duration[0] = duration_1[0];
//			led_1 = 1;
//			Display_7SEG_Timer();
//		}
		break;
	case 3:  // ALL LED_YELLOW blink, 7SEG display mode and time for led_yellow
		LedYellowAll();
		choose_mode = 3;
		choose_duration = 2;
		if(timer_flag[3]==1){
			clearAll();
			Display_7SEG_mode();
		}

		if(is_button_pressed(0)==1){
			clearAll();
			setTimer(50, 3);
			led = INIT_1;
			Display_7SEG_mode();
			status_2 = 4;
		}
//		if(is_button_pressed(1)==1){
//			duration_1[2] = duration_1[2] + 100;
//			led_1 = 2;
//			Display_7SEG_Timer();
//		}
//		if(is_button_pressed(2)==1){
//			duration[2] = duration_1[2];
//			led_1 = 2;
//			Display_7SEG_Timer();
//		}
		break;
	case 4:  // ALL LED_GREEN blink, 7SEG display mode and time for led_green
		LedGreenAll();
		choose_mode = 4;
		choose_duration = 1;
		if(timer_flag[3]==1){
			clearAll();
			Display_7SEG_mode();
		}

		if(is_button_pressed(0)==1){
			clearAll();
			status_2 = 0;
		}
//		if(is_button_pressed(1)==1){
//			duration_1[1] = duration_1[1] + 100;
//			led_1 = 3;
//			Display_7SEG_Timer();
//		}
//		if(is_button_pressed(2)==1){
//			duration[1] = duration_1[1];
//			led_1 = 3;
//			Display_7SEG_Timer();
//		}
		break;
	default:
		break;
	}
}

