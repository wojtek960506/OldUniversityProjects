#ifndef Szachy_hpp
#define Szachy_hpp
#include<iostream>
#include<fstream>
#include<string>

const int PIONEK = 1;
const int KON = 2;	
const int GONIEC = 3;
const int WIEZA = 4;
const int HETMAN = 5;
const int KROL = 6;

using namespace std;

class Plansza
{
public:
//private:
	int dlugosc; 
	int szerokosc;
	int ile_zostalo;
	int **plansza;
//public:
	Plansza(int,int);
	Plansza(){dlugosc=0; szerokosc=0; ile_zostalo=0; plansza=NULL;};
	~Plansza();
	void Wyswietl();
	//bool CzyMoznaPostawic(int,int); //sprawdza czy na zadanym polu stoi figura, albo czy to pole jest bite przez figure
	bool Zapelnij(int,int,int,int,int,int); //rekurencyjna do ustawiania wszystkich figur
};

class Figura
{
protected:
	int nazwa; //dla kazdej figury szczegolnej ta wartosc bedzie inna
	int wiersz; //w tym wierszu stoi figura (liczymy je od zera)
	int kolumna; // w tej kolumnie stoi figura (liczymy je od zera)
public:
	//konstruktor
	Figura(){}
	Figura(int n, int w, int k):nazwa(n),wiersz(w),kolumna(k){} //te wartosci sa inne dla kazdej pojedynczej figury
	
	//destruktor 
	virtual ~Figura(){} //destruktor
	
	//metody
	int Wiersz(){return wiersz;}
	int Nazwa(){return nazwa;}
	int Kolumna(){return kolumna;}
	bool Ustaw (Plansza &,int, int); //zwraca nam czy sie udalo ustawic figure na planszy
	bool Usun(Plansza &); //usuwa figure z planszy
	void Polozenie(int w, int k){wiersz=w; kolumna=k;}; //ustawia pozycje figury na planszy
	virtual void PolaBite(Plansza &)=0; //po ustawieniu figury na planszy zaznacza pola bite przez ta figure
	virtual void UsunBite(Plansza &)=0; //kasuje pola przez bite przez figure
	virtual bool CzyBije(const Plansza &)=0; //czy figura ktora ustawiamy bedzie bila jakas figure stojaca na planszy
};

class Pionek : public Figura
{
public:
	
	Pionek():Figura(PIONEK,-1,-1){} //poczatkowe wspolrzedne wskazuja ze figura jest poza plansza
	~Pionek(){}
	virtual void PolaBite(Plansza &);
	virtual void UsunBite(Plansza &);
	virtual bool CzyBije(const Plansza &);
};

class Wieza : public Figura
{
public:
	Wieza():Figura(WIEZA,-1,-1){} ////poczatkowe wspolrzedne wskazuja ze figura jest poza plansza
	~Wieza(){}
	virtual void PolaBite(Plansza &);
	virtual void UsunBite(Plansza &);
	virtual bool CzyBije(const Plansza &);
};

class Kon : public Figura
{
public:
	Kon():Figura(KON,-1,-1){} //poczatkowe wspolrzedne wskazuja ze figura jest poza plansza
	~Kon(){}
	virtual void PolaBite(Plansza &);
	virtual void UsunBite(Plansza &);
	virtual bool CzyBije(const Plansza &);
};

class Goniec : public Figura
{
public:
	Goniec():Figura(GONIEC,-1,-1){} //poczatkowe wspolrzedne wskazuja ze figura jest poza plansza
	~Goniec(){}
	virtual void PolaBite(Plansza &);
	virtual void UsunBite(Plansza &);
	virtual bool CzyBije(const Plansza &);
};

class Hetman : public Figura
{
public:
	Hetman():Figura(HETMAN,-1,-1){} //poczatkowe wspolrzedne wskazuja ze figura jest poza plansza
	~Hetman(){}
	virtual void PolaBite(Plansza &);
	virtual void UsunBite(Plansza &);
	virtual bool CzyBije(const Plansza &);
};

class Krol : public Figura
{
public:
	Krol():Figura(KROL,-1,-1){}  //poczatkowe wspolrzedne wskazuja ze figura jest poza plansza
	~Krol(){}
	virtual void PolaBite(Plansza &);
	virtual void UsunBite(Plansza &);
	virtual bool CzyBije(const Plansza &);
};

#endif
