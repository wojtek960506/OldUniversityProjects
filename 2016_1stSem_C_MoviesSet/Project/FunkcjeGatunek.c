#include "NaglowekGlowny.h"
#include "NaglowekFunkcjeGatunek.h"
#include "NaglowekFunkcjePliki.h"
#include "NaglowekFunkcjeRekord.h"
#include "NaglowekFunkcjeRozne.h"

void PierwotnyGatunek(Gatunek **glowaG)
{
    Gatunek *gat;
    Gatunek *pG;
    int i;
    for(i=0;i<5;i++)
    {
        gat=(Gatunek*)malloc(sizeof(Gatunek));
        gat->nast=NULL;
        switch(i)
        {
            case 0: strcpy(gat->typ,"komedia");
                    break;
            case 1: strcpy(gat->typ,"akcji");
                    break;
            case 2: strcpy(gat->typ,"przygodowy");
                    break;
            case 3: strcpy(gat->typ,"animowany");
                    break;
            case 4: strcpy(gat->typ,"dramat");
                    break;
        }
        pG=(*glowaG);
        if(pG==NULL)
            (*glowaG)=gat;
        else
        {
            while(pG->nast!=NULL)
                pG=pG->nast;
            pG->nast=gat;
        }
    }
}

void WyswietlGatunek(Gatunek *glowaG)
{
    Gatunek *wsk_gat=glowaG;
    int i=1;
    char *pomocniczy;
    if(wsk_gat==NULL)
    {
        //puts("\nNie ma zadnego gatunku do wyboru !!! Musisz dodac wlasny.");
        return;
    }
    while(wsk_gat->nast!=NULL)
    {
        printf("%d. ",i);
        pomocniczy=wsk_gat->typ;     //operacja do usuwania spacji
        pomocniczy=PominZnakiNiedrukowane(pomocniczy);
        fputs(pomocniczy,stdout);
        puts("");
        wsk_gat=wsk_gat->nast;
        i++;
    }
    printf("%d. ",i);
    pomocniczy=wsk_gat->typ;
    pomocniczy=PominZnakiNiedrukowane(pomocniczy);
    fputs(pomocniczy,stdout);
    printf("\n\n");
}

void UsunPierwszyG(Gatunek **glowaG)
{
    Gatunek *pG=(*glowaG);
    (*glowaG) = pG->nast;
    free(pG);
}

void UsunGatunek(Gatunek **glowaG)
{
    int i,r,x,a; //i-licznik,r-numer usuwanego rekordu,x-dotzchcyasowa liczba rekordow,a-do wyboru tak/nie

    Gatunek *pom;
    Gatunek *pG;
    x=LiczbaElementowG((*glowaG));
    pG=(*glowaG);
    if(pG==NULL)
    {
        puts("Nie ma zadnych dostepnych gatunkow, wiec nie mozemy niczego usunac. Musisz dodac wlasny gatunek !!!");
        return;
    }
    printf("Liczba dostepnych gatunkow to: %d.\n",x);
    printf("Ktory gatunek chcesz usunac? Maksymalny numer to %d.\n",x);
    WpiszSprawdzLiczby(&r,1,x);

    if(r==1)
    {
        puts("Czy na pewno chcesz usunac ten gatunek?\n1 - Tak  2 - Nie");
        WpiszSprawdzLiczby(&a,1,2);
        if(a==2)
            return;
        else
            UsunPierwszyG(glowaG);
    }
    else
    {
        puts("Czy na pewno chcesz usunac ten rekord?\n1 - Tak  2 - Nie");
        WpiszSprawdzLiczby(&a,1,2);
        if(a==2)
            return;
        else
        {
            pG=(*glowaG);
            for(i=1;i<r-1;i++)
                pG=pG->nast;
            pom=pG->nast;
            pG->nast=pom->nast;
            free(pom);
        }
    }
}

void DodajGatunek(Gatunek **glowaG)
{
        Gatunek *gat;
        Gatunek *pG;
        gat=(Gatunek*)malloc(sizeof(Gatunek));
        gat->nast=NULL;
        puts("Podaj nowy gatunek");
        fgets(gat->typ,30,stdin);
        UsunKoniecLiniizfgets(gat->typ);
        //scanf("%s",&gat->typ);
        pG=(*glowaG);
        if(pG==NULL)
            (*glowaG)=gat;
        else
        {
            while(pG->nast!=NULL)
                pG=pG->nast;
            pG->nast=gat;
        }
}

void EdytujGatunek(Gatunek *glowaG)
{
    Gatunek *pG;
    int x,rekord,i;
    pG=glowaG;
    if(pG==NULL)
    {
        puts("Nie ma zadnych dostepnych gatunkow, wiec nie ma czago edytowac. Musisz dodac wlasny gatunek !!!");
        return;
    }
    x=LiczbaElementowG(glowaG);
    printf("Ktory gatunek chcesz edytowac? Maksymalny numer to %d.\n",x);
    WpiszSprawdzLiczby(&rekord,1,x);
    for(i=0;i<rekord-1;i++)
        pG=pG->nast;
    puts("Teraz mozesz edytowac wybrany gatunek");
    fgets(pG->typ,30,stdin);
    UsunKoniecLiniizfgets(pG->typ);
}

int LiczbaElementowG(Gatunek *glowaG) //dla struktury gatunek
{
    Gatunek *wsk=glowaG;
    int i=0;
    while(wsk)
    {
        i++;
        wsk=wsk->nast;
    }
    return i;
}

Gatunek* PrzejdzDo(int n,Gatunek *glowaG) //przechodzi po liscie do danego elementu
{
    Gatunek *pG;
    int i=0;
    pG=glowaG;
    for(i=0;i<n-1;i++)
        pG=pG->nast;
    return pG;
}

char* WyborGatunku(Gatunek *glowaG) //wybieramy gatunek i zapisujemy do niego to co jest w danym polu
{
    char tekst[30];
    char *pom;
    Gatunek **pG=NULL;
    int n,x; // n-zmienna do wyboru numeru
    x=LiczbaElementowG((glowaG));
    if(x==0)
    {
        puts("Nie ma zadnych dostepnych gatunkow. Musisz dodac wlasny !!!");
        return NULL;
    }
    printf("Podaj numer gatunku, ktory wybierasz. Maksymalny numer to %d.\n",x);
    WpiszSprawdzLiczby(&n,1,x);

    (*pG)=PrzejdzDo(n,glowaG);

    strcpy(tekst,(*pG)->typ);
    pom=tekst;
    return pom;

}
