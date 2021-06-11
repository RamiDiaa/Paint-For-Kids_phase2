#include "DeleteAction.h"

#include "..\Figures\CLine.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CCircle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

DeleteAction::DeleteAction(ApplicationManager * pApp):Action(pApp)
{
}

void DeleteAction::ReadActionParameters() 
{	
	
}

//Execute the action
void DeleteAction::Execute() 
{  Output* pOut = pManager->GetOutput();

		if(pManager->GetNumOfSlc()!=0)

			 {pManager->ShiftAndDelete();

				pOut->PrintMessage("Figure has been Deleted");}
		else
				pOut->PrintMessage("No Figure Selected");
	
}


