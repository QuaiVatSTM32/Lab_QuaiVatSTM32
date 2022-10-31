/*
 * trafic_light2.h
 *
 *  Created on: Oct 30, 2022
 *      Author: Admin
 */

#ifndef INC_TRAFIC_LIGHT2_H_
#define INC_TRAFIC_LIGHT2_H_

void LED_RED2(){
	  HAL_GPIO_WritePin ( LED_RED2_GPIO_Port , LED_RED2_Pin , 1);
	  HAL_GPIO_WritePin ( LED_YELLOW2_GPIO_Port , LED_YELLOW2_Pin , 0);
	  HAL_GPIO_WritePin ( LED_GREEN2_GPIO_Port , LED_GREEN2_Pin , 0);
}

void LED_YELLOW2(){
	HAL_GPIO_WritePin ( LED_RED2_GPIO_Port , LED_RED2_Pin , 0);
	HAL_GPIO_WritePin ( LED_YELLOW2_GPIO_Port , LED_YELLOW2_Pin , 1);
	HAL_GPIO_WritePin ( LED_GREEN2_GPIO_Port , LED_GREEN2_Pin , 0);
}

void LED_GREEN2(){
	HAL_GPIO_WritePin ( LED_RED2_GPIO_Port , LED_RED2_Pin , 0);
	HAL_GPIO_WritePin ( LED_YELLOW2_GPIO_Port , LED_YELLOW2_Pin , 0);
	HAL_GPIO_WritePin ( LED_GREEN2_GPIO_Port , LED_GREEN2_Pin , 1);
}


#endif /* INC_TRAFIC_LIGHT2_H_ */
