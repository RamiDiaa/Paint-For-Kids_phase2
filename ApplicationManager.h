#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"

#include "GUI\Input.h"
#include "GUI\Output.h"
#include "GUI\UI_Info.h"

#include "Figures\CFigure.h"
#include "Figures\CCircle.h"
#include "Figures\CRectangle.h"
#include "Figures\CTriangle.h"
#include "Figures\CLine.h"

#include "Actions\AddRectAction.h"
#include "Actions\AddCircAction.h"
#include "Actions\AddLineAction.h"
#include "Actions\AddTriAction.h"

#include "Actions\SelectAction.h"
#include "Actions\ChangeDrCAction.h"
#include "Actions\ChangeFlCAction.h"
#include "Actions\ResizeAction.h"
#include "Actions\DeleteAction.h"
#include "Actions\BringtoFrontAction.h"
#include "Actions\SendtoBackAction.h"

#include "Actions\SwitchToDAction.h"
#include "Actions\SwitchToPAction.h"

#include "Actions\ExitAction.h"

////////////////////RD
#include "Actions\PickColor.h"
#include "Actions\PickShape.h"
#include "Actions\PickBoth.h"
#include "Actions\PickArea.h"
#include "Actions\Restart.h"
#include <stdlib.h>
#include <fstream>
#include "CMUgraphicsLib/CMUgraphics.h"

#include "operators.h"
//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	int NumOfSlc;
	int ClipboardCount;
	CFigure* SlcFigs[MaxFigCount]; //Pointer to the selected figure
	CFigure* Clipboard[MaxFigCount];   //Pointer to the copied/cut figure

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
		
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window
	void SetSelectedFigure(CFigure *Selected);
	CFigure* GetSlcFig();

	// -- Action-Related Functions

	void ChangeCDrawingColor(color);
	void ChangeSDrawingColor(color);
	void ChangeCFillColor(color);
	void ChangeSFillColor(color);
	void ShiftAndDelete();  //delete selected figure and shift
	int GetNumOfSlc();
	void ResizeFigures(double Factor);
	void SaveAll(ofstream& out);
	void LoadAll(ifstream& in);
	void ClearFigList();
	void SwitchToPlay();
	void SwitchToDraw();
	
	void CleanSelectedFig();
	void SendtoBack();
	void BringToFront();
	int GetFigCount();



	/////////////////RD
	color GetRandFig(string& s1);// return color and set shape by refrence
	//color GetRandColor();
	//string GetRandShape();
	float GetRandArea();

	int NumOfRightFigs_Color(color);
	int NumOfRightFigs_Shape(string);
	int NumOfRightFigs_Both(color, string);
	int NumOfRightFigs_Area(float);
	
	int SelectedCase_Color(color, Point);
	int SelectedCase_Shape(string, Point);
	int SelectedCase_Both(color, string, Point);
	int SelectedCase_Area(float, Point);

	void HideFig(Point p1);
	
	//////////////
};


#endif