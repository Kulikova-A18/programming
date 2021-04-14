#include "Container.h"
#include <fstream>
using namespace std;
Language* In(ifstream &ifst);
void In(Container &c, ifstream &ifst){
	while (!ifst.eof()){
		Container *temp = new Container;
		if ((&c == c.Next)&&(!ifst.tellg())){
			c.L = In(ifst);
		}
		else{		
			//идем на последний элемент
			Container *counter = c.Next;
			while(counter->Next != &c){
				counter = counter->Next;
			}
			counter->Next = temp;
			temp->L = In(ifst);
			temp->Next = &c;
		}
	}
};