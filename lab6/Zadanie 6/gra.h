#pragma once

class gra
{
public:
	char trafienia1[30][30], trafienia2[30][30];
	gra();
	void zeruj_trafienia();
	void wyswietl_trafienia(char plansza[30][30], int liczba_statkow);
	int start(char plansza1[30][30], char plansza2[30][30], int tryb1, int tryb2, int liczba_statkow);
	bool zatopienie(char plansza[30][30], char trafienia[30][30], int x, int y);
	int strzal(char plansza[30][30], char trafienia[30][30], int x, int y);
};
