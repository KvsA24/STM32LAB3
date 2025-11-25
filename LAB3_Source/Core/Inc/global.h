/*
 * global.h
 *
 *  Created on: Oct 31, 2025
 *      Author: LENOVO
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_


#define INIT 1
#define RED_GREEN 2
#define YELLOW_RED 3
#define GREEN_RED 4
#define YELLOW_GREEN 5
#define RED_YELLOW 6

#define INIT_MANUAL 21
#define RED_MANUAL 22
#define YELLOW_MANUAL 23
#define YELLOW_MANUAL_2s 24
#define GREEN_MANUAL 25
#define R_G_MANUAL 26
#define G_R_MANUAL 27

#define INIT_CONFIG 31
#define RED_CONFIG 32
#define YELLOW_CONFIG 33
#define GREEN_CONFIG 34

#define CONFIRM 41

#define MAX_INDEX 10

extern int timerCycle;
extern int timer_counter[MAX_INDEX];
extern int timer_flag[MAX_INDEX];
extern int clock_buffer[4];
extern int temp[MAX_INDEX];
int segScan;
extern int status1;


#endif /* INC_GLOBAL_H_ */
