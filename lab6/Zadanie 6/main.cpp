#include <iostream>
#include "klasa.h" //tworzenie plansz
#include "gra.h" //rozgrywka

int main()
{
	int statki[4], suma;
	klasa gracz1, gracz2;
	int tryb, wygrany;
	char powtorz;
	gra rozgrywka;
	while (true)
	{
		suma = 0;
		system("cls");
		//podawanie liczby statkow
		for (int i = 0; i < 4; i++)
		{
			std::cout << "Podaj liczbe statkow " << i + 2 << "-masztowych (nie wiecej jak 15): ";
			std::cin >> statki[i];
			if (statki[i] < 0 || statki[i] > 15)
			{
				i--;
				continue;
			}
			suma += statki[i];
			if (i == 3 && suma == 0)
			{
				system("cls");
				std::cout << "Na planszy musi byc co najmniej 1 statek!\n";
				i = -1;
			}
		}
		//wybor trybu rozstawiania
		do
		{
			system("cls");
			std::cout << "Wybierz tryb rozstawiania statkow:\n"
				<< "1 - automatyczne\n"
				<< "2 - manualne\n";
			std::cin >> tryb;
		} while (tryb != 1 && tryb != 2);
		//rozstawianie statkow
		switch (tryb)
		{
		case 1:
			gracz1.rozstaw_statki_auto(statki);
			gracz2.rozstaw_statki_auto(statki);
			break;
		case 2:
			gracz1.rozstaw_statki_manual(statki, 1);
			gracz2.rozstaw_statki_manual(statki, 2);
			break;
		}
		//wybor trybu rozgrywki
		do
		{
			system("cls");
			std::cout << "Wybierz tryb rozgrywki:\n"
				<< "1 - PvP\n"
				<< "2 - PvPC\n"
				<< "3 - PCvPC\n";
			std::cin >> tryb;
		} while (tryb != 1 && tryb != 2 && tryb != 3);
		//rozgrywka
		switch(tryb)
		{
		case 1:
			wygrany = rozgrywka.start(gracz1.plansza, gracz2.plansza, 1, 1, suma);
			break;
		case 2:
			wygrany = rozgrywka.start(gracz1.plansza, gracz2.plansza, 1, 2, suma);
			break;
		case 3:
			wygrany = rozgrywka.start(gracz1.plansza, gracz2.plansza, 2, 2, suma);
			break;
		}
		//restart
		do
		{
			system("cls");
			std::cout << "Wygral gracz " << wygrany << "!!!"
			<< "\n\nRozpoczac nowa gre? (T/N)";
			std::cin >> powtorz;
		} while (powtorz != 'T' && powtorz != 'N');
		if (powtorz == 'T')
		{
			gracz1.zeruj_plansze();
			gracz2.zeruj_plansze();
			rozgrywka.zeruj_trafienia();
			continue;
		}
		break;
	}
	return 0;
}