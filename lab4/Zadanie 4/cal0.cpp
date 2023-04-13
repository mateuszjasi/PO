#include "cal0.h"
#include <cmath>

void cal::dodaj() {
	wynik += l2;
}

void cal::odejmij() {
	wynik -= l2;
}

void cal::podziel() {
	wynik /= l2;
}

void cal::pomnoz() {
	wynik *= l2;
}

void cal::potega() {
	wynik *= wynik;
}

void cal::modulo() {
	wynik = fmod(wynik, l2);
}

void cal::czysc() {
	wynik = 0;
}