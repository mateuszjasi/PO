# PO
Napisz program -> gra w statki, który będzie operował na planszy o rozmiarze 30x30 i dodatkowych maksymalnych 6 liniach sterowania.<br />
Ilość poszczególnych rodzajów statków ma być konfigurowalna (2-5 masztów).<br />
Zaimplementuj mechanizmy:
1. ręcznego rozstawiania statków (poziomo, pionowo, od danego punktu początkowego statku)
2. automatycznego rozstawiania statków
3. weryfikacji ułożenia statku (aut/manual) - statki nie mogą wychodzić poza plansze, ani stykać się bokami.

Prezentacji planszy na zmianę 2 użytkownikom (przeciwnym stronom)

Załóż że:
- Plansza -> początkowo jest zakryta -> za pomocą gwiazdki *
- Ułożone własne statki są reprezentowane poprzez reprezentację graficzną liczbową - ilości ich masztów np. trójmasztowiec określany jest 3-jkami.
- Obszary zatopione nieprzyjaciela określane są jako X
- Obszary typu "pudło" określane są jako o
