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

#define INIT			1
#define AUTO_RED		2
#define AUTO_GREEN		3
#define AUTO_YELLOW		4

#define MODE_2			11
#define MODE_3			12
#define MODE_4			13
#define MODE_1			14

extern int duration_red;
extern int duration_yellow;
extern int duration_green;

extern int duration_red_1;
extern int duration_yellow_1;
extern int duration_green_1;

extern int status;
extern int status_1;
extern int status_2;

extern int total;

#endif /* INC_GLOBAL_H_ */
