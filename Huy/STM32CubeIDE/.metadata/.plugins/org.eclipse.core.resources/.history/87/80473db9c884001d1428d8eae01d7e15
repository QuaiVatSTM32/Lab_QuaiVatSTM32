/*
 * fsm_manual.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Admin
 */

#include "fsm_manual.h"

void fsm_simple_buttons_run (){
	// TODO
	if(isButton0Pressed() == 1){
		if(timeOut == 1) {
			SevenSEGCounter = INIT;
			timeOut = 0;
		}
		else {
			SevenSEGCounter = 0;
			timeOut = 1;
		}
		setTimer1(10000);
	}
	if(isButton1Pressed() == 1){
		SevenSEGCounter++;
		if(SevenSEGCounter >= 10) SevenSEGCounter = 0;
		setTimer1(10000);
	}
	if(isButton2Pressed() == 1){
		if(timeOut == 1) {
			SevenSEGCounter = INIT;
			timeOut = 0;
		}
		else{
			SevenSEGCounter--;
			if(SevenSEGCounter < 0) SevenSEGCounter = 9;
		}
		setTimer1(10000);
	}

}
