#ifndef ADD_CONNECTION_H
#define ADD_CONNECTION_H
#include <dos.h>
#include "Action.h"
#include "..\Components\Connection.h"


class AddConnection : public Action
{
private:
	int r=15;
	Point Location;
	ApplicationManager* pApp;
public:
	AddConnection(ApplicationManager* pApp);
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};


#endif // !ADDCONNECTION_H
