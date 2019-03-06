#include "NaglowekGlowny.h"
#include "NaglowekFunkcjeGatunek.h"
#include "NaglowekFunkcjePliki.h"
#include "NaglowekFunkcjeRekord.h"
#include "NaglowekFunkcjeRozne.h"

void DodajRekord(Rekord **glowa,Gatunek **glowaG)
{
    Rekord *obecny;
    Rekord *p;
    char *pom;
    int wybierz;
    p=(*glowa);
    obecny=(Rekord*)malloc(sizeof(Rekord));
    obecny->nast=NULL;
    puts("Dodano rekord. Wypelnij dane dotyczace danego filmu.");
    puts("Podaj tytul.");
    fgets(obecny->tytul,30,stdin);
    UsunKoniecLiniizfgets(obecny->tytul);
    puts("Podaj rezysera filmu.");
    fgets(obecny->rezyser,30,stdin);
    UsunKoniecLiniizfgets(obecny->rezyser);
    puts("Podaj rok produkcji filmu.");
    WpiszSprawdzLiczby(&obecny->rok_prod,1950,2016);
    puts("Podaj czas trwania filmu (w minutach).");
    WpiszSprawdzLiczby(&obecny->czas_trw,0,400);
    WyswietlGatunek((*glowaG));
    puts("Z polem  Gatunek zwiazane jest kilka dodatkowych mozliwosci.");
    puts("1. Wybierz z dostepnych 2. Dodaj nowy gatunek");
    puts("3. Usun gatunek         4. Edytuj gatunek");
    WpiszSprawdzLiczby(&wybierz,1,4);
    while(wybierz!=1)
    {
        switch(wybierz)
        {
            case 2: DodajGatunek(glowaG);
                    break;
            case 3: UsunGatunek(glowaG);
                    break;
            case 4: EdytujGatunek((*glowaG));
                    break;
        }
        WyswietlGatunek((*glowaG));
        puts("Mozesz nadal wykonywac operacje zwiazanem z polem Gatunek.");
        puts("1. Wybierz z dostepnych 2. Dodaj nowy gatunek");
        puts("3. Usun gatunek         4. Edytuj gatunek");
        WpiszSprawdzLiczby(&wybierz,1,4);
    }
    pom=WyborGatunku((*glowaG));
    strcpy(obecny->gatunek.typ,pom);
    puts(obecny->gatunek.typ);
    puts("Wytwornia filmowa");
    fgets(obecny->wytw_film,30,stdin);
    UsunKoniecLiniizfgets(obecny->wytw_film);
    if ((*glowa) == NULL)
		(*glowa)=obecny;
    else
    {
        while(p->nast!=NULL)
            p=p->nast;
        p->nast=obecny;
	}

}

void UsunPierwszy(Rekord **glowa)
{
    Rekord *p;
    p=(*glowa);
    (*glowa) = p->nast;
    free(p);
}

void UsunRekord(Rekord **glowa)
{
    Rekord *p;
    int i,r,x,a; //i-licznik,r-numer usuwanego rekordu,x-dotzchcyasowa liczba rekordow,a-do wyboru tak/nie

    Rekord *pom;
    x=LiczbaElementow((*glowa));
    p=(*glowa);
    if(p==NULL)
    {
        puts("Baza jest pusta. Nie mozemy niczego usunac");
        return;
    }
    printf("Liczba elementow w liscie to: %d.\n",x);
    printf("Ktory rekord chcesz usunac? Maksymalny numer to %d.\n",x);
    WpiszSprawdzLiczby(&r,1,x);

    if(r==1)
    {
        puts("Czy na pewno chcesz usunac ten rekord?\n1 - Tak  2 - Nie");
        WpiszSprawdzLiczby(&a,1,2);
        if(a==2)
            return;
        else
            UsunPierwszy(glowa);
    }
    else
    {
        puts("Czy na pewno chcesz usunac ten rekord?\n1 - Tak  2 - Nie");
        WpiszSprawdzLiczby(&a,1,2);
        if(a==2)
            return;
        else
        {
            p=(*glowa);
            for(i=1;i<r-1;i++)
                p=p->nast;
            pom=p->nast;
            p->nast=pom->nast;
            free(pom);
        }
    }
}

void EdytujRekord(Rekord *glowa,Gatunek *glowaG)
{
    Rekord *p;
    int x,rekord,i;

    p=glowa;
    if(p==NULL)
    {
        puts("Baza jest pusta, wiec nie ma czago edytowac.");
        return;
    }
    x=LiczbaElementow(glowa);
    printf("Ktory rekord chcesz edytowac? Maksymalny numer to %d.\n",x);
    WpiszSprawdzLiczby(&rekord,1,x);
    for(i=0;i<rekord-1;i++)
        p=p->nast;
    PomocniczaEdycja(&p,&glowaG);
}

void PomocniczaEdycja(Rekord **obecny,Gatunek **glowaG)
{
    char *pom;
    int a;
    puts("Czy chcesz edytowac tytul?\n1- Tak  2 - Nie");
    WpiszSprawdzLiczby(&a,1,2);
    if(a==1)
    {
        puts("Podaj nowy tytul.");
        fgets((*obecny)->tytul,30,stdin);
        UsunKoniecLiniizfgets((*obecny)->tytul);
    }
    puts("Czy chcesz edytowac rezysera?\n1- Tak  2 - Nie");
    WpiszSprawdzLiczby(&a,1,2);
    if(a==1)
    {
        puts("Podaj nowego rezysera.");
        fgets((*obecny)->rezyser,30,stdin);
        UsunKoniecLiniizfgets((*obecny)->rezyser);
    }
    puts("Czy chcesz edytowac rok produkcji?\n1- Tak  2 - Nie");
    WpiszSprawdzLiczby(&a,1,2);
    if(a==1)
    {
        puts("Podaj nowy rok produkcji.");
        WpiszSprawdzLiczby(&(*obecny)->rok_prod,1950,2016);;
    }
    puts("Czy chcesz edytowac czas trwania?\n1- Tak  2 - Nie");
    WpiszSprawdzLiczby(&a,1,2);
    if(a==1)
    {
        puts("Podaj nowy czas trwania.");
        WpiszSprawdzLiczby(&(*obecny)->czas_trw,0,400);
    }
    puts("Czy chcesz edytowac gatunek?\n1- Tak  2 - Nie");
    WpiszSprawdzLiczby(&a,1,2);
    if(a==1)
    {
        int wybierz;
        WyswietlGatunek((*glowaG));
        puts("Z polem  Gatunek zwiazane jest kilka dodatkowych mozliwosci.");
        puts("1. Wybierz z dostepnych 2. Dodaj nowy gatunek");
        puts("3. Usun gatunek         4. Edytuj gatunek");
        WpiszSprawdzLiczby(&wybierz,1,4);
        while(wybierz!=1)
        {
            switch(wybierz)
            {
                case 2: DodajGatunek(&(*glowaG));
                        break;
                case 3: UsunGatunek(&(*glowaG));
                        break;
                case 4: EdytujGatunek((*glowaG));
                        break;
            }
            WyswietlGatunek((*glowaG));
            puts("Mozesz nadal wykonywac operacje zwiazanem z polem Gatunek.");
            puts("1. Wybierz z dostepnych 2. Dodaj nowy gatunek");
            puts("3. Usun gatunek         4. Edytuj gatunek");
            WpiszSprawdzLiczby(&wybierz,1,4);
        }
        pom=WyborGatunku((*glowaG));
        strcpy((*obecny)->gatunek.typ,pom);
        puts((*obecny)->gatunek.typ);
    }
    puts("Czy chcesz edytowac wytwornie filmowa?\n1- Tak  2 - Nie");
    WpiszSprawdzLiczby(&a,1,2);
    if(a==1)
    {
        puts("Podaj nowa wytwornie filmowa.");
        fgets((*obecny)->wytw_film,30,stdin);
        UsunKoniecLiniizfgets((*obecny)->wytw_film);
    }
}

void WyczyscBaze(Rekord **glowa)
{
    Rekord *p;
    int a;

    if((*glowa)==NULL)
    {
        puts("Baza juz byla pusta.");
        return;
    }
    puts("Czy na pewno chcesz wyczyscic baze?\n1 - Tak  2 - Nie");
        WpiszSprawdzLiczby(&a,1,2);
    if(a==2)
        return;
    p=(*glowa)->nast;
    while((*glowa)->nast!=NULL)
    {
        p=(*glowa)->nast;
        (*glowa)->nast=p->nast;
        free(p);
    }
    (*glowa)=NULL;
    puts("\nBaza zostala wyczyszczona.");
}

void WyswietlBaze(Rekord *glowa)
{
    Rekord *wsk_pomoc = glowa;
	int i = 1;
    if(wsk_pomoc==NULL)
    {
        puts("Baza jest pusta.");
        return;
    }
    printf("    |");
    WyswietlNazwy("Tytul",30);
    WyswietlNazwy("Rezyser",30);
    WyswietlNazwy("Rok produkcji",14);
    WyswietlNazwy("Czas trwania",13);
    WyswietlNazwy("Gatunek",30);
    WyswietlNazwy("Wytwornia filmowa",30);
    puts("\n");
	while(wsk_pomoc -> nast != 0)
	{
		printf("%2d. |",i);
        WyswietlNazwy(wsk_pomoc->tytul,30);
        WyswietlNazwy(wsk_pomoc->rezyser,30);
        printf("%d",wsk_pomoc->rok_prod);
        WyswietlNazwy("",10);
        printf("%d",wsk_pomoc->czas_trw);
        if(wsk_pomoc->czas_trw<10)
            WyswietlNazwy("",12);
        else
        {
            if(wsk_pomoc->czas_trw<100)
                WyswietlNazwy("",11);
            else
                WyswietlNazwy("",10);
        }
        WyswietlNazwy(wsk_pomoc->gatunek.typ,30);
        WyswietlNazwy(wsk_pomoc->wytw_film,30);
        puts("");
		wsk_pomoc = wsk_pomoc -> nast;
		i++;
	}
        printf("%2d. |",i);
        WyswietlNazwy(wsk_pomoc->tytul,30);
        WyswietlNazwy(wsk_pomoc->rezyser,30);
        printf("%d",wsk_pomoc->rok_prod);
        WyswietlNazwy("",10);
        printf("%d",wsk_pomoc->czas_trw);
        if(wsk_pomoc->czas_trw<10)
            WyswietlNazwy("",12);
        else if(wsk_pomoc->czas_trw<100)
            WyswietlNazwy("",11);
        else
            WyswietlNazwy("",10);
        WyswietlNazwy(wsk_pomoc->gatunek.typ,30);
        WyswietlNazwy(wsk_pomoc->wytw_film,30);
        puts("");
		wsk_pomoc = wsk_pomoc -> nast;
}

int LiczbaElementow(Rekord *glowa) //dla struktury rekord
{
    Rekord *wsk=glowa;
    int i=0;
    while(wsk)
    {
        i++;
        wsk=wsk->nast;
    }
    return i;
}
