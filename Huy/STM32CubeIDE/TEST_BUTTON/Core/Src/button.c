/*
 * button.c
 *
 *  Created on: Nov 1, 2022
 *      Author: PC
 */
#include "button.h"

int button1_flag = 0;

int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;
int KeyReg3 = NORMAL_STATE;

int TimeOutForKeyPress =  200;


int isButton1Pressed(){
	if(button1_flag == 1){
		button1_flag = 0;
		return 1;
	}
	return 0;
}

// action to be done after button press
void subKeyProcess(){
	//TODO
	//HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
	button1_flag = 1;
}

// getKetInput: detect button pressed and execute subkeyprocess

void getKeyInput(){
	  KeyReg0 = KeyReg1;
	  KeyReg1 = KeyReg2;
	  KeyReg2 = HAL_GPIO_ReadPin(Button1_GPIO_Port, Button1_Pin);
	  if ((KeyReg0 == KeyReg1) && (KeyReg1 == KeyReg2)){
	    if (KeyReg3 != KeyReg2){
	      KeyReg3 = KeyReg2;

	      if (KeyReg2 == PRESSED_STATE){
		    subKeyProcess();
	        TimeOutForKeyPress = 200;

	      }
	    }else{
	       TimeOutForKeyPress --;
	        if (TimeOutForKeyPress == 0){
//	        	KeyReg3 = NORMAL_STATE;

	        	if(KeyReg2 == PRESSED_STATE){
			        subKeyProcess();
	        	}

	        	TimeOutForKeyPress = 200;

	        }

	    }
	  }

}

