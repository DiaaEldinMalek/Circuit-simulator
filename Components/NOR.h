#ifndef _NOR_H
#define _NOR_H

/*
  Class NOR
  -----------
  represent the 2-input NOR gate
*/

#include "Gate.h"

class NOR :public Gate
{
public:
	NOR(GraphicsInfo* r_pGfxInfo, int r_FanOut);
	NOR();
	virtual void Operate();	//Calculates the output of the NOR gate
	virtual void Draw(UI*);	//Draws 2-input gate

	virtual STATUS GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual STATUS GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual string GetName();


};

#endif