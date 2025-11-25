/*
 * scheduler.h
 *
 *  Created on: Nov 25, 2025
 *      Author: LENOVO
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include <stdint.h>

typedef struct{
	void (*pTask)(void);
	uint32_t Delay;
	uint32_t Period;
	uint8_t RunMe;
	uint32_t TaskID;
} Task;

#define SCH_MAX_TASK 40
#define NO_TASK_ID	0

void SCH_Init(void);
void SCH_AddTask(void (*pFunction)(),
				uint32_t DELAY,
				uint32_t PERIOD);
void SCH_Update(void);
void SCH_Dispatch_Tasks(void);
void SCH_Delete(uint32_t TaskID);

#endif /* INC_SCHEDULER_H_ */
