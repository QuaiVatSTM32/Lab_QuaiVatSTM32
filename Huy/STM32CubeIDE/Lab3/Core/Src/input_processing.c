/*
 * input_processing.c
 *
 *  Created on: Nov 14, 2022
 *      Author: Admin
 */

#include "input_processing.h"


enum ButtonState { BUTTON_RELEASED , BUTTON_PRESSED ,
BUTTON_PRESSED_MORE_THAN_1_SECOND };

enum ButtonState buttonState = BUTTON_RELEASED ;
void fsm_for_input_processing ( void ){
	switch ( buttonState ){
		case BUTTON_RELEASED :
			if( is_button_pressed (0)){
				buttonState = BUTTON_PRESSED ;
				// INCREASE VALUE OF PORT A BY ONE UNIT
				TRAFFIC_MODE++;
				if(TRAFFIC_MODE>=5) TRAFFIC_MODE  =  1;
			}
				switch(TRAFFIC_MODE){
					case 1: fsm_automatic_run();
					break;
					case 2:
						traficDisplay1(RED);
						traficDisplay2(RED);
					break;
					case 3:
						traficDisplay1(YELLOW);
						traficDisplay2(YELLOW);
					break;
					case 4:
						traficDisplay1(GREEN);
						traficDisplay2(GREEN);
					break;
				}
			break ;
		case BUTTON_PRESSED :
			if (! is_button_pressed (0)){
				buttonState = BUTTON_RELEASED ;
				//TODO1
			} else {
				if( is_button_pressed_1s (0) ){
					buttonState = BUTTON_PRESSED_MORE_THAN_1_SECOND ;
				}
			}
			break ;
		case BUTTON_PRESSED_MORE_THAN_1_SECOND :
			if (! is_button_pressed (0)){
				buttonState = BUTTON_RELEASED ;
			}
				//TODO2
			break ;
	}
}
