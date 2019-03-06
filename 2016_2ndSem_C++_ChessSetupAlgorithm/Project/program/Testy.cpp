#include "Szachy.hpp"

using namespace std;

const int DLUGOSC=3;
const int SZEROKOSC=3;
const int P=0; //2
const int S=0; //3
const int G=0; //1
const int W=2; //0
const int H=0; //1
const int K=2; //3

bool wczytajPlik(std::string nazwaPliku,int & dl,int & szer, int & p, int & s, int & g, int & w, int & h, int & k);

int main()
{	
	int dl,szer,p,s,g,w,h,k;
	int menu;
	int pom;
	
	cout<<"MENU GLOWNE PROGRAMU"<<endl;
	cout<<"Jesli chcesz wczytac dane z pliku, podaj liczbe calkowita od 1 do 5."<<endl;
	cout<<"1 -> test1.txt"<<endl;
	cout<<"2 -> test2.txt"<<endl;
	cout<<"3 -> test3.txt"<<endl;
	cout<<"4 -> test4.txt"<<endl;
	cout<<"5 -> test5.txt"<<endl;
	cout<<"Jesli chcesz wczytac dane z klawiatury, wpisz 6."<<endl;
	cout<<"Jesli chcesz zakonczyc dzialanie programu, wpisz 7"<<endl;
	cin>>menu;
	
	while (menu!=7)
	{
		switch(menu)
		{
			case 1:	if (!wczytajPlik("test1.txt",dl,szer,p,s,g,w,h,k))
					{	
						pom=0;
				  		cout<<"nie udalo sie poprawnie odczytac danych"<<endl;
				  	}
					else
			 		  	pom=1;
			 		break;
			 case 2:	if (!wczytajPlik("test2.txt",dl,szer,p,s,g,w,h,k))
					{	
						pom=0;
				  		cout<<"nie udalo sie poprawnie odczytac danych"<<endl;
				  	}
					else
			 		  	pom=1;
			 		break;
			 case 3:	if (!wczytajPlik("test3.txt",dl,szer,p,s,g,w,h,k))
					{	
						pom=0;
				  		cout<<"nie udalo sie poprawnie odczytac danych"<<endl;
				  	}
					else
			 		  	pom=1;
			 		break;
			 case 4:	if (!wczytajPlik("test4.txt",dl,szer,p,s,g,w,h,k))
					{	
						pom=0;
				  		cout<<"nie udalo sie poprawnie odczytac danych"<<endl;
				  	}
					else
			 		  	pom=1;
			 		break;
			 case 5:	if (!wczytajPlik("test5.txt",dl,szer,p,s,g,w,h,k))
					{	
						pom=0;
				  		cout<<"nie udalo sie poprawnie odczytac danych"<<endl;
				  	}
					else
			 		  	pom=1;
			 		break;
			 case 6:	cout<<"Podaj dlugosc planszy"<<endl;
			 		cin>>dl;
			 		cout<<"Podaj szerokosc planszy"<<endl;
			 		cin>>szer;
			 		cout<<"Podaj ilosc pionkow do ustawienia"<<endl;
			 		cin>>p;
			 		cout<<"Podaj ilosc koni do ustawienia"<<endl;
					cin>>s;
					cout<<"Podaj ilosc goncow do ustawienia"<<endl;
					cin>>g;
					cout<<"Podaj ilosc wiez do ustawienia"<<endl;
					cin>>w;
					cout<<"Podaj ilosc hetmanow do ustawienia"<<endl;
					cin>>h;
					cout<<"Podaj ilosc kroli do ustawienia"<<endl;
					cin>>k;
					pom=1;
					break;
		}
		if (pom == 0)
		cout<<"nie udalo sie poprawnie odczytac danych"<<endl;
		else
		{
			cout<<"Dlugosc planszy: "<<dl<<endl;
			cout<<"Szerokosc planszy: "<<szer<<endl;
			cout<<"Ilosc pionkow: "<<p<<endl;
			cout<<"Ilosc koni: "<<s<<endl;
			cout<<"Ilosc goncow: "<<g<<endl;
			cout<<"Ilosc wiez: "<<w<<endl;
			cout<<"Ilosc hetmanow: "<<h<<endl;
			cout<<"Ilosc kroli: "<<k<<endl<<endl;
		}
	
		Plansza szachownica(dl,szer);
	
		//szachownica.Wyswietl();

		if(szachownica.Zapelnij(p,s,g,w,h,k))
			szachownica.Wyswietl();
		else
			cout<<"Nie udalo sie ustawic"<<endl;
			
		cout<<"MENU GLOWNE PROGRAMU"<<endl;
		cout<<"Jesli chcesz wczytac dane z pliku, podaj liczbe calkowita od 1 do 5."<<endl;
		cout<<"1 -> test1.txt"<<endl;
		cout<<"2 -> test2.txt"<<endl;
		cout<<"3 -> test3.txt"<<endl;
		cout<<"4 -> test4.txt"<<endl;
		cout<<"5 -> test5.txt"<<endl;
		cout<<"Jesli chcesz wczytac dane z klawiatury, wpisz 6."<<endl;
		cout<<"Jesli chcesz zakonczyc dzialanie programu, wpisz 7"<<endl;
		cin>>menu;
	}
	
	
	/*if (pom == 0)
		cout<<"nie udalo sie poprawnie odczytac danych"<<endl;
	else
	{
		cout<<"Dlugosc planszy: "<<dl<<endl;
		cout<<"Szerokosc planszy: "<<szer<<endl;
		cout<<"Ilosc pionkow: "<<p<<endl;
		cout<<"Ilosc koni: "<<s<<endl;
		cout<<g<<endl;
		cout<<w<<endl;
		cout<<h<<endl;
		cout<<k<<endl;
	}
	
	Plansza szachownica(dl,szer);
	
	szachownica.Wyswietl();

	if(szachownica.Zapelnij(p,s,g,w,h,k))
		szachownica.Wyswietl();
	else
		cout<<"Nie udalo sie ustawic"<<endl;
	
	
	/*Wieza wieza;
	
	//for (int i=0; i<4;i++)
		//for (int j=0; j<4; j++)
		//{
		//	cout<<"["<<i<<"]["<<j<<"]"<<endl;
			wieza.Ustaw(szachownica,2,2);
		//}
	szachownica.Wyswietl();*/
	cout<<"dziekuje"<<endl;
	return 0;
}

bool wczytajPlik(std::string nazwaPliku,int & dl,int & szer, int & p, int & s, int & g, int & w, int & h, int & k)
	{	
		
		int tab[8];
		std::ifstream plik;
		plik.open( nazwaPliku.c_str() );
		if(!plik.good())
			return false;
		int i=0;
		while(true)
		{
			
			if(i>8)
			{
				//cout<<"za duzo danych w pliku"<<endl;
				return false;
			}
			plik >> tab[i];		
			if ( !plik.good() )
				break; //wystapil blad lub koniec danych

			//cout<<"i: "<<i<<" wartosc: "<<tab[i]<<endl;
			i++;
			
		}
		if(i!=8)
		{
			//cout<<"za malo danych w pliku"<<endl;
			return false;
		}
		dl=tab[0]; //dlugosc
		szer=tab[1]; //szerokosc
		p=tab[2]; //ilosc pionkow
		s=tab[3]; //ilosc koni
		g=tab[4]; //ilosc goncow
		w=tab[5]; //ilosc wiez
		h=tab[6]; //ilosc hetmanow
		k=tab[7]; //ilosc kroli	
		/*
		for(int i=0;i<8;i++)
			cout<<tab[i]<<endl;*/
		return true;
		
}

