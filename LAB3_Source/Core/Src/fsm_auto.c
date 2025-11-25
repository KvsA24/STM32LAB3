/*
 * fsm_auto.c
 *
 *  Created on: Nov 1, 2025
 *      Author: LENOVO
 */

#include "global.h"
#include "software_timer.h"
#include "button.h"
#include "7seg.h"
#include "fsm_auto.h"
#include "main.h"
#include "traffic_light.h"


void fsm_auto()
{
	//Traffic light
	switch(status1)
	{
		case INIT:
		{
			setTimer(0, 5);
			setTimer(1, 3);
			temp[0] = 5;
			temp[1] = 3;
			temp[2] = 2;
			reset();
			updateClock1Buffer((timer_counter[0] * timerCycle + 500)/ 1000);
			updateClock2Buffer(0);	//disable the second row of led segment
			scan7seg();
			status1 = RED_GREEN;
			break;
		}
		case RED_GREEN:
		{
			Red_Green();
			updateClock1Buffer((timer_counter[0] * timerCycle + 500)/ 1000);
			updateClock2Buffer(0);	//disable the second row of led segment
			if(isTimerExpired(1) == 1)
			{
				setTimer(1, temp[2]);
				status1 = RED_YELLOW;
				updateClock1Buffer((timer_counter[0] * timerCycle + 500)/ 1000);
				updateClock2Buffer(0);	//disable the second row of led segment
			}
			if(isButtonPressed(1) == 1)
			{
				status1 = INIT_MANUAL;
			}
			if(isButtonPressed(2) == 1)
			{
				status1 = INIT_CONFIG;
			}
			break;
		}
		case RED_YELLOW:
		{
			Red_Yellow();
			updateClock1Buffer((timer_counter[0] * timerCycle + 500)/ 1000);
			updateClock2Buffer(0);	//disable the second row of led segment
			if(isTimerExpired(1) == 1)
			{
				setTimer(1, temp[0]);
				setTimer(0, temp[1]);
				status1 = GREEN_RED;
				updateClock1Buffer((timer_counter[0] * timerCycle + 500)/ 1000);
				updateClock2Buffer(0);	//disable the second row of led segment
			}
			if(isButtonPressed(1) == 1)
			{
				status1 = INIT_MANUAL;
			}
			if(isButtonPressed(2) == 1)
			{
				status1 = INIT_CONFIG;
			}
			break;
		}
		case GREEN_RED:
		{
			Green_Red();
			updateClock1Buffer((timer_counter[0] * timerCycle + 500)/ 1000);
			updateClock2Buffer(0);	//disable the second row of led segment
			if(isTimerExpired(0) == 1)
			{
				status1 = YELLOW_RED;
				setTimer(0, temp[2]);
				updateClock1Buffer((timer_counter[0] * timerCycle + 500)/ 1000);
				updateClock2Buffer(0);	//disable the second row of led segment
			}
			if(isButtonPressed(1) == 1)
			{
				status1 = INIT_MANUAL;
			}
			if(isButtonPressed(2) == 1)
			{
				status1 = INIT_CONFIG;
			}
			break;
		}
		case YELLOW_RED:
		{
			Yellow_Red();
			updateClock1Buffer((timer_counter[0] * timerCycle + 500)/ 1000);
			updateClock2Buffer(0);	//disable the second row of led segment
			if(isTimerExpired(0) == 1)
			{
				status1 = RED_GREEN;
				setTimer(0, temp[0]);
				setTimer(1, temp[1]);
				updateClock1Buffer((timer_counter[0] * timerCycle + 500)/ 1000);
				updateClock2Buffer(0);	//disable the second row of led segment
			}
			if(isButtonPressed(1) == 1)
			{
				status1 = INIT_MANUAL;
			}
			if(isButtonPressed(2) == 1)
			{
				status1 = INIT_CONFIG;
			}
			break;
		}
		default:
		{
			break;
		}
	}
	//7segment
	scan7seg();
}

