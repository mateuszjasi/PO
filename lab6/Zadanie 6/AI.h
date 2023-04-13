#pragma once

class AI
{
public:
	bool zatop;
	int x, y, kierunek;
	AI();
	bool czy_warto(int x, int y, char trafienia[30][30]);
	void trafiono(int x, int y);
	bool szukaj_kierunku(char trafienia[30][30]);
	void nowe_wspolrzedne(int* nowy_x, int* nowy_y, char trafienia[30][30]);
	void szukaj(int* x, int* y, char trafienia[30][30]);
};
