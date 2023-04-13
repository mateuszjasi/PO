#include "klasa.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

klasa::klasa()
{
	srand(time(0));
	zeruj_plansze();
}

void klasa::wyswietl_plansze()
{
	for (int i = -1; i < 30; i++)
	{
		std::cout.width(2);
		std::cout << i + 1;
		for (int j = 0; j < 30; j++)
		{
			if (i != -1)
			{
				std::cout.width(2);
				std::cout << plansza[i][j];
			}
			else
			{
				std::cout.width(2);
				std::cout << j + 1;
			}
		}
		std::cout << std::endl;
	}
}

bool klasa::rozstaw_statek(int wielkosc, int x, int y, int kierunek, int* statki)
{
	//kierunki: 0-gora 1-prawo 2-dol 3-lewo
	if (kierunek == 0)
	{
		if (!(x - wielkosc >= -1))
			return false;
		if (x + 1 <= 29)
			if (plansza[x + 1][y] != '*')
				return false;
		if (x - wielkosc >= 0)
			if (plansza[x - wielkosc][y] != '*')
				return false;
		for (int i = x; i > x - wielkosc; i--)
		{
			if (plansza[i][y] != '*')
				return false;
			if (y - 1 >= 0)
				if (plansza[i][y - 1] != '*')
					return false;
			if (y + 1 <= 29)
				if (plansza[i][y + 1] != '*')
					return false;
		}
		for (int i = x; i > x - wielkosc; i--)
			plansza[i][y] = (char)wielkosc + 48;
	}
	if (kierunek == 2)
	{
		if (!(x + wielkosc <= 30))
			return false;
		if (x - 1 >= 0)
			if (plansza[x - 1][y] != '*')
				return false;
		if (x + wielkosc <= 29)
			if (plansza[x + wielkosc][y] != '*')
				return false;
		for (int i = x; i < x + wielkosc; i++)
		{
			if (plansza[i][y] != '*')
				return false;
			if (y - 1 >= 0)
				if (plansza[i][y - 1] != '*')
					return false;
			if (y + 1 <= 29)
				if (plansza[i][y + 1] != '*')
					return false;
		}
		for (int i = x; i < x + wielkosc; i++)
			plansza[i][y] = (char)wielkosc + 48;
	}
	if (kierunek == 1)
	{
		if (!(y + wielkosc <= 30))
			return false;
		if (y - 1 >= 0)
			if (plansza[x][y - 1] != '*')
				return false;
		if (y + wielkosc <= 29)
			if (plansza[x][y + wielkosc] != '*')
				return false;
		for (int i = y; i < y + wielkosc; i++)
		{
			if (plansza[x][i] != '*')
				return false;
			if (x - 1 >= 0)
				if (plansza[x - 1][i] != '*')
					return false;
			if (x + 1 <= 29)
				if (plansza[x + 1][i] != '*')
					return false;
		}
		for (int i = y; i < y + wielkosc; i++)
			plansza[x][i] = (char)wielkosc + 48;
	}
	if (kierunek == 3)
	{
		if (!(y - wielkosc >= -1))
			return false;
		if (y + 1 <= 29)
			if (plansza[x][y + 1] != '*')
				return false;
		if (y - wielkosc >= 0)
			if (plansza[x][y - wielkosc] != '*')
				return false;
		for (int i = y; i > y - wielkosc; i--)
		{
			if (plansza[x][i] != '*')
				return false;
			if (x - 1 >= 0)
				if (plansza[x - 1][i] != '*')
					return false;
			if (x + 1 <= 29)
				if (plansza[x + 1][i] != '*')
					return false;
		}
		for (int i = y; i > y - wielkosc; i--)
			plansza[x][i] = (char)wielkosc + 48;
	}
	return true;
}

void klasa::rozstaw_statki_auto(int* statki)
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < statki[i]; j++)
			if (!rozstaw_statek(i + 2, rand() % 30, rand() % 30, rand() % 4, statki))
				j--;
}

void klasa::rozstaw_statki_manual(int* statki, int id)
{
	int x, y, kierunek;
	bool dodano = true;
	char znak;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < statki[i]; j++)
		{
			system("cls");
			wyswietl_plansze();
			std::cout << "Gracz " << id << " rozstawia statki.";
			if (!dodano)
				std::cout << "\nNie mozna bylo dodac statku, sprobuj ponownie.";
			std::cout << "\n\nPodaj poczatek statku " << i + 2 << "-masztowego w pionie: ";
			std::cin >> x;
			std::cout << "Podaj poczatek statku " << i + 2 << "-masztowego w poziomie: ";
			std::cin >> y;
			std::cout << "Podaj kierunek w ktorym jest reszta statku (g-gora, p-prawo, d-dol, l-lewo): ";
			std::cin >> znak;
			switch (znak)
			{
			case 'g':
				kierunek = 0;
				break;
			case 'p':
				kierunek = 1;
				break;
			case 'd':
				kierunek = 2;
				break;
			case 'l':
				kierunek = 3;
				break;
			default:
				dodano = false;
				j--;
				continue;
			}
			dodano = rozstaw_statek(i + 2, x - 1, y - 1, kierunek, statki);
			if (!dodano)
				j--;
		}
}

void klasa::zeruj_plansze()
{
	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 30; j++)
			plansza[i][j] = '*';
}
