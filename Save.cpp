#include <iostream>
#include <fstream>
using namespace.std;
void Save() {
	ofstream myfile;
	myfile.open("ABD.txt");
	myfile << CompCount << endl;
	for (int i = 0; i < MaxCompCount; i++) {
		myfile << CompList[i]->GetName() << "		" << i << "		" << CompList[i]->GetLabel() << "	" << CompList[i]->m_pGfxInfo->PointsList[0].x << "		" << CompList[i]->m_pGfxInfo->PointsList[0].y << endl;

	}
	myfile.close();
}