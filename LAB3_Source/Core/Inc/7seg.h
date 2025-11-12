/*
 * 7seg.h
 *
 *  Created on: Nov 1, 2025
 *      Author: LENOVO
 */

#ifndef INC_7SEG_H_
#define INC_7SEG_H_

void display7SEG(int num);
void update7SEG(int index);
void updateClock1Buffer(int value);
void updateClock2Buffer(int value);
void scan7seg();
void clear7seg();

#endif /* INC_7SEG_H_ */
