#ifndef LABEL_H
#define LABEL_H

#include"Action.h"

class Label : public Action
{
private:
	int Cx, Cy;

public:
	Label(ApplicationManager* pApp);
	virtual ~Label(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif