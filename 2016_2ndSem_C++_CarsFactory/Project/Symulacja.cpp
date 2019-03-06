#include "Fabryka.hpp"


void czekaj2(int sekundy);

int main()
{
	
	//instalujemy stanowiska do produkcji opon
	ProdukcjaOpon prodopon1(2);   
	ProdukcjaOpon prodopon2(3);
	ProdukcjaOpon prodopon3(4);
	ProdukcjaOpon prodopon4(5);
	
	//instalujemy stanowiska do produkcji karoserii
	ProdukcjaKaroserii prodkar1(0);
	ProdukcjaKaroserii prodkar2(1);
	
	//instalujemy stanowiska do produkcji silnikow
	ProdukcjaSilnikow prodsilnik1(6);
	ProdukcjaSilnikow prodsilnik2(7);
	
	//instalujemy stanowiska do malowania karoserii
	
	MalowanieKaroserii malkar1(8);
	MalowanieKaroserii malkar2(9);
	
	//instalujemy stanowiska montujace opony do karoserii
	OponyWKaroserii oponwkar1(10);
	OponyWKaroserii oponwkar2(11);
	
	
	//instalujemy stanowiska montujace silniki w karoserii
	SilnikWKaroserii silnikwkar1(12);
	SilnikWKaroserii silnikwkar2(13);
	
	
	//instalujemy stanowiska montuajce elektronike w karoserii
	ElektronikaWKaroserii elektrwkar1(14);
	ElektronikaWKaroserii elektrwkar2(15);
	
	//ustalamy polaczenia miedzy stanowiskami
	Graf graf;
	//graf.StworzGraf();
	graf.DodajStanowisko(&prodkar1);	 //0
	graf.DodajStanowisko(&prodkar2);	 //1
	graf.DodajStanowisko(&prodopon1);	 //2
	graf.DodajStanowisko(&prodopon2);	 //3
	graf.DodajStanowisko(&prodopon3);	 //4
	graf.DodajStanowisko(&prodopon4);	 //5
	graf.DodajStanowisko(&prodsilnik1);  //6
	graf.DodajStanowisko(&prodsilnik2);  //7
	graf.DodajStanowisko(&malkar1);	 //8
	graf.DodajStanowisko(&malkar2);	 //9
	graf.DodajStanowisko(&oponwkar1);	 //10
	graf.DodajStanowisko(&oponwkar2);	 //11
	graf.DodajStanowisko(&silnikwkar1);  //12
	graf.DodajStanowisko(&silnikwkar2);  //13
	graf.DodajStanowisko(&elektrwkar1);  //14
	graf.DodajStanowisko(&elektrwkar2);  //15
	
	graf.DodajKrawedz(&prodkar1, &malkar1);		//0
	graf.DodajKrawedz(&prodkar1, &malkar2);		//1
	graf.DodajKrawedz(&prodkar2, &malkar1);		//2
	graf.DodajKrawedz(&prodkar2, &malkar2);		//3
	graf.DodajKrawedz(&prodopon1, &oponwkar1);	//4
	graf.DodajKrawedz(&prodopon1, &oponwkar2);	//5
	graf.DodajKrawedz(&prodopon2, &oponwkar1);	//6
	graf.DodajKrawedz(&prodopon2, &oponwkar2);	//7
	graf.DodajKrawedz(&prodopon3, &oponwkar1);	//8
	graf.DodajKrawedz(&prodopon3, &oponwkar2);	//9
	graf.DodajKrawedz(&prodopon4, &oponwkar1);	//10
	graf.DodajKrawedz(&prodopon4, &oponwkar2);	//11
	graf.DodajKrawedz(&prodsilnik1, &silnikwkar1);  //12
	graf.DodajKrawedz(&prodsilnik1, &silnikwkar2);  //13
	graf.DodajKrawedz(&prodsilnik2, &silnikwkar1);  //14
	graf.DodajKrawedz(&prodsilnik2, &silnikwkar2);  //15
	graf.DodajKrawedz(&malkar1, &oponwkar1);		//16
	graf.DodajKrawedz(&malkar1, &oponwkar2);		//17
	graf.DodajKrawedz(&malkar2, &oponwkar1);		//18 
	graf.DodajKrawedz(&malkar2, &oponwkar2);		//19
	graf.DodajKrawedz(&oponwkar1, &silnikwkar1);	//20
	graf.DodajKrawedz(&oponwkar1, &silnikwkar2);	//21
	graf.DodajKrawedz(&oponwkar2, &silnikwkar1);	//22
	graf.DodajKrawedz(&oponwkar2, &silnikwkar2);	//23
	graf.DodajKrawedz(&silnikwkar1, &elektrwkar1);  //24
	graf.DodajKrawedz(&silnikwkar1, &elektrwkar2);  //25
	graf.DodajKrawedz(&silnikwkar2, &elektrwkar1);  //26
	graf.DodajKrawedz(&silnikwkar2, &elektrwkar2);  //27
	
	ofstream plik;
	plik.open("dane.txt");
		
	for(int q=0;q<25;q++)
	{	
		
		for(int a=0;a<1;a++)
		{
			graf.Dzialaj(0);
			graf.Dzialaj(1);
			graf.Dzialaj(2);
			graf.Dzialaj(3);
			graf.Dzialaj(4);
			graf.Dzialaj(5);
			graf.Dzialaj(6);
			graf.Dzialaj(7);
		}
		
		for(int b=0;b<1;b++)
		{	
			graf.Wez(8);
			graf.Dzialaj(8);
			graf.Wez(9);
			graf.Dzialaj(9);
		}
		for(int c=0;c<1;c++)
		{
			graf.Wez(10);
			graf.Dzialaj(10);
			graf.Wez(11);
			graf.Dzialaj(11);
		}
		for(int d=0;d<1;d++)
		{
			graf.Wez(12);
			graf.Dzialaj(12);
			graf.Wez(13);
			graf.Dzialaj(13);
		}
		for(int e=0;e<1;e++)
		{
			graf.Wez(14);
			graf.Dzialaj(14);
			graf.Wez(15);
			graf.Dzialaj(15);
		}
		czekaj2(1);
	}
	
	
	return 0;
}

void czekaj2(int sekundy)
{
	clock_t koniec = clock() + sekundy * CLOCKS_PER_SEC;
	while(clock() < koniec) continue;
}
