#ifndef PICK_BOTH_H
#define PICK_BOTH_H
#include "Action.h"
#include "../GUI/Output.h"
#include "../GUI/Input.h"
#include "../ApplicationManager.h"
class PickBoth : public Action {
	color fill;
	string shape;


	int tries;
	int right;
	int wrong;
	Point p1;

public:
	PickBoth(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();


};

#endif


