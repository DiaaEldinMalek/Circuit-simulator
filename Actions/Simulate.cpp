#include "Simulate.h"
#include "..\ApplicationManager.h"

Simulate::Simulate(ApplicationManager* pApp) : SELECT(pApp)
{}

Simulate::~Simulate(void)
{

}

void Simulate::Execute()
{
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();
	Component** Objects = pManager->getComps();
	Connection** Connect = pManager->getConns();

	//pUI->PrintMsg("Click on a switch to turn it on/off.");

	//Get THE POINT WHERE THE USER CLICKS
	pUI->GetLastPoint(x, y);

	for (int i = pManager->getCompCount() - 1; i > -1; i--) {
		//Calculate the rectangle Corners
		int gateWidth = pUI->getGateWidth();
		int gateHeight = pUI->getGateHeight();
		if (Objects[i] != NULL)
		{
			x1 = Objects[i]->getGfxInfo()->PointsList[0].x - 10;
			y1 = Objects[i]->getGfxInfo()->PointsList[0].y - 10;
			x2 = Objects[i]->getGfxInfo()->PointsList[1].x - 10;
			y2 = Objects[i]->getGfxInfo()->PointsList[1].y - 10;
			if ((x >= x1) && (x <= x2) && (y >= y1) && (y <= y2)) {
				Objects[i]->TurnSwitch();
				break;
			}
		}
	}
	RunCircuit();
}

void Simulate::RunCircuit()
{
	int comp = pManager->getCompCount();
	Component** Objects = pManager->getComps();
	for (int i = 0; i < comp; i++)
	{
		if (Objects[i]->GetName() == "SWITCH")
		{
			DistributeOutput(Objects[i]);
		}
	}
}

void Simulate::DistributeOutput(Component* Root)
{
	if (Root->GetName() != "SWITCH")
	{
		InputPin* Inputs = Root->GetInputpins();
		for (int i = 0; i < Root->getInpincount(); i++)
		{
			Inputs[i].getWire()->Operate();
		}
	}
	if (!Root->GetOutputpin()->getConnCount())
	{
		Root->Operate();
		return;
	}
	else
	{
		Root->Operate();
		Connection** Branch = Root->GetOutputpin()->getConnList();
		for (int i = 0; i < Root->GetOutputpin()->getConnCount(); i++)
		{
			Branch[i]->Operate();
			DistributeOutput(Branch[i]->getDstCmpnt());
		}
	}
}


void Simulate::Undo()
{}

void Simulate::Redo()
{}

