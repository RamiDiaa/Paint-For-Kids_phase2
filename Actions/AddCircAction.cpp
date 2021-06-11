#include "AddCircAction.h"
#include "..\Figures\CCircle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddCircAction::AddCircAction(ApplicationManager * pApp):Action(pApp)
{}

void AddCircAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at center");
	
	//Read Centre and store in point Centre
	pIn->GetPointClicked(Center.x, Center.y);

	pOut->PrintMessage("New Circle: Click point on circumfrence");

	//Read Point on circumfrence and store in point PCircumfrence
	pIn->GetPointClicked(PCircumfrence.x, PCircumfrence.y);

	CircGfxInfo.isFilled = UI.FillFigures;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	CircGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddCircAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();

	
	//Create a circle with the parameters read from the user
	CCircle *C=new CCircle(Center, PCircumfrence, CircGfxInfo);

	//Add the circle to the list of figures
	if(C->IsValid())
		pManager->AddFigure(C);
	else
		pOut->PrintMessage("Invalid points for drawing circle.");

}