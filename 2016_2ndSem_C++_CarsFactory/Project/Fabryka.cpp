#include "Fabryka.hpp"

void Stanowisko::czekaj(int sekundy)
{
	clock_t koniec = clock() + sekundy * CLOCKS_PER_SEC;
	while(clock() < koniec) continue;
}

void WyjatkiRzutowanie::Wyjatek()
{
	cout<<wypisz<<endl;
}

void Krawedz::DodajElementDoKolejki(Element  *elem)
{
	kolejka.push(elem);
	//cout<<"dodalem element do kolejki"<<endl;
}	

Element* Krawedz::PobierzElementZKolejki() //poprzednie stanowisko przekazuje nastepnemu efekt swojej pracy
{
	Element * elem;
	try
		{
		if(kolejka.size()==0)
			throw "Kolejka jest pusta, wiec nie mozemy niczego pobrac";

	
		/*{
			cout<<"nie"<<endl;
			return NULL;
		}*/
		elem=kolejka.front(); //jak zmienisz na <Element> to dodaj *
		kolejka.pop();
		//cout<<"usunalem pierwszy element z kolejki"<<endl;
		return elem;
	}
	catch (const char * s)
	{
		cout<<s<<endl;
		return NULL;
	}
}

void Krawedz::PrzekazElementDoKolejki()
{
	ProdukcjaKaroserii *prodkar;
	ProdukcjaOpon *prodop;
	ProdukcjaSilnikow *prodsil;
	MalowanieKaroserii *malkar;
	OponyWKaroserii *oponwkar;
	SilnikWKaroserii *silwkar;
	ElektronikaWKaroserii *elektrwkar;
	Opona *op;
	Silnik *sil;
	Karoseria *kar;
	Element *elem;
	
	try
	{
		if ( typeid(ProdukcjaKaroserii)==typeid(*poprzednie) )
		{
			prodkar=dynamic_cast<ProdukcjaKaroserii*>(poprzednie);
			kar=prodkar->Przekaz();
			if (kar==NULL)
				throw WyjatkiRzutowanie();
			DodajElementDoKolejki(kar);
			prodkar->Uzyte();		
		}
		if ( typeid(MalowanieKaroserii)==typeid(*poprzednie) )
		{
			malkar=dynamic_cast<MalowanieKaroserii*>(poprzednie);
			kar=malkar->Przekaz();
			if(kar==NULL)
				throw WyjatkiRzutowanie();
			DodajElementDoKolejki(kar);
			malkar->Uzyte();
		}
		if ( typeid(OponyWKaroserii)==typeid(*poprzednie) )
		{
			oponwkar=dynamic_cast<OponyWKaroserii*>(poprzednie);
			kar=oponwkar->Przekaz();
			if (kar==NULL)
				throw WyjatkiRzutowanie();
			DodajElementDoKolejki(kar);
			oponwkar->Uzyte();
		}
		if ( typeid(SilnikWKaroserii)==typeid(*poprzednie) )
		{
			silwkar=dynamic_cast<SilnikWKaroserii*>(poprzednie);
			kar=silwkar->Przekaz();
			if(kar==NULL)
				throw WyjatkiRzutowanie();
			DodajElementDoKolejki(kar);
			silwkar->Uzyte();
		}
		if ( typeid(ProdukcjaOpon)==typeid(*poprzednie) )
		{
			prodop=dynamic_cast<ProdukcjaOpon*>(poprzednie);
			op=prodop->Przekaz();
			if(op==NULL)
				throw WyjatkiRzutowanie();
			DodajElementDoKolejki(op);
			prodop->Uzyte();
		}
		if ( typeid(ProdukcjaSilnikow)==typeid(*poprzednie) )
		{
			prodsil=dynamic_cast<ProdukcjaSilnikow*>(poprzednie);
			sil=prodsil->Przekaz();
			if(sil==NULL)
				throw WyjatkiRzutowanie();
			DodajElementDoKolejki(sil);
			prodsil->Uzyte();
		}
		//cout<<poprzednie->Nazwa()<<". "; //nie potrzebujemy tego wypisywac
	}
	catch (WyjatkiRzutowanie & wyjatek)
	{
		wyjatek.Wyjatek();
	}
}



void Krawedz::ZKolejkiDoStanowiska()
{
	ProdukcjaKaroserii *prodkar;
	ProdukcjaOpon *prodop;
	ProdukcjaSilnikow *prodsil;
	MalowanieKaroserii *malkar;
	OponyWKaroserii *oponwkar;
	SilnikWKaroserii *silwkar;
	ElektronikaWKaroserii *elektrwkar;
	Opona *op;
	Silnik *sil;
	Karoseria *kar;
	Element *elem;
	//cout<<poprzednie->Nazwa()<<endl<<endl;
	if ( typeid(ProdukcjaKaroserii)==typeid(*poprzednie) )
	{
		elem=PobierzElementZKolejki();  //pobieram element z kolejki
		kar=dynamic_cast<Karoseria*>(elem); //rzutuje w dol element na typ Karoseria
		malkar=dynamic_cast<MalowanieKaroserii*>(nastepne); //rzutuje w dol nastepne stanowisko 
		malkar->PobierzKaroserie(kar);
	}
	if ( typeid(MalowanieKaroserii)==typeid(*poprzednie) )
	{
		elem=PobierzElementZKolejki();
		oponwkar=dynamic_cast<OponyWKaroserii*>(nastepne);
		kar=dynamic_cast<Karoseria*>(elem);
		oponwkar->PobierzKaroserie(kar);
	}
	if ( typeid(OponyWKaroserii)==typeid(*poprzednie) )
	{
		elem=PobierzElementZKolejki();
		silwkar=dynamic_cast<SilnikWKaroserii*>(nastepne);
		kar=dynamic_cast<Karoseria*>(elem);
		silwkar->PobierzKaroserie(kar);
	}
	if ( typeid(SilnikWKaroserii)==typeid(*poprzednie) )
	{
		elem=PobierzElementZKolejki();
		elektrwkar=dynamic_cast<ElektronikaWKaroserii*>(nastepne);
		kar=dynamic_cast<Karoseria*>(elem);
		elektrwkar->PobierzKaroserie(kar);
	}
	if ( typeid(ProdukcjaOpon)==typeid(*poprzednie) )
	{
		//if(RozmiarKolejki()>=4)
		//{
		//	for (int i=0;i<4;i++)
				elem=PobierzElementZKolejki(); //pobieramy opone 4 razy
			oponwkar=dynamic_cast<OponyWKaroserii*>(nastepne);
			op=dynamic_cast<Opona*>(elem);
			oponwkar->PobierzOpone(op);
			//cout<<op->NazwaElementu()<<endl;
		//}
		//else
		//	cout<<"za malo opon w poprzednim stanowisku"<<endl;
	}
	if ( typeid(ProdukcjaSilnikow)==typeid(*poprzednie) )
	{
		elem=PobierzElementZKolejki();
		silwkar=dynamic_cast<SilnikWKaroserii*>(nastepne);
		sil=dynamic_cast<Silnik*>(elem);
		silwkar->PobierzSilnik(sil);
	}
	//cout<<nastepne->Nazwa()<<". ";
}

void Graf::DodajKrawedz(Stanowisko *poprz,Stanowisko *nast)
{
	krawedz.push_back(Krawedz(poprz,nast));
	//cout<<"Dodalem stanowisko"<<endl;
}

void Graf::DodajStanowisko(Stanowisko *s)
{
	stanowisko.push_back(s);
	//cout<<Dodalem stanowisko"<<endl;
}

void Graf::Dzialaj(int i) //stanowisko wykonuje dzialanie i przekazuje element do kolejki przed stanowiskiem, przed ktorym jest mniejsza kolejka
{
	try
	{		
		if (i>15) //chcemy miec dostep do stanowiska ktore nie istnieje
			throw "Maksymalny numer stanowiska to 15.";
		if(i==14 || i==15) //stanowisko 14 i 15 to ostatnie stanowiska obslugujace ostatnia czynnosc, 
		{			 //wiec nie przekazuja efektu swojej pracy do innych stanowisk
			/*if(i==14)
				cout<<"lewe"<<endl;
			if(i==15)
				cout<<"prawe"<<endl;*/
			stanowisko[i]->Dzialaj(); //uruchamiamy stanowisko dolaczajace elektronike
			return;
		}	 
		if( krawedz[2*i].RozmiarKolejki()==10 && krawedz[2*i+1].RozmiarKolejki()==10)
		{
			cout<<"Za dluga kolejka. Stanowisko numer "<<stanowisko[i]->Numer()<<" wstrzymuje dzialanie."<<endl;
			return;	
		}	
		stanowisko[i]->Dzialaj();
		if( krawedz[2*i].RozmiarKolejki() < krawedz[2*i+1].RozmiarKolejki() )
		{
			krawedz[2*i].PrzekazElementDoKolejki();
			//cout<<"Przekazalem do prawego stanowiska"<<endl;
			cout<<"Stanowisko numer "<<stanowisko[i]->Numer()<<" Rozmiar kolejki w prawym stanowisku po przekazaniu "<<krawedz[2*i].RozmiarKolejki()<<endl;
		}
		else
		{
			krawedz[2*i+1].PrzekazElementDoKolejki();
			//cout<<"Przekazalem do lewego stanowiska"<<endl;
			cout<<"Stanowisko numer "<<stanowisko[i]->Numer()<<" Rozmiar kolejki w lewym stanowisku po przekazaniu "<<krawedz[2*i+1].RozmiarKolejki()<<endl;
		}
		//cout<<"stanowisko numer "<<stanowisko[i]->Numer()<<" zadzialalo."<<endl;
	}
	catch(const char * tekst)
	{
		cout<<tekst<<endl;
		cout<<"Nic nie robie, bo nie ma takiego stanowiska"<<endl;
		return;
	}
}

void Graf::Daj(int i)
{
	krawedz[i].PrzekazElementDoKolejki();
	cout<<"Rozmiar kolejki po przekazaniu do kolejki "<<krawedz[i].RozmiarKolejki()<<endl;
}

//void Graf::WybierzPolaczenie()

void Graf::Wez(int i) //przekazujemy numer stanowiska ktore pobiera
{
	int a; //lewa kolejka do poboru karoserii
	int b; //prawa kolejka do poboru karoserii
	int c; //pierwsza kolejka do poboru opon
	int d; //druga kolejka do poboru opon
	int e; //trzecia kolejka do poboru opon
	int f; //czwarta kolejka do poboru opon
	int g; //lewa kolejka do poboru silnikow
	int h; //prawa kolejka do poboru silnikow
	int max; //okreslanie gdzie jest najwieksza kolejka opon
	int z; //wybor najwiekszej kolejki opon
	int w;
	if(i<8)
	{
		cout<<"To stanowisko nie moze pobierac zadnych elementow, bo je tworzy. Nie wykonuje zadnych czynnosci."<<endl;
		return;
	}
	if(i>15)
	{
		cout<<"To stanowisko nie istnieje. Nie wykonuje zadnych czynnosci."<<endl;
		return;	
	}
	switch(i)
	{
		case 8:	a=0;
				b=2;
				break;
		case 9:	a=1;
				b=3;
				break;
		case 10:	a=16;
				b=18;
				c=4;
				d=6;
				e=8;
				f=10;
				break;
		case 11:	a=17;
				b=19;
				c=5;
				d=7;
				e=9;
				f=11;
				break;
		case 12:	a=20;
				b=22;
				g=12;
				h=14;
				break;
		case 13:	a=21;
				b=23;
				g=13;
				h=15;
				break;
		case 14:	a=24;
				b=26;
				break;
		case 15:	a=25;
				b=27;
				break;
	}
	if( krawedz[a].RozmiarKolejki() > krawedz[b].RozmiarKolejki() )					
	{
		krawedz[a].ZKolejkiDoStanowiska();
		//cout<<"Wzialem z lewego stanowiska do robienia karoserii."<<endl;
		//cout<<"Rozmiar kolejki w lewym stanowisku po zabraniu "<<krawedz[a].RozmiarKolejki()<<endl;
	}
	else
	{
		krawedz[b].ZKolejkiDoStanowiska();
		//cout<<"Wzialem z prawego stanowiska do robienia karoserii."<<endl;
		//cout<<"Rozmiar kolejki w prawym stanowisku po zabraniu "<<krawedz[b].RozmiarKolejki()<<endl;
	}
	if( i==10 || i==11 )
	{
		if(krawedz[c].RozmiarKolejki() + krawedz[d].RozmiarKolejki() + krawedz[e].RozmiarKolejki() + krawedz[f].RozmiarKolejki() < 4)
		{
			cout<<"Jest za malo wyprodukowanych opon. Nie moge przekazac elementow."<<endl;
			return;
		} 
		if(krawedz[c].RozmiarKolejki() >= 4)
		{
			krawedz[c].ZKolejkiDoStanowiska();
			krawedz[c].ZKolejkiDoStanowiska();
			krawedz[c].ZKolejkiDoStanowiska();
			krawedz[c].ZKolejkiDoStanowiska();
			w=1;
			//cout<<"Wzialem ze stanowiska do produkcji opon numer "<<w<<endl;
			//cout<<"Rozmiar kolejki w po zabraniu "<<krawedz[c].RozmiarKolejki()<<endl;
			return;
		}
		if(krawedz[d].RozmiarKolejki() >= 4)
		{
			krawedz[d].ZKolejkiDoStanowiska();
			krawedz[d].ZKolejkiDoStanowiska();
			krawedz[d].ZKolejkiDoStanowiska();
			krawedz[d].ZKolejkiDoStanowiska();
			w=2;
			//cout<<"Wzialem ze stanowiska do produkcji opon numer "<<w<<endl;
			//cout<<"Rozmiar kolejki w po zabraniu "<<krawedz[d].RozmiarKolejki()<<endl;
			return;
		}
		if(krawedz[e].RozmiarKolejki() >= 4)
		{
			krawedz[e].ZKolejkiDoStanowiska();
			krawedz[e].ZKolejkiDoStanowiska();
			krawedz[e].ZKolejkiDoStanowiska();
			krawedz[e].ZKolejkiDoStanowiska();
			w=3;
			//cout<<"Wzialem ze stanowiska do produkcji opon numer "<<w<<endl;
			//cout<<"Rozmiar kolejki w po zabraniu "<<krawedz[e].RozmiarKolejki()<<endl;
			return;
		}
		if(krawedz[f].RozmiarKolejki() >= 4)
		{
			krawedz[f].ZKolejkiDoStanowiska();
			krawedz[f].ZKolejkiDoStanowiska();
			krawedz[f].ZKolejkiDoStanowiska();
			krawedz[f].ZKolejkiDoStanowiska();
			w=4;
			//cout<<"Wzialem ze stanowiska do produkcji opon numer "<<w<<endl;
			//cout<<"Rozmiar kolejki w po zabraniu "<<krawedz[f].RozmiarKolejki()<<endl;
			return;
		}
		krawedz[c].ZKolejkiDoStanowiska();
		krawedz[d].ZKolejkiDoStanowiska();	
		krawedz[e].ZKolejkiDoStanowiska();
		krawedz[f].ZKolejkiDoStanowiska();
		cout<<"Wzialem po jednej oponie z kazdego stanowiska"<<endl;
		//cout<<"Rozmiar kolejki w pierwszym stanowisku po zabraniu "<<krawedz[c].RozmiarKolejki()<<endl;
		//cout<<"Rozmiar kolejki w drugim stanowisku po zabraniu "<<krawedz[d].RozmiarKolejki()<<endl;
		//cout<<"Rozmiar kolejki w trzecim stanowisku po zabraniu "<<krawedz[e].RozmiarKolejki()<<endl;
		//cout<<"Rozmiar kolejki w czwartym stanowisku po zabraniu "<<krawedz[f].RozmiarKolejki()<<endl;
		
		
		/*max=krawedz[c].RozmiarKolejki();
		z=c;
		w=1;
		if(krawedz[d].RozmiarKolejki() > max )
		{
			max=krawedz[d].RozmiarKolejki();
			z=d;
			w=2;
		}
		if(krawedz[e].RozmiarKolejki() > max )
		{
			max=krawedz[e].RozmiarKolejki();
			z=e;
			w=3;
		}
		if(krawedz[f].RozmiarKolejki() > max )
		{
			max=krawedz[f].RozmiarKolejki();
			z=f;
			w=4;
		}
		krawedz[z].ZKolejkiDoStanowiska();
		cout<<"Wzialem ze stanowiska do produkcji opon numer "<<w<<endl;
		cout<<"Rozmiar kolejki w lewym stanowisku po zabraniu "<<krawedz[a].RozmiarKolejki()<<endl;*/
	}
	if( i==12 || i==13 )
	{
		if( krawedz[g].RozmiarKolejki() > krawedz[h].RozmiarKolejki() )					
		{	
			krawedz[g].ZKolejkiDoStanowiska();
			//cout<<"Wzialem z lewego stanowiska do robienia silnikow."<<endl;
			//cout<<"Rozmiar kolejki w lewym stanowisku po zabraniu "<<krawedz[g].RozmiarKolejki()<<endl;
		}
		else
		{
			krawedz[h].ZKolejkiDoStanowiska();
			//cout<<"Wzialem z prawego stanowiska do robienia silnikow."<<endl;
			//cout<<"Rozmiar kolejki w prawym stanowisku po zabraniu "<<krawedz[h].RozmiarKolejki()<<endl;
		}
	}
	
		
	//krawedz[i].ZKolejkiDoStanowiska();
	//cout<<"Rozmiar kolejki po zabraniu z kolejki "<<krawedz[i].RozmiarKolejki()<<endl;
}




/*void Graf::PodajDalej(int i)
{
	krawedz[i].PrzekazElementDoStanowiska();
}
void Graf::StworzGraf()
{
	int i,k;
	int j=0;
	for(i=0;i<2;i++)
	{
		stanowisko.push_back(new ProdukcjaKaroserii());
		stanowisko[i]->Dzialaj();
	}
	for(;i<6;i++)
	{
		stanowisko.push_back(new ProdukcjaOpon());
		stanowisko[i]->Dzialaj();
	}	
	for(;i<8;i++)
	{
		stanowisko.push_back(new ProdukcjaSilnikow());
		stanowisko[i]->Dzialaj();
	}
	for(;i<10;i++)
	{
		stanowisko.push_back(new MalowanieKaroserii(stanowisko[j]->Przekaz()));
		stanowisko[i]->Dzialaj();
		j++;
	}
	j=8;
	k=2;
	for(;i<12;i++)
	{
		stanowisko.push_back(new OponyWKaroserii(stanowisko[j]->Przekaz(),stanowisko[k]->Przekaz()));
		stanowisko[i]->Dzialaj();
		j++;
		k++;
	}
	for(;i<14;i++)
	{
		stanowisko.push_back(new SilnikWKaroserii(stanowisko[j]->Przekaz(),stanowisko[k]->Przekaz()));
		stanowisko[i]->Dzialaj();
		j++;
		k++;
	}
	for(;i<16;i++)
	{
		stanowisko.push_back(new ElektornikaWKaroserii(stanowisko[j]->Przekaz()));
		stanowisko[i]->Dzialaj();
		j++;
	}
}
*/		
	
/*void Krawedz::PrzekazElementDoStanowiska()
{
	ProdukcjaKaroserii *prodkar;
	ProdukcjaOpon *prodop;
	ProdukcjaSilnikow *prodsil;
	MalowanieKaroserii *malkar;
	OponyWKaroserii *oponwkar;
	SilnikWKaroserii *silwkar;
	ElektronikaWKaroserii *elektrwkar;
	
	if ( typeid(ProdukcjaKaroserii)==typeid(*poprzednie) )  //sprawdzam jaki jest typ poprzedniego stanowiska
	{
		prodkar=dynamic_cast<ProdukcjaKaroserii*>(poprzednie);
		malkar=dynamic_cast<MalowanieKaroserii*>(nastepne);
		malkar->PobierzKaroserie(prodkar->Przekaz());
	}
	if ( typeid(MalowanieKaroserii)==typeid(*poprzednie) )
	{
		malkar=dynamic_cast<MalowanieKaroserii*>(poprzednie);
		oponwkar=dynamic_cast<OponyWKaroserii*>(nastepne);
		oponwkar->PobierzKaroserie(malkar->Przekaz());
	}
	if ( typeid(OponyWKaroserii)==typeid(*poprzednie) )
	{
		oponwkar=dynamic_cast<OponyWKaroserii*>(poprzednie);
		silwkar=dynamic_cast<SilnikWKaroserii*>(nastepne);	
		silwkar->PobierzKaroserie(oponwkar->Przekaz());
	}
	if ( typeid(SilnikWKaroserii)==typeid(*poprzednie) )
	{
		silwkar=dynamic_cast<SilnikWKaroserii*>(poprzednie);
		elektrwkar=dynamic_cast<ElektronikaWKaroserii*>(nastepne);
		elektrwkar->PobierzKaroserie(silwkar->Przekaz());
	}
	if ( typeid(ProdukcjaOpon)==typeid(*poprzednie) )
	{
		prodop=dynamic_cast<ProdukcjaOpon*>(poprzednie);
		oponwkar=dynamic_cast<OponyWKaroserii*>(nastepne);
		oponwkar->PobierzOpone(prodop->Przekaz());
	}
	if ( typeid(ProdukcjaSilnikow)==typeid(*poprzednie) )
	{
		prodsil=dynamic_cast<ProdukcjaSilnikow*>(poprzednie);
		silwkar=dynamic_cast<SilnikWKaroserii*>(nastepne);
		silwkar->PobierzSilnik(prodsil->Przekaz());
	}
}*/

/*void Krawedz::PrzekazElementDoKolejki()
{
	ProdukcjaKaroserii *prodkar;
	ProdukcjaOpon *prodop;
	ProdukcjaSilnikow *prodsil;
	MalowanieKaroserii *malkar;
	OponyWKaroserii *oponwkar;
	SilnikWKaroserii *silwkar;
	ElektronikaWKaroserii *elektrwkar;
	Opona *op;
	Silnik *sil;
	Karoseria *kar;
	Element *elem;
	
	if ( typeid(ProdukcjaKaroserii)==typeid(*poprzednie) )
	{
		

			if(kar==NULL)
				cout<<"poprzednie stanowisko jest puste"<<endl;
			else
			{
				DodajElementDoKolejki(kar);
				prodkar->Uzyte();
			}
		
	}
	if ( typeid(MalowanieKaroserii)==typeid(*poprzednie) )
	{
		malkar=dynamic_cast<MalowanieKaroserii*>(poprzednie);
		kar=malkar->Przekaz();
		if(kar==NULL)
			cout<<"poprzednie stanowisko jest puste"<<endl;
		else
		{
			DodajElementDoKolejki(kar);
			malkar->Uzyte();
		}
	}
	if ( typeid(OponyWKaroserii)==typeid(*poprzednie) )
	{
		oponwkar=dynamic_cast<OponyWKaroserii*>(poprzednie);
		kar=oponwkar->Przekaz();
		if (kar==NULL)
			cout<<"poprzednie stanowisko jest puste"<<endl;
		else
		{
			DodajElementDoKolejki(kar);
			oponwkar->Uzyte();
		}
	}
	if ( typeid(SilnikWKaroserii)==typeid(*poprzednie) )
	{
		silwkar=dynamic_cast<SilnikWKaroserii*>(poprzednie);
		kar=silwkar->Przekaz();
		if(kar==NULL)
			cout<<"poprzednie stanowisko jest puste"<<endl;
		else
		{
			DodajElementDoKolejki(kar);
			silwkar->Uzyte();
		}
	}
	if ( typeid(ProdukcjaOpon)==typeid(*poprzednie) )
	{
		prodop=dynamic_cast<ProdukcjaOpon*>(poprzednie);
		op=prodop->Przekaz();
		if(op==NULL)
			cout<<"poprzednie stanowisko jest puste"<<endl;
		else
		{
			DodajElementDoKolejki(op);
			prodop->Uzyte();
		}
		
	}
	if ( typeid(ProdukcjaSilnikow)==typeid(*poprzednie) )
	{
		prodsil=dynamic_cast<ProdukcjaSilnikow*>(poprzednie);
		sil=prodsil->Przekaz();
		if(sil==NULL)
			cout<<"poprzednie stanowisko jest puste"<<endl;
		else
		{
			DodajElementDoKolejki(sil);
			prodsil->Uzyte();
		}
	}
}*/
