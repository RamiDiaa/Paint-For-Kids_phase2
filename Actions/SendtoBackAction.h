#ifndef BringAndAction_ACTION_H
#define BringAndAction_ACTION_H

#include "Action.h"
#include "..\Figures\CFigure.h"

class SendtoBackAction: public Action
{
	
	
public:
	SendtoBackAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

#endif