#pragma once
#include "Type.h"
struct Functional{
	type mKey;
	short int Year;
	int mRef;
	unsigned short int mLazyCalculations;
	enum typification
	{
		STRICT,
		DYNAMIC
	} mType;
};