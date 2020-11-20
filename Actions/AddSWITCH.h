#pragma once
#ifndef _ADD_SWITCH_GATE_H
#define _ADD_SWITCH_GATE_H

#include "action.h"
#include "..\Components\SWITCH.h"

class AddSWITCH : public Action
{
private:
	//Parameters for rectangular area to be occupied by the ITEM
	int Cx, Cy;	//Center point of the ITEM
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	AddSWITCH(ApplicationManager* pApp);
	virtual ~AddSWITCH(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
	virtual void Load(int x, int y);

};

#endif