#include "Restart.h"


Restart::Restart(ApplicationManager* pApp):Action(pApp){

}
void Restart::ReadActionParameters(){
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Restarting...please wait.");
}
void Restart::Execute(){
	
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	ifstream fin("tempsave.txt", ios::in);
	pManager->LoadAll(fin);
	pOut->CreateDrawToolBar();
	fin.close();
}