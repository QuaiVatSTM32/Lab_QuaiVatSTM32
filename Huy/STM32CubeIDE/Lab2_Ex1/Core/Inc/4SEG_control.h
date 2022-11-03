/*
 * 4SEG_control.h
 *
 *  Created on: Nov 2, 2022
 *      Author: Admin
 */

#ifndef INC_4SEG_CONTROL_H_
#define INC_4SEG_CONTROL_H_
#include "display7SEG.h"

void SEGS_control(int led_index, int num){
	switch (led_index){
		case 0:{
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin,0);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin,1);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin,1);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin,1);
			display7SEG(num);
			}
		break;
		case 1:{
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin,1);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin,0);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin,1);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin,1);
			display7SEG(num);
			}
			break;
		case 2:{
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin,1);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin,1);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin,0);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin,1);
			display7SEG(num);
			}
			break;
		case 3:{
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin,1);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin,1);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin,1);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin,0);
			display7SEG(num);
			}
			break;
		}
}

#endif /* INC_4SEG_CONTROL_H_ */
