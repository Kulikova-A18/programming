#include <fstream>
#include "ObjectOriented.h"
#include <vector>

using namespace std;

ObjectOriented * InOO(ifstream &ifst) {
	ObjectOriented * o;
	o = new ObjectOriented;
	o->mKey = type::OBJORIENTED;
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
		if (tail[0] == 0 || tail[0] == 1 || tail[0] == 2) {
			o->mInher = static_cast<ObjectOriented::inheritance>(tail[0]);
			o->Year = tail[1];
			o->mRef = tail[2];
			return o;
		} else {
			return NULL;
		}
	} else {
		return NULL;
	}
}
