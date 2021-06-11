#include "SendtoBackAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"



SendtoBackAction::SendtoBackAction(ApplicationManager * pApp):Action(pApp)
{}

void SendtoBackAction::ReadActionParameters() 
{

	
}

void SendtoBackAction::Execute() 
{	
	Output* pOut = pManager->GetOutput();
	if(pManager->GetNumOfSlc()!=0)
	{
	pManager->SendtoBack();
	pOut->PrintMessage("Figure is sent to Back");
	}
	else pOut->PrintMessage("No Figure Selected");

}

