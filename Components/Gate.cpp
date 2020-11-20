#include "Gate.h"

//Gate Constructor
//Parameters:
//r_Inputs: no. of gate's input pins
//r_FanOut: Fan out of the gate's output pin
Gate::Gate(GraphicsInfo* pGfxInfo, int r_Inputs, int r_FanOut):Component(pGfxInfo, r_FanOut)
{
	//Allocate number of input pins (equals r_Inputs)
	AssignInputs(r_Inputs);
}
Gate::Gate()
{
}