#include <iostream>
#include <fstream>
#include <string>
#include "Container.h"
using namespace std;
void Init(Container &c);
void Clear(Container *&c);
void In(Container &c, ifstream &ifst);
void Out(Container &c, ofstream &ofst);
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
	Clear(c);
	Out(*c, ofst);
	cout << "The Finish!" << endl;
	system("pause");
	return 0; 
}