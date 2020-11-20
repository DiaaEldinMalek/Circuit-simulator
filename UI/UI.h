#ifndef __UI_H_
#define __UI_H_

#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\Defs.h"

#include <string>
using namespace std;

struct Point
{
	int x,y;
};


//A structure to contain drawing parameters for each component
//Each component stores its drawing points in this struct 
//For example, a Gate can store points of the rectangluar area it occupies
//				The Connection 
//this structure can be extended if desired
struct GraphicsInfo
{
	int PointsCount;
	Point* PointsList;
	GraphicsInfo(int PtsCnt)
	{
		PointsCount = PtsCnt;
		PointsList = new Point[PointsCount];	//allocate required points
	}
	~GraphicsInfo()
	{
		delete[] PointsList;
	}
};


class UI
{

	enum DsgnMenuItem //The items of the design menu (you should add more items)
	{
		//Note: Items are ordered here as they appear in menu
		//If you want to change the menu items order, change the order here
		ITM_AND2,		//AND gate item in menu
		ITM_OR2,		//OR2 gate item in menu
		ITM_NOT,		//NOT gate item in menu
		ITM_NOR,		//NOR gate item in menu
		ITM_XOR,		//XOR gate item in menu
		ITM_XNOR,		//XNOR gate item in menu
		ITM_NAND,		//NAND gate item in menu
		ITM_SWITCH,		//SWITCH item in menu
		ITM_LED,		//LED item in menu
		ITM_CONNECT,    //Connect item in menu
		ITM_EDIT,		//EDIT item in menu
		ITM_LABEL,		//Label item in menu
		ITM_MOVE,		//Move item in menu
		ITM_DELETE,		//Delete item in menu
		ITM_COPY,		//copy item in menu
		ITM_CUT,		//cut item in menu
		ITM_PASTE,		//Paste item in menu
		ITM_SAVE,		//Save item in menu
		ITM_LOAD,		//Load item in menu
		ITM_MODULE,		//module item in menu
		ITM_SWITCH_BAR,		//switch mode  item in menu
	
		ITM_EXIT,		//Exit item
	
		ITM_DSN_CNT		//no. of design menu items ==> This should be the last line in this enum
	};


	enum SimMenuItem //The items of the simulation menu (you should add more items)
	{
		//Note: Items are ordered here as they appear in menu
		//ITM_SIM,	//Simulate menu item
		ITM_TRUTH,	//Truth table menu item
		ITM_SWITCH_BAR2,		//switch mode  item in menu
		ITM_EXIT2,		//Exit item
	
		ITM_SIM_CNT		//no. of simulation menu items ==> This should be the last line in this enum
	
	};



	MODE AppMode;		//Application Mode (design or simulation)
	
	static const int	width = 1600, height = 650,	//Window width and height
						wx = 15 , wy = 15,			//Window starting coordinates
						StatusBarHeight = 50,	//Status Bar Height
						ToolBarHeight = 80,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
						ToolItemWidth = 60;		//Width of each item in toolbar menu

	color DrawColor;		//Drawing color
	color SelectColor;		//Highlighting color
	color ConnColor;		//Connector color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Back ground color


	//This should be calculated accurately because it will be used later to create connections between gates
	//For now, we will assume that rect width = 50 and height = 50
	static const int	GATE_Width = 50,		//Gate Image default width
						GATE_Height = 50;		//Gate Image default height
protected:

	window *pWind;
	
public:
	int getTBHeight() const;
	int getSBHeight() const;
	int getWindowHeight() const;
	UI();
	int Lx, Ly;
	int getGateWidth() const;
	int getGateHeight() const;	
	// Input Functions  ---------------------------
	void GetPointClicked(int &, int &);	//Get coordinate where user clicks
	void GetLastPoint(int&, int&);
	string GetSrting();		//Returns a string entered by the user

	ActionType GetUserAction(); //Reads the user click and maps it to an action

	MODE GetAppMode();
	void SetAppMode(MODE newmode);
	// Output Functions  ---------------------------

	void ChangeTitle(string Title) const;

	void CreateDesignToolBar();	//Tool bar of the design mode
	void CreateSimulationToolBar();//Tool bar of the simulation mode
	void CreateStatusBar() const;	//Create Status bar

	void ClearStatusBar() const;		//Clears the status bar
	void ClearDrawingArea() const;	//Clears the drawing area

		
	// Draws 2-input AND gate
	void DrawAND2(const GraphicsInfo &r_GfxInfo, bool selected = false) const;

	// Draws 2-input OR gate
	void DrawOR2(const GraphicsInfo& r_GfxInfo, bool selected = false) const;

	// Draws 2-input NOR gate
	void DrawNOR(const GraphicsInfo& r_GfxInfo, bool selected = false) const;

	// Draws 2-input NAND gate
	void DrawNAND(const GraphicsInfo& r_GfxInfo, bool selected = false) const;

	// Draws 1-input NOT gate
	void DrawNOT(const GraphicsInfo& r_GfxInfo, bool selected = false) const;

	// Draws 2-input XNOR gate
	void DrawXNOR(const GraphicsInfo& r_GfxInfo, bool selected = false) const;

	// Draws 2-input XOR gate
	void DrawXOR(const GraphicsInfo& r_GfxInfo, bool selected = false) const;

	// Draws LED item
	void DrawLED(const GraphicsInfo& r_GfxInfo, bool selected, STATUS state) const;

	// Draws SWITCH item
	void DrawSWITCH(const GraphicsInfo& r_GfxInfo, bool selected, STATUS state) const;

	// Draws MODULE item
	void DrawMODULE(const GraphicsInfo& r_GfxInfo, bool selected = false) const;

	// Draws Connection
	void DrawConnection(const Point Source, const Point Destination,bool selected = false) const;
	
	void PrintMsg(string msg) const;	//Print a message on Status bar

	void DisplayLabel(Point header, string label) const;

	~UI();
};

#endif