#include"Label.h"
#include"..\ApplicationManager.h"

Label::Label(ApplicationManager* pApp) :Action(pApp)
{
}

Label::~Label(void)
{
}

void Label::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Select a component to Label: ");
	Point Location;
	//Get Center point of the Gate
	pUI->GetPointClicked(Cx, Cy);
	Component** Objects = pManager->getComps();
	for (int i = 0; i < pManager->getCompCount(); i++)
	{
		if (Objects[i] != NULL) {
			if (Cx < Objects[i]->getGfxInfo()->PointsList[1].x
				&& Cx > Objects[i]->getGfxInfo()->PointsList[0].x
				&& Cy < Objects[i]->getGfxInfo()->PointsList[1].y
				&& Cy > Objects[i]->getGfxInfo()->PointsList[0].y)
			{
				if (Objects[i]->GetLabel() != " ")
				{
					pUI->PrintMsg("Component already has a label, use edit label instead.");
					Sleep(1000);
					pUI->ClearStatusBar();
					return;
				}
				pUI->ClearStatusBar();
				pUI->PrintMsg("Enter the label.");
				Sleep(1000);
				pUI->ClearStatusBar();
				Objects[i]->SetLabel(pUI->GetSrting());
			}
		}
	}

	//Clear Status Bar
	pUI->ClearStatusBar();

}

void Label::Undo()
{}

void Label::Redo()
{}

