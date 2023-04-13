#pragma once
#include <string>

class cal {
public:
	double wynik, temp;
	std::string dane;
	char swit;
	cal(double wynik);
	void dodaj(double l2, double* wynik);
	void odejmij(double l2, double* wynik);
	void podziel(double l2, double* wynik);
	void pomnoz(double l2, double* wynik);
	void potega(double* wynik);
	void modulo(double l2, double* wynik);
	void czysc(double* wynik);
};
