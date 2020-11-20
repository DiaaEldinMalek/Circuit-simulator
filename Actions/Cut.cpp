#include"Cut.h"
#include"..\ApplicationManager.h"

string Cut::cutname = "non";
Cut::Cut(ApplicationManager* pApp) :Action(pApp)
{
}

Cut::~Cut(void)
{
}

string Cut::getcutname()
{
	return cutname;
}

void Cut::setcutname()
{
	cutname = "non";
}

void Cut::Execute()
{

	Component** Objects = pManager->getComps();
	Connection** conns = pManager->getConns();
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	//pUI->PrintMsg("Select a component to Cut: ");

	//Get the name of the component in a dummy variable
	for (int i = 0; i<pManager->getCompCount(); i++) {
		if (Objects[i] != NULL) {
			if (Objects[i]->getSelectStatus())
			{
				cutname = Objects[i]->GetName();
			}
		}
	}
	//Checking for the selection of one component.
	if (cutname == "non")
	{
		pUI->PrintMsg("Please select a component and click on the cut item again again.");
		Sleep(3000);
	}else 		pUI->PrintMsg("Copied successfully ");
	Sleep(2000);
	//Clear Status Bar
	pUI->ClearStatusBar();
	//Delete the original component with its connections 
	for (int i = 0; i < pManager->getCompCount(); i++) {
		if (Objects[i] != NULL) {
			if (Objects[i]->getSelectStatus()) {
				Objects[i]->DeleteConnections();
				Objects[i] = NULL;
			}
		}
	}
	for (int i = 0; i < pManager->getConnCount(); i++) {
		if (conns[i] != NULL) {
			if (!conns[i]->getDestPin()->isConnected() || !conns[i]->getSourcePin()->getConnCount()) {
				conns[i] = NULL;
			}

		}
	}
	pUI->ClearStatusBar();
}

void Cut::Undo()
{}

void Cut::Redo()
{}