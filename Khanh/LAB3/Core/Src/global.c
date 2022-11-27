/*
 * global.c
 *
 *  Created on: Nov 4, 2022
 *      Author: PC
 */
#include "global.h"

int status = 0;
int status_1 = 0;
int status_2 = 0;

int duration[NO_OF_LED] = {500, 300, 200};
int duration_1[NO_OF_LED] = {500, 300, 200};
int mode[NUM_OF_MODE] = {1,2,3,4};

int led = 0;
int led_1 = 0;
int led_2 = 0;
int total = 0;

int choose_mode = 0;
int choose_duration = 0;
int choose_duration_1 = 0;

int choose_duration_divider = 0;

int choose_mode_run(){
	switch(choose_mode){
	case 2:
		return 2;
	case 3:
		return 3;
	case 4:
		return 4;
	default:
		break;
	}
	return 0;

}
int choose_duration_run(){
	switch(choose_duration){
	case 0:
		return duration[0]/100;
	case 1:
		return duration[1]/100;
	case 2:
		return duration[2]/100;
	default:
		return 0;
	}
	return 0;
}
int choose_duration_run_1(){
	switch(choose_duration_1){
	case 0:
		return duration_1[0]/100;
	case 1:
		return duration_1[1]/100;
	case 2:
		return duration_1[2]/100;
	default:
		return 0;
	}
	return 0;
}

