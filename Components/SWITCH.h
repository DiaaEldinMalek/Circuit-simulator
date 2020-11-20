#ifndef _SWITCH_H
#define _SWITCH_H

/*
  Class SWITCH
  -----------
  represent the SWITCH ITEM
*/

#include "Gate.h"

class SWITCH :public Gate
{
private:
	STATUS state=STATUS::LOW;
public:
	SWITCH(GraphicsInfo* r_pGfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the SWITCH
	virtual void Draw(UI*);	//Draws THE ITEM

	virtual STATUS GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual STATUS GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1
	virtual void TurnSwitch();
	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual string GetName();

};

#endif