#include <fstream>
#include "Language.h"
using namespace std;

void Out(Procedural* p, ofstream& ofst);
void Out(ObjectOriented* o, ofstream& ofst);
int YearsPassed(ObjectOriented* o);
int YearsPassed(Procedural* o);
int YearsPassed(Functional* o);

void Out(Functional* p, ofstream& ofst);
void Out(Language* lg, ofstream& ofst)
{
	if (lg == NULL)
	{
		ofst << "Incorrect type of language!" << endl;
	}
	else
	{
		switch (lg->mKey) {
		case type::PROCEDURAL:
			Out((Procedural*)(lg), ofst);
			break;
		case type::OBJORIENTED:
			Out((ObjectOriented*)lg, ofst);
			break;
		case type::FUNCTIONAL:
			Out((Functional*)lg, ofst);
			break;
		}
	}
};
int YearsPassed(Language* lg)
{
	if (lg != NULL)
	{
		switch (lg->mKey) {
		case type::PROCEDURAL:
			return YearsPassed((Procedural*)(lg));
			break;

		case type::OBJORIENTED:
			return YearsPassed((ObjectOriented*)lg);
			break;

		case type::FUNCTIONAL:
			return YearsPassed((Functional*)lg);
			break;
		}
	}
	else
	{
		return NULL;
	}

};
