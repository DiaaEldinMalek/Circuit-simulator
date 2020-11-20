#include "Component.h"

Component::Component(GraphicsInfo* r_GfxInfo, int FanOut) :m_OutputPin(FanOut)
{
	m_pGfxInfo = r_GfxInfo;	
}
Component::Component()
{
	isDrawn = false;
}



void Component::TurnSwitch()
{}

GraphicsInfo* Component::getGfxInfo()
{
	return m_pGfxInfo;
}

bool Component::InputisConnected(int pin_index)
{
	return m_InputPins[pin_index].isConnected();
}

void Component::AssignInputs(int Inpinscount)
{
	this->Inpinscount = Inpinscount;
	m_InputPins = new InputPin[Inpinscount];
	for (int i = 0; i < Inpinscount; i++)
	{
		m_InputPins[i].setComponent(this);
	}
}

int Component::getInpincount()
{
	return Inpinscount;
}

InputPin* Component::GetInputpins()
{
	return m_InputPins;
}

OutputPin* Component::GetOutputpin()  
{
	OutputPin* ptr = &m_OutputPin;
	return ptr;
}

OutputPin* Component::GetOutputpin2()
{
	OutputPin* ptr = &m_OutputPin;
	return ptr;
}

void Component::SimMode()
{}

void Component::EditMode()
{}

void Component::DispLabel(UI* pUI) const
{
	Point Header;
	Header.x= (m_pGfxInfo->PointsList[0].x + m_pGfxInfo->PointsList[1].x - 20) / 2;
	Header.y = (m_pGfxInfo->PointsList[1].y) + 10;
	pUI->DisplayLabel(Header, m_Label);
}
string Component::GetLabel() const
{
	return m_Label;
}

void Component::SetLabel(string name)
{
	m_Label = name;
}
void Component::flip()
{

	setSelectStatus(!getSelectStatus());
}

void Component::setSelectStatus(bool s)
{
	selected = s;
}

bool Component::getSelectStatus()
{
	return selected;
}

Component::~Component()
{
	delete[] m_InputPins;

}

bool Component::OutputisFull()
{
	return m_OutputPin.Max_reached();
}

bool Component::Output2isFull()
{
	return m_OutputPin.Max_reached();
}

bool Component::ComponentConnected()
{
	for (int i = 0; i < Inpinscount; i++)
	{
		if (!m_InputPins[i].isConnected())
			if (GetName()!="SWITCH")
			return false;
	}
	if (!m_OutputPin.getConnCount())
		if (GetName()!="LED")
		return false;
	else
		return true;
}

void Component::DeleteConnections()
{
	for (int i = 0; i < Inpinscount; i++)
		m_InputPins[i].RemoveWire();
	m_OutputPin.RemoveConnections();
}