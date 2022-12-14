/*
 * AnalogWatch.h
 *
 *  Created on: Oct 31, 2022
 *      Author: Admin
 */

#ifndef INC_ANALOGWATCH_H_
#define INC_ANALOGWATCH_H_

static int Array[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
void setClockStatus(){
	//TODO
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

void clearAllClock(){
	//TODO
	for(int i = 0; i<12; i++) Array[i] = 0;
	setClockStatus();
}

void setNumberOnClock(int num){
	//TODO
	Array[num] = 1;
	setClockStatus();
}

void clearNumberOnClock(int num){
	//TODO
	Array[num] = 0;
	setClockStatus();
}

int setTime(int hr, int min, int sec){
	clearAllClock();
	//TODO
	int hr_state = hr;
	int min_state = (min - min%5)/5;
	int sec_state = (sec - sec%5)/5;
	//For hour
	setNumberOnClock(hr_state);
	//For minutes
	setNumberOnClock(min_state);
	//For second
	setNumberOnClock(sec_state);
	return sec;
}

#endif /* INC_ANALOGWATCH_H_ */
