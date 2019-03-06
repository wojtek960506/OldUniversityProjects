#ifndef NAGLOWEKGLOWNY_H_INCLUDED
#define NAGLOWEKGLOWNY_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//struktury
typedef struct gatunek1 { //struktura zawierajaca typy gatunkow
        char typ[40];
        struct gatunek1 *nast;
}Gatunek;

typedef struct  rekord {
    char tytul[40];
    char rezyser[40];
    int rok_prod;
    int czas_trw;
    Gatunek gatunek;
    char wytw_film[40];
    struct rekord * nast;
}Rekord;


/*
//
void WyswietlOpcje(void);
void WpiszSprawdzLiczby(int *a, int p, int k);
void WyswietlNazwy(char t[30],int n);
void Sortowanie(int(*komp)(Rekord* s),Rekord **glowa);
void WybierzSortowanie(Rekord **glowa);
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
//


void PierwotnyGatunek(Gatunek **glowaG); //
void WyswietlGatunek(Gatunek *glowaG); //
void UsunPierwszyG(Gatunek **glowaG); //
void UsunGatunek(Gatunek **glowaG); //
void DodajGatunek(Gatunek **glowaG); //
void EdytujGatunek(Gatunek *glowaG); //
int LiczbaElementowG(Gatunek *glowaG); //
Gatunek* PrzejdzDo(int n,Gatunek *glowaG); //
char* WyborGatunku(Gatunek *glowaG); //


void DodajRekord(Rekord **glowa,Gatunek **glowaG); //
void UsunRekord(Rekord **glowa); //
void UsunPierwszy(Rekord **glowa); //
void EdytujRekord(Rekord *glowa, Gatunek *glowaG);//
void PomocniczaEdycja(Rekord **obecny,Gatunek **glowaG); //
void WyczyscBaze(Rekord **glowa); //
void WyswietlBaze(Rekord *glowa); //
int LiczbaElementow(Rekord *glowa); //


void CzytanieZnaku(char t[2],char znak,char pom[30],FILE *wp);
void ZapiszDoPliku(Rekord *glowa);
void ZapiszNazwy(char t[30],int n, FILE *wp);
void WczytajZPliku(Rekord **glowa);
*/
#endif // NAGLOWEKGLOWNY_H_INCLUDED
