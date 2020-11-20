#ifndef Move_H
#define Move_H

#include"Action.h"

class Move : public Action
{
private:
	int Cx, Cy;

public:
	Move(ApplicationManager* pApp);
	virtual ~Move(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};

#endif