#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "..\Defs.h"
#include "..\UI\UI.h"
#include "InputPin.h"
#include "OutputPin.h"
#include <string>


//Base class for classes Gate, Switch, and LED.
class Component
{
protected:
	string m_Label=" ";
	bool selected = false;
	InputPin* m_InputPins;	//Array of input pins of the Gate
	OutputPin m_OutputPin;	//The Gate output pin (modified to be an array)
	GraphicsInfo* m_pGfxInfo;	//The parameters required to draw a component
	int Inpinscount;
	bool isDrawn = true;
public:
	/*Component();*/
	virtual void TurnSwitch();
	Component(GraphicsInfo *r_GfxInfo, int FanOut);
	Component();
	GraphicsInfo* getGfxInfo();
	virtual int getInpincount();
	virtual void AssignInputs(int Inpinscount);
	virtual InputPin* GetInputpins();
	virtual OutputPin* GetOutputpin(); 
	virtual OutputPin* GetOutputpin2(); //Empty virtual function for the module
	/*virtual bool Assign_Inputpin(Connection* connection, int pin_index);*/
	virtual void Operate() = 0;	//Calculates the output according to the inputs
	virtual void Draw(UI*) = 0;	//for each component to Draw itself
	void flip();
	virtual bool OutputisFull();//
	virtual bool Output2isFull();
	virtual bool InputisConnected(int pin_index); //check whether the chosen pin is already connected
	virtual void setSelectStatus(bool s);
	virtual bool getSelectStatus();
	virtual void DispLabel(UI* pUI) const;
	virtual void SetLabel(string name);
	virtual void SimMode();
	virtual void EditMode();
	virtual string GetLabel() const;
	virtual string GetName() = 0; //returns the name of the component 
	virtual STATUS GetOutPinStatus()=0;	//returns status of outputpin if LED, return -1
	virtual STATUS GetInputPinStatus(int n) = 0;	//returns status of Inputpin # n if SWITCH, return -1
	virtual void setInputPinStatus(int n, STATUS s)=0;	//set status of Inputpin # n, to be used by connection class.
	virtual bool ComponentConnected();
	virtual void DeleteConnections();
	//Destructor must be virtual
	virtual ~Component();
};

#endif
