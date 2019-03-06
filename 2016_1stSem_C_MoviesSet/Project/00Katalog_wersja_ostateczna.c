/* Dzie� dobry

Napisa� program b�d�cy baza rekord�w przy u�yciu struktur dynamicznych.

Nale�y zapewni� mo�liwo�� dodawania, usuwania i edytowania rekord�w.
Nale�y zapewni� mo�liwo�� sortowania bazy po dowolnym polu rekordu.
Nale�y opracowa� jaki� spos�b prezentacji wynik�w.
Nale�y umo�liwi� zapisywanie bazy do pliku, odczyt z pliku pod dowolna nazw�.
Nale�y umo�liwi� czyszczenie bazy.
Nale�y napisany program podzieli� na pliki grupuj�ce logicznie wybrane funkcje.
Nale�y zabezpieczy� program przed podawaniem niepoprawnych danych.
Dane w polach rekordu musz� by� sensowne.

KATALOG FILM�W:

Pola w rekordzie:
Tytu�, re�yser, rok produkcji, czas trwania, gatunek, wytw�rnia filmowa
Pole Gatunek powinno zawiera� 5 mo�liwych do wyboru typ�w oraz posiada� mo�liwo�� usuwania, edytowania i dodawania nowych warto�ci. */

//------------------------------------------------------------------------------------------------------------------------------------

#include "NaglowekGlowny.h"
#include "NaglowekFunkcjeGatunek.h"
#include "NaglowekFunkcjePliki.h"
#include "NaglowekFunkcjeRekord.h"
#include "NaglowekFunkcjeRozne.h"

int main(void)
{
    Rekord *glowa = NULL; //inicjacja bazy
    //Rekord *obecny = NULL;
    //Rekord *p;
    Gatunek *glowaG = NULL;
    //Gatunek *gat;
    //Gatunek *pG;
    //Gatunek *pG;
    int operacja;
    int num_op=1;

    printf("Wojciech Zielinski grupa: F2A1\n"
           "Katalog filmow utworzony za pomoca struktur dynamicznych\n");
    PierwotnyGatunek(&glowaG);
    puts("");
    printf("%d. ",num_op);
    WyswietlOpcje();
    WpiszSprawdzLiczby(&operacja,1,9);
    puts("");

    while(operacja!=9)
    {
        switch(operacja)
        {
            case 1: DodajRekord(&glowa,&glowaG);
                    break;
            case 2: UsunRekord(&glowa);
                    break;
            case 3: EdytujRekord(glowa,glowaG);
                    break;
            case 4: WybierzSortowanie(&glowa);
                    break;
            case 5: ZapiszDoPliku(glowa);
                    break;
            case 6: WczytajZPliku(&glowa);
                    break;
            case 7: WyczyscBaze(&glowa);
                    break;
            case 8: WyswietlBaze(glowa);
                    break;
        }
        num_op++;  //dodaje numer operacji
        puts("");
        printf("%d. ",num_op);
        WyswietlOpcje();
        WpiszSprawdzLiczby(&operacja,1,9);
        puts("");
    }


    return 0;
}
