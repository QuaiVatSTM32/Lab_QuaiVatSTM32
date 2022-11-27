/*
 * fsm_automatic.c
 *
 *  Created on: Nov 20, 2022
 *      Author: Admin
 */

#include "fsm_automatic.h"

int status1 = INIT, status2 = INIT;
int counter1 = 0, counter2 = 0;
int inputLEDbuffer[4] = {0,0,0,0};

void fsm_automatic_run(){

	inputLEDbuffer[1] = counter1%10;
	inputLEDbuffer[0] = (counter1-inputLEDbuffer[1])/10;
	inputLEDbuffer[3] = counter2%10;
	inputLEDbuffer[2] = (counter2-inputLEDbuffer[3])/10;
	updateSEGBuffer(inputLEDbuffer);

	if(timer_flag[0] == 1) {
		setTimer(1000, 0);
		counter1--, counter2--;
	}

	switch (status1){
				case INIT:
					if(counter1<=0) {
						status1 = RED;
						counter1 = LED_RED_init;
					}
					traficDisplay1(INIT);
					break;
				case RED:
					if(counter1<=0){
						status1 = GREEN;
						counter1 = LED_GREEN_init;
					}
					traficDisplay1(RED);
					break;
				case GREEN:
					if(counter1<=0){
						status1 = YELLOW;
						counter1 = LED_YELLOW_init;
					}
					traficDisplay1(GREEN);
					break;
				case YELLOW:
					if(counter1<=0){
						status1 = RED;
						counter1 = LED_RED_init;
					}
					traficDisplay1(YELLOW);
					break;
		}
	switch (status2){
			case INIT:
				if(counter2<=0) {
					status2 = GREEN;
					counter2 = LED_GREEN_init;
				}
				traficDisplay2(INIT);
				break;
			case RED:
				if(counter2<=0){
					status2 = GREEN;
					counter2 = LED_GREEN_init;
				}
				traficDisplay2(RED);
				break;
			case GREEN:
				if(counter2<=0){
					status2 = YELLOW;
					counter2 = LED_YELLOW_init;
				}
				traficDisplay2(GREEN);
				break;
			case YELLOW:
				if(counter2<=0){
					status2 = RED;
					counter2 = LED_RED_init;
				}
				traficDisplay2(YELLOW);
				break;
	}
}
