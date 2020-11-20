#ifndef Paste_H
#define Paste_H

#include"Action.h"
#include"..\ApplicationManager.h"
#include"AddANDgate2.h"
#include "AddORgate2.h"
#include "AddNOTgate.h"
#include "AddNORgate.h"
#include "AddNANDgate2.h"
#include "AddXORgate2.h"
#include "AddXNORgate2.h"
#include "AddSWITCH.h"
#include "AddLED.h"
#include"Copy.h"
#include"Cut.h"
#include"Paste.h"
#include"AddMODULE.h"
using namespace std;
#include<string>

class Paste : public Action
{

public:
	Paste(ApplicationManager* pApp);
	virtual ~Paste(void);

	//Execute action (code depends on action type)
	virtual void Execute();
	string name = "non";
	virtual void Undo();
	virtual void Redo();


};

#endif