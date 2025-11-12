/*
 * software_timer.h
 *
 *  Created on: Oct 29, 2025
 *      Author: LENOVO
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_


void timerRun();
void setTimer(int index, int value);
int isTimerExpired(int index);

#endif /* INC_SOFTWARE_TIMER_H_ */
