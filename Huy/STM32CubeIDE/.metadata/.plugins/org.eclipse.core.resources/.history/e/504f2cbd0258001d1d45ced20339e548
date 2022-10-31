/*
 * trafic_light1.h
 *
 *  Created on: Oct 30, 2022
 *      Author: Admin
 */

#ifndef INC_TRAFIC_LIGHT1_H_
#define INC_TRAFIC_LIGHT1_H_

void LED_RED1(){
	  HAL_GPIO_WritePin ( LED_RED1_GPIO_Port , LED_RED1_Pin , 1);
	  HAL_GPIO_WritePin ( LED_YELLOW1_GPIO_Port , LED_YELLOW1_Pin , 0);
	  HAL_GPIO_WritePin ( LED_GREEN1_GPIO_Port , LED_GREEN1_Pin , 0);
}

void LED_YELLOW1(){
	  HAL_GPIO_WritePin ( LED_RED1_GPIO_Port , LED_RED1_Pin , 0);
	  HAL_GPIO_WritePin ( LED_YELLOW1_GPIO_Port , LED_YELLOW1_Pin , 1);
	  HAL_GPIO_WritePin ( LED_GREEN1_GPIO_Port , LED_GREEN1_Pin , 0);
}

void LED_GREEN1(){
	  HAL_GPIO_WritePin ( LED_RED1_GPIO_Port , LED_RED1_Pin , 0);
	  HAL_GPIO_WritePin ( LED_YELLOW1_GPIO_Port , LED_YELLOW1_Pin , 0);
	  HAL_GPIO_WritePin ( LED_GREEN1_GPIO_Port , LED_GREEN1_Pin , 1);
}


#endif /* INC_TRAFIC_LIGHT1_H_ */
