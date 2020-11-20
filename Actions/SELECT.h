#ifndef SELECT_H
#define SELECT_H

#include "action.h"

class SELECT : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int x, y;	//THE POINT WHERE THE USER CLICKS
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	SELECT(ApplicationManager* pApp);
	virtual ~SELECT(void);
	
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};

#endif