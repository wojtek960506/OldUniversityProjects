#ifndef NAGLOWEKFUNKCJEROZNE_H_INCLUDED
#define NAGLOWEKFUNKCJEROZNE_H_INCLUDED

#include "NaglowekGlowny.h"

void WyswietlOpcje(void);
void WpiszSprawdzLiczby(int *a, int p, int k);
void WyswietlNazwy(char t[30],int n);
void WybierzSortowanie(Rekord **glowa);
void Sortowanie(int(*komp)(Rekord* s),Rekord **glowa);
int KomparatorRosnacyTytul(Rekord *s);
int KomparatorRosnacyRezyser(Rekord *s);
int KomparatorRosnacyRok(Rekord *s);
int KomparatorRosnacyCzas(Rekord *s);
int KomparatorRosnacyGatunek(Rekord *s);
int KomparatorRosnacyWytwornia(Rekord *s);
int KomparatorMalejacyTytul(Rekord *s);
int KomparatorMalejacyRezyser(Rekord *s);
int KomparatorMalejacyRok(Rekord *s);
int KomparatorMalejacyCzas(Rekord *s);
int KomparatorMalejacyGatunek(Rekord *s);
int KomparatorMalejacyWytwornia(Rekord *s);
Rekord * ZamienDwa(Rekord * s) ;
void UsunKoniecLiniizfgets(char *t);
char* PominZnakiNiedrukowane(char *t);

#endif // NAGLOWEKFUNKCJEROZNE_H_INCLUDED
