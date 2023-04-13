#pragma once
#include <string>
#include <vector>

class kalkulator
{
public:
	std::string dzialanie;
	std::string liczba;
	std::vector <double> dane;
	std::vector <char> znaki;
	int n = 0;
	double wynik;
	virtual std::string return_dzialanie() { return dzialanie; }
	virtual void return_wynik(double x) { wynik = x; }
	void deszyfr();
	void licz();
	void dodaj(int x);
	void odejmij(int x);
	void podziel(int x);
	void pomnoz(int x);
	void potega(int x);
	void modulo(int x);
	void procent(int x);
	void pierwiastek(int x);
	virtual ~kalkulator() {}
};
