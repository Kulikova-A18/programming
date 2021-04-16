#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include "Functional.h"
#include <ctime>

using namespace std;

void Out(Functional *p, ofstream &ofst) {
	ofst << "[ FUNCTIONAL ]" << endl;
	ofst << "Lazy calculations: " << p->mLazyCalculations << endl;
	ofst << "Typification: ";
	if (p->mType == 0) {
		ofst << "strict";
	} else if (p->mType == 1) {
		ofst << "dynamic";
	}
	ofst << "Year of programming language: " << p->Year << endl;
	ofst << "Number of mentions of the language on the Internet: " << p->mRef << endl;
};
int YearsPassed(Functional* p) {
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	return (timeinfo->tm_year + 1900) - p->Year;
};