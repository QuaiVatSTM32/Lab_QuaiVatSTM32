/*
 * SEGClockControl.h
 *
 *  Created on: Nov 4, 2022
 *      Author: Admin
 */

#ifndef INC_SEGCLOCKCONTROL_H_
#define INC_SEGCLOCKCONTROL_H_

#include "display7SEG.h"

const int MAX_LED = 4;
int index_led = 0;
int led_buffer [4] = {1, 2, 3, 4};

void update7SEG ( int index ){
	if(index_led >= MAX_LED) index_led = 0;
	switch ( index ){
	case 0:
		// Display the first 7 SEG with led_buffer [0]
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin,0);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin,1);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin,1);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin,1);
		display7SEG(led_buffer[0]);
		break ;
	case 1:
		// Display the second 7 SEG with led_buffer [1]
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin,1);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin,0);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin,1);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin,1);
		display7SEG(led_buffer[1]);
		break ;
	case 2:
		// Display the third 7 SEG with led_buffer [2]
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin,1);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin,1);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin,0);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin,1);
		display7SEG(led_buffer[2]);
		break ;
	case 3:
		// Display the forth 7 SEG with led_buffer [3]
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin,1);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin,1);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin,1);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin,0);
		display7SEG(led_buffer[3]);
		break ;
	default :
		break ;
	}
}
void updateClockBuffer (int hour, int minute){
	//Control the hour
	if(hour < 10) {
		led_buffer[0] = 0;
		led_buffer[1] = hour;
	}
	else{
		led_buffer[1] = hour%10;
		led_buffer[0] = (hour - led_buffer[1])/10;
	}
	//Control the minute
	if(minute < 10) {
		led_buffer[2] = 0;
		led_buffer[3] = minute;
		}
	else{
		led_buffer[3] = minute%10;
		led_buffer[2] = (minute - led_buffer[3])/10;
	}
}

#endif /* INC_SEGCLOCKCONTROL_H_ */
