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

			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
			HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, RESET);
			HAL_GPIO_WritePin(LED_AMB1_GPIO_Port, LED_AMB1_Pin, RESET);
			HAL_GPIO_WritePin(LED_AMB2_GPIO_Port, LED_AMB2_Pin, RESET);
			HAL_GPIO_WritePin(LED_GRE1_GPIO_Port, LED_GRE1_Pin, RESET);
			HAL_GPIO_WritePin(LED_GRE2_GPIO_Port, LED_GRE2_Pin, SET);
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
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, RESET);
			HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, RESET);
			HAL_GPIO_WritePin(LED_AMB1_GPIO_Port, LED_AMB1_Pin, SET);
			HAL_GPIO_WritePin(LED_AMB2_GPIO_Port, LED_AMB2_Pin, SET);
			HAL_GPIO_WritePin(LED_GRE1_GPIO_Port, LED_GRE1_Pin, RESET);
			HAL_GPIO_WritePin(LED_GRE2_GPIO_Port, LED_GRE2_Pin, RESET);
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
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, RESET);
			HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, SET);
			HAL_GPIO_WritePin(LED_AMB1_GPIO_Port, LED_AMB1_Pin, RESET);
			HAL_GPIO_WritePin(LED_AMB2_GPIO_Port, LED_AMB2_Pin, RESET);
			HAL_GPIO_WritePin(LED_GRE1_GPIO_Port, LED_GRE1_Pin, SET);
			HAL_GPIO_WritePin(LED_GRE2_GPIO_Port, LED_GRE2_Pin, RESET);
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
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, RESET);
			HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, RESET);
			HAL_GPIO_WritePin(LED_AMB1_GPIO_Port, LED_AMB1_Pin, SET);
			HAL_GPIO_WritePin(LED_AMB2_GPIO_Port, LED_AMB2_Pin, SET);
			HAL_GPIO_WritePin(LED_GRE1_GPIO_Port, LED_GRE1_Pin, RESET);
			HAL_GPIO_WritePin(LED_GRE2_GPIO_Port, LED_GRE2_Pin, RESET);
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
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, RESET);
			HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, RESET);
			HAL_GPIO_WritePin(LED_GRE1_GPIO_Port, LED_GRE1_Pin, RESET);
			HAL_GPIO_WritePin(LED_GRE2_GPIO_Port, LED_GRE2_Pin, RESET);
			if(isTimerExpired(3) == 1)
			{
				HAL_GPIO_TogglePin(LED_AMB1_GPIO_Port, LED_AMB1_Pin);
				HAL_GPIO_TogglePin(LED_AMB2_GPIO_Port, LED_AMB2_Pin);
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
