#include "cal.h"
#include <cmath>

cal::cal(double wynik)
	:wynik(wynik)
{
}


void cal::dodaj(double l2, double* wynik) {
	*wynik += l2;
}

void cal::odejmij(double l2, double* wynik) {
	*wynik -= l2;
}

void cal::podziel(double l2, double* wynik) {
	*wynik /= l2;
}

void cal::pomnoz(double l2, double* wynik) {
	*wynik *= l2;
}

void cal::potega(double* wynik) {
	*wynik *= *wynik;
}

void cal::modulo(double l2, double* wynik) {
	*wynik = fmod(*wynik, l2);
}

void cal::czysc(double* wynik) {
	*wynik = 0;
}
