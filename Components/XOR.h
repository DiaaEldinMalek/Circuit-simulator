#ifndef _XOR_H
#define _XOR_H

/*
  Class XOR
  -----------
  represent the 2-input XOR gate
*/

#include "Gate.h"

class XOR :public Gate
{
public:
	XOR(GraphicsInfo* r_pGfxInfo, int r_FanOut);
	XOR();
	virtual void Operate();	//Calculates the output of the XOR gate
	virtual void Draw(UI*);	//Draws 2-input gate

	virtual STATUS GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual STATUS GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual string GetName();


};

#endif