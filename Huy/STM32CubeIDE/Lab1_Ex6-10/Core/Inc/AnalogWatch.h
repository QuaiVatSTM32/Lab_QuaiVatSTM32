/*
 * AnalogWatch.h
 *
 *  Created on: Oct 31, 2022
 *      Author: Admin
 */

#ifndef INC_ANALOGWATCH_H_
#define INC_ANALOGWATCH_H_

void displayAnalogWatch(int num){
	int Array[12];
	for(int i = 0; i<12; i++) Array[i] = 0;
	while(num>=12) num-=12;
	if(num > -1) Array[num] = 1;
	HAL_GPIO_WritePin ( W0_GPIO_Port, W0_Pin , Array[0]);
	HAL_GPIO_WritePin ( W1_GPIO_Port, W1_Pin , Array[1]);
	HAL_GPIO_WritePin ( W2_GPIO_Port, W2_Pin , Array[2]);
	HAL_GPIO_WritePin ( W3_GPIO_Port, W3_Pin , Array[3]);
	HAL_GPIO_WritePin ( W4_GPIO_Port, W4_Pin , Array[4]);
	HAL_GPIO_WritePin ( W5_GPIO_Port, W5_Pin , Array[5]);
	HAL_GPIO_WritePin ( W6_GPIO_Port, W6_Pin , Array[6]);
	HAL_GPIO_WritePin ( W7_GPIO_Port, W7_Pin , Array[7]);
	HAL_GPIO_WritePin ( W8_GPIO_Port, W8_Pin , Array[8]);
	HAL_GPIO_WritePin ( W9_GPIO_Port, W9_Pin , Array[9]);
	HAL_GPIO_WritePin ( W10_GPIO_Port, W10_Pin , Array[10]);
	HAL_GPIO_WritePin ( W11_GPIO_Port, W11_Pin , Array[11]);
}

void ClearAllClock(){
	displayAnalogWatch(-1);
}


#endif /* INC_ANALOGWATCH_H_ */
