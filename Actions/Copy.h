#ifndef COPY_H
#define COPY_H

#include"Action.h"
using namespace std;
#include<string>
class Copy :public Action
{
public:
	Copy(ApplicationManager* pApp);
	virtual ~Copy(void);
	static string getcopiedname();
	static void setcopiedname();
	//Execute action (code depends on action type)
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
private:
    static string copyname;

};

#endif