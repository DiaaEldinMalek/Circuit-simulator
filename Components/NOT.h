#ifndef _NOT_H
#define _NOT_H

/*
  Class NOT
  -----------
  represent the 1-input NOT gate
*/

#include "Gate.h"

class NOT :public Gate
{
public:
	NOT(GraphicsInfo* r_pGfxInfo, int r_FanOut);
	NOT();
	virtual void Operate();	//Calculates the output of the NOT gate
	virtual void Draw(UI*);	//Draws NOT gate

	virtual STATUS GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual STATUS GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n,STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual string GetName();


};

#endif