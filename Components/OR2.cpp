#include "OR2.h"

OR2::OR2(GraphicsInfo* r_pGfxInfo, int r_FanOut) :Gate(r_pGfxInfo, 2, r_FanOut)
{
}
OR2::OR2()
{
}

void OR2::Operate()
{
	if (m_InputPins[0].getStatus() == HIGH || m_InputPins[1].getStatus() == HIGH) {
		m_OutputPin.setStatus(HIGH);
	}
	else m_OutputPin.setStatus(LOW);
	
}


// Function Draw
// Draws 2-input OR gate
void OR2::Draw(UI* pUI)
{
	//Call output class OR pass gate drawing info to it.
	if (isDrawn) {
		pUI->DrawOR2(*m_pGfxInfo, getSelectStatus());
	}
}

//returns status of outputpin
STATUS OR2::GetOutPinStatus()
{
	return OR2::m_OutputPin.getStatus();
}


//returns status of Inputpin #n
STATUS OR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void OR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

string OR2::GetName()
{
	return "OR2";
}