#ifndef PICK_COLOR_H
#define PICK_COLOR_H
#include "Action.h"
#include "../GUI/Output.h"
#include "../GUI/Input.h"
#include "../ApplicationManager.h"

class PickColor : public Action {
	color fill;
	

	int tries;
	int right;
	int wrong;
	Point p1;

public:
	PickColor(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();
	

};

#endif

