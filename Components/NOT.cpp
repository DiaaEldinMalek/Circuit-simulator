#include "NOT.h"

NOT::NOT(GraphicsInfo* r_pGfxInfo, int r_FanOut) :Gate(r_pGfxInfo, 1, r_FanOut)
{
}
NOT::NOT() {}

void NOT::Operate()
{
	if (m_InputPins[0].getStatus() == HIGH) {
		m_OutputPin.setStatus(LOW);
	}
	else m_OutputPin.setStatus(HIGH);
}


// Function Draw
// Draws 1-input NOT gate
void NOT::Draw(UI* pUI)
{
	//Call output class NOT pass gate drawing info to it.
	if (isDrawn) {
		pUI->DrawNOT(*m_pGfxInfo, getSelectStatus());
	}
}

//returns status of outputpin
STATUS NOT::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
STATUS NOT::GetInputPinStatus(int n)
{
	return m_InputPins[0].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NOT::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[0].setStatus(s);
}

string NOT::GetName()
{
	return "NOT";
}