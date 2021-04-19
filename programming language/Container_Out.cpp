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

void Sort(Container*& c) {
	//if container contains 1 element, do nothing
	if (c == c->Next) {
		return;
	}
	Container* current = c;

	bool flag = false;
	Language* temp;
	//buble sort
	do {
		current = c;
		//if we didnt swap elements container is sorted
		flag = false;
		do {
			if (Compare(current->L, current->Next->L)) {
				temp = current->L;
				current->L = current->Next->L;
				current->Next->L = temp;
				flag = true;
			}
			current = current->Next;
		} while (current->Next != c);
	} while (flag);
};

void ProcOut(Container& c, ofstream& ofst) {
	if (&c != nullptr) {
		ofst << "Container contains that elements:" << endl;
		ofst << endl;
		Container* temp2;
		temp2 = &c;
		int i = 0;
		do {
			ofst << i << ": ";
			if (temp2->L != NULL && temp2->L->mKey == type::PROCEDURAL) {
				Out(temp2->L, ofst);
				ofst << "Number of years since the year the language was created (... - now): " << YearsPassed(temp2->L) << endl;
			}
			else {
				ofst << endl;
			}
			temp2 = temp2->Next;
			i++;
		} while (temp2 != &c);
	}
	else {
		ofst << "Container is empty!" << endl;
	}
}