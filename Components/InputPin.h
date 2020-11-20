#ifndef _INPUTPIN_H
#define _INPUTPIN_H

#include "Pin.h"

class Connection;
class Component; //Forward class declaration

class InputPin: public Pin	//inherited from class Pin
{
	Component* pComp; //Component at which this pin is associated
	bool connected=false;
	Connection* wire;
public:
	InputPin();
	void RemoveWire();
	Connection* getWire();
	void setConnected(Connection* connector);
	void setComponent(Component* pCmp);	//sets the component of this input pin
	Component* getComponent();	//returns the component of this input pin
	bool isConnected() const;
};

#endif