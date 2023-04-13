#include <iostream>
#include <string>
#include "main2.h"

int main2::main2_exe()
{
	wynik = 0;
	while(1)
	{
		system("cls");
		std::cout << "Ekran: "<< wynik
		<< "\nPodaj dzialanie: ";
		//zeby podac liczbe ujemna nalezy wpisac ja ze znakiem '-' bezposredniu po znaku dzialania np 2*-2 = -4 lub 2--2 = 4
		std::cin >> dzialanie;
		if (dzialanie == "E" || dzialanie == "e")
			return 0;
		deszyfr();
	}
	
}
