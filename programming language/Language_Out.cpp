#include <fstream>
#include "Language.h"
using namespace std;
void Out(Procedural *p, ofstream &ofst);
void Out(ObjectOriented *o, ofstream &ofst);
void Out(Language *lg, ofstream &ofst){
	if (lg == NULL){
		ofst << "Incorrect type of language!" << endl;
		ofst << endl;
	}
	else{
		switch (lg->mKey) {
		case type::PROCEDURAL:
			Out((Procedural *)(lg), ofst);
			break;
		case type::OBJORIENTED:
			Out((ObjectOriented *)lg, ofst);
			break;
		}
	}
};