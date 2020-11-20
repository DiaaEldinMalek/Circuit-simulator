#include"Move.h"
#include"..\ApplicationManager.h"

Move::Move(ApplicationManager* pApp) :Action(pApp)
{
}

Move::~Move(void)
{
}

void Move::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Select a component to Move: ");

	//Get Center point of the Gate
	pUI->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pUI->ClearStatusBar();

}

void Move::Undo()
{}

void Move::Redo()
{}

