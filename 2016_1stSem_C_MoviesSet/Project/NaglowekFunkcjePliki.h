#ifndef NAGLOWEKFUNKCJEPLIKI_H_INCLUDED
#define NAGLOWEKFUNKCJEPLIKI_H_INCLUDED

#include "NaglowekGlowny.h"

void CzytanieZnaku(char t[2],char znak,char pom[30],FILE *wp);
void ZapiszNazwy(char t[30],int n, FILE *wp);
void ZapiszDoPliku(Rekord *glowa);
void WczytajZPliku(Rekord **glowa);


#endif // NAGLOWEKFUNKCJEPLIKI_H_INCLUDED
