#include <iostream>
#include "main0.h"

int main0::main0_exe() {
	wynik = 0;
	std::setlocale(LC_ALL, "pl_PL");
	while (1) {
		system("cls");
		std::cout << "Ekran: " << wynik << std::endl;
		std::cout << "Podaj znak dzia³ania: ";
		std::cin >> op;
		if (op != 's' && op != 'S' && op != 'c' && op != 'C' && op != 'e' && op != 'E') {
			std::cout << "Podaj liczbê: ";
			std::cin >> l2;
		}
		switch (op) {
		case '+':
			dodaj();
			break;
		case '-':
			odejmij();
			break;
		case '/':
			podziel();
			break;
		case '*':
			pomnoz();
			break;
		case 's':
		case 'S':
			potega();
			break;
		case '%':
			modulo();
			break;
		case 'c':
		case 'C':
			czysc();
			break;
		case 'e':
		case 'E':
			return 0;
		}
	}
}