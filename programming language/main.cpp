#include <iostream>
#include <fstream>
#include <string>
#include "Container.h"

using namespace std;

void Init(Container &c);
void Clear(Container *&c);
void In(Container &c, ifstream &ifst);
void Out(Container &c, ofstream &ofst);
void ProcOut(Container& c, ofstream& ofst);
void Sort(Container*& c);

int main(int argc, char* argv[]) {
	if (argc != 3) {
		cout << "incorrect command line! Waited: command in_file out_file" << endl;
		exit(1);
	}
	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);

	cout << "The Start!" << endl;
	Container *c = new Container;
	Init(*c);
	In(*c, ifst);
	Out(*c, ofst);

	//Вывод только процедуры
	ofst << "\n\nONLY PROCEDURE." << endl;
	ProcOut(*c, ofst);
	//Вывод сортированного контейнера
	cout << "The Sort!" << endl;
	ofst << "\n\nSORTED CONTAINER." << endl;	
	Sort(c);
	Out(*c, ofst);

	//Вывод только процедуры
	ofst << "\n\nONLY PROCEDURE." << endl;
	ProcOut(*c, ofst);

	//очистка
	ofst << "\n\nCLEARED CONTAINER." << endl;
	Clear(c);
	Out(*c, ofst);

	cout << "The Finish!" << endl;
	system("pause");
	return 0; 
}