#include "SwitchToDAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SwitchDM::SwitchDM(ApplicationManager * pApp):Action(pApp)
{}

void SwitchDM::ReadActionParameters() 
{	
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Switch to draw mode: Let the Creativity Start!");
}

void SwitchDM::Execute() 
{
    Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	ifstream fin("tempsave.txt",ios::in);
	pManager->LoadAll(fin);
	pOut->CreateDrawToolBar();
	fin.close();
}
