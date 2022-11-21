/*
 * software_timer.h
 *
 *  Created on: Nov 4, 2022
 *      Author: PC
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "main.h"

extern int timer_flag[4];

void setTimer(int duration, int T_index);
void timerRun();


#endif /* INC_SOFTWARE_TIMER_H_ */
