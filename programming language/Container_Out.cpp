#include "Container.h"
#include <fstream>

using namespace std;

void Out(Language *lg, ofstream &ofst);
void ProcOut(Language* lg, ofstream& ofst);
int YearsPassed(Language* lg);
bool Compare(Language* first, Language* second);

void Sort(Container*& c) {
	//если контейнер содержит 1 элемент, ничего не делать
	if (c == c->Next) {

		return;
	}
	Container* current = c;
	bool flag = false;
	Language* temp;
	//Сортировка пузырьком
	do {
		current = c;
		//если бы мы не отсортировали контейнер со сменными элементами
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

void Out(Container &c, ofstream &ofst) {
	if (&c != nullptr) {
		ofst << "CONTAINER CONTAINS THAT ELEMENTS:" << endl;
		Container* temp, * temp2;
		temp = &c;
		temp2 = &c;
		int i = 0;
		ofst << i << ": ";
		do {
			Out(temp->L, ofst);
			ofst << "Number of years since the year the language was created (... - now): " 
				<< YearsPassed(temp->L) << endl;
			temp = temp->Next;
			i++;
			ofst << endl;
		} while (temp != &c);
	}
	else {
		ofst << "CONTAINER IS EMPTY!" << endl;
	}
};

void ProcOut(Container& c, ofstream& ofst) {	
	if (&c != nullptr) {
		ofst << "CONTAINER CONTAINS THAT ELEMENTS:" << endl;
		Container* temp2;
		temp2 = &c;
		int i = 0;
		do {
			if (temp2->L != NULL && temp2->L->mKey == type::PROCEDURAL) {
				ofst << i << ": ";
				Out(temp2->L, ofst);
				
				ofst << "Number of years since the year the language was created (... - now): " 
					<< YearsPassed(temp2->L) << endl;
				ofst << endl;

			}
			else {
				ofst << endl;
			}
			temp2 = temp2->Next;
			i++;
		} while (temp2 != &c);
	}
	else {
		ofst << "CONTAINER IS EMPTY!" << endl;
	}
};