/*
 * button.h
 *
 *  Created on: Nov 5, 2022
 *      Author: Admin
 */

#ifndef SRC_BUTTON_H_
#define SRC_BUTTON_H_

#include "main.h"
#include "global.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

int isButtonPressed(int B_index);


void getKeyInput();

#endif /* SRC_BUTTON_H_ */
