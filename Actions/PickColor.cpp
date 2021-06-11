#include "PickColor.h"




PickColor::PickColor(ApplicationManager* pApp) :Action(pApp) {
	tries = 0;
	right = 0;
	wrong = 0;
}
void PickColor::ReadActionParameters() {         // PRINTS PLAYER TASK
	Output* pOut = pManager->GetOutput();
	string shape = "";
	fill = pManager->GetRandFig(shape);
	if (fill == RED) {                         // RED is a "Color" Object.
		pOut->PrintMessage("pick RED figs");
	}
	else if (fill == GREEN) {                  // GREEN is a "Color" Object.
		pOut->PrintMessage("pick GREEN figs");
	}
	else if (fill == BLUE) {                   // BLUE is a "Color" Object.
		pOut->PrintMessage("pick BLUE figs");
	}
	else if (fill == YELLOW) {                   // YELLOW is a "Color" Object.
		pOut->PrintMessage("pick YELLOW figs");
	}
	else if (fill == BLACK) {                   // BLACK is a "Color" Object.
		pOut->PrintMessage("pick BLACK figs");
	}
	else {                
		pOut->PrintMessage("pick WHITE figs");
	}
}
void PickColor::Execute() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	int NumOfRightFigs = pManager->NumOfRightFigs_Color(fill);
	while (right < NumOfRightFigs || wrong < 3) {
		pIn->GetPointClicked(p1.x, p1.y);
		int Case = pManager->SelectedCase_Color(fill, p1);
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
