#ifndef SendAction_ACTION_H
#define SendAction_ACTION_H

#include "Action.h"
#include "..\Figures\CFigure.h"

class BringtoFrontAction: public Action
{
	

public:
	BringtoFrontAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

#endif