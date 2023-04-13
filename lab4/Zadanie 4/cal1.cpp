#include "cal1.h"
#include <cmath>

void cal1::dodaj(double l2, double* wynik) {
	*wynik += l2;
}

void cal1::odejmij(double l2, double* wynik) {
	*wynik -= l2;
}

void cal1::podziel(double l2, double* wynik) {
	*wynik /= l2;
}

void cal1::pomnoz(double l2, double* wynik) {
	*wynik *= l2;
}

void cal1::potega(double* wynik) {
	*wynik *= *wynik;
}

void cal1::modulo(double l2, double* wynik) {
	*wynik = fmod(*wynik, l2);
}

void cal1::czysc(double* wynik) {
	*wynik = 0;
}
