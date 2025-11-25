/*
 * fsm_manual.c
 *
 *  Created on: Nov 9, 2025
 *      Author: LENOVO
 */
#include "main.h"
#include "fsm_config.h"
#include "7seg.h"
#include "button.h"
#include "software_timer.h"
#include "global.h"
#include "traffic_light.h"



static uint8_t count = 0;



void fsm_config()
{

	//scan7seg();
	switch(status1)
	{
		case INIT_CONFIG:
		{
			updateClock2Buffer(temp[0]);
			updateClock1Buffer(0);	//disable the first row of led segment
			status1 = RED_CONFIG;
		}
		case RED_CONFIG:
		{
			redAllOn();
			updateClock2Buffer(temp[0]);
			updateClock1Buffer(0);	//disable the first row of led segment
			if(isButtonPressed(0) == 1)
			{
				temp[0]+=1000;
				if(temp[0] >= 99000)
				{
					temp[0] = 99000;
				}
			}
			if(isButtonPressed(1) == 1)
			{
				temp[0]-=1000;
				if(temp[0] <= 0)
				{
					temp[0] = 0;
				}
			}
			if(isButtonPressed(2) == 1)
			{
				status1 = YELLOW_CONFIG;
			}
			if(isButtonPressed(3) == 1)
			{
				status1 = INIT;
			}
			break;
		}
		case YELLOW_CONFIG:
		{
			yellowAllOn();
			updateClock2Buffer(temp[2]);
			updateClock1Buffer(0);	//disable the first row of led segment
			if(isButtonPressed(0) == 1)
			{
				temp[2]+=1000;
				if(temp[2] >= 99000)
				{
					temp[2] = 99000;
				}
			}
			if(isButtonPressed(1) == 1)
			{
				temp[2]-=1000;
				if(temp[2] <= 0)
				{
					temp[2] = 0;
				}
			}
			if(isButtonPressed(2) == 1)
			{
				status1 = GREEN_CONFIG;
			}
			if(isButtonPressed(3) == 1)
			{
				status1 = INIT;
			}
			break;
		}
		case GREEN_CONFIG:
		{
			greenAllOn();
			updateClock2Buffer(temp[1]);
			updateClock1Buffer(0);	//disable the first row of led segment
			if(isButtonPressed(0) == 1)
			{
				temp[1]+=1000;
				if(temp[1] >= 99000)
				{
					temp[1] = 99000;
				}
			}
			if(isButtonPressed(1) == 1)
			{
				temp[1]-=1000;
				if(temp[1] <= 0)
				{
					temp[1] = 0;
				}
			}
			if(isButtonPressed(2) == 1)
			{
				setTimer(4, 500);
				status1 = CONFIRM;
				count = 0;
			}
			if(isButtonPressed(3) == 1)
			{
				status1 = INIT;
			}
			break;
		}
		case CONFIRM:
		{
			if(temp[1] + temp[2] != temp[0])
			{
				if(isTimerExpired(4) == 1)
				{
					if(count < 4)
					{
						yellowBlinky();
						count++;
					}
					else
					{
						status1 = INIT;
					}
				}
			}
			else
			{
				if(isTimerExpired(4) == 1)
				{
					if(count < 2)
					{
						yellowBlinky();
						count++;
					}
					else
					{
						setTimer(0, temp[0]);
						setTimer(1, temp[1]);
						status1 = RED_GREEN;
					}
				}
			}
		}
		default:
		{
			break;
		}
	}
}
