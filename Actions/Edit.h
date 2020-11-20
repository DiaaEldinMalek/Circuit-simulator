#ifndef EDIT_H
#define EDIT_H

#include"Action.h"

class Edit : public Action
{
private:
	int Cx, Cy;

public:
	Edit(ApplicationManager* pApp);
	virtual ~Edit(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif