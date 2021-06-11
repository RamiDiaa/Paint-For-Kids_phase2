#ifndef SWITCHPM_ACTION_H
#define SWITCHPM_ACTION_H

#include "Action.h"

class SwitchPM : public Action
{
public:
	SwitchPM(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute() ;
};

#endif