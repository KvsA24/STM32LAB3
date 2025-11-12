/*
 * input_processing.c
 *
 *  Created on: Nov 5, 2025
 *      Author: LENOVO
 */

#include "input_processing.h"
#include "main.h"

#define NUMBER_OF_BUTTONS 4

#define DURATION 200
#define IS_PRESSED GPIO_PIN_RESET
#define IS_RELEASED GPIO_PIN_SET

static GPIO_PinState buttonBuffer[NUMBER_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer1[NUMBER_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer2[NUMBER_OF_BUTTONS];
static uint8_t flagForButtonPress2s[NUMBER_OF_BUTTONS];
static uint16_t counterForButtonPress2s[NUMBER_OF_BUTTONS];
static GPIO_TypeDef* buttonPorts[NUMBER_OF_BUTTONS] = {
		BUTTON1_GPIO_Port,
		BUTTON2_GPIO_Port,
		BUTTON3_GPIO_Port,
		BUTTON4_GPIO_Port
};
static uint16_t buttonPins[NUMBER_OF_BUTTONS] = {
		BUTTON1_Pin,
		BUTTON2_Pin,
		BUTTON3_Pin,
		BUTTON4_Pin
};
void button_reading(void)
{
	for(char i = 0; i < NUMBER_OF_BUTTONS; i++)
	{
		debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
		debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(buttonPorts[i], buttonPins[i]);
		if(debounceButtonBuffer1[i] == debounceButtonBuffer2[i])
		{
			buttonBuffer[i] = debounceButtonBuffer1[i];
			if(buttonBuffer[i] == IS_PRESSED)
			{
				if(counterForButtonPress2s[i] < DURATION)
				{
					counterForButtonPress2s[i]++;
				}
				else
				{
					flagForButtonPress2s[i] = 1;
				}
			}
			else
			{
				counterForButtonPress2s[i] = 0;
				flagForButtonPress2s[i] = 0;
			}
		}
	}
}
unsigned char is_button_pressed(uint8_t index)
{
	if(index >= NUMBER_OF_BUTTONS)
	{
		return 0;
	}
	return (buttonBuffer[index] == IS_PRESSED);
}
unsigned char is_button_long_pressed(uint8_t index)
{
	if(index >= NUMBER_OF_BUTTONS)
	{
		return 0xff;
	}
	return (flagForButtonPress2s[index] == 1);
}
