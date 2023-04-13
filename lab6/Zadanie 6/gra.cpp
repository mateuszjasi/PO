#include "gra.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "AI.h"

gra::gra()
{
	srand(time(0));
	zeruj_trafienia();
}

void gra::zeruj_trafienia()
{
	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 30; j++)
		{
			trafienia1[i][j] = '*';
			trafienia2[i][j] = '*';
		}
}

void gra::wyswietl_trafienia(char plansza[30][30], int liczba_statkow)
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
	std::cout << "Liczba pozostalych statkow przeciwnika: " << liczba_statkow << std::endl;
}

int gra::start(char plansza1[30][30], char plansza2[30][30], int tryb1, int tryb2, int liczba_statkow)
{
	int x, y, sum1, sum2;
	sum1 = liczba_statkow;
	sum2 = liczba_statkow;
	AI pc1, pc2;
	//gracz 1
	while (true)
	{
		while (true)
		{
			system("cls");
			wyswietl_trafienia(trafienia1, sum2);
			std::cout << "\nTura gracza 1!\n\n";
			if (tryb1 == 1)
			{
				do
				{
					std::cout << "Podaj wspolrzedne w pionie: ";
					std::cin >> x;
					std::cout << "Podaj wpolrzedne w poziomie: ";
					std::cin >> y;
				} while (x < 1 || x > 30 || y < 1 || y > 30 || trafienia1[x - 1][y - 1] != '*');
			}
			else
			{
				std::cout << "Komputer nie mysli, bo nie umie, ale za to kalkuluje...";
				if (pc1.zatop)
					pc1.szukaj(&x, &y, trafienia1);
				else
					do
					{
						x = rand() % 30;
						y = rand() % 30;
					} while (!pc1.czy_warto(x, y, trafienia1));
					x++;
					y++;
					std::cout << "\nKomputer strzela w pole o wspolrzednych: " << x << " " << y << std::endl;
			}
			switch (strzal(plansza2, trafienia1, x - 1, y - 1))
			{
			case 0:
				std::cout << "\nPudlo!\n";
				system("pause");
				break;
			case 1:
				if (tryb1 == 2 && pc1.zatop == false)
					pc1.trafiono(x - 1, y - 1);
				std::cout << "\nTrafiono!\n";
				system("pause");
				continue;
			case 2:
				std::cout << "\nTrafiono, zatopiono!\n";
				system("pause");
				sum2--;
				if (sum2 == 0)
				{
					system("cls");
					return 1;
				}
				if (tryb1 == 2)
				{
					pc1.zatop = false;
					pc1.kierunek = 0;
				}
				continue;
			}
			break;
		}
		//gracz 2
		while (true)
		{
			system("cls");
			wyswietl_trafienia(trafienia2, sum1);
			std::cout << "\nTura gracza 2!\n\n";
			if (tryb2 == 1)
			{
				do
				{
					std::cout << "Podaj wspolrzedne w pionie: ";
					std::cin >> x;
					std::cout << "Podaj wpolrzedne w poziomie: ";
					std::cin >> y;
				} while (x < 1 || x > 30 || y < 1 || y > 30 || trafienia2[x - 1][y - 1] != '*');
			}
			else
			{
				std::cout << "Komputer nie mysli, bo nie umie, ale za to kalkuluje...";
				if (pc2.zatop)
					pc2.szukaj(&x, &y, trafienia2);
				else
					do
					{
						x = rand() % 30;
						y = rand() % 30;
					} while (!pc2.czy_warto(x, y, trafienia2));
				x++;
				y++;
				std::cout << "\nKomputer strzela w pole o wspolrzednych: " << x << " " << y << std::endl;
			}
			switch (strzal(plansza1, trafienia2, x - 1, y - 1))
			{
			case 0:
				std::cout << "\nPudlo!\n";
				system("pause");
				break;
			case 1:
				if (tryb2 == 2 && pc2.zatop == false)
					pc2.trafiono(x - 1, y - 1);
				std::cout << "\nTrafiono!\n";
				system("pause");
				continue;
			case 2:
				if (tryb2 == 2)
				{
					pc2.zatop = false;
					pc2.kierunek = 0;
				}
				std::cout << "\nTrafiono, zatopiono!\n";
				system("pause");
				sum1--;
				if (sum1 == 0)
				{
					system("cls");
					return 2;
				}
				continue;
			}
			break;
		}
	}
}

//moglem stworzyc obiekty dla statkow i dac im cos w stylu punktow zycia, ale juz konczylem tworzyc funkcje jak na to wpadlem i nie chcialo mi sie tego zmieniac
bool gra::zatopienie(char plansza[30][30], char trafienia[30][30], int x, int y)
{
	int dlugosc = (int)plansza[x][y] - 48, trafiony = 0;
	if (x == 0 && plansza[x + 1][y] != '*')
	{
		for (int i = 0; i < dlugosc; i++)
			if (trafienia[x + i][y] == 'x')
				trafiony++;
		if (trafiony == dlugosc)
			return true;
		return false;
	}
	if (x == 29 && plansza[x - 1][y] != '*')
	{
		for (int i = 0; i < dlugosc; i++)
			if (trafienia[x - i][y] == 'x')
				trafiony++;
		if (trafiony == dlugosc)
			return true;
		return false;
	}
	if ((x < 29 && plansza[x + 1][y] != '*') || (x > 0 && plansza[x - 1][y] != '*'))
	{
		while (true)
		{
			if (x != 0 && plansza[x - 1][y] == '*')
				break;
			if (x == 0)
				break;
			x--;
		}
		for (int i = 0; i < dlugosc; i++)
			if (trafienia[x + i][y] == 'x')
				trafiony++;
		if (trafiony == dlugosc)
			return true;
		return false;
	}
	if (y == 0 && plansza[x][y + 1] != '*')
	{
		for (int i = 0; i < dlugosc; i++)
			if (trafienia[x][y + i] == 'x')
				trafiony++;
		if (trafiony == dlugosc)
			return true;
		return false;
	}
	if (y == 29 && plansza[x][y - 1] != '*')
	{
		for (int i = 0; i < dlugosc; i++)
			if (trafienia[x][y - i] == 'x')
				trafiony++;
		if (trafiony == dlugosc)
			return true;
		return false;
	}
	if ((y > 0 && plansza[x][y + 1] != '*') || (y < 29 && plansza[x][y - 1] != '*'))
	{
		while (true)
		{
			if (y != 0 && plansza[x][y - 1] == '*')
				break;
			if (y == 0)
				break;
			y--;
		}
		for (int i = 0; i < dlugosc; i++)
			if (trafienia[x][y + i] == 'x')
				trafiony++;
		if (trafiony == dlugosc)
			return true;
		return false;
	}
}

int gra::strzal(char plansza[30][30], char trafienia[30][30], int x, int y)
{
	if (plansza[x][y] == '*')
	{
		trafienia[x][y] = 'o';
		return 0;
	}
	trafienia[x][y] = 'x';
	if (zatopienie(plansza, trafienia, x, y))
		return 2;
	return 1;
}
