#pragma once
#include <string>

class cal1 {
public:
	double wynik, temp;
	char swit;
	std::string dane;
	void dodaj(double l2, double* wynik);
	void odejmij(double l2, double* wynik);
	void podziel(double l2, double* wynik);
	void pomnoz(double l2, double* wynik);
	void potega(double* wynik);
	void modulo(double l2, double* wynik);
	void czysc(double* wynik);
};
