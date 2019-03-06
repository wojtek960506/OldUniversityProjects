/* Dzieñ dobry

Napisaæ program bêd¹cy baza rekordów przy u¿yciu struktur dynamicznych.

Nale¿y zapewniæ mo¿liwoœæ dodawania, usuwania i edytowania rekordów.
Nale¿y zapewniæ mo¿liwoœæ sortowania bazy po dowolnym polu rekordu.
Nale¿y opracowaæ jakiœ sposób prezentacji wyników.
Nale¿y umo¿liwiæ zapisywanie bazy do pliku, odczyt z pliku pod dowolna nazw¹.
Nale¿y umo¿liwiæ czyszczenie bazy.
Nale¿y napisany program podzieliæ na pliki grupuj¹ce logicznie wybrane funkcje.
Nale¿y zabezpieczyæ program przed podawaniem niepoprawnych danych.
Dane w polach rekordu musz¹ byæ sensowne.

KATALOG FILMÓW:

Pola w rekordzie:
Tytu³, re¿yser, rok produkcji, czas trwania, gatunek, wytwórnia filmowa
Pole Gatunek powinno zawieraæ 5 mo¿liwych do wyboru typów oraz posiadaæ mo¿liwoœæ usuwania, edytowania i dodawania nowych wartoœci. */

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
