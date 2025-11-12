/*
 * button.h
 *
 *  Created on: Oct 5, 2023
 *      Author: KAI
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#define NORMAL_STATE SET
#define PRESSED_STATE RESET
#define LONG_PRESS_DURATION 200
#define NUMBER_OF_BUTTONS 4

extern int button_flag[NUMBER_OF_BUTTONS];
int isButtonPressed(int index);
int isButtonLongPressed(int index);
void getKeyInput();

#endif /* INC_BUTTON_H_ */

