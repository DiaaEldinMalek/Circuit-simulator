#include "InputPin.h"
#include "Connection.h"

InputPin::InputPin()
{}

void InputPin::setComponent(Component *pCmp)
{
	this->pComp = pCmp;
}

Component* InputPin::getComponent()
{
	return pComp;
}

bool InputPin::isConnected() const
{
	return connected;
}

void InputPin::setConnected(Connection* connector)
{
	wire = connector;
	connected = true;
}

Connection* InputPin::getWire()
{
	return wire;
}

void InputPin::RemoveWire()
{
	wire = NULL;
	connected = false;
}