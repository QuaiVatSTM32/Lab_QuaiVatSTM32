/*
 * global.h
 *
 *  Created on: Nov 4, 2022
 *      Author: PC
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "input_processing.h"
#include "main.h"

#define INIT			22
#define AUTO_RED		23
#define AUTO_GREEN		24
#define AUTO_YELLOW		25
#define INIT_1			33


#define NUM_OF_MODE		4

#define NO_OF_LED		3

extern int duration[NO_OF_LED];
extern int duration_1[NO_OF_LED];
extern int duration_update[NO_OF_LED];
extern int mode[NUM_OF_MODE];


extern int status; // AUTO MODE
extern int status_1;// AUTO MODE
extern int status_2;// 4 MODE

extern int led; //
extern int led_1;
extern int led_2;

extern int choose_duration_divider;
extern int choose_mode;
extern int choose_duration; //INIT DURATION
extern int choose_duration_1;// SET DURATION
extern int choose_duration_update;// UPDATE DURATION

int choose_mode_run();
int choose_duration_run();
int choose_duration_run_1();
int choose_duration_run_update();


#endif /* INC_GLOBAL_H_ */
