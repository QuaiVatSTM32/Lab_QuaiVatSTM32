/*
 * button.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Admin
 */

#include "button.h"

int button_flag[3] = {0, 0, 0};
int MAX_button = 3;

int KeyReg0[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg1[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg2[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};

int KeyReg3[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int TimerForKeyPress = 300;

int isButton0Pressed(){
	if(button_flag[0] == 1){
		button_flag[0] = 0;
		return 1;
	}
	return 0;
}

int isButton1Pressed(){
	if(button_flag[1] == 1){
		button_flag[1] = 0;
		return 1;
	}
	return 0;
}

int isButton2Pressed(){
	if(button_flag[2] == 1){
		button_flag[2] = 0;
		return 1;
	}
	return 0;
}

//void subKeyProcess(){
//	//TODO
//	button1_flag = 1;
//}

void getKeyInput(){
	for(int i = 0; i<MAX_button; i++){
		KeyReg2[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg0[i];
		switch(i){
		case 0: KeyReg0[i] = HAL_GPIO_ReadPin(Button0_GPIO_Port, Button0_Pin);
				break;
		case 1: KeyReg0[i] = HAL_GPIO_ReadPin(Button1_GPIO_Port, Button1_Pin);
				break;
		case 2: KeyReg0[i] = HAL_GPIO_ReadPin(Button2_GPIO_Port, Button2_Pin);
				break;
		}
		if((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i])){
			if(KeyReg2[i] != KeyReg3[i]){
				KeyReg3[i] = KeyReg2[i];

				if(KeyReg3[i] == PRESSED_STATE){
					//TODO
					button_flag[i] = 1;
					TimerForKeyPress = 300;
				}
			} else{
				TimerForKeyPress--;
				if(TimerForKeyPress == 0){
					//TODO
					KeyReg3[i] = NORMAL_STATE;
				}
			}
		}
	}
}
