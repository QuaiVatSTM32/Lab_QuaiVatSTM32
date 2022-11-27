/*
 * software_timer.c
 *
 *  Created on: Nov 1, 2022
 *      Author: Admin
 */

#include "software_timer.h"
const int TIMER_CYCLE = 10;
int timer_counter[3] = {0, 0, 0};
int timer_flag[3] = {0, 0, 0};

void setTimer0(int duration){
	timer_counter[0] = duration/TIMER_CYCLE;
	timer_flag[0] = 0;
}
void setTimer1(int duration){
	timer_counter[1] = duration/TIMER_CYCLE;
	timer_flag[1] = 0;
}
void setTimer2(int duration){
	timer_counter[2] = duration/TIMER_CYCLE;
	timer_flag[2] = 0;
}

void timerRun(){
	for(int i = 0; i<3; i++){
		if(timer_counter[i] > 0){
			timer_counter[i]--;
			if(timer_counter[i] <= 0) timer_flag[i] = 1;
		}
	}
}

