#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include "ObjectOriented.h"
#include <ctime>

using namespace std;

void Out(ObjectOriented *o, ofstream &ofst) {
	ofst << "[ OBJECT-ORIENTED ]" << endl;
	ofst << "Inheritance: ";
	if (o->mInher == 0) {
		ofst << "single";
	} else if (o->mInher == 1) {
		ofst << "multiple";
	} else {
		ofst << "interface";
	}
	ofst << endl;
	ofst << "Year of programming language: " << o->Year << endl;
	ofst << "Number of mentions of the language on the Internet: " << o->mRef << endl;
};

int YearsPassed(ObjectOriented* o) {
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	return (timeinfo->tm_year + 1900) - o->Year;
};