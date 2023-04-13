#include "AI.h"

AI::AI()
{
	zatop = false;
	kierunek = 0;
}

bool AI::czy_warto(int x, int y, char trafienia[30][30])
{
	//sprawdzam czy pole jest puste
	if (trafienia[x][y] != '*')
		return false;
	//sprawdzam czy pole jest obok statku lub jest juz obstrzelane dookola
	//x==0 y==0
	if (x == 0 && y == 0 && (trafienia[x + 1][y] == 'o' && trafienia[x][y + 1] == 'o' || (trafienia[x + 1][y] == 'x' || trafienia[x][y + 1] == 'x')))
		return false;
	//x==0 y==29
	if (x == 0 && y == 29 && (trafienia[x + 1][y] == 'o' && trafienia[x][y - 1] == 'o' || (trafienia[x + 1][y] == 'x' || trafienia[x][y - 1] == 'x')))
		return false;
	//x==29 y==29
	if (x == 29 && y == 0 && (trafienia[x - 1][y] == 'o' && trafienia[x][y + 1] == 'o' || (trafienia[x - 1][y] == 'x' || trafienia[x][y + 1] == 'x')))
		return false;
	//x==29 y==29
	if (x == 29 && y == 29 && (trafienia[x - 1][y] == 'o' && trafienia[x][y - 1] == 'o' || (trafienia[x - 1][y] == 'x' || trafienia[x][y - 1] == 'x')))
		return false;
	//x==0 y>0 y<29
	if (x == 0 && y > 0 && y < 29 && (trafienia[x + 1][y] == 'o' && trafienia[x][y + 1] == 'o' && trafienia[x][y - 1] == 'o' || (trafienia[x + 1][y] == 'x' || trafienia[x][y + 1] == 'x' || trafienia[x][y - 1] == 'x')))
		return false;
	//x==29 y>0 y<29
	if (x == 29 && y > 0 && y < 29 && (trafienia[x - 1][y] == 'o' && trafienia[x][y + 1] == 'o' && trafienia[x][y - 1] == 'o' || (trafienia[x - 1][y] == 'x' || trafienia[x][y + 1] == 'x' || trafienia[x][y - 1] == 'x')))
		return false;
	//y==0 x>0 x<29
	if (y == 0 && x > 0 && x < 29 && (trafienia[x][y + 1] == 'o' && trafienia[x + 1][y] == 'o' && trafienia[x - 1][y] == 'o' || (trafienia[x][y + 1] == 'x' || trafienia[x + 1][y] == 'x' || trafienia[x - 1][y] == 'x')))
		return false;
	//y==29 x>0 x<29
	if (y == 29 && x > 0 && x < 29 && (trafienia[x][y - 1] == 'o' && trafienia[x + 1][y] == 'o' && trafienia[x - 1][y] == 'o' || trafienia[x][y - 1] == 'x' || trafienia[x + 1][y] == 'x' || trafienia[x - 1][y] == 'x'))
		return false;
	//x>0 x<29 y>0 y<29
	if (x > 0 && x < 29 && y>0 && y < 29 && (trafienia[x + 1][y] == 'o' && trafienia[x - 1][y] == 'o' && trafienia[x][y + 1] == 'o' && trafienia[x][y - 1] == 'o' || (trafienia[x + 1][y] == 'x' || trafienia[x - 1][y] == 'x' || trafienia[x][y + 1] == 'x' || trafienia[x][y - 1] == 'x')))
		return false;
	return true;
}

void AI::trafiono(int x, int y)
{
	this->x = x;
	this->y = y;
	zatop = true;
}

bool AI::szukaj_kierunku(char trafienia[30][30])
{
	if (x < 29 && trafienia[x + 1][y] == 'x')
		kierunek = 1;
	else if (x > 0 && trafienia[x - 1][y] == 'x')
		kierunek = 1;
	else if (y < 29 && trafienia[x][y + 1] == 'x')
		kierunek = 2;
	else if (y > 0 && trafienia[x][y - 1] == 'x')
		kierunek = 2;
	if (kierunek)
		return true;
	return false;
}

void AI::nowe_wspolrzedne(int* nowy_x, int* nowy_y, char trafienia[30][30])
{
	if (x > 0 && trafienia[x - 1][y] == '*')
	{
		*nowy_x = x - 1;
		*nowy_y = y;
	}
	else if (x < 29 && trafienia[x + 1][y] == '*')
	{
		*nowy_x = x + 1;
		*nowy_y = y;
	}
	else if (y < 29 && trafienia[x][y + 1] == '*')
	{
		*nowy_x = x;
		*nowy_y = y + 1;
	}
	else if (y > 0 && trafienia[x][y - 1] == '*')
	{
		*nowy_x = x;
		*nowy_y = y - 1;
	}
}

void AI::szukaj(int* nowy_x, int* nowy_y, char trafienia[30][30])
{
	//kierunek: 0-brak, 1-pionowy, 2-poziomy
	bool znaleziono = false;
	if (kierunek == 0)
		if (!szukaj_kierunku(trafienia))
			nowe_wspolrzedne(nowy_x, nowy_y, trafienia);
	if (kierunek == 1)
	{
		for (int i = 1; x - i >= 0; i++)
		{
			if (trafienia[x - i][y] == '*')
			{
				*nowy_x = x - i;
				*nowy_y = y;
				znaleziono = true;
				break;
			}
			if (trafienia[x - i][y] == 'o')
				break;
		}
		if (!znaleziono)
		{
			for (int i = 1; x + i <= 29; i++)
			{
				if (trafienia[x + i][y] == '*')
				{
					*nowy_x = x + i;
					*nowy_y = y;
					znaleziono = true;
					break;
				}
				if (trafienia[x + i][y] == 'o')
					break;
			}
		}
	}
	else if (kierunek == 2)
	{
		for (int i = 1; y + i <= 29; i++)
		{
			if (trafienia[x][y + i] == '*')
			{
				*nowy_x = x;
				*nowy_y = y + i;
				znaleziono = true;
				break;
			}
			if (trafienia[x][y + i] == 'o')
				break;
		}
		if (!znaleziono)
		{
			for (int i = 1; y - i >= 0; i++)
			{
				if (trafienia[x][y - i] == '*')
				{
					*nowy_x = x;
					*nowy_y = y - i;
					znaleziono = true;
					break;
				}
				if (trafienia[x][y - i] == 'o')
					break;
			}
		}
	}
}
