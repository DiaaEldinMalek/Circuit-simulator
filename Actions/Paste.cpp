#include"Paste.h"


Paste::Paste(ApplicationManager* pApp) :Action(pApp)
{
}

Paste::~Paste(void)
{
}

void Paste::Execute()
{
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();
	Action* pAct = NULL;
	//Print Action Message
	pUI->PrintMsg("Select a location to Paste the component into: ");
	Sleep(3000);
	if (Copy::getcopiedname() != "non") {
		name = Copy::getcopiedname();
		Copy::setcopiedname();
	}
	else if (Cut::getcutname() != "non") {
		name = Cut::getcutname();
		Cut::setcutname();
	}
	else {
		pUI->ClearStatusBar();
		pUI->PrintMsg("You did not copy or cut any component");
		Sleep(3000);
		//Clear Status Bar
		pUI->ClearStatusBar();
	}
	if (name != "non") {
		if (name == "AND2") {
			pAct = new AddANDgate2(pManager);
		}
		else if (name == "OR2") {
			pAct = new AddORgate2(pManager);
		}
		else if (name == "NAND") {
			pAct = new AddNANDgate2(pManager);
		}
		else if (name == "NOR") {
			pAct = new AddNORgate2(pManager);
		}
		else if (name == "NOT") {
			pAct = new AddNOTgate(pManager);
		}
		else if (name == "XOR") {
			pAct = new AddXORgate2(pManager);
		}
		else if (name == "XNOR") {
			pAct = new AddXNORgate2(pManager);
			
		}
		else if (name == "MODULE") {
			pAct = new AddMODULE(pManager);
		}
	}
	pAct->Execute();
	pManager->UpdateInterface();
}

void Paste::Undo()
{}

void Paste::Redo()
{}