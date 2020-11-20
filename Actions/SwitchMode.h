#ifndef _SwitchMode_H
#define SwitchMode_H

#include"Action.h"
class Component;

class SwitchMode : public Action
{
public:
	SwitchMode(ApplicationManager* pApp);
	virtual ~SwitchMode(void);

	//Execute action (code depends on action type)
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
	bool CircuitConnected();


};

#endif