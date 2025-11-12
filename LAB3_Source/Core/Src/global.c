/*
 * global.c
 *
 *  Created on: Oct 31, 2025
 *      Author: LENOVO
 */
#include "global.h"


int timerCycle = 10;
int timer_counter[MAX_INDEX] = {0};
int timer_flag[MAX_INDEX] = {0};
int clock_buffer[4];
int temp[MAX_INDEX] = {0};
int segScan = 0;
int status1 = INIT;


