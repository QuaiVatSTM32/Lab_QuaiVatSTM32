/*
 * display7EG2.h
 *
 *  Created on: Oct 31, 2022
 *      Author: Admin
 */

#ifndef INC_DISPLAY7SEG2_H_
#define INC_DISPLAY7SEG2_H_

void Led_Status2(int LedArray[7]){
		  HAL_GPIO_WritePin ( A2_GPIO_Port, A2_Pin , LedArray[0]);
		  HAL_GPIO_WritePin ( B2_GPIO_Port, B2_Pin , LedArray[1]);
		  HAL_GPIO_WritePin ( C2_GPIO_Port, C2_Pin , LedArray[2]);
		  HAL_GPIO_WritePin ( D2_GPIO_Port, D2_Pin , LedArray[3]);
		  HAL_GPIO_WritePin ( E2_GPIO_Port, E2_Pin , LedArray[4]);
		  HAL_GPIO_WritePin ( F2_GPIO_Port, F2_Pin , LedArray[5]);
		  HAL_GPIO_WritePin ( G2_GPIO_Port, G2_Pin , LedArray[6]);
}

void display7SEG2(int num){
	switch(num){
		case 0: {
					int LedArray[7] = { 0, 0, 0, 0, 0, 0, 1};
					Led_Status2(LedArray);
				}
		break;

		case 1: {
					int LedArray[7] = { 1, 0, 0, 1, 1, 1, 1};
					Led_Status2(LedArray);
				}
				break;
		case 2: {
					int LedArray[7] = { 0, 0, 1, 0, 0, 1, 0};
					Led_Status2(LedArray);
				}
				break;
		case 3: {
					int LedArray[7] = { 0, 0, 0, 0, 1, 1, 0};
					Led_Status2(LedArray);
				}
				break;
		case 4: {
					int LedArray[7] = { 1, 0, 0, 1, 1, 0, 0};
					Led_Status2(LedArray);
				}
				break;
		case 5: {
					int LedArray[7] = { 0, 1, 0, 0, 1, 0, 0};
					Led_Status2(LedArray);
				}
				break;
		case 6: {
					int LedArray[7] = { 0, 1, 0, 0, 0, 0, 0};
					Led_Status2(LedArray);
				}
				break;
		case 7: {
					int LedArray[7] = { 0, 0, 0, 1, 1, 1, 1};
					Led_Status2(LedArray);
				}
				break;
		case 8: {
					int LedArray[7] = { 0, 0, 0, 0, 0, 0, 0};
					Led_Status2(LedArray);
				}
				break;
		case 9: {
					int LedArray[7] = { 0, 0, 0, 0, 1, 0, 0};
					Led_Status2(LedArray);
				}
				break;
		default: {
					int LedArray[7] = { 0, 0, 0, 0, 0, 0, 1};
					Led_Status2(LedArray);
				}
				break;
	}
}


#endif /* INC_DISPLAY7SEG2_H_ */
