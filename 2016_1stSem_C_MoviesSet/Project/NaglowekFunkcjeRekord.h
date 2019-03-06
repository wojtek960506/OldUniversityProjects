#ifndef NAGLOWEKFUNKCJEREKORD_H_INCLUDED
#define NAGLOWEKFUNKCJEREKORD_H_INCLUDED

#include "NaglowekGlowny.h"

void DodajRekord(Rekord **glowa,Gatunek **glowaG);
void UsunPierwszy(Rekord **glowa);
void UsunRekord(Rekord **glowa);
void EdytujRekord(Rekord *glowa, Gatunek *glowaG);
void PomocniczaEdycja(Rekord **obecny,Gatunek **glowaG);
void WyczyscBaze(Rekord **glowa);
void WyswietlBaze(Rekord *glowa);
int LiczbaElementow(Rekord *glowa);

#endif // NAGLOWEKFUNKCJEREKORD_H_INCLUDED
