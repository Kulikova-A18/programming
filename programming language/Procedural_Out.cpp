#include <fstream>
#include "Procedural.h"
using namespace std;
void Out(Procedural *p, ofstream &ofst) {
	ofst << "Procedural." << endl;
	ofst << "Abstrat data type = " << p->mAbstractDT << endl;
	ofst << "Year of programming language:" << p->Year << endl;
	ofst << endl;
};