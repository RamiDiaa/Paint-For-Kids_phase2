#include "BringtoFrontAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"



BringtoFrontAction::BringtoFrontAction(ApplicationManager * pApp):Action(pApp)
{}

void BringtoFrontAction::ReadActionParameters() 
{}

void BringtoFrontAction::Execute() 
{	
	Output* pOut = pManager->GetOutput();
	if(pManager->GetNumOfSlc()!=0){
	pManager->BringToFront();
	pOut->PrintMessage("Figure is Brought to Front");}
	else pOut->PrintMessage("No Figure Selected");

}

