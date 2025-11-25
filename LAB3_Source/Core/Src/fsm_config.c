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



static uint8_t index = 0;



void fsm_config()
{

	//scan7seg();
	switch(status1)
	{
		case INIT_CONFIG:
		{
			updateClock2Buffer(temp[index]);
			updateClock1Buffer(0);	//disable the first row of led segment
			status1 = RED_CONFIG;
		}
		case RED_CONFIG:
		{
			redAllOn();
			updateClock2Buffer(temp[index]);
			updateClock1Buffer(0);	//disable the first row of led segment
			if(isButtonPressed(0) == 1)
			{
				temp[0]++;
				if(temp[0] >= 99)
				{
					temp[0] = 99;
				}
			}
			if(isButtonPressed(1) == 1)
			{
				temp[0]--;
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
			index = 0;
			break;
		}
		case YELLOW_CONFIG:
		{
			yellowAllOn();
			updateClock2Buffer(temp[index]);
			updateClock1Buffer(0);	//disable the first row of led segment
			if(isButtonPressed(0) == 1)
			{
				temp[2]++;
				if(temp[2] >= 99)
				{
					temp[2] = 99;
				}
			}
			if(isButtonPressed(1) == 1)
			{
				temp[2]--;
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
			index = 2;
			break;
		}
		case GREEN_CONFIG:
		{
			greenAllOn();
			updateClock2Buffer(temp[index]);
			updateClock1Buffer(0);	//disable the first row of led segment
			if(isButtonPressed(0) == 1)
			{
				temp[1]++;
				if(temp[1] >= 99)
				{
					temp[1] = 99;
				}
			}
			if(isButtonPressed(1) == 1)
			{
				temp[1]--;
				if(temp[1] <= 0)
				{
					temp[1] = 0;
				}
			}
			if(isButtonPressed(2) == 1)
			{
				if(temp[1] + temp[2] != temp[0])
				{
					status1 = INIT;
				}
				else
				{
					setTimer(0, temp[0]);
					setTimer(1, temp[1]);
					status1 = RED_GREEN;
				}
			}
			if(isButtonPressed(3) == 1)
			{
				status1 = INIT;
			}
			index = 1;
			break;
		}
		default:
		{
			break;
		}
	}
}
