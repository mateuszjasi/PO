#include "cal2.h"

void kalkulator::deszyfr()
{
	dzialanie = return_dzialanie();
	for(int i = 0; i < dzialanie.size(); i++)
	{
		if(dzialanie[i]>='0' && dzialanie[i]<='9')
		{
			liczba = dzialanie[i];
			i++;
			while ((dzialanie[i] >= '0' && dzialanie[i] <= '9') || dzialanie[i] == '.')
			{
				liczba += dzialanie[i];
				i++;
			}
			i--;
			dane.push_back(stod(liczba));
		} else if(i==0 || (dzialanie[i]=='-' && !(dzialanie[i - 1] >= '0' && dzialanie[i - 1] <= '9')))
		{
			liczba = dzialanie[i];
			i++;
			while ((dzialanie[i] >= '0' && dzialanie[i] <= '9') || dzialanie[i] == '.')
			{
				liczba += dzialanie[i];
				i++;
			}
			i--;
			dane.push_back(stod(liczba));
		} else
		{
			znaki.push_back(dzialanie[i]);
			n++;
		}
	}
	licz();
}

void kalkulator::licz()
{
	for(int i = 3, j = 0, dzial; i;)
	{
		if(znaki.empty())
			break;
		dzial = 0;
		if(i == 3 && (znaki[j]=='p' || znaki[j] == '^' || znaki[j] == '%'))
		{
			switch (znaki[j])
			{
				case '%':
					procent(j);
					break;
				case 'p':
					pierwiastek(j);
					break;
				case '^':
					potega(j);
					break;
			}
			dzial = 1;
		} else if (i == 2 && (znaki[j] == '/' || znaki[j] == '*'))
		{
			switch (znaki[j])
			{
				case '/':
					podziel(j);
					break;
				case '*':
					pomnoz(j);
					break;
			}
			dzial = 1;
		} else if (i == 1 && (znaki[j] == '+' || znaki[j] == '-'))
		{
			switch (znaki[j])
			{
			case '+':
				dodaj(j);
				break;
			case '-':
				odejmij(j);
				break;
			}
			dzial = 1;
		}
		if(dzial)
		{
			dane.erase(dane.begin() + j + 1);
			znaki.erase(znaki.begin() + j);
			n--;
		} else
			j++;
		if (j == n)
		{
			j = 0;
			i--;
		}
	}
	return_wynik(dane.front());
	dane.pop_back();
}

void kalkulator::dodaj(int x) {
	dane[x] += dane[x+1];
}

void kalkulator::odejmij(int x) {
	dane[x] -= dane[x + 1];
}

void kalkulator::podziel(int x) {
	dane[x] /= dane[x + 1];
}

void kalkulator::pomnoz(int x) {
	dane[x] *= dane[x + 1];
}

void kalkulator::procent(int x) {
	dane[x] *= dane[x + 1] / 100;
}

void kalkulator::pierwiastek(int x) {
	dane[x] = pow(dane[x], 1 / dane[x + 1]);
}

void kalkulator::potega(int x) {
	dane[x] = pow(dane[x], dane[x + 1]);
}