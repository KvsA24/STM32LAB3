/*
 * software_timer.c
 *
 *  Created on: Oct 29, 2025
 *      Author: LENOVO
 */

#include "software_timer.h"
#include "global.h"
#include "main.h"

void setTimer(int index, int value)
{
	timer_counter[index] = value / timerCycle;
	timer_flag[index] = 0;
}

int isTimerExpired(int index)
{
	if(timer_flag[index] == 1)
	{
		return 1;
	}
	return 0;
}


void timerRun()
{
	for (int i = 0; i < MAX_INDEX; i++)
	{
		if(timer_counter[i] > 0)
		{
			timer_counter[i]--;
			if(timer_counter[i] <= 0)
			{
				timer_flag[i] = 1;
			}
		}
	}
}


