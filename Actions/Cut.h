#ifndef CUT_H
#define CUT_H

#include"Action.h"
using namespace std;
#include<string>

class Cut :public Action
{
public:
	Cut(ApplicationManager* pApp);
	virtual ~Cut(void);
	static string getcutname();
	static void setcutname();

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
protected:
	static string cutname;
};

#endif