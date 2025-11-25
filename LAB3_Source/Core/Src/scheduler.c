/*
 * scheduler.c
 *
 *  Created on: Nov 25, 2025
 *      Author: LENOVO
 */
#include "scheduler.h"

Task SCH_task_G[SCH_MAX_TASK];
uint8_t current_index_task = 0;

void SCH_Init(void)
{
	current_index_task = 0;
}

void SCH_AddTask(void (*pFunction)(),
				uint32_t DELAY,
				uint32_t PERIOD)
{
	if(current_index_task < SCH_MAX_TASK)
	{
		SCH_task_G[current_index_task].pTask = pFunction;
		SCH_task_G[current_index_task].Delay = DELAY;
		SCH_task_G[current_index_task].Period = PERIOD;
		SCH_task_G[current_index_task].RunMe = 0;

		SCH_task_G[current_index_task].TaskID = current_index_task;
		current_index_task++;
	}
}

void SCH_Update(void)
{
	for(int i = 0; i < current_index_task; i++)
	{
		if(SCH_task_G[i].pTask)
		{
			if(SCH_task_G[i].Delay > 0)
			{
				SCH_task_G[i].Delay--;
			}
			else
			{
				SCH_task_G[i].RunMe+=1;
				if(SCH_task_G[i].Period)
				{
					SCH_task_G[i].Delay = SCH_task_G[i].Period;
				}
			}
		}
	}
}

void SCH_Dispatch_Tasks(void)
{
	for(int i = 0; i < current_index_task; i++)
	{
		if(SCH_task_G[i].RunMe > 0)
		{
			(*SCH_task_G[i].pTask)();
			SCH_task_G[i].RunMe--;
		}
	}
}
