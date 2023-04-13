#pragma once

class klasa
{
public:
	klasa();
	char plansza[30][30];
	void wyswietl_plansze();
	bool rozstaw_statek(int wielkosc, int x, int y, int kierunek, int* statki);
	void rozstaw_statki_auto(int* statki);
	void rozstaw_statki_manual(int* statki, int id);
	void zeruj_plansze();
};