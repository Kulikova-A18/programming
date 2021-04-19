#include <fstream>
#include "Procedural.h"

using namespace std;

Procedural * InProc(ifstream &ifst) {

	Procedural * p;
	p = new Procedural;
	p->mKey = type::PROCEDURAL;
	int inh;
	ifst >> inh;

	if (inh == 1 || inh == 0) {
		p->mAbstractDT = inh;
		ifst >> p->Year;
		ifst >> p->mRef;
		return p;
	}
	else {
		char b;
		ifst >> b;
		while (!ifst.eof() && ifst.peek() != '\n') {
			ifst >> b;
		}
		return NULL;
	}
}
