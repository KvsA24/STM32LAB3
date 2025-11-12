#include "button.h"
#include "main.h"
#include "global.h"

int KeyReg0[NUMBER_OF_BUTTONS];
int KeyReg1[NUMBER_OF_BUTTONS];
int KeyReg2[NUMBER_OF_BUTTONS];
int KeyReg3[NUMBER_OF_BUTTONS];

int TimeOutForKeyPress[NUMBER_OF_BUTTONS];
int button_pressed[NUMBER_OF_BUTTONS];
int button_long_pressed[NUMBER_OF_BUTTONS];
int button_flag[NUMBER_OF_BUTTONS];

int isButtonPressed(int index){
	if(button_flag[index] == 1){
		button_flag[index] = 0;
		return 1;
	}
	return 0;
}
GPIO_TypeDef* buttonPorts[NUMBER_OF_BUTTONS] = {
		BUTTON1_GPIO_Port,
		BUTTON2_GPIO_Port,
		BUTTON3_GPIO_Port,
		BUTTON4_GPIO_Port
};
uint16_t buttonPins[NUMBER_OF_BUTTONS] = {
		BUTTON1_Pin,
		BUTTON2_Pin,
		BUTTON3_Pin,
		BUTTON4_Pin
};

int isButtonLongPressed(int index){
	if(button_long_pressed[index] == 1){
		button_long_pressed[index] = 0;
		return 1;
	}
	return 0;
}


void getKeyInput()
{
	for(int i = 0; i < NUMBER_OF_BUTTONS; ++i)
	{
		  KeyReg2[i] = KeyReg1[i];
		  KeyReg1[i] = KeyReg0[i];
		  // Add your key
		  KeyReg0[i] = HAL_GPIO_ReadPin(buttonPorts[i], buttonPins[i]);

		  if ((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i]))
		  {
		    if (KeyReg2[i] != KeyReg3[i])
		    {
		      KeyReg3[i] = KeyReg2[i];

		      if (KeyReg3[i] == PRESSED_STATE)
		      {
		        TimeOutForKeyPress[i] = LONG_PRESS_DURATION;
		      }
		      else
		      {
		    	  if(TimeOutForKeyPress[i] > 0 && TimeOutForKeyPress[i] < LONG_PRESS_DURATION)
		    	  {
		    		  button_flag[i] = 1;
		    	  }
		      }

		    }
		    else
		    {
		       if(KeyReg3[i] == PRESSED_STATE)
		       {
		    	   if(TimeOutForKeyPress[i] > 0)
		    	   {
		    		   TimeOutForKeyPress[i]--;
		    	   }
		    	   if(TimeOutForKeyPress[i] == 0)
		    	   {
		    		   button_long_pressed[i] = 1;
		    	   }
		       }
		    }
		  }
	}
}

