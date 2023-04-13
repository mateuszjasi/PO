#include "main1.h"
#include <iostream>

int main1::main1_exe()
{
	wynik = 0;
	pamiec = 0;
	jestm = 0;
	std::setlocale(LC_ALL, "pl_PL");
	while (1) {
		swit = ' ';
		while(1)
		{
			system("cls");
			std::cout << "Ekran: " << wynik << " " << swit << std::endl
				<< "Wartosc w pamieci: " << pamiec << std::endl
				<< "Dostepne operacje:\n+ dodawanie\n- odejmowanie\n/ dzielenie\n* mnozenie\n% reszta z dzielenia\nS podniesienie do kwadratu\nC czyszczenie ekranu\nE wyjscie z programu\n"
				<< "M wykonanie jednej z wyzszych operacji na pamieci\nR wywolanie wyniku z pamieci (tylko w trybie operacji na pamieci)\n\n";
			if (jestm == 1)
				std::cout << "Przeprowadzisz operacje na pamieci kliknij \"M\", aby anulowac\n";
			std::cout << "Wprowdz dane: ";
			std::cin >> dane;
			if(dane == "M" || dane == "m")
				(jestm == 0) ? jestm = 1 : jestm = 0;
			else if (dane == "+" || dane == "-" || dane == "/" || dane == "*" || dane == "s" || dane == "S" || dane == "%" || dane == "c" || dane == "C" || dane == "E"
				|| dane == "e" || (dane == "R" || dane == "r" && jestm == 1))
			{
				swit = dane[0];
				break;
			}
			else
				wynik = std::stod(dane);
		}
		while(swit != 's' && swit != 'S' && swit != 'c' && swit != 'C' && swit != 'E' && swit != 'e' && jestm == 0)
		{
			system("cls");
			std::cout << "Ekran: " << wynik << " " << swit << std::endl;
			std::cout << "Podaj wartosc lub zmien operacje: ";
			std::cin >> dane;
			if (dane == "+" || dane == "-" || dane == "/" || dane == "*" || dane == "%")
				swit = dane[0];
			else if(dane == "s" || dane == "S" || dane == "c" || dane == "C" || dane == "E" || dane == "e")
			{
				swit = dane[0];
				break;
			}
			else
				break;
		}
		switch (swit) {
		case '+':
			dodaj((jestm == 0) ? std::stod(dane) : wynik, (jestm == 0) ? &wynik : &pamiec);
			break;
		case '-':
			odejmij((jestm == 0) ? std::stod(dane) : wynik, (jestm == 0) ? &wynik : &pamiec);
			break;
		case '/':
			podziel((jestm == 0) ? std::stod(dane) : wynik, (jestm == 0) ? &wynik : &pamiec);
			break;
		case '*':
			pomnoz((jestm == 0) ? std::stod(dane) : wynik, (jestm == 0) ? &wynik : &pamiec);
			break;
		case '%':
			modulo((jestm == 0) ? std::stod(dane) : wynik, (jestm == 0) ? &wynik : &pamiec);
			break;
		case 's':
		case 'S':
			potega((jestm == 0) ? &wynik : &pamiec);
			break;
		case 'c':
		case 'C':
			czysc((jestm == 0) ? &wynik : &pamiec);
			break;
		case 'r':
		case 'R':
			wynik = pamiec;
			break;
		case 'e':
		case 'E':
			return 0;
		}
		if (jestm == 1)
			jestm = 0;
	}
}
