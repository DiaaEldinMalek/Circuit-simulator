#ifndef CONNECTION_H
#define CONNECTION_H

#include "component.h"
#include "InputPin.h"
#include "OutputPin.h"
#include "Component.h"


class Connection
{
protected:
	int Modout=0;
	string c_label;
	bool selected;
	Point Src, Dest;		//Locations of source and destination objects
	Component*	SrcCmpnt;	//Connection source component
	Component*	DstCmpnt;	//Connection Destination component
	InputPinIndex	InputPin_index;		//The Input pin to which this connection is linked (0 for first pin ,1 for second)
	int dir; //related to n, but used in calculation (1 for the down,-1 for up, 0 for middle)
	OutputPin* SrcPin;	//The Source pin of this connection (an output pin of certain Component)
	InputPin* DstPin;	//The Destination pin of this connection (an input pin of certain Component)
public:

	//Connection(const GraphicsInfo &r_GfxInfo, Component *pS=NULL,Component *pD=NULL, int Pin=0);

	Connection(Component* SrcCmpnt, Component* DstCmpnt, InputPinIndex InputPin_index, int Modout);
	virtual void Operate() ;	//Calculates the output according to the inputs
	virtual void DrawC(UI* pUI);//for each connection to Draw 
	Component* getDstCmpnt();
	void setSourcePin();
	void setDestPin();
	OutputPin* getSourcePin();
	InputPin* getDestPin();
	~Connection();
	
	STATUS GetOutPinStatus();	//returns status of outputpin if LED, return -1
	STATUS GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.


};
#endif