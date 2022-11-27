/*
 * button.c
 *
 *  Created on: Nov 26, 2022
 *      Author: PC
 */
#include "main.h"

#define N0_OF_BUTTONS					3
#define BUTTON_IS_PRESSED				GPIO_PIN_RESET
#define BUTTON_IS_RELEASED 				GPIO_PIN_SET
#define DURATION_FOR_AUTO_INCREASING	100

int FLAG_CHECK_PRESSED[N0_OF_BUTTONS]={0,0,0};
static uint16_t counterForButtonPress1s [N0_OF_BUTTONS];

static GPIO_PinState Key_0 [N0_OF_BUTTONS];
static GPIO_PinState Key_1 [N0_OF_BUTTONS];
static GPIO_PinState Key_2 [N0_OF_BUTTONS];
static GPIO_PinState Key_3 [N0_OF_BUTTONS];

static uint8_t buttonBuffer [N0_OF_BUTTONS];
static uint8_t flagForButtonPress1s [N0_OF_BUTTONS];
static uint16_t counterForButtonPress1s [N0_OF_BUTTONS];
// mode  time  select button
// RESET INC DEC
void button_reading ( void ) {
	for ( unsigned char i = 0; i < N0_OF_BUTTONS ; i ++) {
			Key_2[i]=Key_1[i];
			Key_1[i]=Key_0[i];
			if (i==0)  Key_0[i] = HAL_GPIO_ReadPin (Button1_GPIO_Port, Button1_Pin);
			if (i==1)  Key_0[i] = HAL_GPIO_ReadPin (Button2_GPIO_Port, Button2_Pin);
			if (i==2)  Key_0[i] = HAL_GPIO_ReadPin (Button3_GPIO_Port, Button3_Pin);

			if(Key_2[i]==Key_1[i] && Key_1[i]==Key_0[i]){
				if(Key_3[i]!=Key_2[i]){
					Key_3[i]=Key_2[i];
					if(Key_3[i]==BUTTON_IS_PRESSED){
						buttonBuffer[i]=BUTTON_IS_PRESSED;
						counterForButtonPress1s[i] = DURATION_FOR_AUTO_INCREASING;
					}else{
						buttonBuffer[i]=BUTTON_IS_RELEASED;
						flagForButtonPress1s[i]=0;
						FLAG_CHECK_PRESSED[i]=1;
					}
				}else{
					if(Key_3[i]==BUTTON_IS_PRESSED){
						counterForButtonPress1s[i]--;
						if(counterForButtonPress1s[i]==0){
							flagForButtonPress1s[i]=1;
						}
					}
			}
		}
	}
}
unsigned char is_button_pressed ( uint8_t index ) {
	if( index >= N0_OF_BUTTONS ) return 0;
	if(buttonBuffer[index]==BUTTON_IS_PRESSED && FLAG_CHECK_PRESSED[index]==1 ){
		FLAG_CHECK_PRESSED[index]=0;
		return 1;
	}
	return 0;
}
unsigned char is_button_pressed_1s ( uint8_t index ) {
	if( index >= N0_OF_BUTTONS ) return 0;
	return (flagForButtonPress1s[index]==1);
}



