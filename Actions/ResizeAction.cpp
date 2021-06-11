#include "ResizeAction.h"

#include "..\Figures\CLine.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CCircle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ResizeAction::ResizeAction(ApplicationManager * pApp):Action(pApp)
{}

void ResizeAction::ReadActionParameters() 
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	
	
		pOut->PrintMessage("Enter the factor you wish to resize the selected figure by: ");
		Factor=stod(pIn->GetSrting(pOut));

}

void ResizeAction::Execute() 
{	
	Output* pOut = pManager->GetOutput();

	if(pManager->GetNumOfSlc()!=0){
	ReadActionParameters();
	if(Factor>0)
	{
		pOut->PrintMessage("Figure(s) resized.");
		pManager->ResizeFigures(Factor);
	}
	else
	{
		pOut->PrintMessage("Factor can't be negative. Please try again.");
	}}
	else pOut->PrintMessage("No Figure Selected");

}
