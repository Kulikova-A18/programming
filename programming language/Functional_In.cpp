#include <fstream>
#include "Functional.h"
#include <vector>

using namespace std;

Functional* InFunc(ifstream& ifst) {
	Functional* f;
	f = new Functional;
	f->mKey = type::FUNCTIONAL;
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

	if (tail.size() == 4 && flag) {
		if (tail[0] == 0 || tail[0] == 1) {
			f->mLazyCalculations = tail[0];
			if (tail[1] == 0 || tail[1] == 1) {
				f->mType = static_cast<Functional::typification>(tail[1]);
				f->Year = tail[2];
				f->mRef = tail[3];
				return f;
			}
			else
				return NULL;
		}
		else {
			return NULL;
		}
	}
	else {
		return NULL;
	}
}