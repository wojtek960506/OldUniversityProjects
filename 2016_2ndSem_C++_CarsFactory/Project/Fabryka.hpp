#ifndef Fabryka_hpp
#define Fabryka_hpp

#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<typeinfo>
#include<iterator>
#include<cstdio>
#include<ctime>
#include<fstream>

using namespace std;

class Element
{
	private:
		string nazwaElementu; //nazwa
		
	public:
		//konstruktory
		Element(){}
		Element(string s):nazwaElementu(s){}; //okreslamy nazwe
		//destruktor
		string NazwaElementu(){return nazwaElementu;} //zwracamy nazwe
		virtual ~Element(){}
		virtual void Wypisz(){cout<<nazwaElementu<<endl;}	
		
};

class Opona : public Element
{
	public:
		Opona():Element("Opona"){}
		~Opona(){};
		void Wypisz(){cout<<NazwaElementu()<<endl;}
		
		
};

class Karoseria : public Element
{
	private:
		bool czyOpony;
		bool czySilnik;
		bool czyPomalowana;
		bool czyElektronika;
	public:
		//konstruktory
		Karoseria():Element("Karoseria"),czyOpony(false),czySilnik(false),czyPomalowana(false),czyElektronika(false){}
		~Karoseria(){};
		void Czy(); //{if(czyPomalowana){cout<<"pomalowana"<<endl;}else{cout<<"niepomalowana"<<endl;}};
		//void Czy(){if(czyOpony){cout<<"z oponami"<<endl;}else{cout<<"bez opon"<<endl;}};
		void Maluj() {czyPomalowana=true;};
		void MontujElektronike() {czyElektronika=true;};
		void MontujOpony() {czyOpony=true;};
		void MontujSilnik() {czySilnik=true;};
		bool CzyPomalowana(){if(czyPomalowana) return true; else return false;};
		bool CzyOpony(){if(czyOpony) return true; else return false;};
		bool CzySilnik(){if(czySilnik) return true; else return false;}
		bool CzyElektronika(){if(czyElektronika) return true; else return false;}
};

class Silnik : public Element
{
	public:
		//konstruktor
		Silnik():Element("Silnik"){}
		~Silnik(){}	
};

class Stanowisko
{
	private:
		string nazwaStanowiska;
		int numer;
	public:
		Stanowisko(string s, int n):nazwaStanowiska(s),numer(n){}
		virtual ~Stanowisko(){}
		virtual void Dzialaj() = 0 ;
		virtual int Numer(){return numer;};
		virtual string Nazwa(){return nazwaStanowiska;};
		virtual void Uzyte(){};
		void czekaj(int sekundy);
		//Element* Przekaz();
		
		/*
		virtual void PobierzKaroserie(Element*);
		virtual void PobierzSilnik(Element*);
		virtual void PobierzOpone(Element*);		
		*/
};


class ProdukcjaOpon : public Stanowisko
{
	private:
		Opona* opona;
	public:
		ProdukcjaOpon():Stanowisko("Produkcja Opon",-1){opona=NULL;}
		ProdukcjaOpon(int n):Stanowisko("Produkcja Opon",n){opona=NULL;}
		~ProdukcjaOpon(){}
		virtual void Dzialaj();
		Opona* Przekaz(){return opona;}; //zwracamy wskaznik na obiekt typu Opona
		virtual void Uzyte(){opona=NULL;};
};

class ProdukcjaKaroserii : public Stanowisko
{
	private:
		Karoseria* karoseria;
	public:
		ProdukcjaKaroserii():Stanowisko("Produkcja Karoserii",-1){karoseria=NULL;}
		ProdukcjaKaroserii(int n):Stanowisko("Produkcja Karoserii",n){karoseria=NULL;}
		~ProdukcjaKaroserii(){}
		virtual void Dzialaj();
		Karoseria* Przekaz(){return karoseria;}; //zwracamy wskaznik na obiekt typu Karoseria
		virtual void Uzyte(){karoseria=NULL;};
		
};

class MalowanieKaroserii : public Stanowisko
{
	private:
		//Element * elem;
		Karoseria *karoseria;
	public:
		MalowanieKaroserii():Stanowisko("Malowanie Karoserii",-1){karoseria=NULL;}
		MalowanieKaroserii(Karoseria  *k,int n):Stanowisko("Malowanie Karoserii",n),karoseria(k){karoseria=NULL;}
		MalowanieKaroserii(int n):Stanowisko("Malowanie Karoserii",n){karoseria=NULL;}
		~MalowanieKaroserii(){}
		virtual void Dzialaj(); //{karoseria->CzyPomalowana(true);}
		Karoseria* Przekaz(){return karoseria;}; //zwracamy wskaznik na obiekt typu Karoseria
		void PobierzKaroserie(Karoseria *kar){karoseria=kar;}; //pobiera karoserie z poprzedniego stanowiska
		virtual void Uzyte(){karoseria=NULL;};
};

class ProdukcjaSilnikow : public Stanowisko
{
	private:
		
		Silnik* silnik;
	public:
		ProdukcjaSilnikow():Stanowisko("Produkcja Silnikow",-1){silnik=NULL;}
		ProdukcjaSilnikow(int n):Stanowisko("Produkcja Silnikow",n){silnik=NULL;}
		~ProdukcjaSilnikow(){}
		virtual void Dzialaj();
		Silnik* Przekaz(){return silnik;}; //zwracamy wskaznik na obiekt typu Silnik
		virtual void Uzyte(){silnik=NULL;};
};

class OponyWKaroserii : public Stanowisko
{
	private:
		Opona* opony;
		Karoseria* karoseria;
	public:
		OponyWKaroserii():Stanowisko("Dolaczanie opon do karoserii",-1){karoseria=NULL;opony=NULL;}
		OponyWKaroserii(int n):Stanowisko("Dolaczanie opon do karoserii",n){karoseria=NULL;opony=NULL;}
		OponyWKaroserii(Karoseria *k, Opona *o,int n):Stanowisko("Dolaczanie opon do karoserii",n),karoseria(k),opony(o){}
		~OponyWKaroserii(){}
		virtual void Dzialaj();
		Karoseria* Przekaz(){return karoseria;}; //przekazujemy element dalej
		void PobierzOpone(Opona *op){opony=op;}; //pobiera opone z poprzedniego stanowiska
		void PobierzKaroserie(Karoseria *kar){karoseria=kar;}; //pobiera karoserie z poprzedniego stanowiska
		virtual void Uzyte(){karoseria=NULL;opony=NULL;}; //po wykonaniu dzialaniu na obiektach nie ma ich juz w stanowisku
};

class SilnikWKaroserii : public Stanowisko
{
	private:
		Silnik* silnik;
		Karoseria* karoseria;
	public:
		SilnikWKaroserii():Stanowisko("Dolaczanie silnika do karoserii",-1){silnik=NULL;karoseria=NULL;}
		SilnikWKaroserii(int n):Stanowisko("Dolaczanie silnika do karoserii",n){silnik=NULL;karoseria=NULL;}
		SilnikWKaroserii(Karoseria *k, Silnik *s,int n):Stanowisko("Dolaczanie silnika do karoserii",n),karoseria(k),silnik(s){}
		~SilnikWKaroserii(){}
		virtual void Dzialaj();
		Karoseria* Przekaz(){return karoseria;};
		void PobierzKaroserie(Karoseria *kar){karoseria=kar;}; //pobiera karoserie z poprzedniego stanowiska
		void PobierzSilnik(Silnik *sil){silnik=sil;}; //pobiera silnik z poprzedniego stanowiska
		virtual void Uzyte(){silnik=NULL;karoseria=NULL;};
};

class ElektronikaWKaroserii : public Stanowisko
{
	private:
		Karoseria* karoseria;
		int licznik;
	public:
		ElektronikaWKaroserii():Stanowisko("Dolaczanie elektroniki do karoserii",-1){karoseria=NULL;licznik=0;}
		ElektronikaWKaroserii(int n):Stanowisko("Dolaczanie elektroniki do karoserii",n){karoseria=NULL;licznik=0;}
		ElektronikaWKaroserii(Karoseria *k,int n):Stanowisko("Dolaczanie elektorniki do karoserii",n),karoseria(k){licznik=0;}
		~ElektronikaWKaroserii(){}
		virtual void Dzialaj();
		Karoseria* Przekaz(){return karoseria;}; //zwraca karoserie
		void PobierzKaroserie(Karoseria *kar){karoseria=kar;}; //pobiera karoserie z poprzedniego stanowiska
		virtual void Uzyte(){karoseria=NULL;};
};

class Krawedz //laczy stanowiska
{
	private:
		Stanowisko* poprzednie;
		Stanowisko* nastepne;
		queue<Element*> kolejka;
	public:
		Krawedz(Stanowisko* poprz, Stanowisko* nast):poprzednie(poprz),nastepne(nast){}
		~Krawedz(){};
		void DodajElementDoKolejki(Element *e);
		Element* PobierzElementZKolejki();
		int RozmiarKolejki(){return kolejka.size();};
		
		void PrzekazElementDoKolejki(); //wstawia  element do kolejki
		void ZKolejkiDoStanowiska(); //pobiera element z kolejki i przekazuje do stanowiska
		
			
		void PrzekazElementDoStanowiska();
};

class Graf
{
	private:
		vector<Krawedz> krawedz;
		vector<Stanowisko*> stanowisko;
	public:
		void DodajKrawedz(Stanowisko*, Stanowisko*);
		void DodajStanowisko(Stanowisko*);
		void Dzialaj(int); //int to numer stanowiska ktore uruchamiamy
		int RozmiarGrafu(){return krawedz.size();};
		
		void Daj(int); //przekazuje element do kolejki
		//void PrzekazDoKolejki(int); //w argumencie jest numer krawedzi
		
		void Wez(int); //pobiera element z kolejki
		//void WezZKolejki(int);
		
		//void PodajDalej(int);
		//void PrzekazElement(int);
};

class WyjatkiRzutowanie
{
	private:
		string wypisz;
	public:
		WyjatkiRzutowanie():wypisz("poprzednie stanowisko jest puste "){}
		~WyjatkiRzutowanie(){}
		void Wyjatek();
};


#endif
