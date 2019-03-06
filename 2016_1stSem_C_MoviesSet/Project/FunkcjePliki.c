#include "NaglowekGlowny.h"
#include "NaglowekFunkcjeGatunek.h"
#include "NaglowekFunkcjePliki.h"
#include "NaglowekFunkcjeRekord.h"
#include "NaglowekFunkcjeRozne.h"

void CzytanieZnaku(char t[2],char znak,char pom[50],FILE *wp)
{
    strcpy(pom,"");
    znak=getc(wp);
    while(znak!='|')
    {
        t[0]=znak;
        t[1]='\0';
        strcat(pom,t);
        znak=getc(wp);
    }
}

void ZapiszNazwy(char t[30],int n, FILE *wp)
{
    int i;
    fprintf(wp,"%s",t);
    for(i=0;i<(n-strlen(t));i++)
        fprintf(wp," ");
    fprintf(wp,"|");
}

void ZapiszDoPliku(Rekord *glowa)
{
    Rekord *obecny;
    FILE *wp;
    char nazwa[30];
    char *wsk;
    int x;
    obecny=glowa;
    if(obecny==NULL)
    {
        puts("Baza jest pusta. Nie mamy czego zapisac do pliku.");
        return;
    }
    puts("Podaj nazwe pliku, do ktorego chcesz zapisac katalog z filmami.");
    gets(nazwa);
    if(strcmp(nazwa,"filemon")==0)
    {
        puts("Taka nazwa pliku jest niemozliwa. Zapisywanie nie bedzie kontynuowane.");
        return;
    }
    wsk=nazwa;
    while((*wsk)!='\0')
    {
        if(ispunct(*wsk))
        {
            puts("Niepoprawna nazwa pliku. Zapisywanie nie bedzie kontynuowane.");
            return;
        }
        wsk++;
    }
    strcat(nazwa,".txt");
    wp=fopen(nazwa,"w");
    x=LiczbaElementow(glowa);
    fprintf(wp,"%d|",x);
    while(obecny->nast!=NULL)
    {
        ZapiszNazwy(obecny->tytul,28,wp);
        ZapiszNazwy(obecny->rezyser,28,wp);
        fprintf(wp,"%d",obecny->rok_prod);
        ZapiszNazwy("",8,wp);
        fprintf(wp,"%d",obecny->czas_trw);
        if(obecny->czas_trw<10)
            ZapiszNazwy("",10,wp);
        else
        {
            if(obecny->czas_trw<100)
                ZapiszNazwy("",9,wp);
            else
                ZapiszNazwy("",8,wp);
        }
        ZapiszNazwy(obecny->gatunek.typ,28,wp);
        ZapiszNazwy(obecny->wytw_film,28,wp);
        obecny=obecny->nast;
    }
    ZapiszNazwy(obecny->tytul,28,wp);
    ZapiszNazwy(obecny->rezyser,28,wp);
    fprintf(wp,"%d",obecny->rok_prod);
    ZapiszNazwy("",8,wp);
    fprintf(wp,"%d",obecny->czas_trw);
    if(obecny->czas_trw<10)
        ZapiszNazwy("",10,wp);
    else
    {
        if(obecny->czas_trw<100)
            ZapiszNazwy("",9,wp);
        else
            ZapiszNazwy("",8,wp);
    }
    ZapiszNazwy(obecny->gatunek.typ,28,wp);
    ZapiszNazwy(obecny->wytw_film,28,wp);
    fclose(wp);

}

void WczytajZPliku(Rekord **glowa)
{
    Rekord *obecny;
    FILE *wp;
    int i=0;

    obecny=(Rekord*)malloc(sizeof(Rekord));
    obecny->nast=NULL;
    (*glowa)=obecny;


    char nazwa[30];
    char pom[50];
    char sprawdz[50];
    char znak;
    char t[2];
    int liczba,numer;
    puts("Podaj nazwe pliku z ktorego maja byc odczytane dane.");
    fgets(nazwa,30,stdin);
    UsunKoniecLiniizfgets(nazwa);
    if(strcmp(nazwa,"filmy") && strcmp(nazwa,"pokaz"))
    {
        puts("Podales bledna nazwe pliku. Wczytywanie zostaje przerwane.");
        return;
    }
    strcat(nazwa,".txt");
    wp=fopen(nazwa,"rt");
    fscanf(wp,"%d",&numer);
    CzytanieZnaku(t,znak,pom,wp);
    while(i!=numer)
    {

        CzytanieZnaku(t,znak,pom,wp);
        strcpy(obecny->tytul,pom); //wczytano tytul
        CzytanieZnaku(t,znak,pom,wp);
        strcpy(obecny->rezyser,pom);


        fscanf(wp,"%d",&liczba);
        obecny->rok_prod=liczba;
        CzytanieZnaku(t,znak,pom,wp); //czyta przestrzen pomiedzy liczbami
        fscanf(wp,"%d",&liczba);
        obecny->czas_trw=liczba;
        CzytanieZnaku(t,znak,pom,wp); //czyta przestrzen pomiedzy liczbami
        CzytanieZnaku(t,znak,pom,wp);
        strcpy(obecny->gatunek.typ,pom);
        CzytanieZnaku(t,znak,pom,wp);
        strcpy(obecny->wytw_film,pom);
        if(i!=numer-1)
        {
            obecny->nast=(Rekord*)malloc(sizeof(Rekord));
            obecny=obecny->nast;
            obecny->nast=NULL;
        }
        else
            obecny->nast=NULL;
        i++;
    }
        fclose(wp);
}
