#include "EXIT.h"
#include "..\ApplicationManager.h"

EXIT::EXIT(ApplicationManager* pApp) :Action(pApp)
{
}

EXIT::~EXIT(void)
{
}

void EXIT::Execute()
{
	Component** Objects = pManager->getComps();
	Connection** Connections = pManager->getConns();
	for (int i = 0; i < pManager->getCompCount(); i++)
	{
		delete Objects[i];
		Objects[i] = NULL;
	}
	for (int i = 0 ; i < pManager->getConnCount(); i++)
	{
		delete Connections[i];
		Connections[i] = NULL;
	}
	pManager->setCompCount(0);
}
void EXIT::Undo()
{}

void EXIT::Redo()
{}


