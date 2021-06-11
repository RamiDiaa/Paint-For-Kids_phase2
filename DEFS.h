#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contais some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_LINE,		//Draw Line
	DRAW_RECT,		//Draw Rectangle
	DRAW_TRI,		//Draw Triangle
	DRAW_CIRC,		//Draw Circle
	CHNG_DRAW_CLR,	//Change the drawing color
	CHNG_FILL_CLR,	//Change the filling color
	DEL,			//Delete a figure(s)
	MOVE,			//Move a figure(s)
	RESIZE,			//Resize a figure(s)
	ROTATE,			//Rotate a figure(s)
	SEND_BACK,		//Send a figure to the back of all figures "Bonus Part"
	BRNG_FRNT,		//Bring a figure to the front of all figures "Bonus Part"
	SAVE,			//Save the whole graph to a file
	LOAD,			//Load a graph from a file
	SELECT,         //Select a figure
	EXIT,			//Exit the application
	COPY,
	CUT,
	ZOOM_IN,
	ZOOM_OUT,
	PASTE,
	COLOR_RED,
	COLOR_YELLOW,
	COLOR_BLUE,
	COLOR_GREEN,
	COLOR_WHITE,
	COLOR_BLACK,

	/// /////////RD

	PICK_SHAPE,
	PICK_COLOR,
	PICK_AREA,
	PICK_BOTH,
	RESTART,


	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	EMPTY,			//A click on empty place in the toolbar
	
	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY			//Switch interface to Play mode

	///TODO: Add more action types (if needed)
};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif