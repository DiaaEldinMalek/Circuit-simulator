#include <iostream>
#include <fstream>

void Load() {
	int CompCount;
	string CompType;
	string label;
	double id;
	double x;
	double y;

	ifstream myfile("ABD.txt");
	myfile >> CompCount;
	while (myfile >> CompType >> id >> label >> x >> y)
	{
		if(CompType.compare("AND2")==0){
			Action loadAction = new AddANDgate2(this);
			loadAction->load(x, y);
		else if(CompType.compare("NAND") == 0) {
			Action loadAction = new AddNANDgate2(this);
			loadAction->load(x, y);
		else if (CompType.compare("NOR") == 0) {
			Action loadAction = new AddNORgate(this);
			loadAction->load(x, y);
		else if (CompType.compare("NOT") == 0) {
			Action loadAction = new AddNOTgate(this);
			loadAction->load(x, y);
		else if (CompType.compare("OR2") == 0) {
			Action loadAction = new AddORgate2(this);
			loadAction->load(x, y);
		else if (CompType.compare("XNOR") == 0) {
			Action loadAction = new AddXNORgate2(this);
			loadAction->load(x, y);
		else if (CompType.compare("XOR") == 0) {
			Action loadAction = new AddXORgate2(this);
			loadAction->load(x, y);
		else if (CompType.compare("LED") == 0) {
			Action loadAction = new AddLED(this);
			loadAction->load(x, y);
		else if (CompType.compare("SWITCH") == 0) {
			Action loadAction = new AddSWITCH(this);
			loadAction->load(x, y);
	}
}