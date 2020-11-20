#include "AddXORgate2.h"
#include "..\ApplicationManager.h"

AddXORgate2::AddXORgate2(ApplicationManager* pApp) :Action(pApp)
{
}

AddXORgate2::~AddXORgate2(void)
{
}

void AddXORgate2::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("2-Input XOR Gate: Click to add the gate");

	//Get Center point of the Gate
	pUI->GetPointClicked(Cx, Cy);

	//The following lines check whether the user draws in the drawing area
	int y1 = pUI->getTBHeight();
	int y2 = pUI->getSBHeight();
	int y = pUI->getWindowHeight();
	int gate = pUI->getGateHeight();

	if (Cy - gate / 2 < y1 || Cy + gate / 2 > y - y2)
	{
		pUI->PrintMsg("Invalid location for drawing.");
		Sleep(2000);
		pUI->ClearDrawingArea();
		return; //exits the function 
	}

	//Clear Status Bar
	pUI->ClearStatusBar();
	//Calculate the rectangle Corners
	int gateWidth = pUI->getGateWidth();
	int gateHeight = pUI->getGateHeight();

	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the XOR gate

	pGInfo->PointsList[0].x = Cx - gateWidth / 2;
	pGInfo->PointsList[0].y = Cy - gateHeight / 2;
	pGInfo->PointsList[1].x = Cx + gateWidth / 2;
	pGInfo->PointsList[1].y = Cy + gateHeight / 2;
	XOR* pA = new XOR(pGInfo, XOR_FANOUT);
	pManager->AddComponent(pA);
}

void AddXORgate2::Undo()
{}

void AddXORgate2::Redo()
{}


void AddXORgate2::Load(int x, int y)
{
	UI* pUI = pManager->GetUI();
	int gateWidth = pUI->getGateWidth();
	int gateHeight = pUI->getGateHeight();

	GraphicsInfo* pGInfo = new GraphicsInfo(2);

	pGInfo->PointsList[0].x = x;
	pGInfo->PointsList[0].y = y;
	pGInfo->PointsList[1].x = x + gateWidth;
	pGInfo->PointsList[1].y = y + gateHeight;
	XOR* pA = new XOR(pGInfo, XOR_FANOUT);
	pManager->AddComponent(pA);
}
