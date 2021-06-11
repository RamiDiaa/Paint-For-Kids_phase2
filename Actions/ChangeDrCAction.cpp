#include "ChangeDrCAction.h"

#include "..\Figures\CLine.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CCircle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ChangeCDCAction::ChangeCDCAction(ApplicationManager * pApp):Action(pApp)
{IsSelected=false;}

void ChangeCDCAction::ReadActionParameters() 
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	SelectedFigure=pManager->GetSlcFig();
	if(SelectedFigure==NULL)
	{
		pOut->PrintMessage("Select Color to Change Current Drawing Color");
	}
	else
	{
		pOut->PrintMessage("Select Color to Change Drawing Color of Selected Figure");
	}
	SelectedColorIndex=pManager->GetUserAction();
	pOut->ClearStatusBar();
}

void ChangeCDCAction::Execute() 
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	if(SelectedColorIndex==18)
	{
		SelectedColor=BLACK;
		IsSelected=true;
		pOut->PrintMessage("Current Drawing Color changed to BLACK");
	}
	else if(SelectedColorIndex==19)
	{
		SelectedColor=WHITE;
		IsSelected=true;
		pOut->PrintMessage("Current Drawing Color changed to WHITE");
	}
	else if(SelectedColorIndex==20)
	{
		SelectedColor=RED;
		IsSelected=true;
		pOut->PrintMessage("Current Drawing Color changed to RED");
	}
	else if(SelectedColorIndex==21)
	{
		SelectedColor=GREEN;
		IsSelected=true;
		pOut->PrintMessage("Current Drawing Color changed to GREEN");
	}
	else if(SelectedColorIndex==22)
	{
		SelectedColor=BLUE;
		IsSelected=true;
		pOut->PrintMessage("Current Drawing Color changed to BLUE");
	}
	else
	{
		pOut->PrintMessage("No Color has been selected");
	}
	if(SelectedFigure==NULL)
	{
		if(IsSelected)
		{
			pManager->ChangeCDrawingColor(SelectedColor);
		}
	}
	else
	{
		pManager->ChangeSDrawingColor(SelectedColor);
	}
}
