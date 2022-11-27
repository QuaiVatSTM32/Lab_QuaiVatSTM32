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
		status = INIT;
		status_1 = INIT;

		status_2 = 1;
	case 1: //	AUTO MODE
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
		choose_mode = 2;
		choose_duration_update = 0;
		LedRedAll();

		if(timer_flag[3]==1){
			clearAll();
			Display_7SEG_mode();

			if(is_button_pressed(0)==1){
				clearAll();
				setTimer(50, 3);
				led = INIT_1;
				Display_7SEG_mode();
				status_2 = 3;
			}
			if(is_button_pressed(1)==1){
				led = INIT_1;
				duration_update[0] = duration_update[0] + 100;
				choose_mode = 2;
				if(duration_update[0]<=900){
					choose_duration_update = duration_update[0]/100;
				}
				else{
					choose_duration_divider = duration_update[0]/1000;
					choose_duration_update = (duration_update[0] - (duration_update[0]%1000))/100;
				}

				Display_7SEG_mode();
			}
			if(is_button_pressed(2)==1){
				led = INIT_1;
				choose_mode = 2;
				duration[0] = duration_update[0];
				duration_1[0] = duration_update [0];
				choose_duration_update = duration_update[0]/100;
				Display_7SEG_mode();
			}
		}
		break;
	case 3:  // ALL LED_YELLOW blink, 7SEG display mode and time for led_yellow
		choose_mode = 3;
		choose_duration_update = 2;
		LedYellowAll();
		if(timer_flag[3]==1){
			clearAll();
			Display_7SEG_mode();

			if(is_button_pressed(0)==1){
				clearAll();
				setTimer(50, 3);
				led = INIT_1;
				Display_7SEG_mode();
				status_2 = 4;
			}

			if(is_button_pressed(1)==1){
				led = INIT_1;
				duration_update[2] = duration_update[2] + 100;
				choose_mode = 3;
				if(duration_update[2]<=900){
					choose_duration_update = duration_update[2]/100;
				}
				else{
					choose_duration_divider = duration_update[2]/1000;
					choose_duration_update = (duration_update[2] - (duration_update[2]%1000))/100;
				}

				Display_7SEG_mode();
			}
			if(is_button_pressed(2)==1){
				led = INIT_1;
				duration[2] = duration_update[2];
				duration_1[2] = duration_update [2];
				choose_mode = 3;
				choose_duration_update = duration_update[2]/100;
				Display_7SEG_mode();
			}
		}
		break;
	case 4:  // ALL LED_GREEN blink, 7SEG display mode and time for led_green
		choose_mode = 4;
		choose_duration_update = 1;
		LedGreenAll();

		if(timer_flag[3]==1){
			clearAll();
			Display_7SEG_mode();

			if(is_button_pressed(0)==1){
				clearAll();
				status_2 = 0;

			}

			if(is_button_pressed(1)==1){
				led = INIT_1;
				duration_update[1] = duration_update[1] + 100;
				choose_mode = 2;
				if(duration_update[1]<=900){
					choose_duration_update = duration_update[1]/100;
				}
				else{
					choose_duration_divider = duration_update[1]/1000;
					choose_duration_update = (duration_update[1] - (duration_update[1]%1000))/100;
				}

				Display_7SEG_mode();
			}
			if(is_button_pressed(2)==1){
				led = INIT_1;
				duration[1] = duration_update[1];
				duration_1[1] = duration_update [1];
				choose_mode = 4;
				choose_duration_update = duration_update[1]/100;
				Display_7SEG_mode();
			}
	}

		break;
	default:
		break;
	}
}

