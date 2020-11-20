#ifndef Delete_H
#define Delete_H

#include"Action.h"
#include "..\Defs.h"

class Delete : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int x, y;	//THE POINT WHERE THE USER CLICKS
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	ActionType userkey;
	Delete(ApplicationManager* pApp);
	virtual ~Delete(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif