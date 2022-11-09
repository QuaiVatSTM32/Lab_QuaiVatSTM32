/*
 * display7SEG.c
 *
 *  Created on: Nov 6, 2022
 *      Author: Admin
 */

#include "display7SEG.h"

void Led_Status(int LedArray[7]){
		  HAL_GPIO_WritePin ( A_GPIO_Port, A_Pin , LedArray[0]);
		  HAL_GPIO_WritePin ( B_GPIO_Port, B_Pin , LedArray[1]);
		  HAL_GPIO_WritePin ( C_GPIO_Port, C_Pin , LedArray[2]);
		  HAL_GPIO_WritePin ( D_GPIO_Port, D_Pin , LedArray[3]);
		  HAL_GPIO_WritePin ( E_GPIO_Port, E_Pin , LedArray[4]);
		  HAL_GPIO_WritePin ( F_GPIO_Port, F_Pin , LedArray[5]);
		  HAL_GPIO_WritePin ( G_GPIO_Port, G_Pin , LedArray[6]);
}

void display7SEG(int num){
	switch(num){
		case 0: {
					int LedArray[7] = { 0, 0, 0, 0, 0, 0, 1};
					Led_Status(LedArray);
				}
		break;

		case 1: {
					int LedArray[7] = { 1, 0, 0, 1, 1, 1, 1};
					Led_Status(LedArray);
				}
				break;
		case 2: {
					int LedArray[7] = { 0, 0, 1, 0, 0, 1, 0};
					Led_Status(LedArray);
				}
				break;
		case 3: {
					int LedArray[7] = { 0, 0, 0, 0, 1, 1, 0};
					Led_Status(LedArray);
				}
				break;
		case 4: {
					int LedArray[7] = { 1, 0, 0, 1, 1, 0, 0};
					Led_Status(LedArray);
				}
				break;
		case 5: {
					int LedArray[7] = { 0, 1, 0, 0, 1, 0, 0};
					Led_Status(LedArray);
				}
				break;
		case 6: {
					int LedArray[7] = { 0, 1, 0, 0, 0, 0, 0};
					Led_Status(LedArray);
				}
				break;
		case 7: {
					int LedArray[7] = { 0, 0, 0, 1, 1, 1, 1};
					Led_Status(LedArray);
				}
				break;
		case 8: {
					int LedArray[7] = { 0, 0, 0, 0, 0, 0, 0};
					Led_Status(LedArray);
				}
				break;
		case 9: {
					int LedArray[7] = { 0, 0, 0, 0, 1, 0, 0};
					Led_Status(LedArray);
				}
				break;
		default: {
					int LedArray[7] = { 0, 0, 0, 0, 0, 0, 1};
					Led_Status(LedArray);
				}
				break;
	}
}
