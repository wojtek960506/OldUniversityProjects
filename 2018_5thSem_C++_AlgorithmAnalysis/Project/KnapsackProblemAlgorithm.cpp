#include "KnapsackProblemAlgorithm.h"

KnapsackProblemAlgorithm::KnapsackProblemAlgorithm(){}

KnapsackProblemAlgorithm::~KnapsackProblemAlgorithm(){}

//przekazujemy to co odczytalismy z pliku i to co obliczysmy w najkrotszych sciezkach 
KnapsackProblemAlgorithm::KnapsackProblemAlgorithm(ShortestPathsAlgorithm* spa, int c){
	vertices = spa->getVertices();
	adjList = spa->getAdjList();
	numberOfVertices = spa->getNumberOfVertices();
	numberOfEdges = spa->getNumberOfEdges();
	shortestPaths = spa->getShortestPaths();
	capacityOfKnapsack = c;

	//usuwamy wszystkie struktury danych uzywane podczas liczenia najkrotszych sciezek, gdy¿ nie bêd¹
	//nam ju¿ potrzebne i nie chcemy, ¿eby zaœmieca³y nam pamiêæ
	spa->clearEverything();
}

//funkcja pomocnicza do wyluskania miast ktore nalezy napasc, ktore zostaly zapisane jako char
void KnapsackProblemAlgorithm::whatIsIn(string s,vector<int> * vectTemp, int index) {
	int l = s.length();	//ilosc rabunkow
	string str;
	for (int i = 0; i<l; i++) {	
		int temp = (int)(s.at(i));	//zapisywalismy kod ascii liter i teraz odczytujemy go z  
		int z = temp - 96-1;
		
		//przy pierwotnym zapisie sciezek wierzcholki byly zapisywane w odwrotnej kolejnosci, wiec wstawiamy je odwrotnie
		vectTemp->insert(vectTemp->begin(), shortestPaths[index][shortestPaths[index].size() -1 - z]);
	}
}

void KnapsackProblemAlgorithm::findBestEscapeRoute() {
	//obliczamy dla kazdej sciezki maksymalna wartosc rabunku i to gdzie te rabunki maja byc wykonane
	int maxRobbery = 0;
	int pathWithMaxRobbery=0;

	for (int i = 0; i < shortestPaths.size(); i++) {
		checkBestBenefit(vertices, shortestPaths[i],i);
		if (whereToRob[i][0] > maxRobbery)
			maxRobbery = whereToRob[i][0];
		
		//maxRobbery = max(maxRobbery, whereToRob[i][0]); //w pierwszym elemencie danego wektora jest zapisana wartosc rabunku
		if (maxRobbery == whereToRob[i][0])
			pathWithMaxRobbery = i;
	}

	theBestRobbery.push_back(pathWithMaxRobbery); //najpierw zapisujemy numer sciezki
	theBestRobbery.push_back(maxRobbery); //potem zapisujemy wartosc rabunku
	
	for (int i = whereToRob[pathWithMaxRobbery].size() - 1; i >=1 ; i--)
		theBestRobbery.push_back(whereToRob[pathWithMaxRobbery][i]); //na koniec dodajemy "wierzcholki" w ktorych beda rabunki
}

void KnapsackProblemAlgorithm::checkBestBenefit(vector<vertex> vertices, vector<int> path, int index) {
	int length = path.size(); //dlugosc sciezki

	//liczymy elementy od tego z indeksem 1
	int *volumes = new int[length+1];		//tablica objetosci przedmiotow z danej sciezki
	int *benefits = new int[length+1];		//tablica wartosci przedmiotow z danej sciezki
	int *numbers = new int[length + 1];		//tablica numerow wierzcholkow na œcie¿ce

	//indeks o numerze 0 jest pomocniczy do realizacji algorytmu
	volumes[0] = 0;
	benefits[0] = 0;
	numbers[0] = -1;
	int i, j;

	for (i = 1,j=length-1; i < length + 1; i++,j--) {
		numbers[i] = vertices[path[j]].number;
	}
	for (int i = 1; i < length + 1; i++) {
		volumes[i] = vertices[numbers[i]].volume;
		benefits[i] = vertices[numbers[i]].benefit;
	}

	char char1; //pomocnicza zmienna, zeby zobaczyc ktore produkty wybrane zostaly


	int ** A = new int *[length + 1];		//tablica do algorytmu sprawdzania maksymalnej wartosci
	string ** S = new string *[length + 1]; //do sprawdzania które produkty zostaly wybrane 

	for (i = 0; i < length + 1; i++) {
		A[i] = new int[capacityOfKnapsack + 1];
		S[i] = new string[capacityOfKnapsack + 1];
	}

	//ustawiamy poczatkowe wartosci dla tablic A i S
	for (i = 0; i < length+1; i++) {
		A[i][0] = 0;
		S[i][0] = "";
	}
	for (j = 0; j < capacityOfKnapsack+1; j++) {
		A[0][j] = 0;
		S[0][j] = "";
	}


	for (i = 1; i < length + 1; i++) {
		char1 = char(i + 96); //'a' ma kod ASCII 96 
		for (j = 0; j < capacityOfKnapsack+1; j++) {
			if (volumes[i]>j) {
				A[i][j] = A[i - 1][j];
				S[i][j] = S[i - 1][j];
			}
			else {
				A[i][j] = max(A[i - 1][j], A[i - 1][j - volumes[i]] + benefits[i]);
				if (A[i][j] == (A[i - 1][j - volumes[i]] + benefits[i])) { //sprawdzamy czy dodalismy nowy element do plecaka
					S[i][j] = S[i - 1][j - volumes[i]] + char1;		//jezeli tak, to dolaczamy kolejna litere reperzentujaca ktory element
																	//zostal dodany
				}
				else S[i][j] = S[i - 1][j]; //jak nie to nie dodajemy tej litery
			}
		}
	}

	int maxValue = A[length][capacityOfKnapsack]; //wartosc w prawym dolnym rogu tej macierzy to maksymalna wartosc w plecaku

	vector<int> vectTemp = vector<int>();	//pierwsza wartosc w naszym wektorze to maksymalna wartosc dla danego zestawu danych
	
	whatIsIn(S[length][capacityOfKnapsack],&vectTemp, index); //musimy wyluskac informacje o tym ktore miasta trzeba napasc
	
	vectTemp.insert(vectTemp.begin(), maxValue); //na koniec dolaczamy informacje o tym jaka jest wartosc tych rabunkow
	whereToRob.push_back(vectTemp); //dodajemy obliczona wartosc rabunkow i miejsca rabunkow dla konkretnej sciezki
	
	vectTemp.clear();


	delete A, S;
}

void KnapsackProblemAlgorithm::bestRouteDetails(int v1,int v2, string fN) {
	
	ofstream myFile(fN);
	
	if (myFile.is_open()) {
		myFile << "PROPONUJE TAKA DROGE UCIECZKI POMIEDZY MIASTAMI " << v1 << " i " << v2 << "." << endl;

		myFile << endl << "Miasta, ktore nalezy kolejno odwiedzic: ";
		for (int i = shortestPaths[theBestRobbery[0]].size() - 1; i >= 0; i--) {
			if (i != 0)
				myFile << shortestPaths[theBestRobbery[0]][i] << " -> ";
			else
				myFile << shortestPaths[theBestRobbery[0]][i] << endl;
		}
		myFile << endl << "Maksymalna wartosc lupow wynosi " << theBestRobbery[1] << "." << endl;
		myFile << endl << "Musimy napasc na miasta ";

		for (int i = 2; i < theBestRobbery.size(); i++) {
			if (i != theBestRobbery.size() - 1)
				myFile << theBestRobbery[i] << " , ";
			else
				myFile << theBestRobbery[i] << ".";
		}
	}
	else {
		cout << "Unable to open a file " + fN << endl;
		char c;
		cin >> c;
	}
}





