#include "ExitAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ExitAction::ExitAction(ApplicationManager * pApp):Action(pApp)
{}

void ExitAction::ReadActionParameters() 
{	
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("EXIT");
	pOut->ClearStatusBar();
}

void ExitAction::Execute() 
{
	Output* pOut = pManager->GetOutput();
	pManager->ClearFigList();
	ReadActionParameters();
}
