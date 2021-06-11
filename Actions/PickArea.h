#ifndef PICK_AREA_H
#define PICK_AREA_H
#include "Action.h"
#include "../GUI/Output.h"
#include "../GUI/Input.h"
#include "../ApplicationManager.h"

class PickArea : public Action {
	float area;
	
	int tries;
	int right;
	int wrong;
	Point p1;



public:
	PickArea(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();


};

#endif



