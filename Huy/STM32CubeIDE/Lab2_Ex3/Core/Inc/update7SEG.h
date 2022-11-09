/*
 * update7SEG.h
 *
 *  Created on: Nov 3, 2022
 *      Author: Admin
 */

#ifndef INC_UPDATE7SEG_H_
#define INC_UPDATE7SEG_H_


const int MAX_LED = 4;
int index_led = 0;
int led_buffer [4] = {1, 2, 3, 4};

void update7SEG ( int index ){
	switch ( index ){
	case 0:
		// Display the first 7 SEG with led_buffer [0]
		break ;
	case 1:
		// Display the second 7 SEG with led_buffer [1]
		break ;
	case 2:
		// Display the third 7 SEG with led_buffer [2]
		break ;
	case 3:
		// Display the forth 7 SEG with led_buffer [3]
		break ;
	default :
	break ;
}
 
#endif /* INC_UPDATE7SEG_H_ */
