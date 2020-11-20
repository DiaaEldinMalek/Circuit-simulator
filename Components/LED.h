#ifndef _LED_H
#define _LED_H

/*
  Class LED
  -----------
  represent the LED ITEM 
*/

#include "Gate.h"

class LED :public Gate
{
public:
	LED(GraphicsInfo* r_pGfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the LED 
	virtual void Draw(UI*);	//Draws LED ITEM

	virtual STATUS GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual STATUS GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual string GetName();
private:
	STATUS state=LOW;

};

#endif