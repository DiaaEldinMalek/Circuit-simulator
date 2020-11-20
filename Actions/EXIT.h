#ifndef EXIT_H
#define EXIT_H

#include "Action.h"

class EXIT : public Action
{
public:
	EXIT(ApplicationManager* pApp);
	virtual ~EXIT(void);

	//Execute action (code depends on action type)
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();

};


#endif