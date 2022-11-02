/*
 * software_timer.c
 *
 *  Created on: Nov 1, 2022
 *      Author: PC
 */

#include "software_timer.h"

int counter_timer1;
int timer1_flag = 0;

void setTimer(int duration){
	counter_timer1 = duration;
	timer1_flag = 0;
}
void timerRun(){
	if(counter_timer1 > 0){
		counter_timer1--;
		if(counter_timer1<=0) timer1_flag = 1;
	}
}
