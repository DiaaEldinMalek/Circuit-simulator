#include "SwitchMode.h"
#include"..\ApplicationManager.h"
#include"..\CMUgraphicsLib/CMUgraphics.h"
SwitchMode::SwitchMode(ApplicationManager* pApp) :Action(pApp)
{
}

SwitchMode::~SwitchMode(void)
{
}

void SwitchMode::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();
	if (pUI->GetAppMode() == DESIGN)
	{
		if (!CircuitConnected())
		{
			pUI->PrintMsg("Cannot start simulation unless all circuits are validly connected.");
			Sleep(2000);
			pUI->ClearStatusBar();
			return;
		} 
		else
		{
			pUI->CreateSimulationToolBar();
			pUI->CreateStatusBar();
			pUI->SetAppMode(SIMULATION);
			pUI->PrintMsg("Click on a switch to start simulation.");
			Sleep(2000);
			pUI->ClearStatusBar();
		}
	}
	else {
		pUI->SetAppMode(DESIGN);
		pUI->CreateDesignToolBar();
		pUI->CreateStatusBar();
	}
}



bool SwitchMode::CircuitConnected()
{
	int comp = pManager->getCompCount();
	Component** Objects = pManager->getComps();
	for (int i = 0; i < comp; i++)
	{
		if (Objects[i] != NULL)
			if (!Objects[i]->ComponentConnected())
			return false;
	}
	return true;
}

void SwitchMode::Undo()
{}

void SwitchMode::Redo()
{}

