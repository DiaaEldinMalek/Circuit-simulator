#ifndef CONST_H
#define CONST_H

//This header file contains some defenitions to be used all over the application

//All possible actions
enum ActionType 
{
	ADD_Buff,			//Add 1-input Buffer gate
	ADD_INV,			//Add 1-input Inverter gate
	ADD_AND_GATE_2,		//Add 2-input AND gate
	ADD_OR2_GATE_2,		//Add 2-input OR gate
	ADD_NAND_GATE_2,	//Add 2-input NAND gate
	ADD_NOR_GATE_2,		//Add 2-input NOR gate
	ADD_XOR_GATE_2,		//Add 2-input XOR gate
	ADD_XNOR_GATE_2,	//Add 2-input XNOR gate
	ADD_Switch,			//Add Switch
	ADD_LED,			//Add LED
	ADD_CONNECTION,		//Add Wire Connection
	ADD_MODULE,		//Add MODULE gate

	ADD_Label,			//Add Label to a Component, a Connection
	EDIT_Label,			//Edit Label of a Component, a Connection

	Change_Switch,		//Change Switch Status in Simulation Mode

	SELECT_THIS,		//Select a Component, a Connection
	DEL,		//Delete a Component, a Connection
	MOVE,		//Move a Component, a Connection

    COPY,		//copy a Component, a Connection
	CUT,		//CUT a Component, a Connection
	PASTE,		//PASTE a Component, a Connection
	
	SIM,        //simulation action
	TRUTH,      // truth table of the whole circuit

	SAVE,		//Save the whole Circuit to a file
	LOAD,		//Load a Circuit from a file

	UNDO,		//Undo the last Action preformed
	REDO,		//Redo the last Action canceled

	DSN_MODE,	//Switch to Design mode
	SIM_MODE,	//Switch to Simulatiom mode



	EXIT_THIS,		//Exit the application

	STATUS_BAR,		//A click on the status bar
	DSN_TOOL,	//A click on an empty place in the design tool bar

};

enum InputPinIndex
{
	ModOne, //Module input pin #1
	ModTwo, // ................ #2
	ModThree, // ................ #3
	ModFour, // ................ #4
	ModFive, // ................ #5
	Cup, //Normal Component upper input pin 
	Cmid, //LED/Inverter input pin
	Cdown // lower input pin
};

//Possible Status for the pin
enum STATUS
{
	LOW,
	HIGH,
	NCON	//not connected
};

enum  MODE	//Modes of operation
{
	DESIGN,
	SIMULATION
};

//Maximum number of input pins that can be connected to any output pin
#define MAX_CONNS 20

//assume fan out is 5 for now it can be read from the user or can be predefined as const
enum FANOUT
{
	AND2_FANOUT = 5,	//Default fan out of 2-input AND gate
	OR2_FANOUT = 5,	//Default fan out of 2-input OR gate
	NOT_FANOUT = 5,	//Default fan out of INVERTER gate
	NOR_FANOUT = 5,	//Default fan out of 2-input NOR gate
	XNOR_FANOUT = 5,	//Default fan out of 2-input XNOR gate
	NAND_FANOUT = 5,	//Default fan out of 2-input NAND gate
	XOR_FANOUT = 5,	//Default fan out of 2-input XOR gate
	SWITCH_FANOUT = 5,	//Default fan out of SWITCH
	LED_FANOUT = 5,	//Default fan out of LED
	MODULE_FANOUT = 5,	//Default fan out of MODULE
};


#ifndef NULL
#define NULL 0
#endif

#endif