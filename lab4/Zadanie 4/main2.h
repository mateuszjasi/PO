#pragma once
#include "cal2.h"

class main2 : public kalkulator
{
public:
	std::string dzialanie;
	std::string return_dzialanie() { return dzialanie; }
	void return_wynik(double x) { wynik = x; }
	int main2_exe();
};
