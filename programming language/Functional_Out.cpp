#include <fstream>
#include "Functional.h"
using namespace std;

void Out(Functional *p, ofstream &ofst) {
	ofst << "Functional." << endl;
	ofst << "Lazy calculations: " << p->mLazyCalculations << endl;
	ofst << "Typification: ";
	if (p->mType == 0){
		ofst << "strict";
	}
	else if (p->mType == 1){
		ofst << "dynamic";
	}
	ofst << endl;
	ofst << "Year of programming language: " << p->Year << endl;
	ofst << endl;
};