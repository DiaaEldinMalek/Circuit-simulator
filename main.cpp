#include <iostream>
#include <sstream>
#include <cmath>

#include "ApplicationManager.h"
int main()
{

	ActionType ActType;
	//Create an object of ApplicationManager
	ApplicationManager AppManager;



	while (true)
	{
		//Read user action
		ActType = AppManager.GetUserAction();

		//Exexute the action
		AppManager.ExecuteAction(ActType);

		if (ActType == EXIT_THIS)
				break;
		//Update the drawing window
		AppManager.UpdateInterface();
	}
		
	return 0;
}

