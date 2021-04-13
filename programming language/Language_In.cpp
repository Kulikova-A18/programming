//#pragma once
#include <fstream>
#include "Language.h"
using namespace std;
ObjectOriented* InOO(ifstream &ifst);
Procedural * InProc(ifstream &ifst);
Language * In(int key, ifstream &ifst){
	int inh;
	switch (key){
	case 1:
		return (Language *)InProc(ifst);
	case 2:
		return (Language *)InOO(ifst);
	default:
		char b;
		ifst >> b;
		while (!ifst.eof() && ifst.peek() != '\n'){
			ifst >> b;
		}
		return NULL;
	}
};
Language* In(ifstream &ifst) {
	Language *lg;
	int k;
	ifst >> k;
	lg = In(k, ifst);
	return lg;
};
