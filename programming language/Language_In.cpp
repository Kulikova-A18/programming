#include <fstream>
#include "Language.h"

using namespace std;

ObjectOriented* InOO(ifstream& ifst);
Procedural* InProc(ifstream& ifst);
Functional* InFunc(ifstream& ifst);

Language* In(int key, ifstream& ifst) {
	int inh;
	switch (key) {

	case 1:
		return (Language*)InProc(ifst);

	case 2:
		return (Language*)InOO(ifst);

	case 3:
		return (Language*)InFunc(ifst);

	default:
		char b;
		ifst >> b;
		while (!ifst.eof() && ifst.peek() != '\n') {
			ifst >> b;
		}
		return NULL;
	}
};

Language* In(ifstream& ifst) {
	Language* lg;
	int k;
	ifst >> k;
	if (ifst.fail()) {

		//Восстановили поток
		ifst.clear();
		ifst.ignore(numeric_limits<streamsize>::max(), '\n');
		return NULL;
	}
	lg = In(k, ifst);
	return lg;
};
