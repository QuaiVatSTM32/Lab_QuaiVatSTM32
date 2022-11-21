/*
 * software_timer.c
 *
 *  Created on: Nov 4, 2022
 *      Author: PC
 */

#include "software_timer.h"

#define NO_OF_TIMER 	4


int timer_counter[NO_OF_TIMER] = {0, 0, 0, 0};
int timer_flag[NO_OF_TIMER] = {0, 0, 0, 0};

void setTimer(int duration, int T_index){
	timer_counter[T_index] = duration;
	timer_flag[T_index] = 0;
}

void timerRun(){
	for(int i = 0; i<NO_OF_TIMER; i++){
		if(timer_counter[i] > 0){
			timer_counter[i]--;
			if(timer_counter[i] <= 0) timer_flag[i] = 1;
		}
	}
}

