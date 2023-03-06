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
int duration_update[NO_OF_LED] = {500, 300, 200};
int mode[NUM_OF_MODE] = {1,2,3,4};

int DisplayNumAutoMode[4] ={0,5,0,3};


int led = 0;
int led_1 = 0;
int led_2 = 0;
int total = 0;

int choose_mode = 0;
int choose_duration = 0;
int choose_duration_1 = 0;
int choose_duration_update = 0;

int choose_duration_divider = 0;


