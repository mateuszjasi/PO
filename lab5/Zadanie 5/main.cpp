#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

class klasa
{
public:
	char plansza[30][30];
	int statki[4];
	void wyswietl_plansze()
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
	int rozstaw_statek(int wielkosc, int x, int y, int kierunek)
	{
		//kierunki: 0-gora 1-prawo 2-dol 3-lewo
		if (plansza[x][y] != '*')
			return 1;
		if (kierunek == 0 && !(x - wielkosc >= -1))
			return 1;
		if (kierunek == 2 && !(x + wielkosc <= 30))
			return 1;
		if (kierunek == 1 && !(y + wielkosc <= 30))
			return 1;
		if (kierunek == 3 && !(y - wielkosc >= -1))
			return 1;
		std::cout << x << " " << y << " " << wielkosc << std::endl;
		if (kierunek == 0)
		{
			if (x + 1 <= 29)
				if (plansza[x + 1][y] != '*')
					return 1;
			if (x - wielkosc >= 0)
				if (plansza[x - wielkosc][y] != '*')
					return 1;
			for (int i = x; i > x - wielkosc; i--)
			{
				std::cout << i << std::endl;
				if (y - 1 >= 0)
					if (plansza[i][y - 1] != '*')
						return 1;
				if (y + 1 <= 29)
					if (plansza[i][y + 1] != '*')
						return 1;
			}
			for (int i = x; i > x - wielkosc; i--)
				plansza[i][y] = (char)wielkosc + 48;
		}
		if (kierunek == 2)
		{
			if (x - 1 >= 0)
				if (plansza[x - 1][y] != '*')
					return 1;
			if (x + wielkosc <= 29)
				if (plansza[x + wielkosc][y] != '*')
					return 1;
			for (int i = x; i < x + wielkosc; i++)
			{
				if (y - 1 >= 0)
					if (plansza[i][y - 1] != '*')
						return 1;
				if (y + 1 <= 29)
					if (plansza[i][y + 1] != '*')
						return 1;
			}
			for (int i = x; i < x + wielkosc; i++)
				plansza[i][y] = (char)wielkosc + 48;
		}
		if (kierunek == 1)
		{
			if (y - 1 >= 0)
				if (plansza[x][y - 1] != '*')
					return 1;
			if (y + wielkosc <= 29)
				if (plansza[x][y + wielkosc] != '*')
					return 1;
			for (int i = y; i < y + wielkosc; i++)
			{
				if (x - 1 >= 0)
					if (plansza[x - 1][i] != '*')
						return 1;
				if (x + 1 <= 29)
					if (plansza[x + 1][i] != '*')
						return 1;
			}
			for (int i = y; i < y + wielkosc; i++)
				plansza[x][i] = (char)wielkosc + 48;
		}
		if (kierunek == 3)
		{
			if (y + 1 <= 29)
				if (plansza[x][y + 1] != '*')
					return 1;
			if (y - wielkosc >= 0)
				if (plansza[x][y - wielkosc] != '*')
					return 1;
			for (int i = y; i > y - wielkosc; i--)
			{
				if (x - 1 >= 0)
					if (plansza[x - 1][i] != '*')
						return 1;
				if (x + 1 <= 29)
					if (plansza[x + 1][i] != '*')
						return 1;
			}
			for (int i = y; i > y - wielkosc; i--)
				plansza[x][i] = (char)wielkosc + 48;
		}
		return 0;
	}
	void rozstaw_statki_auto()
	{
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < statki[i]; j++)
				if (rozstaw_statek(i + 2, rand() % 30, rand() % 30, rand() % 4))
					j--;
	}
	void zeruj_plansze()
	{
		for (int i = 0; i < 30; i++)
			for (int j = 0; j < 30; j++)
				plansza[i][j] = '*';
	}
};

int main()
{
	srand(time(0));
	klasa gracz;
	int tryb, x, y, kierunek, nie_dodano;
	char znak;
	while (1)
	{
		gracz.zeruj_plansze();
		for (int i = 0; i < 4; i++)
		{
			system("cls");
			std::cout << "Podaj ilosc statkow " << i + 2 << "-masztowych (nie wiecej jak 5): ";
			fflush(stdin);
			std::cin >> gracz.statki[i];
			if (gracz.statki[i] > 5)
				i--;
		}
		while (1)
		{
			system("cls");
			std::cout << "Wybierz tryb:\n"
				<< "1 - automatyczne rozstawienie statkow\n"
				<< "2 - manualne rozstawienie statkow\n";
			fflush(stdin);
			std::cin >> tryb;
			if (tryb == 1 || tryb == 2)
				break;
		}
		switch (tryb)
		{
		case 1:
			gracz.rozstaw_statki_auto();
			break;
		case 2:
			nie_dodano = 0;
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < gracz.statki[i]; j++)
				{
					system("cls");
					gracz.wyswietl_plansze();
					if (nie_dodano)
						std::cout << "Nie mozna bylo dodac statku, sprobuj ponownie.\n\n";
					std::cout << "Podaj poczatek statku " << i + 2 << "-masztowego w pionie: ";
					std::cin >> x;
					std::cout << "Podaj poczatek statku " << i + 2 << "-masztowego w poziomie: ";
					std::cin >> y;
					std::cout << "Podaj kierunek w ktorym jest reszta statku (g-gora, p-prawo, l-lewo, d-dol): ";
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
						nie_dodano = 0;
						j--;
						continue;
					}
					nie_dodano = gracz.rozstaw_statek(i + 2, x - 1, y - 1, kierunek);
					if (nie_dodano)
						j--;
				}
			break;
		}
		//nie zapetlam, bo nie ma sensu wylacznie zapelnianie planszy
		//ponizej bedzie wlasciwa gra, rowniez cala gre bedzie mozna zresetowac bez wylaczania konsoli
		system("cls");
		gracz.wyswietl_plansze();
		return 0;
		
	}
}