#include <iostream>
#include "cal.h"

int main() {
	cal k1;
	k1.wynik = 0;
	std::setlocale(LC_ALL, "pl_PL");
	while (1) {
		system("cls");
		std::cout << "Ekran: " << k1.wynik << std::endl;
		std::cout << "Podaj znak dzia³ania: ";
		std::cin >> k1.op;
		if (k1.op != 's' && k1.op != 'S' && k1.op != 'c' && k1.op != 'C' && k1.op != 'e' && k1.op != 'E') {
			std::cout << "Podaj liczbê: ";
			std::cin >> k1.l2;
		}
		switch (k1.op) {
		case '+':
			k1.dodaj();
			break;
		case '-':
			k1.odejmij();
			break;
		case '/':
			k1.podziel();
			break;
		case '*':
			k1.pomnoz();
			break;
		case 's':
		case 'S':
			k1.potega();
			break;
		case '%':
			k1.modulo();
			break;
		case 'c':
		case 'C':
			k1.czysc();
			break;
		case 'e':
		case 'E':
			return 0;
		}
	}
}