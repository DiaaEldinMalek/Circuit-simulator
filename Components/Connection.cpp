#include "Connection.h"

Connection::Connection(Component* SrcCmpnt, Component* DstCmpnt, InputPinIndex InputPin_index, int Modout)
{
	this->SrcCmpnt = SrcCmpnt;
	this->DstCmpnt = DstCmpnt;
	this->Modout = Modout;
	this->InputPin_index = InputPin_index;
	this->setSourcePin();
	this->setDestPin();
}

void Connection::DrawC(UI* pUI)
{

	if (DstCmpnt != NULL && SrcCmpnt != NULL) 
	{
		int Dy_down = DstCmpnt->getGfxInfo()->PointsList[1].y;
		int Dy_up = DstCmpnt->getGfxInfo()->PointsList[0].y;
		int Sy_down = SrcCmpnt->getGfxInfo()->PointsList[1].y;
		int Sy_up = SrcCmpnt->getGfxInfo()->PointsList[0].y;
		int H = pUI->getGateHeight();
		Src.x = SrcCmpnt->getGfxInfo()->PointsList[1].x;
		Dest.x = DstCmpnt->getGfxInfo()->PointsList[0].x;
		Dest.y = (Dy_down + Dy_up) / 2; //default location for input pin (middle)
		switch (Modout)
		{
		case 0:
			Src.y = (Sy_down + Sy_up) / 2;
			break;
		case 1:
			Src.y = (Sy_down + Sy_up) / 2 - 0.145*H;
			break;
		case 2: 
			Src.y = (Sy_down + Sy_up) / 2 + 0.145 * H;
			break;
		}
		switch (InputPin_index)
		{
		case Cup:
			Dest.y = Dest.y - H / 4; 
			break;
		case Cmid:
			break;
		case Cdown:
			Dest.y = Dest.y + H / 4;
			break;
		default:
			Dest.y = Dy_up + 0.1875 * H + 0.1563 * (int)(InputPin_index);
		}
		pUI->DrawConnection(Src, Dest, selected);
	}
}

void Connection::setSourcePin()
{
	if (Modout == 2)
		SrcPin = SrcCmpnt->GetOutputpin2();
	else
		SrcPin = SrcCmpnt->GetOutputpin();

	SrcPin->ConnectTo(this);
}

void Connection::setDestPin()	
{
	InputPin* hello = DstCmpnt->GetInputpins();
	DstPin = &hello[InputPin_index];
	DstPin->setConnected(this);
}

OutputPin* Connection::getSourcePin()
{
	return SrcPin;	
}

InputPin* Connection::getDestPin()
{	
	return DstPin;
}

Component* Connection::getDstCmpnt()
{
	return DstCmpnt;
}

void Connection::Operate()
{
	//Status of connection destination pin = status of connection source pin
	DstPin->setStatus((STATUS)SrcPin->getStatus());
}

STATUS Connection::GetOutPinStatus()	//returns status of outputpin if LED, return -1
{
	return SrcPin->getStatus();
}

STATUS Connection::GetInputPinStatus(int n)	//returns status of Inputpin # n if SWITCH, return -1
{
	return SrcPin->getStatus();	//n is ignored as connection has only one input pin (src pin)	
}

void Connection::setInputPinStatus(int n, STATUS s)
{
	SrcPin->setStatus(s);
}

Connection::~Connection()
{
	SrcPin->RemoveConnections();
}
