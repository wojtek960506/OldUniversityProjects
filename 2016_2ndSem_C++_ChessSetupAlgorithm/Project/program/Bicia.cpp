#include "Szachy.hpp"

//POLA BITE
void Pionek::PolaBite(Plansza & P) // pion moze bic tylko po skosie w dol o jedno pole
{
	if(wiersz+1 <= P.dlugosc-1 && kolumna-1 >= 0)
		if((--P.plansza[wiersz+1][kolumna-1])==-1) //lewy dolny rog
			P.ile_zostalo--;
	if(wiersz+1 <= P.dlugosc-1 && kolumna+1 <= P.szerokosc-1)
		if((--P.plansza[wiersz+1][kolumna+1])==-1) //prawy dolny rog
			P.ile_zostalo--;
}

void Krol::PolaBite(Plansza & P) //krol moze bic we wszystkich kierunkach o jedno pole
{
	if(wiersz-1 >= 0 && kolumna-1 >= 0)		
		if((--P.plansza[wiersz-1][kolumna-1])==-1) //lewy gorny rog
			P.ile_zostalo--;
	if(wiersz-1 >= 0)
		if((--P.plansza[wiersz-1][kolumna])==-1) //gora
			P.ile_zostalo--;
	if(wiersz-1 >= 0 && kolumna+1 <= P.szerokosc-1)
		if((--P.plansza[wiersz-1][kolumna+1])==-1) //prawy gorny rog
			P.ile_zostalo--;
	if(kolumna-1 >= 0)
		if((--P.plansza[wiersz][kolumna-1])==-1) //lewo
			P.ile_zostalo--;
	if(wiersz+1 <= P.dlugosc-1 && kolumna-1 >= 0)
		if((--P.plansza[wiersz+1][kolumna-1])==-1) //lewy dolny rog
			P.ile_zostalo--;
	if(wiersz+1 <= P.dlugosc-1)
		if((--P.plansza[wiersz+1][kolumna])==-1) //dol
			P.ile_zostalo--;
	if(wiersz+1 <= P.dlugosc-1 && kolumna+1 <= P.szerokosc-1)
		if((--P.plansza[wiersz+1][kolumna+1])==-1) //prawy dolny rog
			P.ile_zostalo--;
	if(kolumna <= P.szerokosc-1)
		if((--P.plansza[wiersz][kolumna+1])==-1) //prawo
			P.ile_zostalo--;
	
	
}
	
void Kon::PolaBite(Plansza & P) //rozklad bic konia
{
	if(wiersz+1 <= P.dlugosc-1 && kolumna+2 <= P.szerokosc-1)
		if((--P.plansza[wiersz+1][kolumna+2])==-1) //dwa w prawo, jeden w dol
			P.ile_zostalo--;
	if(wiersz+2 <= P.dlugosc-1 && kolumna+1 <= P.szerokosc-1)
		if((--P.plansza[wiersz+2][kolumna+1])==-1) //jeden w prawo, dwa w dol
			P.ile_zostalo--;
	if(wiersz+2 <= P.dlugosc-1 && kolumna-1 >= 0)
		if((--P.plansza[wiersz+2][kolumna-1])==-1) //jeden w lewo, dwa w dol
			P.ile_zostalo--;
	if(wiersz+1 <= P.dlugosc-1 && kolumna-2 >= 0)
		if((--P.plansza[wiersz+1][kolumna-2])==-1) //dwa w lewo, jeden w dol
			P.ile_zostalo--;
	if(wiersz-1 >= 0 && kolumna-2 >= 0)
		if((--P.plansza[wiersz-1][kolumna-2])==-1) //dwa w lewo, jeden w gore
			P.ile_zostalo--;
	if(wiersz-2 >= 0 && kolumna-1 >= 0)
		if((--P.plansza[wiersz-2][kolumna-1])==-1) //jeden w lewo, dwa w gore
			P.ile_zostalo--;
	if(wiersz-2 >= 0 && kolumna+1 <= P.szerokosc-1)
		if((--P.plansza[wiersz-2][kolumna+1])==-1) //jeden w prawo, dwa w gore
			P.ile_zostalo--;
	if(wiersz-1 >= 0 && kolumna +2 <= P.szerokosc-1)
		if((--P.plansza[wiersz-1][kolumna+2])==-1) //dwa w prawo, jeden w gore
			P.ile_zostalo--;
			
		
}

void Goniec::PolaBite(Plansza & P)
{
	//jesli numer wiersza jest wiekszy niz zero to jedziemy po przekatnych w gore
	for(int i=1;i<=wiersz;i++)
	{
		if(kolumna-i >= 0)
			if((--P.plansza[wiersz-i][kolumna-i])==-1) //po przekatnej w gore w lewo
				P.ile_zostalo--;
		if(kolumna+i <= P.szerokosc-1)
			if((--P.plansza[wiersz-i][kolumna+i])==-1) //po przekatnej w gore w prawo
				P.ile_zostalo--;
	}	
	//jesli numer wiersza jest mniejszy niz dlugosc-1 szachownicy to idziemy po przekatnych w dol
	for(int i=1;i<=P.dlugosc-1-wiersz;i++)
	{
		if(kolumna-i >= 0)
			if((--P.plansza[wiersz+i][kolumna-i])==-1) //po przekatnej w dol w lewo
				P.ile_zostalo--;
		if(kolumna+i <= P.szerokosc-1)
			if((--P.plansza[wiersz+i][kolumna+i])==-1) //po przekatnej w dol w prawo
				P.ile_zostalo--;
	}
}

void Wieza::PolaBite(Plansza & P)
{
	for(int i=1;i<=wiersz;i++)
	{
		if((--P.plansza[wiersz-i][kolumna])==-1) //po kolumnie w gore
			P.ile_zostalo--;
	}
	for(int i=1;i<=P.dlugosc-1-wiersz;i++)
	{
		if((--P.plansza[wiersz+i][kolumna])==-1) //po kolumnie w dol
			P.ile_zostalo--;
	}
	for(int i=1;i<=kolumna;i++)
	{
		if((--P.plansza[wiersz][kolumna-i])==-1) //po wierszu w lewo
			P.ile_zostalo--;
	}
	for(int i=1;i<=P.szerokosc-1-kolumna;i++) //po wierszu w prawo
	{
		if((--P.plansza[wiersz][kolumna+i])==-1)
			P.ile_zostalo--;
	}
}

void Hetman::PolaBite(Plansza & P)
{
	//jesli numer wiersza jest wiekszy niz zero to jedziemy po przekatnych i kolumnach w gore
	for(int i=1;i<=wiersz;i++)
	{
		if(kolumna-i >= 0)
			if((--P.plansza[wiersz-i][kolumna-i])==-1) //po przekatnej w gore w lewo
				P.ile_zostalo--;
		if(kolumna+i <= P.szerokosc-1)
			if((--P.plansza[wiersz-i][kolumna+i])==-1) //po przekatnej w gore w prawo
				P.ile_zostalo--;
		if((--P.plansza[wiersz-i][kolumna])==-1) //po kolumnie w gore
			P.ile_zostalo--;	
	}
	//jesli numer wiersza jest mniejszy niz dlugosc-1 szachownicy to idziemy po przekatnych i kolumnach w dol
	for(int i=1;i<=P.dlugosc-1-wiersz;i++)
	{
		if(kolumna-i >= 0)
			if((--P.plansza[wiersz+i][kolumna-i])==-1) //po przekatnej w dol w lewo
				P.ile_zostalo--;
		if(kolumna+i <= P.szerokosc-1)
			if((--P.plansza[wiersz+i][kolumna+i])==-1) //po przekatnej w dol w prawo
				P.ile_zostalo--;
		if((--P.plansza[wiersz+i][kolumna])==-1) //po kolumnie w dol
			P.ile_zostalo--;
	}
	//po przekatnej niekoniecznie mamy tyle samo pol co po kolumnie 
	for(int i=1;i<=kolumna;i++)
	{
		if((--P.plansza[wiersz][kolumna-i])==-1) //po wierszu w lewo
			P.ile_zostalo--;
	}
	for(int i=1;i<=P.szerokosc-1-kolumna;i++) //po wierszu w prawo
	{
		if((--P.plansza[wiersz][kolumna+i])==-1)
			P.ile_zostalo--;
	}
}

//funkcje bic w ktorych sprawdzamy, czy czy przy ustawianiu figura ustawiana nie bije figur juz stojących
bool Pionek::CzyBije(const Plansza & P) // pion moze bic tylko po skosie w dol o jedno pole
{
	if(wiersz+1 <= P.dlugosc-1 && kolumna-1 >= 0)
		if((P.plansza[wiersz+1][kolumna-1])>0) //lewy dolny rog
			return true;
	if(wiersz+1 <= P.dlugosc-1 && kolumna+1 <= P.szerokosc-1)
		if((P.plansza[wiersz+1][kolumna+1])>0) //prawy dolny rog
			return true;
	return false; //jesli ustawiona figura nie bije zadnej figury, ktora juz jest na planszy
}

bool Krol::CzyBije(const Plansza & P) // pion moze bic tylko po skosie w dol o jedno pole
{
	if(wiersz-1 >= 0 && kolumna-1 >= 0)		
		if((P.plansza[wiersz-1][kolumna-1])>0) //lewy gorny rog
			return true;
	if(wiersz-1 >= 0)
		if((P.plansza[wiersz-1][kolumna])>0) //gora
			return true;
	if(wiersz-1 >= 0 && kolumna+1 <= P.szerokosc-1)
		if((P.plansza[wiersz-1][kolumna+1])>0) //prawy gorny rog
			return true;
	if(kolumna-1 >= 0)
		if((P.plansza[wiersz][kolumna-1])>0) //lewo
			return true;
	if(wiersz+1 <= P.dlugosc-1 && kolumna-1 >= 0)
		if((P.plansza[wiersz+1][kolumna-1])>0) //lewy dolny rog
			return true;
	if(wiersz+1 <= P.dlugosc-1)
		if((P.plansza[wiersz+1][kolumna])>0) //dol
			return true;
	if(wiersz+1 <= P.dlugosc-1 && kolumna+1 <= P.szerokosc-1)
		if((P.plansza[wiersz+1][kolumna+1])>0) //prawy dolny rog
			return true;
	if(kolumna+1 <= P.szerokosc-1)
		if((P.plansza[wiersz][kolumna+1])>0) //prawo
			return true;
	return false; //jesli ustawiona figura nie bije zadnej figury, ktora juz jest na planszy	
}

bool Kon::CzyBije(const Plansza & P) // pion moze bic tylko po skosie w dol o jedno pole
{
	if(wiersz+1 <= P.dlugosc-1 && kolumna+2 <= P.szerokosc-1)
		if((P.plansza[wiersz+1][kolumna+2])>0) //dwa w prawo, jeden w dol
			return true;
	if(wiersz+2 <= P.dlugosc-1 && kolumna+1 <= P.szerokosc-1)
		if((P.plansza[wiersz+2][kolumna+1])>0) //jeden w prawo, dwa w dol
			return true;
	if(wiersz+2 <= P.dlugosc-1 && kolumna-1 >= 0)
		if((P.plansza[wiersz+2][kolumna-1])>0) //jeden w lewo, dwa w dol
			return true;
	if(wiersz+1 <= P.dlugosc-1 && kolumna-2 >= 0)
		if((P.plansza[wiersz+1][kolumna-2])>0) //dwa w lewo, jeden w dol
			return true;
	if(wiersz-1 >= 0 && kolumna-2 >= 0)
		if((P.plansza[wiersz-1][kolumna-2])>0) //dwa w lewo, jeden w gore
			return true;
	if(wiersz-2 >= 0 && kolumna-1 >= 0)
		if((P.plansza[wiersz-2][kolumna-1])>0) //jeden w lewo, dwa w gore
			return true;
	if(wiersz-2 >= 0 && kolumna+1 <= P.szerokosc-1)
		if((P.plansza[wiersz-2][kolumna+1])>0) //jeden w prawo, dwa w gore
			return true;
	if(wiersz-1 >= 0 && kolumna +2 <= P.szerokosc-1)
		if((P.plansza[wiersz-1][kolumna+2])>0) //dwa w prawo, jeden w gore
			return true;
	return false; //jesli ustawiona figura nie bije zadnej figury, ktora juz jest na planszy
}

bool Goniec::CzyBije(const Plansza & P) // pion moze bic tylko po skosie w dol o jedno pole
{
	//jesli numer wiersza jest wiekszy niz zero to jedziemy po przekatnych w gore
	for(int i=1;i<=wiersz;i++)
	{
		if(kolumna-i >= 0)
			if((P.plansza[wiersz-i][kolumna-i])>0) //po przekatnej w gore w lewo
				return true;
		if(kolumna+i <= P.szerokosc-1)
			if((P.plansza[wiersz-i][kolumna+i])>0) //po przekatnej w gore w prawo
				return true;
	}	
	//jesli numer wiersza jest mniejszy niz dlugosc-1 szachownicy to idziemy po przekatnych w dol
	for(int i=1;i<=P.dlugosc-1-wiersz;i++)
	{
		if(kolumna-i >= 0)
			if((P.plansza[wiersz+i][kolumna-i])>0) //po przekatnej w dol w lewo
				return true;
		if(kolumna+i <= P.szerokosc-1)
			if((P.plansza[wiersz+i][kolumna+i])>0) //po przekatnej w dol w prawo
				return true;
	}
	return false; //jesli ustawiona figura nie bije zadnej figury, ktora juz jest na planszy
}

bool Wieza::CzyBije(const Plansza & P) // pion moze bic tylko po skosie w dol o jedno pole
{
	for(int i=1;i<=wiersz;i++)
	{
		if((P.plansza[wiersz-i][kolumna])>0) //po kolumnie w gore
			return true;
	}
	for(int i=1;i<=P.dlugosc-1-wiersz;i++)
	{
		if((P.plansza[wiersz+i][kolumna])>0) //po kolumnie w dol
			return true;
	}
	for(int i=1;i<=kolumna;i++)
	{
		if((P.plansza[wiersz][kolumna-i])>0) //po wierszu w lewo
			return true;
	}
	for(int i=1;i<=P.szerokosc-1-kolumna;i++) //po wierszu w prawo
	{
		if((P.plansza[wiersz][kolumna+i])>0)
			return true;
	}
	return false; //jesli ustawiona figura nie bije zadnej figury, ktora juz jest na planszy
}

bool Hetman::CzyBije(const Plansza & P) // pion moze bic tylko po skosie w dol o jedno pole
{
	//jesli numer wiersza jest wiekszy niz zero to jedziemy po przekatnych i kolumnach w gore
	for(int i=1;i<=wiersz;i++)
	{
		if(kolumna-i >= 0)
			if((P.plansza[wiersz-i][kolumna-i])>0) //po przekatnej w gore w lewo
				return true;
		if(kolumna+i <= P.szerokosc-1)
			if((P.plansza[wiersz-i][kolumna+i])>0) //po przekatnej w gore w prawo
				return true;
		if((P.plansza[wiersz-i][kolumna])>0) //po kolumnie w gore
			return true;	
	}
	//jesli numer wiersza jest mniejszy niz dlugosc-1 szachownicy to idziemy po przekatnych i kolumnach w dol
	for(int i=1;i<=P.dlugosc-1-wiersz;i++)
	{
		if(kolumna-i >= 0)
			if((P.plansza[wiersz+i][kolumna-i])>0) //po przekatnej w dol w lewo
				return true;
		if(kolumna+i <= P.szerokosc-1)
			if((P.plansza[wiersz+i][kolumna+i])>0) //po przekatnej w dol w prawo
				return true;
		if((P.plansza[wiersz+i][kolumna])>0) //po kolumnie w dol
			return true;
	}
	//po przekatnej niekoniecznie mamy tyle samo pol co po kolumnie 
	for(int i=1;i<=kolumna;i++)
	{
		if((P.plansza[wiersz][kolumna-i])>0) //po wierszu w lewo
			return true;
	}
	for(int i=1;i<=P.szerokosc-1-kolumna;i++) //po wierszu w prawo
	{
		if((P.plansza[wiersz][kolumna+i])>0)
			return true;
	}
	return false; //jesli ustawiona figura nie bije zadnej figury, ktora juz jest na planszy
}


//Uswua bicia figury przy usuwaniu jej z planszy
void Pionek::UsunBite(Plansza & P) // pion moze bic tylko po skosie w dol o jedno pole
{
	if(wiersz+1 <= P.dlugosc-1 && kolumna-1 >= 0)
		if((++P.plansza[wiersz+1][kolumna-1])==0) //lewy dolny rog
			P.ile_zostalo++;
	if(wiersz+1 <= P.dlugosc-1 && kolumna+1 <= P.szerokosc-1)
		if((++P.plansza[wiersz+1][kolumna+1])==0) //prawy dolny rog
			P.ile_zostalo++;
}

void Krol::UsunBite(Plansza & P) //krol moze bic we wszystkich kierunkach o jedno pole
{
	if(wiersz-1 >= 0 && kolumna-1 >= 0)		
		if((++P.plansza[wiersz-1][kolumna-1])==0) //lewy gorny rog
			P.ile_zostalo++;
	if(wiersz-1 >= 0)
		if((++P.plansza[wiersz-1][kolumna])==0) //gora
			P.ile_zostalo++;
	if(wiersz-1 >= 0 && kolumna+1 <= P.szerokosc-1)
		if((++P.plansza[wiersz-1][kolumna+1])==0) //prawy gorny rog
			P.ile_zostalo++;
	if(kolumna-1 >= 0)
		if((++P.plansza[wiersz][kolumna-1])==0) //lewo
			P.ile_zostalo++;
	if(wiersz+1 <= P.dlugosc-1 && kolumna-1 >= 0)
		if((++P.plansza[wiersz+1][kolumna-1])==0) //lewy dolny rog
			P.ile_zostalo++;
	if(wiersz+1 <= P.dlugosc-1)
		if((++P.plansza[wiersz+1][kolumna])==0) //dol
			P.ile_zostalo++;
	if(wiersz+1 <= P.dlugosc-1 && kolumna+1 <= P.szerokosc-1)
		if((++P.plansza[wiersz+1][kolumna+1])==0) //prawy dolny rog
			P.ile_zostalo++;
	if(kolumna+1 <= P.szerokosc-1)
		if((++P.plansza[wiersz][kolumna+1])==0) //prawo
			P.ile_zostalo++;
	
	
}
	
void Kon::UsunBite(Plansza & P) //rozklad bic konia
{
	if(wiersz+1 <= P.dlugosc-1 && kolumna+2 <= P.szerokosc-1)
		if((++P.plansza[wiersz+1][kolumna+2])==0) //dwa w prawo, jeden w dol
			P.ile_zostalo++;
	if(wiersz+2 <= P.dlugosc-1 && kolumna+1 <= P.szerokosc-1)
		if((++P.plansza[wiersz+2][kolumna+1])==0) //jeden w prawo, dwa w dol
			P.ile_zostalo++;
	if(wiersz+2 <= P.dlugosc-1 && kolumna-1 >= 0)
		if((++P.plansza[wiersz+2][kolumna-1])==0) //jeden w lewo, dwa w dol
			P.ile_zostalo++;
	if(wiersz+1 <= P.dlugosc-1 && kolumna-2 >= 0)
		if((++P.plansza[wiersz+1][kolumna-2])==0) //dwa w lewo, jeden w dol
			P.ile_zostalo++;
	if(wiersz-1 >= 0 && kolumna-2 >= 0)
		if((++P.plansza[wiersz-1][kolumna-2])==0) //dwa w lewo, jeden w gore
			P.ile_zostalo++;
	if(wiersz-2 >= 0 && kolumna-1 >= 0)
		if((++P.plansza[wiersz-2][kolumna-1])==0) //jeden w lewo, dwa w gore
			P.ile_zostalo++;
	if(wiersz-2 >= 0 && kolumna+1 <= P.szerokosc-1)
		if((++P.plansza[wiersz-2][kolumna+1])==0) //jeden w prawo, dwa w gore
			P.ile_zostalo++;
	if(wiersz-1 >= 0 && kolumna +2 <= P.szerokosc-1)
		if((++P.plansza[wiersz-1][kolumna+2])==0) //dwa w prawo, jeden w gore
			P.ile_zostalo++;
			
		
}

void Goniec::UsunBite(Plansza & P)
{
	//jesli numer wiersza jest wiekszy niz zero to jedziemy po przekatnych w gore
	for(int i=1;i<=wiersz;i++)
	{
		if(kolumna-i >= 0)
			if((++P.plansza[wiersz-i][kolumna-i])==0) //po przekatnej w gore w lewo
				P.ile_zostalo++;
		if(kolumna+i <= P.szerokosc-1)
			if((++P.plansza[wiersz-i][kolumna+i])==0) //po przekatnej w gore w prawo
				P.ile_zostalo++;
	}	
	//jesli numer wiersza jest mniejszy niz dlugosc-1 szachownicy to idziemy po przekatnych w dol
	for(int i=1;i<=P.dlugosc-1-wiersz;i++)
	{
		if(kolumna-i >= 0)
			if((++P.plansza[wiersz+i][kolumna-i])==0) //po przekatnej w dol w lewo
				P.ile_zostalo++;
		if(kolumna+i <= P.szerokosc-1)
			if((++P.plansza[wiersz+i][kolumna+i])==0) //po przekatnej w dol w prawo
				P.ile_zostalo++;
	}
}

void Wieza::UsunBite(Plansza & P)
{
	for(int i=1;i<=wiersz;i++)
	{
		if((++P.plansza[wiersz-i][kolumna])==0) //po kolumnie w gore
			P.ile_zostalo++;
	}
	for(int i=1;i<=P.dlugosc-1-wiersz;i++)
	{
		if((++P.plansza[wiersz+i][kolumna])==0) //po kolumnie w dol
			P.ile_zostalo++;
	}
	for(int i=1;i<=kolumna;i++)
	{
		if((++P.plansza[wiersz][kolumna-i])==0) //po wierszu w lewo
			P.ile_zostalo++;
	}
	for(int i=1;i<=P.szerokosc-1-kolumna;i++) //po wierszu w prawo
	{
		if((++P.plansza[wiersz][kolumna+i])==0)
			P.ile_zostalo++;
	}
}

void Hetman::UsunBite(Plansza & P)
{
	//jesli numer wiersza jest wiekszy niz zero to jedziemy po przekatnych i kolumnach w gore
	for(int i=1;i<=wiersz;i++)
	{
		if(kolumna-i >= 0)
			if((++P.plansza[wiersz-i][kolumna-i])==0) //po przekatnej w gore w lewo
				P.ile_zostalo++;
		if(kolumna+i <= P.szerokosc-1)
			if((++P.plansza[wiersz-i][kolumna+i])==0) //po przekatnej w gore w prawo
				P.ile_zostalo++;
		if((++P.plansza[wiersz-i][kolumna])==0) //po kolumnie w gore
			P.ile_zostalo++;	
	}
	//jesli numer wiersza jest mniejszy niz dlugosc-1 szachownicy to idziemy po przekatnych i kolumnach w dol
	for(int i=1;i<=P.dlugosc-1-wiersz;i++)
	{
		if(kolumna-i >= 0)
			if((++P.plansza[wiersz+i][kolumna-i])==0) //po przekatnej w dol w lewo
				P.ile_zostalo++;
		if(kolumna+i <= P.szerokosc-1)
			if((++P.plansza[wiersz+i][kolumna+i])==0) //po przekatnej w dol w prawo
				P.ile_zostalo++;
		if((++P.plansza[wiersz+i][kolumna])==0) //po kolumnie w dol
			P.ile_zostalo++;
	}
	//po przekatnej niekoniecznie mamy tyle samo pol co po kolumnie 
	for(int i=1;i<=kolumna;i++)
	{
		if((++P.plansza[wiersz][kolumna-i])==0) //po wierszu w lewo
			P.ile_zostalo++;
	}
	for(int i=1;i<=P.szerokosc-1-kolumna;i++) //po wierszu w prawo
	{
		if((++P.plansza[wiersz][kolumna+i])==0)
			P.ile_zostalo++;
	}
}
