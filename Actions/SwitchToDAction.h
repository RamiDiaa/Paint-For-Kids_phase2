#ifndef SWITCHDM_ACTION_H
#define SWITCHDM_ACTION_H

#include "Action.h"

class SwitchDM: public Action
{
public:
	SwitchDM(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute() ;
};

#endif