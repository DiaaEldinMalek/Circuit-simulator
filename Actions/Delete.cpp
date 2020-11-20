#include "Delete.h"
#include "..\ApplicationManager.h"

Delete::Delete(ApplicationManager* pApp) :Action(pApp)
{
}

Delete::~Delete(void)
{
}

void Delete::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();
	Component** Objects = pManager->getComps();
	Connection** conns = pManager->getConns();
	for (int j = 0; j < pManager->getCompCount(); j++) {
		if (Objects[j] != NULL) {
			Objects[j]->setSelectStatus(false);
		}
	}
	pManager->UpdateInterface();

	//Print Action Message
	pUI->PrintMsg("Click on the components to select, then click on the Delete item again to delete them: " );
	while (userkey != DEL) {
		//Get Center point of the Gate
		pUI->GetLastPoint(x, y);
		for (int i = pManager->getCompCount() - 1; i > -1; i--) {
			//Calculate the rectangle Corners
			int gateWidth = pUI->getGateWidth();
			int gateHeight = pUI->getGateHeight();
			if (Objects[i] != NULL) {
			x1 = Objects[i]->getGfxInfo()->PointsList[0].x - 10;
			y1 = Objects[i]->getGfxInfo()->PointsList[0].y - 10;
			x2 = Objects[i]->getGfxInfo()->PointsList[1].x - 10;
			y2 = Objects[i]->getGfxInfo()->PointsList[1].y - 10;
			if ((x >= x1) && (x <= x2) && (y >= y1) && (y <= y2)) {
				Objects[i]->flip();
				pManager->UpdateInterface();
				break;
			}
			}
		}
		userkey = pUI->GetUserAction();
	}
	if (pManager->getCompCount() < 1) {
		pUI->ClearDrawingArea();
	}
	else {
		for (int i = 0; i < pManager->getCompCount(); i++) {
			if (Objects[i]!= NULL) {
				if (Objects[i]->getSelectStatus()) {
					Objects[i]->DeleteConnections();
					Objects[i] = NULL;
				}
			}
		}
		for (int i = 0; i < pManager->getConnCount(); i++) {
			if (conns[i] != NULL) {
				if (!conns[i]->getDestPin()->isConnected()||!conns[i]->getSourcePin()->getConnCount()) {
					conns[i] = NULL;
				}

			}
		}
		pUI->ClearStatusBar();
	}
}
void Delete::Undo()
{}

void Delete::Redo()
{}

