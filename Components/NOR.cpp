#include "NOR.h"

NOR::NOR(GraphicsInfo* r_pGfxInfo, int r_FanOut) :Gate(r_pGfxInfo, 2, r_FanOut)
{
}
NOR::NOR() {}

void NOR::Operate()
{
	if (m_InputPins[0].getStatus() == HIGH && m_InputPins[1].getStatus() == HIGH) {
		m_OutputPin.setStatus(LOW);
	}
	else m_OutputPin.setStatus(HIGH);
}


// Function Draw
// Draws 2-input NOR gate
void NOR::Draw(UI* pUI)
{
	//Call output class NOR pass gate drawing info to it.
	if (isDrawn) {
		pUI->DrawNOR(*m_pGfxInfo, getSelectStatus());
	}
}

//returns status of outputpin
STATUS NOR::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
STATUS NOR::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NOR::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
string NOR::GetName()
{
	return "NOR";
}