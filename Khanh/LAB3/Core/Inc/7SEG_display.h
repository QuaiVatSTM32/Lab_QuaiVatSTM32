/*
 * 7SEG_display.h
 *
 *  Created on: Nov 4, 2022
 *      Author: PC
 */

#ifndef INC_7SEG_DISPLAY_H_
#define INC_7SEG_DISPLAY_H_

#include "main.h"
#include "global.h"
#include "fsm_4mode.h"
#include "software_timer.h"

void LED_7SEG(int status);
void Display_7SEG_mode();
void Display7SEGwithNum(int input[4]);
void Display_7SEG_Timer();
void EnBuffer(int n);
void clearEnBuffer();

#endif /* INC_7SEG_DISPLAY_H_ */
