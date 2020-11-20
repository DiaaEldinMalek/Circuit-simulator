#ifndef _MODULE_H
#define _MODULE_H

/*
  Class MODULE
  --
*/

#include "Gate.h"
#include"AND2.h"
#include"NAND.h"
#include"NOR.h"
#include"NOT.h"
#include"OR2.h"
#include"XNOR.h"
#include"XOR.h"

class MODULE :public Gate
{
private:
	OutputPin m_OutputPin2;
	AND2 CandE, CEandED, AandB, BandA, CandB;
	NAND p1NANDp2, p3NANDp4, EDnandAB;
	OR2 EorD;
	NOR ABnorBA, AnorB, CBnorAB;
	XOR ExorD;
	XNOR AxnorB;
public:
	MODULE(GraphicsInfo* r_pGfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the MODULE ITEM
	virtual void Draw(UI*);	//Draws 2-input gate

	virtual STATUS GetOutPinStatus();
	 STATUS GetOutPin2Status();	//returns status of outputpin if LED, return -1
	virtual STATUS GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual string GetName();
	virtual OutputPin* GetOutputPin2();
	virtual bool Output2isFull();
	virtual void DeleteConnections();
};

#endif