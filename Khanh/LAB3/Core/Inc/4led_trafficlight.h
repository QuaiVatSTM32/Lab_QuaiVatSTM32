/*
 * 4led_trafficlight.h
 *
 *  Created on: Nov 18, 2022
 *      Author: PC
 */

#ifndef INC_4LED_TRAFFICLIGHT_H_
#define INC_4LED_TRAFFICLIGHT_H_
#include "main.h"
#include "software_timer.h"
#include "global.h"
#include "7SEG_display.h"
#include "fsm_4mode.h"

void LedRedAll();
void LedGreenAll();
void LedYellowAll();


void clearAll();

void fsm_mode1_run();

#endif /* INC_4LED_TRAFFICLIGHT_H_ */
