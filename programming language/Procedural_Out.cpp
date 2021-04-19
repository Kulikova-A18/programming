#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include "Procedural.h"
#include <ctime>

using namespace std;

void Out(Procedural *p, ofstream &ofst) {
	ofst << "Procedural." << endl;
	ofst << "Abstrat data type: " << p->mAbstractDT << endl;
	ofst << "Year of programming language: " << p->Year << endl;
	ofst << "Number of mentions of the language on the Internet: " << p->mRef << endl;
	//ofst << endl;
};

int YearsPassed(Procedural* p) {
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	return (timeinfo->tm_year + 1900) - p->Year;
};