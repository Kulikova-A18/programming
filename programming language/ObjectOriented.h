#pragma once
#include "Type.h"
struct ObjectOriented{
	type mKey;
	enum inheritance {
		SINGLE,
		MULTIPLE,
		INTERFACE
	};
	inheritance mInher;
	short int Year;
};