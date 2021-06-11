#include "PickArea.h"




PickArea::PickArea(ApplicationManager* pApp) :Action(pApp) {
	tries = 0;
	right = 0;
	wrong = 0;
}
void PickArea::ReadActionParameters() {         // PRINTS PLAYER TASK
	Output* pOut = pManager->GetOutput();
	area = pManager->GetRandArea();
	pOut->PrintMessage("pick figs with area more than ");
	
}
void PickArea::Execute() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	int NumOfRightFigs = pManager->NumOfRightFigs_Area(area);
	while (right < NumOfRightFigs || wrong < 3) {
		pIn->GetPointClicked(p1.x, p1.y);
		int Case = pManager->SelectedCase_Area(area, p1);
		if (Case == 0) {
			pOut->PrintMessage("No figure is selected");
		}
		else if (Case == 1) {
			pOut->PrintMessage("you got that right!!!");
			right++;
			tries++;
			pManager->HideFig(p1);
		}
		else if (Case == -1) {
			pOut->PrintMessage("you got that wrong ---");
			wrong++;
			tries++;
		}
		pManager->UpdateInterface();
	}

	if (wrong > 2) {
		pOut->PrintMessage("you lost,you got 3 wrong attempts");
	}
	else if (right = NumOfRightFigs) {
		pOut->PrintMessage("you win,you got all right figures");
	}


}
