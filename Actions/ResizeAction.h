#ifndef RESIZE_ACTION_H
#define RESIZE_ACTION_H

#include "Action.h"
#include "..\Figures\CFigure.h"

class ResizeAction: public Action
{
	double Factor;
	CFigure* SelectedFigure;
public:
	ResizeAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

#endif