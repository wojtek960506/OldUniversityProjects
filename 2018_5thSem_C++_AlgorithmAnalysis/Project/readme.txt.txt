Wojciech Zieliñski nr indeksu: 281 280
AAL-9-LS rabuœ
Temat projektu:
"Œcigany przez krajowe s³u¿by rabuœ zabytków zmuszony jest uciekaæ za granicê.
Nale¿y zaproponowaæ mu drogê prowadz¹c¹ przez najmniejsz¹ iloœæ miast, gdy¿
tam g³ównie czaj¹ siê patrole policji. Chciwy rabuœ palnuje po drodze dokonaæ
intratnych rabie¿y, ale podró¿uje samochodem z ograniczon¹ pojemnoœci¹ baga¿nika.
Pomó¿ rabusiowi wybraæ najbardziej op³acalne napady na drodze jego najkrótszej
ucieczki za granicê. Danymi wejœciowymi s¹ graf miast, pojemnoœæ baga¿nika,
po³o¿enie ³upów oraz ich wielkoœci i wartoœci."

->Mo¿liwe polecenia aktywacji programu:
1. Odczyt danych z pliku
nazwa_programu  --file nazwa_pliku
nazwa_programu  -f nazwa_pliku 
  * dwa rownowazne wywolania
2. Generacja danych losowych
nazwa_programu --gen
nazwa_programu -g
  * dwa rownowazne wywolania 
3. Testowanie czasu wykonania przy losowym generowaniu danych
nazwa_programu -b begin -n number -s step -i instance
  * begin to poczatkowa ilosc wierzcholkow i krawedzi w grafie 
  * number to ilosc krokow
  * step to wielkosc kroku (o ile zwiekszamy ilosc generowanych danych
    w kolejnym wywolaniu)
  * instance to ilosc instancji problemu generowanych dla danej ilosci
    wierzcholkow i krawedzi  
4. Generacja szczegolnego przypadku
nazwa_programu -genS levels
  * levels to wyznacznik ilosci wierzcholkow
5. Generacja szczegolnych przypadkow pesymistycznych do testu z liczeniem
   czasu wykonania
nazwa _programu  --first first --steps steps
  * first to wyznacznik ilosci wierzcholkow w pierwszym kroku
  * steps to ilosc krokow pomniejszona o jeden (tak wlasciwie jest to
    ostatnia wartosc wyznacznika i jest on zwiekszany o 1 co kolejne wykonanie
->Opis konwencji dotycz¹cych danych wejœciowych i prezentacji wyników:
	W przypadku aktywacji programu sposobem 1 lub 2 otrzymane wyniki s¹ zapisywane do pliku.
Jest tam informacja o tym pomiêdzy, którymi wierzcho³kami by³a szukana droga ucieczki, proponowana
droga ucieczki, miejsca gdzie nale¿y dokonaæ rabunków, aby zmaksymalizowaæ zysk oraz ca³kowita wartoœæ
tych¿e rabunków.
	Dane wejœciowe to tablica wierzcho³ków (miast), z informacjami o numerze wierzcho³ka oraz wartoœci
i objêtoœci ³upów w nim, objêtoœæ plecaka, pierwszy i ostatni wierzcho³ek. Dodatkowo w przypadku generowania
danych losowych znaczenie ma maksymalna objêtoœæ i wartoœæ ³upów w miastach.

->Metoda rozwi¹zania
	Skupi³em siê na niezale¿nym u¿yciu dwóch algorytmów: najkrótszej œcie¿ki oraz problemu plecakowego. Algorytm 
najkrótszej œcie¿ki odrobinê zmodyfikowa³em, aby znajdywa³ mi wszystkie najkrótsze œcie¿ki i potem dla
znalezionych œcie¿ek realizowa³em algorytm plecakowy z naciskiem na to, aby dodatkowo otrzymaæ informacjê
o tym, które konkretnie miasta na tej najkrótszej œcie¿ce nale¿y zrabowaæ, aby otrzymaæ najwiêkszy zysk.
	Przedstawiê g³ówne struktury danych, które u¿y³em. Reprezentowa³em zbiór wierzcho³ków jako wektor struktur,
w których przechowywa³em informacje o numerze wierzcho³ka oraz objêtoœci i wartoœci ³upu w nim. Informacje
o krawêdziach zapisywa³em jako listê s¹siedztwa, czyli wektor list. U¿ywa³em te¿ pomocniczych struktur najczêœciej
w postaci list lub wektorów przy realizowania moich dwóch g³ównych algorytmów.

->Funkcjonalna dekompozycja programu na modu³y Ÿród³owe:
	Zastosowa³em 4 g³ówne pliki Ÿród³owe:
	  -KnapsackProblemAlgorithm.h -> s¹ w nim zawarte wszystkie deklaracje struktur danych i metod potrzebnych do
	   rozwi¹zania problemu plecakowego
	  -RandomGraphGenerator.h -> wszystkie deklaracje struktur danych i metod potrzebnych do wygenerowania losowego
	   grafu miast o zadanych parametrach
	  -ReadFromFile.h -> klasa obs³uguj¹ca odczytywanie danych o grafie miast z pliku tekstowego o konkretnym formacie
	   zapisu danych
	` -ShortestPathsAlgorithm -> wszystkie deklaracje struktur danych i metod wykorzystywanych do rozwi¹zania
	   problemu znalezienia wszystkich najkrótszych œcie¿ek w grafie
	  -Vertex.h -> mieœci siê tutaj tylko definicja struktury wierzcho³ka grafu, która jest wykorzystywana przez inne
	   pliki nag³ówkowe

