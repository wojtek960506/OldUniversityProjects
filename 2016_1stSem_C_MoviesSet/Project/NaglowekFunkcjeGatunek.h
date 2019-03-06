#ifndef NAGLOWEKFUNKCJEGATUNEK_H_INCLUDED
#define NAGLOWEKFUNKCJEGATUNEK_H_INCLUDED

#include "NaglowekGlowny.h"

void PierwotnyGatunek(Gatunek **glowaG);
void WyswietlGatunek(Gatunek *glowaG);
void UsunPierwszyG(Gatunek **glowaG);
void UsunGatunek(Gatunek **glowaG);
void DodajGatunek(Gatunek **glowaG);
void EdytujGatunek(Gatunek *glowaG);
int LiczbaElementowG(Gatunek *glowaG);
Gatunek* PrzejdzDo(int n,Gatunek *glowaG);
char* WyborGatunku(Gatunek *glowaG);

#endif // NAGLOWEKFUNKCJEGATUNEK_H_INCLUDED
