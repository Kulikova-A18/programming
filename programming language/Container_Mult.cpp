#include "Container.h"
#include <fstream>

using namespace std;

void Out(Language* lg, ofstream& ofst);

void MultiMethod(Container& c, ofstream& ofst) {
	
	if (&c != nullptr) {

		ofst << endl << "Multimethod." << endl;
		Container* first;
		Container* second;
		first = &c;
		int i = 0;

		//от 0 до n-1
		while (first->Next != &c) {
			second = first->Next;

			//от first до n
			while (second != &c) {
				ofst << i << ": ";
				if (first->L == NULL || second->L == NULL) {
					ofst << "Unknown type." << endl;
				}

				else {					
					switch (first->L->mKey) {

					case type::PROCEDURAL:
						switch (second->L->mKey) {
						
						case type::PROCEDURAL:
							ofst << "Procedural and Procedural." << endl;
							break;

						case type::OBJORIENTED:
							ofst << "Procedural and OOP." << endl;
							break;

						case type::FUNCTIONAL:
							ofst << "Procedural and Functional" << endl;
							break;

						default:
							ofst << "Unknown type." << endl;
							break;
						}
						break;

					case type::OBJORIENTED:
						switch (second->L->mKey) {

						case type::PROCEDURAL:
							ofst << "OOP and Procedural." << endl;
							break;

						case type::OBJORIENTED:
							ofst << "OOP and OOP." << endl;
							break;
						
						case type::FUNCTIONAL:
							ofst << "OOP and Functional" << endl;
							break;
						
						default:
							ofst << "Unknown type." << endl;
							break;
						}
						break;
					
					case type::FUNCTIONAL:
						switch (second->L->mKey) {
						
						case type::PROCEDURAL:
							ofst << "Functional and Procedural." << endl;
							break;
						
						case type::OBJORIENTED:
							ofst << "Functional and OOP." << endl;
							break;
						
						case type::FUNCTIONAL:
							ofst << "Functional and Functional" << endl;
							break;
						
						default:
							ofst << "Unknown type." << endl;
							break;
						}
						break;
					
					default:
						ofst << "Unknown type." << endl;
						break;
					}
				}

				Out(first->L, ofst);
				ofst << endl;

				Out(second->L, ofst);
				ofst << endl;

				second = second->Next;
				i++;
			}

			first = first->Next;
		}
	}
	else {
		ofst << "Container is empty!" << endl;

	}
}