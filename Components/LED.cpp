#include "LED.h"

LED::LED(GraphicsInfo* r_pGfxInfo, int r_FanOut) :Gate(r_pGfxInfo, 1, r_FanOut)
{
}


void LED::Operate()
{
	if (m_InputPins[0].getStatus() == HIGH) {
		state=HIGH;
	}
	else state=LOW;
}


// Function Draw
// Draws 2-input LED gate
void LED::Draw(UI* pUI)
{
	//Call output class LED pass gate drawing info to it.
	pUI->DrawLED(*m_pGfxInfo,getSelectStatus(), state);
}

//returns status of outputpin
STATUS LED::GetOutPinStatus()
{
	return NCON;
}


//returns status of Inputpin #n
STATUS LED::GetInputPinStatus(int n)
{
	return m_InputPins[0].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void LED::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[0].setStatus(s);
}
string LED::GetName()
{
	return "LED";
}