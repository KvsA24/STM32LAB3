/*
 * fsm_manual.c
 *
 *  Created on: Nov 9, 2025
 *      Author: LENOVO
 */
#include "main.h"
#include "fsm_manual.h"
#include "7seg.h"
#include "button.h"
#include "software_timer.h"
#include "global.h"


void fsm_manual()
{
	switch(status1)
	{
		case INIT_MANUAL:
		{
			updateClock1Buffer(0);	//disable the first row of led segment
			updateClock2Buffer(0);
			status1 = RED_MANUAL;
		}
		case RED_MANUAL:
		{

			redOn();
			if(isButtonPressed(0) == 1)
			{
				status1 = R_G_MANUAL;
				setTimer(2, 2);
			}
			if(isButtonLongPressed(0) == 1)
			{
				status1 = YELLOW_MANUAL_2s;
				setTimer(3, 1);
			}
			if(isButtonPressed(3) == 1)
			{
				status1 = INIT;
			}
			break;
		}
		case R_G_MANUAL:
		{
			yellowAllOn();
			if(isTimerExpired(2) == 1)
			{
				status1 = GREEN_MANUAL;
				timer_flag[2] = 0;
			}
			if(isButtonLongPressed(0) == 1)
			{
				status1 = YELLOW_MANUAL_2s;
				setTimer(3, 1);
			}
			if(isButtonPressed(3) == 1)
			{
				status1 = INIT;
			}
			break;
		}
		case GREEN_MANUAL:
		{
			greenOn();
			if(isButtonPressed(0) == 1)
			{
				setTimer(2, 2);
				status1 = G_R_MANUAL;
			}
			if(isButtonLongPressed(0) == 1)
			{
				status1 = YELLOW_MANUAL_2s;
				setTimer(3, 1);
			}
			if(isButtonPressed(3) == 1)
			{
				status1 = INIT;
			}
			break;
		}
		case G_R_MANUAL:
		{
			yellowAllOn();
			if(isTimerExpired(2) == 1)
			{
				status1 = RED_MANUAL;
				timer_flag[2] = 0;
			}
			if(isButtonLongPressed(0) == 1)
			{
				status1 = YELLOW_MANUAL_2s;
				setTimer(3, 1);
			}
			if(isButtonPressed(3) == 1)
			{
				status1 = INIT;
			}
			break;
		}
		case YELLOW_MANUAL_2s:
		{
			reset();
			if(isTimerExpired(3) == 1)
			{
				yellowAllOn();
				setTimer(3, 1);
			}
			if(isButtonPressed(3) == 1)
			{
				status1 = INIT;
			}
			break;
		}
		default:
		{
			break;
		}
	}
}
