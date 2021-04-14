#include <fstream>
#include "ObjectOriented.h"
using namespace std;
void Out(ObjectOriented *o, ofstream &ofst){
	ofst << "Object-Oriented." << endl;
	ofst << "Inheritance: ";
	if (o->mInher == 0){
		ofst << "single";
	}
	else if (o->mInher == 1){
		ofst << "multiple";
	}
	else {
		ofst << "interface";
	}
	ofst << endl;
	ofst << "Year of programming language:" << o->Year << endl;
	ofst << endl;
};