/*
 * software_timer.h
 *
 *  Created on: Nov 1, 2022
 *      Author: Admin
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_
//#include "global.h"
extern int timer_flag[3];

void setTimer0(int duration);
void setTimer1(int duration);
void setTimer2(int duration);
void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
