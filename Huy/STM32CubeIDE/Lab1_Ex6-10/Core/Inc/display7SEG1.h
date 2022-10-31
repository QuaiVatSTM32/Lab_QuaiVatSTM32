/*
 * display7SEG.h
 *
 *  Created on: Oct 30, 2022
 *      Author: Admin
 */

#ifndef SRC_DISPLAY7SEG_H_
#define SRC_DISPLAY7SEG_H_


#endif /* SRC_DISPLAY7SEG_H_ */

void Led_Status1(int LedArray[7]){
		  HAL_GPIO_WritePin ( A1_GPIO_Port, A1_Pin , LedArray[0]);
		  HAL_GPIO_WritePin ( B1_GPIO_Port, B1_Pin , LedArray[1]);
		  HAL_GPIO_WritePin ( C1_GPIO_Port, C1_Pin , LedArray[2]);
		  HAL_GPIO_WritePin ( D1_GPIO_Port, D1_Pin , LedArray[3]);
		  HAL_GPIO_WritePin ( E1_GPIO_Port, E1_Pin , LedArray[4]);
		  HAL_GPIO_WritePin ( F1_GPIO_Port, F1_Pin , LedArray[5]);
		  HAL_GPIO_WritePin ( G1_GPIO_Port, G1_Pin , LedArray[6]);
}

void display7SEG1(int num){
	switch(num){
		case 0: {
					int LedArray[7] = { 0, 0, 0, 0, 0, 0, 1};
					Led_Status1(LedArray);
				}
		break;

		case 1: {
					int LedArray[7] = { 1, 0, 0, 1, 1, 1, 1};
					Led_Status1(LedArray);
				}
				break;
		case 2: {
					int LedArray[7] = { 0, 0, 1, 0, 0, 1, 0};
					Led_Status1(LedArray);
				}
				break;
		case 3: {
					int LedArray[7] = { 0, 0, 0, 0, 1, 1, 0};
					Led_Status1(LedArray);
				}
				break;
		case 4: {
					int LedArray[7] = { 1, 0, 0, 1, 1, 0, 0};
					Led_Status1(LedArray);
				}
				break;
		case 5: {
					int LedArray[7] = { 0, 1, 0, 0, 1, 0, 0};
					Led_Status1(LedArray);
				}
				break;
		case 6: {
					int LedArray[7] = { 0, 1, 0, 0, 0, 0, 0};
					Led_Status1(LedArray);
				}
				break;
		case 7: {
					int LedArray[7] = { 0, 0, 0, 1, 1, 1, 1};
					Led_Status1(LedArray);
				}
				break;
		case 8: {
					int LedArray[7] = { 0, 0, 0, 0, 0, 0, 0};
					Led_Status1(LedArray);
				}
				break;
		case 9: {
					int LedArray[7] = { 0, 0, 0, 0, 1, 0, 0};
					Led_Status1(LedArray);
				}
				break;
		default: {
					int LedArray[7] = { 0, 0, 0, 0, 0, 0, 1};
					Led_Status1(LedArray);
				}
				break;
	}
}

