#include "PickBoth.h"



/*
todo 

add type and area attributes for every fig 
*/

PickBoth::PickBoth(ApplicationManager* pApp) :Action(pApp) {
	tries = 0;
	right = 0;
	wrong = 0;
}
void PickBoth::ReadActionParameters() {         // PRINTS PLAYER TASK
	Output* pOut = pManager->GetOutput();
	fill = pManager->GetRandFig(shape);
	if (fill == RED) {                         // RED is a "Color" Object.
		pOut->PrintMessage("pick all" + shape +"s - RED COLOR");
	}
	else if (fill == GREEN) {                  // GREEN is a "Color" Object.
		pOut->PrintMessage("pick all" + shape + "s - GREEN COLOR");
	}
	else if (fill == BLUE) {                   // BLUE is a "Color" Object.
		pOut->PrintMessage("pick all" + shape + "s - BLUE COLOR");
	}
	else if (fill == YELLOW) {                   // YELLOW is a "Color" Object.
		pOut->PrintMessage("pick all" + shape + "s - YELLOW COLOR");
	}
	else if (fill == BLACK) {                   // BLACK is a "Color" Object.
		pOut->PrintMessage("pick all" + shape + "s - BLACK COLOR");
	}
	else {
		pOut->PrintMessage("pick all" + shape + "s - WHITE COLOR");
	}
}
void PickBoth::Execute() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	int NumOfRightFigs = pManager->NumOfRightFigs_Both(fill,shape);
	while (right < NumOfRightFigs || wrong < 3) {
		pIn->GetPointClicked(p1.x, p1.y);
		int Case = pManager->SelectedCase_Both(fill, shape, p1);
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

