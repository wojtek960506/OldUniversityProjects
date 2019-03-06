#include "Szachy.hpp"

Plansza::Plansza(int m, int n) //konstruktor argumentowy
{
	if (  m+n > 0 && m*n > 0 )
	{
		plansza = new int*[m];
		for (int k=0; k<m ; k++)
			plansza[k]=new int[n];
		dlugosc=m;
		szerokosc=n;
		ile_zostalo=m*n;
		for (int i=0; i<m ; i++)
			for (int j=0; j<n; j++)
				plansza[i][j]=0;
	}
	
	else
	{
		cout<<"Podano zle wymiary szachownicy."<<endl;
		dlugosc=0;
		szerokosc=0;
		plansza=NULL;
	}
}

Plansza::~Plansza()
{
	for (int i=0; i<dlugosc ; i++ )
			delete plansza[i];
	delete plansza;			
}


//wyswielanie planszy
void Plansza::Wyswietl()
{
	for(int i=0; i<dlugosc; i++)
	{
		for(int j=0; j<szerokosc; j++)
		{
			if(plansza[i][j]<0)
				cout<<plansza[i][j]<<" ";
			else
			{
				switch(plansza[i][j])
				{
					case 1:  cout<<" "<<"P"<<" ";
						   break;
					case 2:  cout<<" "<<"S"<<" ";
						   break;
					case 3:  cout<<" "<<"G"<<" ";
						   break;
					case 4:  cout<<" "<<"W"<<" ";
						   break;
					case 5:  cout<<" "<<"H"<<" ";
						   break;
					case 6:  cout<<" "<<"K"<<" ";
						   break;
					default: cout<<" "<<plansza[i][j]<<" ";	  
						   break;
				}
				//cout<<" "<<plansza[i][j]<<" ";
			}
		}
		cout<<endl;
	}
	cout<<endl;
}
//ustawianie pojedynczej figury na planszy
//zwraca prawde jezeli ustawimy figure na szachownicy a falsz jezeli nie uda sie jej ustawic
bool Figura::Ustaw(Plansza & P, int w, int k) //musimy znac wspolrzedne na ktorych stawiamy figure
{
	
	if(w<0 || w>P.dlugosc-1 || k<0 || k>P.szerokosc-1)
	{
		//cout<<"Pole, na ktorym chcemy ustawic figure, nie nalezy do szachownicy"<<endl;
		return false;
	}
	if(P.plansza[w][k]<0)
	{
		//cout<<"Pole, na ktorym chcemy ustawic figure, jest bite przez inna figure."<<endl;
		return false;
	}
	if(P.plansza[w][k]>0)
	{
		//cout<<"Pole, na ktorym chcemy ustawic figure, jest zajete przez inna figure."<<endl;
		return false;
	}
	Polozenie(w,k); //ustalamy polozenie figury na planszy
	//cout<<"mama"<<endl;
	if(CzyBije(P)) //sprawdzamy czy figura nie bedzie bila zadnej innej figury
	{
		//cout<<"Jesli ustawimy figure na tym polu, to bedzie biła inna figure."<<endl;
		wiersz=-1; //z powrotem ustalamy polozenie domyslne
		kolumna=-1;
		return false;
	}
	//jesli dojdziemy do tego momentu w funkcji, to znaczy, ze mozemy ustawic figure na planszy
	PolaBite(P);
	P.plansza[w][k]=nazwa;
	return true;
}

bool Figura::Usun(Plansza & P) //musimy wiedziec jaka figure usuwamy
{
	if (nazwa <1 || nazwa>6)
	{
		cout<<"Nie ma takiej figury na planszy"<<endl;
		return false;
	}
	if(wiersz<0 || wiersz>P.dlugosc-1 || kolumna<0 || kolumna>P.szerokosc-1)
	{
		//cout<<"Pole, z ktorego chcemy usunac figure, nie nalezy do szachownicy"<<endl;
		return false;
	}
	UsunBite(P);
	P.plansza[wiersz][kolumna]=0;
	return true;
}		

/*bool Plansza::CzyMoznaPostawic(int w, int k)
{
	if (w < 0 || w > dlugosc-1 || k < 0 || k > szerokosc-1)
	{
		cout<<"Podane wspolrzedne nie naleza do szachownicy"<<endl;
		return false;
	}
	if (plansza[w][k]==0)
		return false;
	else 
		return true;
		
	if(w<0 || w>P.dlugosc-1 || k<0 || k>P.szerokosc-1)
	{
		cout<<"Pole, na ktorym chcemy ustawic figure, nie nalezy do szachownicy"<<endl;
		return false;
	}
	if(P.plansza[w][k]<0)
	{
		cout<<"Pole, na ktorym chcemy ustawic figure, jest bite przez inna figure."<<endl;
		return false;
	}
	if(P.plansza[w][k]>0)
	{
		cout<<"Pole, na ktorym chcemy ustawic figure, jest zajete przez inna figure."<<endl;
		return false;
	}
	Polozenie(w,k); //ustalamy polozenie figury na planszy
	if(CzyBije(P)) //sprawdzamy czy figura nie bedzie bila zadnej innej figury
	{
		cout<<"Jesli ustawimy figure na tym polu, to bedzie biła inna figure."<<endl;
		wiersz=-1; //z powrotem ustalamy polozenie domyslne
		kolumna=-1;
		return false;
	} 
	
}*/

//ilosc odpowiednich figur jest przekazywana do funkcji ustawiajacej je na planszy -> p-piony s-skoczki(konie) g-gonce w-wieze h-hetmany k-krole
bool Plansza::Zapelnij(int p, int s, int g, int w, int h, int k) //funkcja zwraca prawde jesli ustawi dany zbior figur na planszy
{
	int pomoc; //uzywam do zatrzymania petli przy ustawianiu figur
	int wracaj=0; //gdy danej figury nie mozemy ustawic, to wracamy do poprzedneij
	int poprzw=0; //wiersz poprzednio ustawionej figury
	int poprzk=0; //kolumna poprzednio ustawionej figury
	int ustawiono=0;
	//zapelniamy tablice w ktorej beda przechowywane figury
	if( p < 0 || s < 0 || g < 0 || w < 0 || h < 0 || k < 0 )
	{
		cout<<"Ktoras z danych okreslajacych ilosc figur na planszy jest niepoprawna"<<endl;
		return false;
	}
	int ilosc=p+w+s+g+h+k; //suma wszystkich figur do ustawienia
	if(ilosc>ile_zostalo)
	{
		cout<<"Ilosc figur do ustawienia jest wieksza niz ilosc pol na szachownicy"<<endl;
		return false;
	}
	Figura *figury[ilosc];
		
		/*for(int n=0; n < p; n++)
			figury[n] = new Pionek();
		for(int n=p; n < p+s; n++)
			figury[n] = new Kon();
		for(int n=p+s; n < p+s+g; n++)
			figury[n] = new Goniec();
		for(int n=p+s+g; n < p+s+g+w; n++)
			figury[n] = new Wieza();
		for(int n=p+s+g+w; n < p+s+g+w+h; n++)
			figury[n] = new Hetman();
		for(int n=p+s+g+w+h; n < p+s+g+w+h+k; n++)
			figury[n] = new Krol();*/		
			
		for(int n=0; n < h; n++)
			figury[n] = new Hetman();
		
		for(int n=h; n < h+w; n++)
			figury[n] = new Wieza();
		
		for(int n=h+w; n < h+w+g; n++)
			figury[n] = new Goniec();
		for(int n=h+w+g; n < h+w+g+s; n++)
			figury[n] = new Kon();
		for(int n=h+w+g+s; n < h+w+g+w+s+k; n++)
			figury[n] = new Krol();
		for(int n=k+s+g+w+h; n < p+s+g+w+h+k; n++)
			figury[n] = new Pionek();			

	
	
		
	//algorytm ustawiania na planszy wszystkich figur ze zbioru
	int iloscpowrotow=0;
	for(int i=0; i<ilosc; i++)
	{
		if(poprzw<0 || poprzk<0)
		{
			return false;
		}
		int kol;
		int wier;
		pomoc=0;
		if(wracaj == 1)
		{
			if(poprzk==szerokosc-1) //jesli poprzedni element byl w ostatniej kolumnie
			{
				kol=0;
				wier=poprzw+1;
			}
			else //poprzedni element znajduje sie gdzies w srodku wiersza
			{
				wier=poprzw;
				kol=poprzk+1;
			}	
				
		}
		else
		{
			kol=0;
			wier=0;
		}
		wracaj=0;
		for (int wrsz=wier; wrsz < dlugosc; wrsz++)
		{
			for (int klmn=kol; klmn < szerokosc; klmn++)
			{
				if (figury[i]->Ustaw(*this,wrsz,klmn))
				{	
					ustawiono++;
					pomoc=1;
					break;
				}
				if(wrsz == dlugosc-1 && klmn == szerokosc-1)
				{
					wracaj=1;
					iloscpowrotow++;
				}
			}
			if (pomoc == 1)
			{	
				break;
			}
		}
		if (wracaj==1)
		{	

			if (i!=0)
			{
				i--; //cofamy sie zeby usunac poprzednio ustawiona figure
				poprzw=figury[i]->Wiersz();
				poprzk=figury[i]->Kolumna();
				figury[i]->Usun(*this);
				ustawiono--;
				if(poprzw==dlugosc-1 && poprzk==szerokosc-1)
				{
					i--; //cofamy sie zeby usunac poprzednio ustawiona figure
					if (i==-1)
					{
						cout<<"Ilosc powrotow "<<iloscpowrotow<<endl;
						return false;
					}
					poprzw=figury[i]->Wiersz();
					poprzk=figury[i]->Kolumna();
					
					figury[i]->Usun(*this);
					ustawiono--;
				}
			}
			else
			{
				cout<<"Ilosc powrotow "<<iloscpowrotow<<endl;
				return false; //jesli nie moglismy na zadnym polu ustawic pierwszej figury to innych tez nie ustawimy
			}	
			i--; //cofamy sie jeszcze o jeden zeby moc zmienic polozenie poprzedniej figury (petla for doda nam 1 i bedzie OK)
			
		}
		//Wyswietl();
		if (i==ilosc-1)
		{
			cout<<"Ilosc powrotow "<<iloscpowrotow<<endl;
			return true;
		}
		//cout<<"nr powrotu: "<<iloscpowrotow<<endl;
	}						
}
