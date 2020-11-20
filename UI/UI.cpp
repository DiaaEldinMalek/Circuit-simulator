#include "UI.h"

UI::UI()
{
	AppMode = DESIGN;	//Design Mode is the startup mode

	//Initilaize interface colors
	DrawColor = BLACK;
	SelectColor = BLUE;
	ConnColor = RED;
	MsgColor = BLUE;
	BkGrndColor = WHITE;
	
	//Create the drawing window
	pWind = new window(width, height, wx, wy);	


	ChangeTitle("ABD's prototype");

	CreateDesignToolBar();	//Create the desgin toolbar
	CreateStatusBar();		//Create Status bar
}

int UI::getWindowHeight() const
{
	return height;
}

int UI::getTBHeight() const
{
	return ToolBarHeight;
}
int UI::getSBHeight() const
{
	return StatusBarHeight;
}



int UI::getGateWidth() const
{
	return GATE_Width;
}

int UI::getGateHeight() const
{
	return GATE_Height;
}


//======================================================================================//
//								Input Functions 										//
//======================================================================================//

void UI::GetPointClicked(int &x, int &y)
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
	Lx = x;
	Ly = y;
}

void UI::GetLastPoint(int& x, int& y)
{
	x = Lx;
	y = Ly;
}

MODE UI::GetAppMode() {
	return AppMode;
}

void UI::SetAppMode(MODE newmode)
{
	AppMode = newmode;
}

string UI::GetSrting()
{
	//Reads a complete string from the user until the user presses "ENTER".
	//If the user presses "ESCAPE". This function should return an empty string.
	//"BACKSPACE" is also supported
	//User should see what he is typing at the status bar


	string userInput;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);

		switch(Key)
		{
		case 27: //ESCAPE key is pressed
			PrintMsg("");
			return ""; //returns nothing as user has cancelled the input
		
		case 13:		//ENTER key is pressed
			return userInput;
		
		case 8:		//BackSpace is pressed
			if(userInput.size() > 0)
				userInput.resize(userInput.size() -1 );
			break;
		
		default:
			userInput+= Key;
		};
		
		PrintMsg(userInput);
	}

}

//This function reads the position where the user clicks to determine the desired action
ActionType UI::GetUserAction() 
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click
	Lx = x;
	Ly = y;
	if (AppMode == DESIGN)	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_AND2: return ADD_AND_GATE_2;
			case ITM_OR2: return ADD_OR2_GATE_2;
			case ITM_NOT: return ADD_INV;
			case ITM_NOR: return ADD_NOR_GATE_2;
			case ITM_XOR: return ADD_XOR_GATE_2;
			case ITM_XNOR: return ADD_XNOR_GATE_2;
			case ITM_NAND: return ADD_NAND_GATE_2;
			case ITM_SWITCH: return ADD_Switch;
			case ITM_LED: return ADD_LED;
			case ITM_CONNECT: return ADD_CONNECTION;
			case ITM_EDIT: return EDIT_Label;
			case ITM_LABEL: return ADD_Label;
			case ITM_MOVE: return MOVE;
			case ITM_DELETE: return DEL;
			case ITM_COPY: return COPY;
			case ITM_CUT: return CUT;
			case ITM_PASTE: return PASTE;
			case ITM_SAVE: return SAVE;
			case ITM_LOAD: return LOAD;
			case ITM_MODULE: return ADD_MODULE;
			case ITM_SWITCH_BAR: return SIM_MODE;
			case ITM_EXIT: return EXIT_THIS;

			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= ToolBarHeight && y < height - StatusBarHeight)
		{
			return SELECT_THIS;	//user want to select/unselect a statement in the flowchart
		}

		//[3] User clicks on the status bar
		return STATUS_BAR;
	}
	else	//Application is in Simulation mode
	{
		if (y >= 0 && y < ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{/*
			case ITM_SIM: return SIM;*/
			case ITM_TRUTH: return TRUTH;
			case ITM_SWITCH_BAR2: return DSN_MODE;

			case ITM_EXIT2: return EXIT_THIS;

			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		}
		//[2] User clicks on the drawing area
		if (y >= ToolBarHeight && y < height - StatusBarHeight)
		{
			return SIM;	//user want to turn on/off the switch
		}
	}
}



//======================================================================================//
//								Output Functions										//
//======================================================================================//

//////////////////////////////////////////////////////////////////////////////////
void UI::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void UI::CreateStatusBar() const
{
	pWind->SetPen(BROWN,3);
	pWind->DrawLine(0, height-StatusBarHeight, width, height-StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////
void UI::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = StatusBarHeight - 10;

	// Print the Message
    pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial"); 
	pWind->SetPen(MsgColor); 
	pWind->DrawString(MsgX, height - MsgY, msg);
}
//////////////////////////////////////////////////////////////////////////////////
void UI::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(BkGrndColor);
	pWind->SetBrush(BkGrndColor);
	pWind->DrawRectangle(MsgX, height - MsgY, width, height);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (degin) area
void UI::ClearDrawingArea() const
{
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, ToolBarHeight, width, height - StatusBarHeight);
	
}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode
void UI::CreateDesignToolBar() 
{
	AppMode = DESIGN;	//Design Mode

	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item
	string MenuItemImages[ITM_DSN_CNT];
	MenuItemImages[ITM_AND2] = "images\\Menu\\MENU_AND2.jpg";
	MenuItemImages[ITM_OR2]  = "images\\Menu\\MENU_OR2.jpg";
	MenuItemImages[ITM_NOT] = "images\\Menu\\MENU_NOT.jpg";
	MenuItemImages[ITM_NOR] = "images\\Menu\\MENU_NOR.jpg";
	MenuItemImages[ITM_XOR] = "images\\Menu\\MENU_XOR.jpg";
	MenuItemImages[ITM_NAND] = "images\\Menu\\MENU_NAND.jpg";
	MenuItemImages[ITM_XNOR] = "images\\Menu\\MENU_XNOR.jpg";
	MenuItemImages[ITM_SWITCH] = "images\\Menu\\MENU_SWITCH.jpg";
	MenuItemImages[ITM_LED] = "images\\Menu\\MENU_LED.jpg";
	MenuItemImages[ITM_CONNECT] = "images\\Menu\\MENU_CONNECT.jpg";
	MenuItemImages[ITM_EDIT] = "images\\Menu\\MENU_EDIT.jpg";
	MenuItemImages[ITM_LABEL] = "images\\Menu\\MENU_LABEL.jpg";
	MenuItemImages[ITM_MOVE] = "images\\Menu\\MENU_MOVE.jpg";
	MenuItemImages[ITM_DELETE] = "images\\Menu\\MENU_DELETE.jpg";
	MenuItemImages[ITM_COPY] = "images\\Menu\\MENU_COPY.jpg";
	MenuItemImages[ITM_CUT] = "images\\Menu\\MENU_CUT.jpg";
	MenuItemImages[ITM_PASTE] = "images\\Menu\\MENU_PASTE.jpg";
	MenuItemImages[ITM_SAVE] = "images\\Menu\\MENU_SAVE.jpg";
	MenuItemImages[ITM_LOAD] = "images\\Menu\\MENU_LOAD.jpg";
	MenuItemImages[ITM_MODULE] = "images\\Menu\\MENU_MODULE.jpg";
	MenuItemImages[ITM_SWITCH_BAR] = "images\\Menu\\MENU_SWITCH_BAR.jpg";
	MenuItemImages[ITM_EXIT] = "images\\Menu\\MENU_EXIT.jpg";

	pWind->DrawRectangle(0, 0, 1600, 80);
	//Draw menu item one image at a time
	for(int i=0; i<ITM_DSN_CNT; i++)
		pWind->DrawImage(MenuItemImages[i],i*ToolItemWidth,0,ToolItemWidth, ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(BROWN,3);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void UI::CreateSimulationToolBar()
{
	AppMode = SIMULATION;	//Simulation Mode

	string MenuItemImages[ITM_SIM_CNT];/*
	MenuItemImages[ITM_SIM] = "images\\Menu\\MENU_SIM.jpg";*/
	MenuItemImages[ITM_TRUTH] = "images\\Menu\\MENU_TRUTH.jpg";
	MenuItemImages[ITM_SWITCH_BAR2] = "images\\Menu\\MENU_SWITCH_BAR2.jpg";
	MenuItemImages[ITM_EXIT2] = "images\\Menu\\MENU_EXIT2.jpg";

	pWind->DrawRectangle(0, 0, 1600, 80);
	//Draw menu item one image at a time
	for (int i = 0; i < ITM_SIM_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * ToolItemWidth, 0, ToolItemWidth, ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(BROWN, 3);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);



}

//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//

void UI::DrawAND2(const GraphicsInfo &r_GfxInfo, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Gates\\GATE_AND2_HI.jpg";
	else  
		GateImage = "Images\\Gates\\GATE_AND2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, GATE_Width, GATE_Height);
}
void UI::DrawOR2(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\GATE_OR2_HI.jpg";
	else
		GateImage = "Images\\Gates\\GATE_OR2.jpg";

	//Draw OR2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by OR2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, GATE_Width, GATE_Height);
}

void UI::DrawNOR(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\GATE_NOR_Hi.jpg";
	else
		GateImage = "Images\\Gates\\GATE_NOR.jpg";

	//Draw NOR Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by NOR Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, GATE_Width, GATE_Height);
}

void UI::DrawNAND(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\GATE_NAND_Hi.jpg";
	else
		GateImage = "Images\\Gates\\GATE_NAND.jpg";

	//Draw NAND Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by NAND Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, GATE_Width, GATE_Height);
}

void UI::DrawNOT(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\GATE_NOT_Hi.jpg";
	else
		GateImage = "Images\\Gates\\GATE_NOT.jpg";

	//Draw NOT Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by NOT Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, GATE_Width, GATE_Height);
}

void UI::DrawXNOR(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\GATE_XNOR_Hi.jpg";
	else
		GateImage = "Images\\Gates\\GATE_XNOR.jpg";

	//Draw XNOR Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by XNOR Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, GATE_Width, GATE_Height);
}

void UI::DrawXOR(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\GATE_XOR_Hi.jpg";
	else
		GateImage = "Images\\Gates\\GATE_XOR.jpg";

	//Draw XOR Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by XOR Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, GATE_Width, GATE_Height);
}
void UI::DrawSWITCH(const GraphicsInfo& r_GfxInfo, bool selected, STATUS state) const
{
	string GateImage;
	if (state && selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\SWITCH_CLOSED_Hi.jpg";
	else if (selected)
		GateImage = "Images\\Gates\\SWITCH_OPEN_Hi.jpg";
	else if (state)
		GateImage = "Images\\Gates\\SWITCH_CLOSED.jpg";
	else
		GateImage = "Images\\Gates\\SWITCH_OPEN.jpg";

	//Draw Switch item at Gfx_Info (1st corner)
	//Set the Image Width & Height by XOR Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, GATE_Width, GATE_Height);
}
void UI::DrawLED(const GraphicsInfo& r_GfxInfo, bool selected, STATUS state) const
{
	string GateImage;
	if (state && selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\LED_ON_Hi.jpg";
	else if (selected)
		GateImage = "Images\\Gates\\LED_OFF_Hi.jpg";
	else if (state)
		GateImage = "Images\\Gates\\LED_ON.jpg";
	else
		GateImage = "Images\\Gates\\LED_OFF.jpg";

	//Draw LED item at Gfx_Info (1st corner)
	//Set the Image Width & Height by XOR Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, GATE_Width, GATE_Height);
}
void UI::DrawMODULE(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\GATE_MODULE_HI.jpg";
	else
		GateImage = "Images\\Gates\\GATE_MODULE.jpg";

	//Draw module item at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, GATE_Width, GATE_Height);
}


void UI::DrawConnection(const Point S, const Point D, bool selected) const
{
	int x1 = S.x;
	int x2 = D.x;
	int y1 = S.y;
	int y2 = D.y;
	if (selected)
		pWind->SetPen(BLACK, 1);
	else
		pWind->SetPen(RED, 1);
	if (abs (y2 - y1) < GATE_Height)
	{
		if (x1 < x2)
		{
			pWind->DrawLine(x1, y1, x1 + 15, y1);
			pWind->DrawLine(x1 + 15, y1, x1 + 15, y2);
			pWind->DrawLine(x1 + 15, y2, x2, y2);
		}
		else
		{
			int n = 1;
			if (y2 > y1)
				n = -1;
			pWind->DrawLine(x1, y1, x1 + GATE_Width / 2, y1);
			pWind->DrawLine(x1 + GATE_Width / 2, y1, x1 + GATE_Width / 2, y1 + n * GATE_Height);
			pWind->DrawLine(x1 + GATE_Width / 2, y1 + n * GATE_Height, x2 - GATE_Width / 2, y1 + n * GATE_Height);
			pWind->DrawLine(x2 - GATE_Width / 2, y1 + n * GATE_Height, x2 - GATE_Width / 2, y2);
			pWind->DrawLine(x2 - GATE_Width / 2, y2, x2, y2);
		}
		return;
	}

	pWind->DrawLine(x1, y1, x1 + GATE_Width/2, y1);
	pWind->DrawLine(x1 + GATE_Width / 2, y1, x1 + GATE_Width / 2, (y2 + y1) / 2);
	pWind->DrawLine(x1 + GATE_Width / 2, (y2 + y1) / 2, x2 - GATE_Width / 2, (y2 + y1) / 2);
	pWind->DrawLine(x2 - GATE_Width / 2, (y2 + y1) / 2, x2 - GATE_Width / 2, y2);
	pWind->DrawLine(x2 - GATE_Width / 2, y2, x2, y2);

	//pWind->DrawLine(S.x, S.y, D.x, D.y);
}

void UI::DisplayLabel(Point header, string label) const
{
	if (header.y > height - StatusBarHeight-20)
		header.y = header.y - 1.6*GATE_Height;
	pWind->DrawString(header.x, header.y, label);
}



UI::~UI()
{
	delete pWind;
	pWind = NULL;
}