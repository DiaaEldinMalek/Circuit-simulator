#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "UI\UI.h"
#include "Actions\Action.h"
#include "Components\Component.h"
#include "Components/Connection.h"
//Main class that manages everything in the application.
class ApplicationManager
{
private:
	int CompCount;		//Actual number of Components
	enum { MaxCompCount = 200 };	//Max no of Components	
	enum { MaxConnCount = 4000 }; //Max no of Connections	
	int ConnCount;
	Connection* ConnList[MaxConnCount];
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)
	UI* pUI; //pointer to the UI
public:	
	ApplicationManager(); //constructor

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();
	
	//Creates an action and executes it
	void ExecuteAction(ActionType);
	
	void UpdateInterface();	//Redraws all the drawing window

	//Gets a pointer to UI Object
	UI* GetUI();
	
	//Returns the pointer to the array of components
	Component** getComps();

	//Returns the pointer to the array of connections
	Connection** getConns();

	//Get number of components
	int getCompCount();

	//Get number of connections
	int getConnCount();

	void setCompCount(int num);
	//Adds a new component to the list of components
	void AddComponent(Component* pComp);

	//Adds a new connection
	void AddConn(Connection* pConn);

	//destructor
	~ApplicationManager();
};

#endif