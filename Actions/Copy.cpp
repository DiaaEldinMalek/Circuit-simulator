#include"Copy.h"
#include"..\ApplicationManager.h"

string Copy::copyname = "non";
Copy::Copy(ApplicationManager* pApp) :Action(pApp)
{
}

Copy::~Copy(void)
{
}

string Copy::getcopiedname()
{
	return copyname;
}

void Copy::setcopiedname()
{
	copyname = "non";
}

void Copy::Execute()
{
	Component** Objects = pManager->getComps();
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	//pUI->PrintMsg("Select a component to copy: ");

	//Checking if a component is selected
	//Getting the name of the selected component
	for (int i = 0; i< pManager->getCompCount(); i++) {
		if (Objects[i] != NULL) {
			if (Objects[i]->getSelectStatus())
			{
				copyname = Objects[i]->GetName();
			}
		}
	}
	//Checking for the selection of one component.
	if (copyname=="non")
	{
		pUI->PrintMsg("Please select a component and click on the copy item again again.");
		Sleep(2000);
	}else 
		pUI->PrintMsg("Copied successfully ");
	Sleep(2000);
	//Clear Status Bar
	pUI->ClearStatusBar();

}

void Copy::Undo()
{}

void Copy::Redo()
{}