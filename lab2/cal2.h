#pragma once
#include "cal.h"

class cal2 :public cal
{
public:
	double pamiec;
	bool jestm;
	cal2(double wynik, double pamiec, bool jestm);
};
