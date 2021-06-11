#include "SwitchToPAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SwitchPM::SwitchPM(ApplicationManager * pApp):Action(pApp)
{}

void SwitchPM::ReadActionParameters() 
{	
	Output* pOut = pManager->GetOutput();
	if(pManager->GetFigCount()!=0)
	pOut->PrintMessage("Switch to play mode: Let's Have Fun!");
	else pOut->PrintMessage("No Figures to Play with!");
}

void SwitchPM::Execute() 
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();

	if(pManager->GetFigCount()!=0){
	 pManager->CleanSelectedFig();
	ofstream fout("tempsave.txt",ios::out);
	pManager->SaveAll(fout);
    pOut->CreatePlayToolBar();
	fout.close();}
}
