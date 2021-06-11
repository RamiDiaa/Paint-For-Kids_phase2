
#ifndef PICK_SHAPE_H
#define PICK_SHAPE_H
#include "Action.h"
#include "../GUI/Output.h"
#include "../GUI/Input.h"
#include "../ApplicationManager.h"

class PickShape : public Action {
	string shape;


	int tries;
	int right;
	int wrong;
	Point p1;

public:
	PickShape(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();


};


#endif
