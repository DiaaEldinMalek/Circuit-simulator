#include "ApplicationManager.h"
#include "Actions\AddANDgate2.h"
#include "Actions\AddORgate2.h"
#include "Actions\AddNOTgate.h"
#include "Actions\AddNORgate.h"
#include "Actions\AddNANDgate2.h"
#include "Actions\AddXORgate2.h"
#include "Actions\AddXNORgate2.h"
#include "Actions\AddSWITCH.h"
#include "Actions\AddLED.h"
#include "Actions\AddConnection.h"
#include "Actions\EXIT.h"
#include "Actions\SELECT.h"
#include"Actions\SwitchMode.h"
#include"Actions\Copy.h"
#include"Actions\Cut.h"
#include "Actions\Label.h"
#include "Actions\Edit.h"
#include"Actions\Delete.h"	
#include"Actions\Paste.h"
#include"Actions\Move.h"
#include"Actions/AddMODULE.h"
#include "Actions/Simulate.h"
#include <fstream>

ApplicationManager::ApplicationManager()
{
	CompCount = 0;
	ConnCount = 0;
	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = NULL;
	for (int i = 0; i < MaxConnCount; i++)
		ConnList[i] = NULL;
	//Creates the UI Object & Initialize the UI
	pUI = new UI;
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;		
}

void ApplicationManager::AddConn(Connection* pConn) 
{
	ConnList[ConnCount++] = pConn;
}
////////////////////////////////////////////////////////////////////

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return pUI->GetUserAction(); 	
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;
	switch (ActType)
	{
	case ADD_AND_GATE_2:
		pAct = new AddANDgate2(this);
		break;
	case ADD_OR2_GATE_2:
		pAct = new AddORgate2(this);
		break;
	case ADD_INV:
		pAct = new AddNOTgate(this);
		break;
	case ADD_NOR_GATE_2:
		pAct = new AddNORgate2(this);
		break;
	case ADD_XNOR_GATE_2:
		pAct = new AddXNORgate2(this);
		break;
	case ADD_XOR_GATE_2:
		pAct = new AddXORgate2(this);
		break;
	case ADD_NAND_GATE_2:
		pAct = new AddNANDgate2(this);
		break;
	case ADD_LED:
		pAct = new AddLED(this);
		break;
	case ADD_Switch:
		pAct = new AddSWITCH(this);
		break;
	case ADD_CONNECTION:
		pAct = new AddConnection(this);
		break;
	case ADD_Label:
		pAct = new Label(this);
		break;
	case ADD_MODULE:
		pAct = new AddMODULE(this);
		break;
	case EDIT_Label:
		pAct = new Edit(this);
		break;
	case EXIT_THIS:
		pAct = new EXIT(this);
		break;
	case SELECT_THIS:
		pAct = new SELECT(this);
		break;
	case DSN_MODE:
		pAct = new SwitchMode(this);
		break;
	case SIM_MODE:
		pAct = new SwitchMode(this);
		break;
	case COPY:
		pAct = new Copy(this);
		break;
	case CUT:
		pAct = new Cut(this);
		break;
	case PASTE:
		pAct = new Paste(this);
		break;
	case DEL:
		pAct = new Delete(this);
		break;
	case MOVE:
		pAct = new Move(this);
		break;
	case SIM:
		pAct = new Simulate(this);
	case SAVE:
		void Save();
		break;
	case LOAD:
		void Load();
		break;
	};
	if(pAct)
	{
		pAct->Execute();
		delete pAct;
		pAct = NULL;
	}
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{
	pUI->ClearDrawingArea();
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i] != NULL) {
			CompList[i]->Draw(pUI);
			CompList[i]->DispLabel(pUI);
		}
	}	
	for (int i = 0; i < ConnCount; i++) {
		if (ConnList[i] != NULL) {
			ConnList[i]->DrawC(pUI);
		}
	}

}

////////////////////////////////////////////////////////////////////
UI* ApplicationManager::GetUI()
{
	return pUI;
}

////////////////////////////////////////////////////////////////////
int ApplicationManager::getCompCount()
{
	return (CompCount);
}

int ApplicationManager::getConnCount()
{
	return (ConnCount);
}

void ApplicationManager::setCompCount(int num)
{
	CompCount = num;
}
////////////////////////
Component** ApplicationManager::getComps()
{
	return CompList;
}

Connection** ApplicationManager::getConns()
{
	return ConnList;
}
////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	delete pUI;
	pUI = NULL;
}