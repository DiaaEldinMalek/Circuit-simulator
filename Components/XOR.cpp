#include "XOR.h"

XOR::XOR(GraphicsInfo* r_pGfxInfo, int r_FanOut) :Gate(r_pGfxInfo, 2, r_FanOut)
{
}
XOR::XOR()
{
}

void XOR::Operate()
{
	if (m_InputPins[0].getStatus() ==m_InputPins[1].getStatus()) {
		m_OutputPin.setStatus(LOW);
	}
	else m_OutputPin.setStatus(HIGH);
}


// Function Draw
// Draws 2-input XOR gate
void XOR::Draw(UI* pUI)
{
	//Call output class and pass gate drawing info to it.
	if (isDrawn) {
		pUI->DrawXOR(*m_pGfxInfo, getSelectStatus());
	}
}

//returns status of outputpin
STATUS XOR::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
STATUS XOR::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void XOR::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

string XOR::GetName()
{
	return "XOR";
}