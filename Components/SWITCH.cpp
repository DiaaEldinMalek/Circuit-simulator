#include "SWITCH.h"

SWITCH::SWITCH(GraphicsInfo* r_pGfxInfo, int r_FanOut) :Gate(r_pGfxInfo, 1, r_FanOut)
{
}

void SWITCH::TurnSwitch()
{
	if (state == HIGH)
		state = LOW;
	else if (state == LOW)
		state = HIGH;
}

void SWITCH::Operate()
{
		m_OutputPin.setStatus(state);
}


// Function Draw
// Draws SWITCH ITEM
void SWITCH::Draw(UI* pUI)
{
	//Call output class AND pass gate drawing info to it.
	pUI->DrawSWITCH(*m_pGfxInfo, getSelectStatus(), state);
}

//returns status of outputpin
STATUS SWITCH::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
STATUS SWITCH::GetInputPinStatus(int n)
{
	return NCON;	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void SWITCH::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[0].setStatus(s);
}

string SWITCH::GetName()
{
	return "SWITCH";
}