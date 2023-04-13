#include <iostream>
#include "cal2.h"

int main()
{
	cal2 k1(0,0,0);
	std::setlocale(LC_ALL, "pl_PL");
	while (1) {
		k1.swit = ' ';
		while(1)
		{
			system("cls");
			std::cout << "Ekran: " << k1.wynik << " " << k1.swit << std::endl
				<< "Wartosc w pamieci: " << k1.pamiec << std::endl
				<< "Dostepne operacje:\n+ dodawanie\n- odejmowanie\n/ dzielenie\n* mnozenie\n% reszta z dzielenia\nS podniesienie do kwadratu\nC czyszczenie ekranu\nE wyjscie z programu\n"
				<< "M wykonanie jednej z wyzszych operacji na pamieci\nR wywolanie wyniku z pamieci (tylko w trybie operacji na pamieci)\n\n";
			if (k1.jestm == 1)
				std::cout << "Przeprowadzisz operacje na pamieci kliknij \"M\", aby anulowac\n";
			std::cout << "Wprowdz dane: ";
			std::cin >> k1.dane;
			if(k1.dane == "M" || k1.dane == "m")
				(k1.jestm == 0) ? k1.jestm = 1 : k1.jestm = 0;
			else if (k1.dane == "+" || k1.dane == "-" || k1.dane == "/" || k1.dane == "*" || k1.dane == "s" || k1.dane == "S" || k1.dane == "%" || k1.dane == "c" || k1.dane == "C" || k1.dane == "E"
				|| k1.dane == "e" || (k1.dane == "R" || k1.dane == "r" && k1.jestm == 1))
			{
				k1.swit = k1.dane[0];
				break;
			}
			else
				k1.wynik = std::stod(k1.dane);
		}
		while(k1.swit != 's' && k1.swit != 'S' && k1.swit != 'c' && k1.swit != 'C' && k1.swit != 'E' && k1.swit != 'e' && k1.jestm == 0)
		{
			system("cls");
			std::cout << "Ekran: " << k1.wynik << " " << k1.swit << std::endl;
			std::cout << "Podaj wartosc lub zmien operacje: ";
			std::cin >> k1.dane;
			if (k1.dane == "+" || k1.dane == "-" || k1.dane == "/" || k1.dane == "*" || k1.dane == "%")
				k1.swit = k1.dane[0];
			else if(k1.dane == "s" || k1.dane == "S" || k1.dane == "c" || k1.dane == "C" || k1.dane == "E" || k1.dane == "e")
			{
				k1.swit = k1.dane[0];
				break;
			}
			else
				break;
		}
		switch (k1.swit) {
		case '+':
			k1.dodaj((k1.jestm == 0) ? std::stod(k1.dane) : k1.wynik, (k1.jestm == 0) ? &k1.wynik : &k1.pamiec);
			break;
		case '-':
			k1.odejmij((k1.jestm == 0) ? std::stod(k1.dane) : k1.wynik, (k1.jestm == 0) ? &k1.wynik : &k1.pamiec);
			break;
		case '/':
			k1.podziel((k1.jestm == 0) ? std::stod(k1.dane) : k1.wynik, (k1.jestm == 0) ? &k1.wynik : &k1.pamiec);
			break;
		case '*':
			k1.pomnoz((k1.jestm == 0) ? std::stod(k1.dane) : k1.wynik, (k1.jestm == 0) ? &k1.wynik : &k1.pamiec);
			break;
		case '%':
			k1.modulo((k1.jestm == 0) ? std::stod(k1.dane) : k1.wynik, (k1.jestm == 0) ? &k1.wynik : &k1.pamiec);
			break;
		case 's':
		case 'S':
			k1.potega((k1.jestm == 0) ? &k1.wynik : &k1.pamiec);
			break;
		case 'c':
		case 'C':
			k1.czysc((k1.jestm == 0) ? &k1.wynik : &k1.pamiec);
			break;
		case 'r':
		case 'R':
			k1.wynik = k1.pamiec;
			break;
		case 'e':
		case 'E':
			return 0;
		}
		if(k1.jestm == 1)
			k1.jestm = 0;
	}
}