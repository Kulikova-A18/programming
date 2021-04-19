#include <fstream>
#include "Procedural.h"
#include <vector>

using namespace std;

Procedural * InProc(ifstream &ifst) {
	Procedural * p;
	p = new Procedural;
	p->mKey = type::PROCEDURAL;

	int inh;
	bool flag = true;
	vector<int> tail;

	do {
		ifst >> inh;
		if (ifst.fail()) {
			//Восстановили поток
			ifst.clear();
			ifst.ignore(numeric_limits<streamsize>::max(), '\n');
			flag = false;
			break;
		}
		if (inh >= 0) {
			tail.push_back(inh);
		}
	} while (!ifst.eof() && ifst.peek() != '\n');

	if (tail.size() == 3 && flag) {
		if (tail[0] == 1 || tail[0] == 0) {
			p->mAbstractDT = inh;
			p->Year = tail[1];
			p->mRef = tail[2];
			return p;
		} else {
			return NULL;
		}
	} else {
		return NULL;
	}
}
