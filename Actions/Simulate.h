#ifndef SIMULATE_H
#define SIMULATE_H

#include "SELECT.h"
class Component;
class Simulate : public SELECT
{
private:
	int x, y;	//THE POINT WHERE THE USER CLICKS
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	Simulate(ApplicationManager* pApp);
	virtual ~Simulate(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
	void DistributeOutput(Component* Root);
	void RunCircuit();
};
#endif // !SIMULATE_H
