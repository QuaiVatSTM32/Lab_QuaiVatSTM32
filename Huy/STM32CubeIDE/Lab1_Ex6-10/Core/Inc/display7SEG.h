/*
 * display7SEG.h
 *
 *  Created on: Oct 31, 2022
 *      Author: Admin
 */

#ifndef INC_DISPLAY7SEG_H_
#define INC_DISPLAY7SEG_H_

#include "display7SEG1.h"
#include "display7SEG2.h"

void display7SEG(int num){
	if(num<10) {
		display7SEG1(0);
		display7SEG2(num);
	}
	else{
		int first, second;
		second = num%10;
		first = (num - second)/10;
		display7SEG1(first);
		display7SEG2(second);
	}
}
#endif /* INC_DISPLAY7SEG_H_ */
