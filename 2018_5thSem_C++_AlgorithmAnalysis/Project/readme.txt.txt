Wojciech Zieli�ski nr indeksu: 281 280
AAL-9-LS rabu�
Temat projektu:
"�cigany przez krajowe s�u�by rabu� zabytk�w zmuszony jest ucieka� za granic�.
Nale�y zaproponowa� mu drog� prowadz�c� przez najmniejsz� ilo�� miast, gdy�
tam g��wnie czaj� si� patrole policji. Chciwy rabu� palnuje po drodze dokona�
intratnych rabie�y, ale podr�uje samochodem z ograniczon� pojemno�ci� baga�nika.
Pom� rabusiowi wybra� najbardziej op�acalne napady na drodze jego najkr�tszej
ucieczki za granic�. Danymi wej�ciowymi s� graf miast, pojemno�� baga�nika,
po�o�enie �up�w oraz ich wielko�ci i warto�ci."

->Mo�liwe polecenia aktywacji programu:
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
->Opis konwencji dotycz�cych danych wej�ciowych i prezentacji wynik�w:
	W przypadku aktywacji programu sposobem 1 lub 2 otrzymane wyniki s� zapisywane do pliku.
Jest tam informacja o tym pomi�dzy, kt�rymi wierzcho�kami by�a szukana droga ucieczki, proponowana
droga ucieczki, miejsca gdzie nale�y dokona� rabunk�w, aby zmaksymalizowa� zysk oraz ca�kowita warto��
tych�e rabunk�w.
	Dane wej�ciowe to tablica wierzcho�k�w (miast), z informacjami o numerze wierzcho�ka oraz warto�ci
i obj�to�ci �up�w w nim, obj�to�� plecaka, pierwszy i ostatni wierzcho�ek. Dodatkowo w przypadku generowania
danych losowych znaczenie ma maksymalna obj�to�� i warto�� �up�w w miastach.

->Metoda rozwi�zania
	Skupi�em si� na niezale�nym u�yciu dw�ch algorytm�w: najkr�tszej �cie�ki oraz problemu plecakowego. Algorytm 
najkr�tszej �cie�ki odrobin� zmodyfikowa�em, aby znajdywa� mi wszystkie najkr�tsze �cie�ki i potem dla
znalezionych �cie�ek realizowa�em algorytm plecakowy z naciskiem na to, aby dodatkowo otrzyma� informacj�
o tym, kt�re konkretnie miasta na tej najkr�tszej �cie�ce nale�y zrabowa�, aby otrzyma� najwi�kszy zysk.
	Przedstawi� g��wne struktury danych, kt�re u�y�em. Reprezentowa�em zbi�r wierzcho�k�w jako wektor struktur,
w kt�rych przechowywa�em informacje o numerze wierzcho�ka oraz obj�to�ci i warto�ci �upu w nim. Informacje
o kraw�dziach zapisywa�em jako list� s�siedztwa, czyli wektor list. U�ywa�em te� pomocniczych struktur najcz�ciej
w postaci list lub wektor�w przy realizowania moich dw�ch g��wnych algorytm�w.

->Funkcjonalna dekompozycja programu na modu�y �r�d�owe:
	Zastosowa�em 4 g��wne pliki �r�d�owe:
	  -KnapsackProblemAlgorithm.h -> s� w nim zawarte wszystkie deklaracje struktur danych i metod potrzebnych do
	   rozwi�zania problemu plecakowego
	  -RandomGraphGenerator.h -> wszystkie deklaracje struktur danych i metod potrzebnych do wygenerowania losowego
	   grafu miast o zadanych parametrach
	  -ReadFromFile.h -> klasa obs�uguj�ca odczytywanie danych o grafie miast z pliku tekstowego o konkretnym formacie
	   zapisu danych
	` -ShortestPathsAlgorithm -> wszystkie deklaracje struktur danych i metod wykorzystywanych do rozwi�zania
	   problemu znalezienia wszystkich najkr�tszych �cie�ek w grafie
	  -Vertex.h -> mie�ci si� tutaj tylko definicja struktury wierzcho�ka grafu, kt�ra jest wykorzystywana przez inne
	   pliki nag��wkowe

