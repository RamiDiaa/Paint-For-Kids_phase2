#include "SelectAction.h"
#include "..\Figures\CLine.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CCircle.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SelectAction::SelectAction(ApplicationManager * pApp):Action(pApp)
{}

void SelectAction::ReadActionParameters() 
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Select Figure number "+to_string(pManager->GetNumOfSlc()+1)+":");
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->ClearStatusBar();
}

//Execute the action
void SelectAction::Execute() 
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	CFigure *Selected=pManager->GetFigure(P1.x,P1.y);

	if(Selected==NULL)
	{
		pOut->PrintMessage("No new figure has been selected");
	}
	else pManager->SetSelectedFigure(Selected);
}
