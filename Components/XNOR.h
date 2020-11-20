#ifndef _XNOR_H
#define _XNOR_H

/*
  Class XNOR
  -----------
  represent the 2-input XNOR gate
*/

#include "Gate.h"

class XNOR :public Gate
{
public:
	XNOR(GraphicsInfo* r_pGfxInfo, int r_FanOut);
	XNOR();
	virtual void Operate();	//Calculates the output of the XNOR gate
	virtual void Draw(UI*);	//Draws 2-input gate

	virtual STATUS GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual STATUS GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual string GetName();


};

#endif