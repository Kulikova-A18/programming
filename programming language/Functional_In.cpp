#include <fstream>
#include "Functional.h"
using namespace std;

Functional* InFunc(ifstream& ifst) {
	Functional* f;
	f = new Functional;
	f->mKey = type::FUNCTIONAL;
	int inh;
	ifst >> inh;
	if (inh == 1 || inh == 0) {
		f->mLazyCalculations = inh;
	}
	else {
		char b;
		ifst >> b;
		while (!ifst.eof() && ifst.peek() != '\n') {
			ifst >> b;
		}
		return NULL;
	}
	ifst >> inh;
	if (inh == 0) {
		f->mType = Functional::STRICT;
	}
	else if (inh == 1) {
		f->mType = Functional::DYNAMIC;
	}
	else {
		char b;
		ifst >> b;
		while (!ifst.eof() && ifst.peek() != '\n') {
			ifst >> b;
		}
		return NULL;
	}
	ifst >> f->Year;
	ifst >> f->mRef;
	return f;
}