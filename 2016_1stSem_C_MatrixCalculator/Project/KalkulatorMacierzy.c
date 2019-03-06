#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define MAKS_TAB 5 //jest to maksymalny rozmiar obydwu wymiarow kazdej tablicy uzytej w programie

void not(int a, int wez[][MAKS_TAB],int oblicz[][MAKS_TAB]);                              //funkcja do liczenia NOT
void nor(int a, int wez1[][MAKS_TAB], int wez2[][MAKS_TAB],int oblicz[][MAKS_TAB]);       //funkcja do liczenia NOR
void nand(int a, int wez1[][MAKS_TAB], int wez2[][MAKS_TAB],int oblicz[][MAKS_TAB]);      //funkcja do liczenia NAND
void or(int a, int wez1[][MAKS_TAB], int wez2[][MAKS_TAB],int oblicz[][MAKS_TAB]);        //funkcja do liczenia OR
void and(int a, int wez1[][MAKS_TAB], int wez2[][MAKS_TAB],int oblicz[][MAKS_TAB]);       //funkcja do liczenia AND
void xor(int a, int wez1[][MAKS_TAB], int wez2[][MAKS_TAB],int oblicz[][MAKS_TAB]);       //funkcja do liczenia XOR
void wypelnij_macierz(int a, int (wyp)[MAKS_TAB][MAKS_TAB]);                              //funkcja do wypelniania macierzy
void zamien_macierz(int a, int wez[MAKS_TAB][MAKS_TAB], int zamien[MAKS_TAB][MAKS_TAB]);  //funkcja do wpisania wartosci macierzy w inna macierz
void wczytaj(int *a, int p, int k);                                                       //funkcja, ktora wczytuje liczbe i dba o to aby byla poprawna

int main(void)
{
    int rozmiar,operacja,nmdo=1;   // rozmiar macierzy, wybor obliczenia,  nmdo - nowa macierz do obliczen;
    int tab1[MAKS_TAB][MAKS_TAB],tab2[MAKS_TAB][MAKS_TAB],tab3[MAKS_TAB][MAKS_TAB]; //tab1-pierwsza macierz do obliczen, tab2-druga macierz do obliczen
    printf("Wojciech Zielinski ; grupa F2A1\n"                                      //tab3-macierz zapisujaca wynik
            "Kalkulator macierzy kwadratowych pracujacy na liczbach binarnych.\n\n"
            "Najpierw bedziesz musial/a okreslic jaka operacje ma wykonac kalkulator.\n"
            "Nastepnie zostaniesz poproszony/a o podanie rozmiaru macierzy.\n"
            "Ostatnim Twoim zadaniem bedzie wypelnienie pol macierzy liczbami binarnymi.\n"
            "Po wykonaniu obliczen bedziesz mogl je kontynuowac.\n\n");
    //printf("Podaj rozmiar macierzy. Maksymalny rozmiar macierzy to 5.\n");
    //wczytaj(&rozmiar, 1,5);
    printf("\nJaki rodzaj operacji ma byc wykonywany ?\n\n"
           "1) AND    2) OR\n"
           "3) NAND   4) NOR\n"
           "5) XOR    6) NOT\n\n"
           "Podaj liczbe odpowiadajaca wybranej przez Ciebie operacji.\n"
           "Aby zakonczyc wcisnij 7.\n");
    wczytaj(&operacja, 1,7);    //wczytuje numer operacji

    while(operacja != 7)  //program dziala dopoki nie wpiszemy odpowiednich wartosci
    {
        if(nmdo==1) //korzystamy z wyniku otrzymanego w poprzednim obliczeniu
        {
            printf("Podaj rozmiar macierzy. Maksymalny rozmiar macierzy to 5.\n");
            wczytaj(&rozmiar, 1,5);
            if (operacja==6)     // wyplenianie macierzy, gdy NOT
            {
                printf("\nBedziesz musial/a wczytac jedna macierz.\n");
                printf("\nWypelnij macierz.\n");
                wypelnij_macierz(rozmiar, tab1);
            }
            else                 // wypelnianie macierzy gdy nie NOT
            {
                printf("\nBedziesz musial/a wczytac dwie macierze.\n");
                printf("\nWypelnij pierwsza macierz.\n");
                wypelnij_macierz(rozmiar,tab1);
                printf("\nWypelnij druga macierz.\n");
                wypelnij_macierz(rozmiar,tab2);
            }
        }
            else  //korzystamy z wyniku otrzymanego wpoprzednim obliczeniu
        {
            if (operacja!=6) //dla NOTa nie musimy podawac kolejnej macierzy gdy wykorzystujemy poprzedni wynik
            {
                printf("\nBedziesz musial/a wczytac jedna macierz.\n");
                printf("Wypelnij druga macierz.\n");
                wypelnij_macierz(rozmiar,tab2);
            }
        }

        switch (operacja)   //w zaleznosci od podanej wartosci zmiennej 'operacja' program wykonuje odpowiednie dzialanie
        {
            case 1 : and(rozmiar, tab1, tab2, tab3);
                     break;
            case 2 : or(rozmiar, tab1, tab2, tab3) ;
                     break;
            case 3 : nand(rozmiar, tab1, tab2, tab3) ;
                     break;
            case 4 : nor(rozmiar, tab1, tab2, tab3) ;
                     break;
            case 5 : xor(rozmiar, tab1, tab2, tab3) ;
                     break;
            case 6 : not(rozmiar, tab1, tab3);
                     break;
        }
        printf("\nMozesz kontynuowac liczenie wykorzystujac otrzymany wynik\nlub wczytac calkowicie nowe wartosci.\n"
               " Jezeli chcesz uzyc otrzymany wynik podaj  0\n"
               " Jezeli chcesz wczytac calkowicie nowe macierze podaj 1\n"
               " Jezeli chcesz zakonczyc program wczytaj 2\n");
        wczytaj(&nmdo,0,2);
        if(nmdo==2)
            break; //jezeli w tym momencie wczytamy 2, to petla sie zakonczy i nie bedziemy juz mogli wykonywac zadnych obliczen
        if(nmdo==0)
            zamien_macierz(rozmiar, tab3, tab1); //wynik zapisujemy jako pierwsza macierz
        printf("\nJaki rodzaj operacji ma byc wykonywany?\n\n"
               "1) AND    2) OR\n"
               "3) NAND   4) NOR\n"
               "5) XOR    6) NOT\n\n"
               "Podaj liczbe odpowiajaca wybranej przez Ciebie operacji.\n"
               "Aby zakonczyc wcisnij 7.\n");
        scanf("%d",&operacja); //jesli w tym momencie podamy 7 to program zakonczy swoje dzialanie, jezeli dobra wartosc, to petla wykona sie kolejny raz
    }
    return 0;
}

// FUNKCJE

void wczytaj(int *a, int p, int k)
{
    while(1)
    {
        while(scanf("%d",a)!=1 || *a<p || *a>k) //blad jest wtedy jezeli podamy jakis znak drukowany inny niz liczba
        {
            if(p==0 && k==1)
            printf("Podana wartosc jest niepoprawna.\nPodaj 0 lub 1.\n");
            else
            {
                if(k==5) printf("Podana wartosc jest niepoprawna.\nPodaj rozmiar macierzy. Mozesz wczytac 1,2,3,4 lub 5.\n");
                else printf("Podana wartosc jest niepoprawna.\nPodaj liczbe odpowiadajaca wybranej przez Ciebie operacji.\n");
            }
            while(getchar()!='\n');
        }
        if(!isspace(getchar())) //jezeli po odczytaniu poprawnej wartosci scanfa w buforze bedzie sie znajdowal jakis znak inny niz spacja, enter, tabulator
        {                       //to wtedy zostanie to odczytane jako blad i zostaniemy poproszeni o ponowne podanie wartosci
            if(p==0 && k==1)    //czyli np, jak podamy 1a, to do wartosc odczytana przez scnaf bedzie poprawna, ale getchar pobierze 'a' i bedzie blad
                printf("Podana wartosc jest niepoprawna.\nPodaj 0 lub 1.\n");
            else
            {
                if(k==5) printf("Podana wartosc jest niepoprawna.\nPodaj rozmiar macierzy. Mozesz wczytac 1,2,3,4 lub 5.\n");
                else printf("Podana wartosc jest niepoprawna.\nPodaj liczbe odpowiadajaca wybranej przez Ciebie operacji.\n");
            }
            while(getchar()!='\n');
                continue;
        }
        else
            break;
    }
}

void wypelnij_macierz(int a, int wyp[MAKS_TAB][MAKS_TAB])  //a to rozmiar macierzy
{
    int i,j,b;    /* i-wiersze j-kolumny */
    printf("Ilosc bitow do wczytania to %d.\n\n",a*a);
    for(i=0;i<a;i++)
        for(j=0;j<a;j++)
        {
            printf("Wiersz nr %d. Kolumna numer %d. Podaj 0 lub 1.\n",i+1,j+1);
            //scanf("%d",&b);
            wczytaj(&b,0,1); //korzystamy z funkcji wczytaj aby wypelnic kolejne pola macierzy
            wyp[i][j]=b;
        }
}
void zamien_macierz(int a, int wez[MAKS_TAB][MAKS_TAB], int zamien[MAKS_TAB][MAKS_TAB])

{
    int i,j;
    printf("\nPierwsza macierz do kolejnych obliczen to:\n");
    for(i=0;i<a;i++)
        {
        for(j=0;j<a;j++)
        {
            zamien[i][j]=wez[i][j]; //na odpowiednich miejscach tablica zamien przyjmuje wartosci tablicy wez
            printf("%2d",zamien[i][j]); // wyswietlamy macierz po zamianie
        }
        printf("\n");
        }
}

void not(int a ,int wez[MAKS_TAB][MAKS_TAB], int oblicz[MAKS_TAB][MAKS_TAB])
{
    int i,j;
    printf("\nOtrzymany wynik to:\n\n");
    for(i=0;i<a;i++)
    {
        for(j=0;j<a;j++)
        {
            oblicz[i][j]=!(wez[i][j]); //operacja logiczna NOT
            printf("%2d",oblicz[i][j]);
        }
        printf("\n");
    }
}

void and(int a, int wez1[MAKS_TAB][MAKS_TAB], int wez2[MAKS_TAB][MAKS_TAB], int oblicz[MAKS_TAB][MAKS_TAB])
{
    int i,j;
    printf("\nOtrzymany wynik to:\n\n");
    for(i=0;i<a;i++)
    {
        for(j=0;j<a;j++)
        {
            oblicz[i][j]=wez1[i][j] && wez2[i][j]; //operacja logiczna AND
            printf("%2d",oblicz[i][j]);
        }
        printf("\n");
    }
}

void or(int a, int wez1[MAKS_TAB][MAKS_TAB], int wez2[MAKS_TAB][MAKS_TAB], int oblicz[MAKS_TAB][MAKS_TAB])
{
    int i,j;
    printf("\nOtrzymany wynik to:\n\n");
    for(i=0;i<a;i++)
    {
        for(j=0;j<a;j++)
        {
            oblicz[i][j]=wez1[i][j] || wez2[i][j];  //operacja logiczna OR
            printf("%2d",oblicz[i][j]);
        }
        printf("\n");
    }
}

void nand(int a, int wez1[MAKS_TAB][MAKS_TAB], int wez2[MAKS_TAB][MAKS_TAB], int oblicz[MAKS_TAB][MAKS_TAB])
{
    int i,j;
    printf("\nOtrzymany wynik to:\n\n");
    for(i=0;i<a;i++)
    {
        for(j=0;j<a;j++)
        {
            oblicz[i][j]=!(wez1[i][j] && wez2[i][j]); //operacja logiczna NAND
            printf("%2d",oblicz[i][j]);
        }
        printf("\n");
    }
}

void nor(int a, int wez1[MAKS_TAB][MAKS_TAB], int wez2[MAKS_TAB][MAKS_TAB], int oblicz[MAKS_TAB][MAKS_TAB])
{
    int i,j;
    printf("\nOtrzymany wynik to:\n\n");
    for(i=0;i<a;i++)
    {
        for(j=0;j<a;j++)
        {
            oblicz[i][j]=!(wez1[i][j] || wez2[i][j]); //operacja logiczna NOR
            printf("%2d",oblicz[i][j]);
        }
        printf("\n");
    }
}

void xor(int a, int wez1[MAKS_TAB][MAKS_TAB], int wez2[MAKS_TAB][MAKS_TAB], int oblicz[MAKS_TAB][MAKS_TAB])
{
    int i,j;
    printf("\nOtrzymany wynik to:\n\n");
    for(i=0;i<a;i++)
    {
        for(j=0;j<a;j++)
        {
            oblicz[i][j]=(wez1[i][j] && !(wez2[i][j])) ||  (!(wez1[i][j]) && wez2[i][j] ); //operacja logiczna XOR
            printf("%2d",oblicz[i][j]);
        }
        printf("\n");
    }
}
