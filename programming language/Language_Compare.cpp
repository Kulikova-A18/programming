#include "Language.h"

int YearsPassed(Language* lg);

bool Compare(Language* first, Language* second) {
	return YearsPassed(first) < YearsPassed(second);
};