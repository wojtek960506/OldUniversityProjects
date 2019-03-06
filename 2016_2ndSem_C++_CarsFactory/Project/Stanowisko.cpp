#include "Fabryka.hpp"

void Karoseria::Czy()
{
	if (czyOpony)
		cout<<"ma opony"<<endl;
	else
		cout<<"nie ma opon"<<endl;	
	if (czyPomalowana)
		cout<<"pomalowana"<<endl;
	else
		cout<<"niepomalowana"<<endl;
		
	if (czySilnik)
		cout<<"z silnikiem"<<endl;
	else
		cout<<"bez silnika"<<endl;
		
	if (czyElektronika)
		cout<<"z elektronika"<<endl;
	else
		cout<<"bez elektroniki"<<endl<<endl;

}

void ProdukcjaOpon::Dzialaj() //tworzy opone
{
	czekaj(0.5);
	opona = new Opona;
	//cout<<"Utworzylem opone"<<endl;
	//cout<<Numer()<<" Utworzylem opone"<<endl;
}

void ProdukcjaKaroserii::Dzialaj() //tworzy karoserie
{
	czekaj(1);
	karoseria = new Karoseria;
	//cout<<"Utworzylem karoserie"<<endl;
	//cout<<Numer()<<" Utworzylem karoserie"<<endl;
}

void ProdukcjaSilnikow::Dzialaj() //tworzy silnik
{
	czekaj(1.5);
	silnik = new Silnik;
	//cout<<"Utworzylem silnik"<<endl;
	//cout<<Numer()<<" Utworzylem silnik"<<endl;
}

void MalowanieKaroserii::Dzialaj()
{
	czekaj(1);
	if(karoseria!=NULL)
	{
		karoseria->Maluj();
		//cout<<"Pomalowalem karoserie"<<endl;
		cout<<Numer()<<" Pomalowalem karoserie"<<endl;
		//Uzyte();
	}
	else
		cout<<Numer()<<" nie udalo sie pomalowac"<<endl;
}	

void OponyWKaroserii::Dzialaj()
{
	czekaj(0.5);
	if(karoseria!=NULL && opony!=NULL && (*this).Przekaz()->CzyPomalowana())
	{
		karoseria->MontujOpony();
		//cout<<"Dolaczylem opony do karoserii"<<endl;
		cout<<Numer()<<" Dolaczylem opony do karoserii"<<endl;
		//Uzyte();
	}
	else
		cout<<Numer()<<" nie udalo sie dolaczyc opon"<<endl;
}

void SilnikWKaroserii::Dzialaj()
{
	czekaj(0.3);
	if(karoseria!=NULL && silnik!=NULL && (*this).Przekaz()->CzyPomalowana() && (*this).Przekaz()->CzyOpony())
	{
		karoseria->MontujSilnik();
		//cout<<"Dolaczylem silnik do karoserii"<<endl;
		cout<<Numer()<<" Dolaczylem silnik do karoserii"<<endl;
		//Uzyte();
	}
	else
		cout<<Numer()<<" nie udalo sie dolaczyc silnika"<<endl;
}

void ElektronikaWKaroserii::Dzialaj()
{
	czekaj(0);
	ofstream plik;
	plik.open("dane.txt", ios::app);
		
	if(karoseria!=NULL && (*this).Przekaz()->CzyPomalowana() && (*this).Przekaz()->CzyOpony() && (*this).Przekaz()->CzySilnik())
	{
		karoseria->MontujElektronike();
		//cout<<"Dolaczylem elektronike do karoserii"<<endl;
		cout<<Numer()<<" Dolaczylem elektornike do karoserii. Samochod gotowy. ";
		licznik++;
		cout<<"Utworzono "<<licznik<<" samochodow"<<endl;
		if(plik.good() == true)
			plik<<"Utworzono "<<licznik<<" samochodow"<<endl;
		//Uzyte();
	}
	else
	{
		cout<<Numer()<<" nie udalo sie dolaczyc elektroniki"<<endl;
		if(plik.good() == true)
			plik<<"nie udalo sie dolaczyc elektroniki, czyli samochod nie zostal jeszcze ukonczony"<<endl;
	}
	plik.close();
}
