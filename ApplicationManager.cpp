#include "ApplicationManager.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
	NumOfSlc=0;
	ClipboardCount=0;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
	{
		FigList[i] = NULL;
		SlcFigs[i]=NULL;
		Clipboard[i]=NULL;
	}
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;
		case DRAW_CIRC:
			pAct= new AddCircAction(this);
            break;
		case DRAW_LINE:
			pAct= new AddLineAction(this);
            break;
		case DRAW_TRI:
			pAct= new AddTriAction(this);
			break;
		case SELECT:
			pAct= new SelectAction(this);
			break;
		case CHNG_DRAW_CLR:
			pAct= new ChangeCDCAction(this);
			break;
		case CHNG_FILL_CLR:
			pAct= new ChangeCFCAction(this);
			break;
		case RESIZE:
			pAct=new ResizeAction(this);
			break;
		
		case DEL:
			pAct=new DeleteAction(this);
			break;
		case  TO_PLAY:
			pAct=new SwitchPM(this);
			break;
		case TO_DRAW:
			pAct=new SwitchDM(this);
			break;
		case EXIT:
			pAct=new ExitAction(this);
			break;

		case SEND_BACK:
			pAct=new SendtoBackAction(this);
			break;

		case BRNG_FRNT:
			pAct=new BringtoFrontAction(this);
			break;

			/// ////////////////////RD
		case PICK_COLOR:
			pAct = new PickColor(this);
			break;
		case PICK_SHAPE:
			pAct = new PickShape(this);
			break;
		case PICK_BOTH:
			pAct = new PickBoth(this);
			break;
		case PICK_AREA:
			pAct = new PickArea(this);
			break;
		case RESTART:
			pAct = new Restart(this);
			break;
	
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
	{
		FigList[FigCount] = pFig;
		FigCount++;
	}

}

int ApplicationManager::GetFigCount() {return FigCount;}

void ApplicationManager:: ShiftAndDelete()
{
	for(int k=0;k<NumOfSlc;k++)
	{
	   for(int i=0;i<FigCount;i++)
	{
		 if(SlcFigs[k]==FigList[i])	
		{
			FigList[i]=NULL;delete SlcFigs[k];SlcFigs[k]=NULL;
			for(int j=i;j<FigCount-1;j++)
			{
				FigList[j]=FigList[j+1];
			}
			 FigList[FigCount-1]=NULL;
			 FigCount--;
		}
	}
	}
	for(int i=0;i<NumOfSlc;i++)
		SlcFigs[i]=NULL;
	NumOfSlc=0;
}

void ApplicationManager::BringToFront()
{

	for(int u=NumOfSlc-1;u>-1;u--)
	  {
	   
		  for(int i=0;i<FigCount;i++)
	    {
			if(SlcFigs[u]==FigList[i])
			{
				FigList[FigCount++]=FigList[i];
				FigList[i]=NULL;SlcFigs[u]=NULL;
				 for(int j=i;j<FigCount-1;j++)
			 {
					  FigList[j]=FigList[j+1];
			 }
				 FigList[FigCount-1]=NULL;FigCount--;
				 FigList[FigCount-1]->SetSelected(false);
				 
			}
	  }
     
   }
	NumOfSlc=0;
	
}

void ApplicationManager::SendtoBack()
{
		for(int u=NumOfSlc-1;u>-1;u--)
	  {
		for(int i=0;i<FigCount;i++)
		{
			if(SlcFigs[u]==FigList[i])
			{
				
				FigList[FigCount++]=FigList[i];
				FigList[i]=NULL;SlcFigs[u]=NULL;
				 for(int j=i;j>0;j--)
			 {
					  FigList[j]=FigList[j-1];
			 }
				 FigList[0] = FigList[FigCount-1];
				 FigList[FigCount--]=NULL;
				 FigList[0] ->SetSelected(false);
				
			}
		}

		}
		 NumOfSlc=0;
}

	
	




////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	
	
	for(int i=FigCount-1;i>=0;i--)
	{
		if(FigList[i]->IsPointInside(x,y))
		{
			return FigList[i];
		}
	}

	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.
	return NULL;
}

CFigure* ApplicationManager::GetSlcFig()
{
	return SlcFigs[0];
}

void ApplicationManager::ResizeFigures(double Factor)
{
	for(int i=0;i<NumOfSlc;i++)
	{
		SlcFigs[i]->Resize(Factor);
		if(SlcFigs[i]->IsValid()==false)
		{
			pOut->PrintMessage("Invalid resize factor");
			for(int j=0;j<=i;j++)
			{
				SlcFigs[i]->Resize(1/Factor);
			}
			break;
		}
	}
}



void ApplicationManager::SaveAll(ofstream& out)
{
	out<<pOut->getCrntDrawColor()<<"\t"<<pOut->getCrntFillColor()<<endl;
	out<<FigCount<<endl;
	for(int i=0;i<FigCount;i++)
	{
		FigList[i]->Save(out);
	}
}

void ApplicationManager::LoadAll(ifstream& in)
{
	ClearFigList();
	int count;
	color draw, fill;
	in >> draw >> fill;
	ChangeCDrawingColor(draw);
	ChangeCFillColor(fill);
	if (fill == INDIAN) UI.FillFigures = 0;
	in >> count;
	CFigure* LoadedFig;
	GfxInfo dummy;
	dummy.BorderWdth = pOut->getCrntPenWidth();
	dummy.DrawClr = pOut->getCrntDrawColor();
	dummy.FillClr = pOut->getCrntFillColor();
	dummy.isFilled = 0;
	for (int i = 0; i < count; i++)
	{
		string type;
		in >> type;
		if (type == "CIRCLE")
		{
			LoadedFig = new CCircle(dummy);
			LoadedFig->Load(in);
		}
		else if (type == "RECT")
		{
			LoadedFig = new CRectangle(dummy);
			LoadedFig->Load(in);
		}
		else if (type == "TRIANG")
		{
			LoadedFig = new CTriangle(dummy);
			LoadedFig->Load(in);
		}
		else if (type == "LINE")
		{
			LoadedFig = new CLine(dummy);
			LoadedFig->Load(in);
		}
		AddFigure(LoadedFig);
	}
	LoadedFig->setnexID(FigList[FigCount - 1]->GetID() + 1);
}


void ApplicationManager::ClearFigList()
{
	for(int i=0;i<FigCount;i++)
	{
		delete FigList[i];
		FigList[i]=NULL;
	}
	FigCount=0;
}

void ApplicationManager::SetSelectedFigure(CFigure *Selected) 
{
	SlcFigs[NumOfSlc]=Selected;
	if(SlcFigs[NumOfSlc]->IsSelected()==true)
	{
		for(int i=0;i<NumOfSlc;i++)
		{
			if(SlcFigs[i]->GetID()==SlcFigs[NumOfSlc]->GetID())
			{
				SlcFigs[i]->SetSelected(false);
				if(NumOfSlc-1==0) pOut->PrintMessage("Figure deselected. No figures are currently selected.");
				else if (NumOfSlc-1==1) pOut->PrintMessage("Figure deselected. Number of Selected Figures is 1 .");
				else pOut->PrintMessage("Figure deselected. You got "+to_string(NumOfSlc-1)+" figures selected.");
				SlcFigs[i]=SlcFigs[NumOfSlc-1];
				SlcFigs[NumOfSlc-1]=NULL;
				SlcFigs[NumOfSlc]=NULL;
				NumOfSlc--;
				break;
			}
		}
	}
	else if(SlcFigs!=NULL)
	{
		SlcFigs[NumOfSlc]->SetSelected(true);
		SlcFigs[NumOfSlc]->PrintInfo(pOut);
		NumOfSlc++;
	}
}

int ApplicationManager::GetNumOfSlc()
{
	return NumOfSlc;
}

void ApplicationManager::ChangeCDrawingColor(color SelectedColor)
{
	pOut->changeCrntDrawColor(SelectedColor);
}

void ApplicationManager::ChangeSDrawingColor(color SelectedColor)
{
	for(int i=0;i<NumOfSlc;i++)
	{
		SlcFigs[i]->ChngDrawClr(SelectedColor);
	}
}

void ApplicationManager::ChangeCFillColor(color SelectedColor)
{
	if(SelectedColor==UI.FillColor)
	{
		UI.FillFigures=0;
		UI.FillColor=INDIAN;
	}
	else
	{
		UI.FillFigures=1;
		pOut->changeCrntFillColor(SelectedColor);
	}
}

void ApplicationManager::ChangeSFillColor(color SelectedColor)
{
	for(int i=0;i<NumOfSlc;i++)
	{
		SlcFigs[i]->ChngFillClr(SelectedColor);
	}
}




void ApplicationManager::CleanSelectedFig()
{
	for(int i=0;i<NumOfSlc;i++)
	{
		SlcFigs[i]->SetSelected(false);
		SlcFigs[i]=NULL;
	}
	NumOfSlc=0;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	pOut->ClearDrawArea();
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }



void ApplicationManager:: SwitchToPlay()
{
	for(int i=0; i<FigCount; i++)
		FigList[i]->tempSave();
}



void ApplicationManager:: SwitchToDraw()
{
	for(int i=0; i<FigCount; i++)
		{
			FigList[i]->returntempborder();
			FigList[i]->returntempfilled();
	    }
}




///////////////////////////RD
color ApplicationManager::GetRandFig(string& s1) { // return color and set shape by refrence
	if (FigCount != 0) {
		int rnd = rand() % FigCount;
		s1 = FigList[rnd]->GetShape();
		return FigList[rnd]->GetFillColor();
	}
	return NULL;
}

float ApplicationManager::GetRandArea() {
	if (FigCount != 0) {
		int rnd = rand() % FigCount;
		return FigList[rnd]->GetArea();
	}
	return NULL;
}


/*
////////////////////////////////////////////////////////remove
color ApplicationManager::GetRandColor() {
	if (FigCount != 0) {
		int rnd = rand() % FigCount;
		return FigList[rnd]->GetFillColor();
	}
	return NULL;
}


string ApplicationManager::GetRandShape() {
	if (FigCount != 0) {
		int rnd = rand() % FigCount;
		return FigList[rnd]->GetShape();
	}
	return NULL;
}

/////////////////////////////////////////////////////////
*/


int ApplicationManager::NumOfRightFigs_Color(color c1) {
	int r = 0;
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->GetFillColor() == c1) {
			r++;
		}
	}
	return r;
}

int ApplicationManager::NumOfRightFigs_Shape(string s1) {
	int r = 0;
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->GetShape() == s1) {
			r++;
		}
	}
	return r;
}

int ApplicationManager::NumOfRightFigs_Both(color c1, string s1) {
	int r = 0;
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->GetShape() == s1){
			if (FigList[i]->GetFillColor() == c1) {
				r++;
			}
		}
	}
	return r;
}

int ApplicationManager::NumOfRightFigs_Area(float a1) {
	int r = 0;
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->GetArea() >= a1) {
			r++;
		}
	}
	return r;
}
//////


int ApplicationManager::SelectedCase_Color(color c1, Point p1) {
	// 0  : nothing is selected
	// 1  : right 
	// -1 : wrong

	CFigure* Selected = GetFigure(p1.x, p1.y);
	if (Selected == NULL) {
		return 0;
	}
	else if (Selected->GetFillColor() == c1) {
		return 1;
	}
	else { //if (Selected->GetFillColor() != c1) {
		return -1;
	}


}

int ApplicationManager::SelectedCase_Shape(string s1, Point p1) {
	// 0  : nothing is selected
	// 1  : right 
	// -1 : wrong
	/*
		Action* pAct = NULL;
		if (p1.y >= 0 && p1.y < UI.ToolBarHeight) {
			pOut->PrintMessage("toolbar//////////");
			int ClickedItemOrder = (p1.x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder) {
			case ITM_P_H_FSHAPE: pAct = new PickShape(this); break;
			case ITM_P_H_FCOLOR: pAct = new PickColor(this); break;
			case ITM_P_H_FBOTH: pAct = new PickBoth(this); break;
			case ITM_AREA: pAct = new PickArea(this); break;
			case ITM_SWITCH_DRAW:pAct = new SwitchDM(this); break;
			case ITM_EXIT2: pAct = new ExitAction(this); break;
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}
		//ExecuteAction(pAct);
		*/


	CFigure* Selected = GetFigure(p1.x, p1.y);
	if (Selected == NULL) {
		return 0;
	}
	else if (Selected->GetShape() == s1) {
		return 1;
	}
	else{// if (Selected->GetShape() != s1) {
		return -1;
	}

}

int ApplicationManager::SelectedCase_Both(color c1, string s1, Point p1) {
	// 0  : nothing is selected
	// 1  : right 
	// -1 : wrong

	CFigure* Selected = GetFigure(p1.x, p1.y);
	if (Selected == NULL) {
		return 0;
	}
	else if (Selected->GetShape() == s1 && Selected->GetFillColor() == c1) {
		return 1;
	}
	else{// if (Selected->GetShape() != s1 || Selected->GetFillColor() != c1) {
		return -1;
	}


}

int ApplicationManager::SelectedCase_Area(float a1, Point p1) {
	// 0  : nothing is selected
	// 1  : right 
	// -1 : wrong

	CFigure* Selected = GetFigure(p1.x, p1.y);
	if (Selected == NULL) {
		return 0;
	}
	else if (Selected->GetArea() >= a1) {
		return 1;
	}
	else {//if (Selected->GetArea() < a1) {
		return -1;
	}

}



void ApplicationManager::HideFig(Point p1) {
	CFigure* Selected = GetFigure(p1.x, p1.y);
	for (int i = 0; i < FigCount; i++)
	{
		if (Selected == FigList[i])
		{

			FigList[i] = FigList[FigCount - 1];
			FigList[FigCount - 1] = NULL;
			FigCount--;


		}
	}
	UpdateInterface();

}
/////////////////////////^^^



////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{

	for(int i=0; i<NumOfSlc; i++)
		{
			SlcFigs[i]=NULL;
		}


	for(int i=0; i<FigCount; i++)
	{
		delete FigList[i];
		FigList[i]=NULL;
	}

	

	delete pIn;
	delete pOut;
	
	
	

}