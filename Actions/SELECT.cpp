#include "SELECT.h"
#include "..\ApplicationManager.h"

SELECT::SELECT(ApplicationManager* pApp) :Action(pApp)
{
}

SELECT::~SELECT(void)
{
}



void SELECT::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();
	Component** Objects = pManager->getComps();
	Connection** Connect = pManager->getConns();
	for (int j = 0; j < pManager->getCompCount(); j++) {
		if (Objects[j] != NULL) {
			Objects[j]->setSelectStatus(false);
		}
	}
	//Get THE POINT WHERE THE USER CLICKS
	pUI->GetLastPoint(x,y);

	for (int i = pManager->getCompCount()-1; i >-1 ; i--) {
		//Calculate the rectangle Corners
		int gateWidth = pUI->getGateWidth();
		int gateHeight = pUI->getGateHeight();
		if (Objects[i] != NULL) {
		x1 =Objects[i]->getGfxInfo()->PointsList[0].x-10;
		y1 =Objects[i]->getGfxInfo()->PointsList[0].y-10;
		x2 =Objects[i]->getGfxInfo()->PointsList[1].x-10;
		y2 = Objects[i]->getGfxInfo()->PointsList[1].y-10;
		if ((x >= x1) && (x <= x2) && (y >= y1) && (y <= y2)) {
				Objects[i]->flip();
				break;
			}
		}
	} 


}

void SELECT::Undo()
{}

void SELECT::Redo()
{}

