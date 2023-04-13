#include <iostream>
#include "main0.h"
#include "main1.h"
#include "main2.h"

int main()
{
	int tryb;
	main0 cal_prosty;
	main1 cal_naukowy;
	main2 cal_string;
	while(1)
	{
		system("cls");
		std::cout << "Tryby:\n"
		<< "0 - zakoncz program\n"
		<< "1 - kalkulator prosty\n"
		<< "2 - kalkulator naukowy\n"
		<< "3 - kalkulator na cale polecenia\n"
		<< "Podaj tryb: ";
		std::cin >> tryb;
		switch(tryb)
		{
		case 0:
			return 0;
		case 1:
			cal_prosty.main0_exe();
			break;
		case 2:
			cal_naukowy.main1_exe();
			break;
		case 3:
			cal_string.main2_exe();
			break;
		}
	}
	
}
