#ifndef RESTART_H
#define RESTART_H

#include "Action.h"
#include "../GUI/Output.h"
#include "../GUI/Input.h"
#include "../ApplicationManager.h"

class Restart:public Action{
public:
	Restart(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

#endif
