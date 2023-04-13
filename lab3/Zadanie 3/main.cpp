#include <iostream>
#include <string>
#include "kalkulator.h"

int main()
{
	std::string dzialanie;
	std::cout << "Podaj dzialanie: ";
	//zeby podac liczbe ujemna nalezy wpisac ja ze znakiem '-' bezposredniu po znaku dzialania np 2*-2 = -4 lub 2--2 = 4
	std::cin >> dzialanie;
	kalkulator cal(dzialanie);
	std::cout << "Wynik = " << cal.wynik;
}
