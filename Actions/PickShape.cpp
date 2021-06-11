#include "PickShape.h"



PickShape::PickShape(ApplicationManager* pApp) :Action(pApp) {
	tries = 0;
	right = 0;
	wrong = 0;
}
void PickShape::ReadActionParameters() {         // PRINTS PLAYER TASK
	Output* pOut = pManager->GetOutput();
	color fill = pManager->GetRandFig(shape);
	if (shape == "Rectangle") {    
		pOut->PrintMessage("pick RECTANGLES figs");
	}
}
void PickShape::Execute() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	int NumOfRightFigs = pManager->NumOfRightFigs_Shape(shape);
	while (right < NumOfRightFigs || wrong < 3) {
		pIn->GetPointClicked(p1.x, p1.y);
		
		int Case = pManager->SelectedCase_Shape(shape, p1);
		if (Case == 0) {
			pOut->PrintMessage("No figure is selected(pick shape)");
		}
		else if (Case == 1) {
			pOut->PrintMessage("you got that right!!!(pick shape)");
			right++;
			tries++;
			pManager->HideFig(p1);
		}
		else if (Case == -1) {
			pOut->PrintMessage("you got that wrong ---(pick shape)");
			wrong++;
			tries++;
		}
		pManager->UpdateInterface();
		//pIn->GetUserAction();
	}

	if (wrong > 2) {
		pOut->PrintMessage("you lost,you got 3 wrong attempts");
	}
	else if (right = NumOfRightFigs) {
		pOut->PrintMessage("you win,you got all right figures");
	}


}
