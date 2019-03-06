#include "NaglowekGlowny.h"
#include "NaglowekFunkcjeGatunek.h"
#include "NaglowekFunkcjePliki.h"
#include "NaglowekFunkcjeRekord.h"
#include "NaglowekFunkcjeRozne.h"

void WyswietlOpcje(void)
{
    printf("Wybierz jedna z opcji\n\n"
           "1. Dodaj rekord          2. Usun rekord\n"
           "3. Edytuj rekord         4. Sortuj baze\n"
           "5. Zapisz baze do pliku  6. Odczytaj z pliku\n"
           "7. Wyczysc baze          8. Wyswietl Baze\n"
           "9. Wyjdz z programu\n");
}

void WpiszSprawdzLiczby(int *a, int p, int k)
{
    while(1)
    {
        while(scanf("%d",a)!=1 || *a<p || *a>k) //blad jest wtedy jezeli podamy jakis znak drukowany inny niz liczba
        {

                printf("Podana wartosc jest niepoprawna.\n");
            while(getchar()!='\n');
        }
        if(!isspace(getchar())) //jezeli po odczytaniu poprawnej wartosci scanfa w buforze bedzie sie znajdowal jakis znak inny niz spacja, enter, tabulator
        {                       //to wtedy zostanie to odczytane jako blad i zostaniemy poproszeni o ponowne podanie wartosci
                                //czyli np, jak podamy 1a, to do wartosc odczytana przez scnaf bedzie poprawna, ale getchar pobierze 'a' i bedzie blad
                printf("Podana wartosc jest niepoprawna.\nPodaj liczbe odpowiadajaca wybranej przez Ciebie operacji.\n");
            while(getchar()!='\n');
                continue;
        }
        else
            break;
    }
}

void WyswietlNazwy(char t[30],int n)
{
    int i;
    printf("%s",t);
    for(i=0;i<(n-strlen(t));i++)
        printf(" ");
    printf("|");
}

void WybierzSortowanie(Rekord **glowa)
{
    Rekord *pom=(*glowa);
    int a,s;
    if(pom==NULL)
   {
       puts("Baza jest pusta,wiec nie mamy czego sortowac.");
       return;
   }
    printf("Wybierz po ktorym polu rekordu chcesz posortowac katalog.\n"
           "1. Tytul              2. Rezyser\n"
           "3. Rok produkcji      4. Czas trwania\n"
           "5. Gatunek            6. Wytwornia filmowa\n");
    WpiszSprawdzLiczby(&a,1,6);
    puts("Chcesz posortowac rosnaco, czy malejaco ?");
    puts("1. rosnaco   2.malejaco\n");
    puts("Podaj liczbe odpowowiadajaca wybranemu rodzajowi sortowania.");
    WpiszSprawdzLiczby(&s,1,2);
    if(s==1)
    {
        switch(a)
        {
            case 1: Sortowanie(KomparatorRosnacyTytul,glowa);
                    break;
            case 2: Sortowanie(KomparatorRosnacyRezyser,glowa);
                    break;
            case 3: Sortowanie(KomparatorRosnacyRok,glowa);
                    break;
            case 4: Sortowanie(KomparatorRosnacyCzas,glowa);
                    break;
            case 5: Sortowanie(KomparatorRosnacyGatunek,glowa);
                    break;
            case 6: Sortowanie(KomparatorRosnacyWytwornia,glowa);
                    break;
        }
    }
    else
    {
        switch(a)
        {
            case 1: Sortowanie(KomparatorMalejacyTytul,glowa);
                    break;
            case 2: Sortowanie(KomparatorMalejacyRezyser,glowa);
                    break;
            case 3: Sortowanie(KomparatorMalejacyRok,glowa);
                    break;
            case 4: Sortowanie(KomparatorMalejacyCzas,glowa);
                    break;
            case 5: Sortowanie(KomparatorMalejacyGatunek,glowa);
                    break;
            case 6: Sortowanie(KomparatorMalejacyWytwornia,glowa);
                    break;
        }
    }
}

void Sortowanie(int(*komp)(Rekord* s),Rekord **glowa) //funkcja korzysta ze wskaznika na funkcje
{
    Rekord *p;
    int x,i; //pod x przypiszemy liczbe elementow
    x=LiczbaElementow((*glowa));
    if(x==1)
        return;
    p=(*glowa);
    for(i=0;i<x-1;i++)
    {
        if(komp((*glowa)))
        {
            (*glowa)=ZamienDwa((*glowa));
        }

        p=(*glowa);
        while(p->nast->nast!=NULL)
        {

            if(komp(p->nast))
                p->nast=ZamienDwa(p->nast);
            p=p->nast;
        }
    }
}

int KomparatorRosnacyTytul(Rekord *s)
{
    if(strcmp(s->tytul,s->nast->tytul)>0)
        return 1;
    else
        return 0;
}

int KomparatorRosnacyRezyser(Rekord *s)
{
    if(strcmp(s->rezyser,s->nast->rezyser)>0)
        return 1;
    else
        return 0;
}

int KomparatorRosnacyRok(Rekord *s)
{
    return s->rok_prod > s->nast->rok_prod;
}

int KomparatorRosnacyCzas(Rekord *s)
{
    return s->czas_trw > s->nast->czas_trw;
}


int KomparatorRosnacyGatunek(Rekord *s)
{
    if(strcmp(s->gatunek.typ,s->nast->gatunek.typ)>0)
        return 1;
    else
        return 0;
}

int KomparatorRosnacyWytwornia(Rekord *s)
{
    if(strcmp(s->wytw_film,s->nast->wytw_film)>0)
        return 1;
    else
        return 0;
}

int KomparatorMalejacyTytul(Rekord *s)
{
    if(strcmp(s->tytul,s->nast->tytul)<0)
        return 1;
    else
        return 0;
}

int KomparatorMalejacyRezyser(Rekord *s)
{
    if(strcmp(s->rezyser,s->nast->rezyser)<0)
        return 1;
    else
        return 0;
}

int KomparatorMalejacyRok(Rekord *s)
{
    return s->rok_prod < s->nast->rok_prod;
}

int KomparatorMalejacyCzas(Rekord *s)
{
    return s->czas_trw < s->nast->czas_trw;
}

int KomparatorMalejacyGatunek(Rekord *s)
{
    if(strcmp(s->gatunek.typ,s->nast->gatunek.typ)<0)
        return 1;
    else
        return 0;
}

int KomparatorMalejacyWytwornia(Rekord *s)
{
    if(strcmp(s->wytw_film,s->nast->wytw_film)<0)
        return 1;
    else
        return 0;
}

Rekord * ZamienDwa(Rekord * s)
{
	Rekord * t = s->nast;
	s->nast = t->nast;
	t->nast = s;
	return t;
}

void UsunKoniecLiniizfgets(char *t)
{
    char *wsk;
    wsk=t;
    while((*wsk)!='\n')
        wsk++;
    if((*wsk)=='\n')
        (*wsk)='\0';
}

char* PominZnakiNiedrukowane(char *t)
{
    char *wsk;
    wsk=t;
    while(isspace(*wsk))
        wsk++;
    return wsk;
}
