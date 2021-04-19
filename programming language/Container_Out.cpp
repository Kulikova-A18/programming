#include "Container.h"
#include <fstream>

using namespace std;

void Out(Language *lg, ofstream &ofst);
int YearsPassed(Language* lg);
bool Compare(Language* first, Language* second);

void Out(Container &c, ofstream &ofst) {
	if (&c != nullptr) {
		ofst << "Container contains that elements:" << endl;
		ofst << endl;

		Container* temp;
		temp = &c;
		int i = 0;

		do {
			ofst << i << ": ";
			Out(temp->L, ofst);
			ofst << "Number of years since the year the language was created (... - now): " << YearsPassed(temp->L) << endl;
			temp = temp->Next;
			i++;

		} while (temp != &c);
	}
	else {
		ofst << "Container is empty!" << endl;
	}
};
