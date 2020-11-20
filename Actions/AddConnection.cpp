#include "AddConnection.h"
#include "..\ApplicationManager.h"
#include <dos.h>
AddConnection::AddConnection(ApplicationManager* pApp) :Action(pApp) 
{
	this->pApp = pApp;
};

void AddConnection::Undo()
{}

void AddConnection::Redo()
{}

void AddConnection::Execute()
{
	int modOutpin=0;
	string inputGate;
	InputPinIndex n; 
	int c = pManager->getCompCount(); //number of components
	Component** Objects = pApp->getComps(); //array of components
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();
	int o_index = -1, i_index = -1; //indices of the objects that are being connected in the components array

	pUI->PrintMsg("Click on an output pin to make a new connection.");

	//Find the nearest output pin
	pUI->GetPointClicked(Location.x, Location.y);

	for (int i = 0; i < c; i++)
	{
		//finding the nearest output pin (right side) that falls within a certain radius
		if (Objects[i] != NULL) {
			int Rx = Objects[i]->getGfxInfo()->PointsList[1].x; // Rightmost x coordinate
			int Ry_down = Objects[i]->getGfxInfo()->PointsList[1].y; //Lower y coordinate
			int Ry_up = Objects[i]->getGfxInfo()->PointsList[0].y;// Upper y coordinate
			
			if (Location.x < Rx + r && Location.x > Rx - r && Location.y < Ry_down && Location.y > Ry_up)
			{
				o_index = i; //setting the output index
				if (Objects[i]->GetName() == "MODULE")
				{
					if (Location.y > (Ry_down + Ry_up) / 2)
						modOutpin = 2;
					else
						modOutpin = 1;
				}
			}
		}
	}
	if (o_index<0) //the previous if statement held false, and o_index=-1 still

	{
		pUI->PrintMsg("Cannot find an output pin. try again");
		Sleep(2000); //pauses for 2 seconds
		pUI->ClearStatusBar();
		return; //exits the action class
	}
	else if (Objects[o_index]->GetName() == "LED")
	{
		pUI->PrintMsg("LEDs do not output.");
		Sleep(2000);
		pUI->ClearStatusBar();
		return;
	}
	else if (modOutpin != 0) //this is not a module, or the first output is chosen 
	{
		if (Objects[o_index]->OutputisFull())
		{
			pUI->PrintMsg("Cannot make any more connections to this output.");
			Sleep(2000);
			pUI->ClearStatusBar();
			return;
		}
	}
	else if (modOutpin ==2)
	{
		if (Objects[o_index]->Output2isFull())
		{
			pUI->PrintMsg("Cannot make any more connections to this output.");
			Sleep(2000);
			pUI->ClearStatusBar();
			return;
		}
	}

	pUI->ClearStatusBar();
	pUI->PrintMsg("Great! Now, click on an input pin.");


	pUI->GetPointClicked(Location.x, Location.y);
	
	for (int i = 0; i < c ; i++)
	{
		if (i == o_index) //a gate cannot connect to itself
			continue;
		//finding the nearest input pin (left side) that falls within a certain radius
		if (Objects[i] != NULL)
		{
			int Lx = Objects[i]->getGfxInfo()->PointsList[0].x;
			int Ly_down = Objects[i]->getGfxInfo()->PointsList[1].y;
			int Ly_up = Objects[i]->getGfxInfo()->PointsList[0].y;
			int Ly = (Ly_down + Ly_up) / 2; //center y coordinate

			if (Location.x < Lx + r && Location.x > Lx - r && Location.y < Ly_down && Location.y > Ly_up)
			{
				i_index = i;
				if (Objects[i]->GetName() == "MODULE")
				{
					Ly_up = Ly_up + (pUI->getGateHeight()) / 10;
					int fac = (pUI->getGateHeight()*(4/25));
					for (int z = 0; z < 5; z++)
					{
						if (Location.y > Ly_up + z*fac && Location.y < Ly_up + fac*(z+1))
						{
							n = (InputPinIndex) (z);
							break;
						}
					}
				}
				if (Location.y > Ly) //if the user pressed in the lower half
					n = Cdown;
				else //if the user pressed in the upper half
					n = Cup;
			}
		}
	}
	if (i_index<0) //a valid input pin wasn't found

	{
		pUI->PrintMsg("Cannot find an input pin. Try again");
		Sleep(2000);
		pUI->ClearStatusBar();
		return;
	}
	pUI->ClearStatusBar();

	inputGate = Objects[i_index]->GetName();
	if (inputGate == "LED" || inputGate == "NOT")//gates have only one input pin
		n = Cmid;
	else if (inputGate == "SWITCH") //Switches have no input pins
	{
		pUI->PrintMsg("A switch does not take input.");
		Sleep(2000);
		pUI->ClearStatusBar();
		return;
	}

	bool InputPinConnected;
	switch (n) 
	{
	case Cup: 
		InputPinConnected = Objects[i_index]->InputisConnected(0);
		break; 
	case Cmid: 
		InputPinConnected = Objects[i_index]->InputisConnected(0); 
		break;
	case Cdown: 
		InputPinConnected = Objects[i_index]->InputisConnected(1); 
		break;
	default: 
		InputPinConnected = Objects[i_index]->InputisConnected((int) n);
		break;
	}

	if (InputPinConnected)
	{
		pUI->PrintMsg("Input pin already has a connection.");
		Sleep(2000);
		pUI->ClearStatusBar();
		return;
	}

	Connection* Cnct = new Connection(Objects[o_index], Objects[i_index], n, modOutpin);
	pManager->AddConn(Cnct);
	pUI->PrintMsg("You have successfuly connected two objects.");
	Sleep(2000);
	pUI->ClearStatusBar();
}
