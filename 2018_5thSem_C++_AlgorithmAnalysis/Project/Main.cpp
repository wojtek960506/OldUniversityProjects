#include <iostream>
#include "ReadFromFile.h"
#include "ShortestPathsAlgorithm.h"
#include "KnapsackProblemAlgorithm.h"
#include "RandomGraphGenerator.h"

#include <chrono>

using namespace std;

struct test{
	int n;
	long long int time;
	double q;

};

//--help
//-h

//--file graphStructure.txt
//-f graphStructure.txt

//--gen
//-g

//-genS 8 (ilosc leveli - maks wyszlo 18)

//-b -100 n -9 -s 200 -i 2 testOfTime.txt

//--first 1 --steps 10 --inst 1

//objetosc plecaka uzywana pryz kazdym rodzaju wywolania programu
#define CAPACITY_OF_KNAPSACK 100
#define MAX_VOLUME 20
#define MAX_BENEFIT 30
#define NUMBER_OF_VERTICES 1000
#define NUMBER_OF_EGDES 1000
#define FIRST_VERTEX 0
#define LAST_VERTEX 499


void findBestPath(ShortestPathsAlgorithm * shortestPathsAlgorithm, int firstVertex, int lastVertex, bool saveToFile);
void writeErrorToFile(string fN, int firstVertex, int lastVertex);
void showHelp();

//zlozonosc do liczenia wspolczynnika q
double functionT(int n) {
	//return n*2;
	return pow(3, n);
}

int main(int argc, char **argv) {

	char c;
	int firstVertex, lastVertex;
	firstVertex = FIRST_VERTEX;
	lastVertex = LAST_VERTEX;
	ReadFromFile readFromFile; // = ReadFromFile();
	ShortestPathsAlgorithm shortestPathsAlgorithm; // = ShortestPathsAlgorithm();
	RandomGraphGenerator randomGraphGenerator; // = RandomGraphGenerator();
	
//------------------------------------------------------------------------------------------------------------------------------------------------
//wyswietlenie pomocy--------------------------------------------------------wyswietlenie pomocy--------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------
	if (argc == 2 && ((strcmp(argv[1], "--help")) == 0 || (strcmp(argv[1], "-h")) == 0) )  {
		showHelp();
	}
	//odczyt z pliku
	else if (argc == 3 && ((strcmp(argv[1], "--file") == 0) || (strcmp(argv[1], "-f") == 0))) {
		readFromFile.readFromFile(argv[2]);
		shortestPathsAlgorithm = ShortestPathsAlgorithm(&readFromFile);
		findBestPath(&shortestPathsAlgorithm, firstVertex, lastVertex, true);
	}

//------------------------------------------------------------------------------------------------------------------------------------------------
//generacja danych losowych-------------------------------------------------generacja danych losowych---------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------
//--gen
	else if ( argc == 2 && (( strcmp(argv[1],"--gen") == 0) || (strcmp(argv[1],"-g") == 0)) ) {
		randomGraphGenerator = RandomGraphGenerator(NUMBER_OF_VERTICES, NUMBER_OF_EGDES, MAX_VOLUME, MAX_BENEFIT);
		randomGraphGenerator.generateGraph();
		chrono::high_resolution_clock::time_point t1, t2;
		long long int timePoint=0;
		t1 = chrono::high_resolution_clock::now();
		shortestPathsAlgorithm = ShortestPathsAlgorithm(&randomGraphGenerator);
		findBestPath(&shortestPathsAlgorithm, firstVertex, lastVertex, true);
		t2 = chrono::high_resolution_clock::now();
		timePoint = chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count();
		//shortestPathsAlgorithm.clearEverything();
	}

//------------------------------------------------------------------------------------------------------------------------------------------------
//generacja losowych danych do testowania czasu-------------------------------generacja losowych danych do testowania czasu-----------------------
//------------------------------------------------------------------------------------------------------------------------------------------------
//-b 500 -n 9 -s 500 -i 2 testOfTime.txt
	else if (argc == 10 && (strcmp(argv[1], "-b") == 0) && (strcmp(argv[3], "-n") == 0)
			&& (strcmp(argv[5], "-s") == 0)	&& (strcmp(argv[7], "-i") == 0)) {
		//string fN = "testOfTime.txt";
		string fN = argv[9];

		ofstream myFile(fN);

		if (!myFile.is_open()) {
			cout << "Unable to open a file " + fN << endl;
			char c;
			cin >> c;
			return 0;
		}

		chrono::high_resolution_clock::time_point t1, t2;
		int beginVertices = atoi(argv[2]);
		int numberOfVertices = beginVertices;
		int numberOfSteps = atoi(argv[4]);
		int stepValue = atoi(argv[6]);
		int numberOfInstances = atoi(argv[8]);

		//do oszacowania zlozonosci
		vector<long long int> times;
		vector<long int> vertices;
		vector<double> q;

		for (int i = 0; i < numberOfSteps; i++) {
			for (int j = 0; j < numberOfInstances; j++) {
				randomGraphGenerator = RandomGraphGenerator(numberOfVertices, numberOfVertices*2, MAX_BENEFIT, MAX_VOLUME);
				randomGraphGenerator.generateGraph();
				long long int timePoint = 0;
				t1 = chrono::high_resolution_clock::now();
				shortestPathsAlgorithm = ShortestPathsAlgorithm(&randomGraphGenerator);
				findBestPath(&shortestPathsAlgorithm, firstVertex, lastVertex, false);
				t2 = chrono::high_resolution_clock::now();
				timePoint = chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count();
				
				times.push_back(timePoint);
				vertices.push_back(numberOfVertices);
				randomGraphGenerator.clearEverything();
			}
			numberOfVertices += stepValue;	
		}

		//liczymy q
		int medianaIndex;
		if (times.size() % 2 == 1) { //nieparzysta ilosc
			medianaIndex = (times.size() + 1) / 2-1;
		}
		else {
			medianaIndex = times.size() / 2-1;
		}

		int w = 15;
		myFile << "GENERACJA LOSOWYCH DANYCH DO TESTOWANIA CZASU" << endl << endl;
		myFile << setw(w) << "n" << setw(w) <<  "t(n)[ns]" << setw(w) << "q(n)" <<endl;
		for (int i = 0; i < times.size(); i++) {
			double temp;
			temp = (times[i] * functionT(vertices[medianaIndex])) / (functionT(vertices[i])*times[medianaIndex]);
			q.push_back(temp);
			//myFile << setw(w) << vertices[i] << setw(w) << times[i] << setw(w) << temp << endl;
			myFile << vertices[i] << "\t" << times[i] << "\t" << temp << endl;
		}
		myFile.close();
	}

//------------------------------------------------------------------------------------------------------------------------------------------------
//generacja szczegolnego przypadku---------------------------------------generacja szczegolnego przypadku-----------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------

	else if (argc == 3 && (strcmp(argv[1], "-genS") == 0)) {
		randomGraphGenerator = RandomGraphGenerator(MAX_VOLUME, MAX_BENEFIT);
		randomGraphGenerator.generateSpecialGraph(atoi(argv[2]));
		shortestPathsAlgorithm = ShortestPathsAlgorithm(&randomGraphGenerator);
		findBestPath(&shortestPathsAlgorithm, 0, 2*atoi(argv[2])+1, true);
	}

//------------------------------------------------------------------------------------------------------------------------------------------------
//generacja danych szczegolnych do testowania czasu-------------------------generacja danych szczegolnych do testowania czasu---------------------
//------------------------------------------------------------------------------------------------------------------------------------------------
//--first 1 --steps 14 --inst 1
	else if (argc == 7 && (strcmp(argv[1], "--first") == 0) && (strcmp(argv[3], "--steps") == 0) && (strcmp(argv[5], "--inst") == 0)) {
		int levels = atoi(argv[2]);
		int firstLevel = levels;
		int steps = atoi(argv[4]);
		int instances = atoi(argv[6]);
		string fN = "testOfTime.txt";

		ofstream myFile(fN);

		if (!myFile.is_open()) {
			cout << "Unable to open a file " + fN << endl;
			char c;
			cin >> c;
			return 0;
		}

		chrono::high_resolution_clock::time_point t1, t2;
		
		//do oszacowania zlozonosci
		vector<long long int> times;
		vector<long int> vertices;
		vector<double> q;

		for (int i = 0; i < steps; i++) {
			for (int j = 0; j < instances; j++) {
				//za kazdym obiegiem tworzymy nowy obiekt do generowania danych szczegolnych
				RandomGraphGenerator specialGenerator = RandomGraphGenerator(MAX_VOLUME, MAX_BENEFIT);
				specialGenerator.generateSpecialGraph(levels);
				long long int timePoint = 0;
				t1 = chrono::high_resolution_clock::now();
				shortestPathsAlgorithm = ShortestPathsAlgorithm(&specialGenerator);
				findBestPath(&shortestPathsAlgorithm, 0, 2 * levels + 1, false);
				t2 = chrono::high_resolution_clock::now();
				timePoint = chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count();

				times.push_back(timePoint);
				vertices.push_back(2 * levels + 1);
			}
			levels++;
		}

		int medianaIndex;

		int last = 2 * (levels-1) + 1;
		if (times.size() % 2 == 1) { //nieparzysta ilosc
			medianaIndex = (times.size() + 1) / 2-1;
		}
		else {
			medianaIndex = (times.size()) / 2-1;
		}

		int w1 = 5;
		int w = 15;
		myFile << setw(w1) << "levels" << setw(w1) << "n" << setw(w) << "t(n)[ns]" << setw(w) << "q(n)" << endl;
		for (int i = 0; i < times.size(); i++) {
			double temp;
			temp = (times[i] * functionT(medianaIndex)) / (functionT(i)*times[medianaIndex]);
			q.push_back(temp);
			myFile << setw(w1) << firstLevel + i << setw(w1) << vertices[i] << setw(w) << times[i] << setw(w) << temp << endl;
		}
		myFile.close();
	}

	else {
		cout << "blad argumentow" << endl;
		return -1;
	}
	
	//system("pause");
	return 0;
}

//------------------------------------------------------------------------------------------------------------------------------------------------
//FUNKCJE--------FUNKCJE--------FUNKCJE--------FUNKCJE--------FUNKCJE--------FUNKCJE--------FUNKCJE--------FUNKCJE--------FUNKCJE--------FUNKCJE--
//------------------------------------------------------------------------------------------------------------------------------------------------
void findBestPath(ShortestPathsAlgorithm * shortestPathsAlgorithm,int firstVertex, int lastVertex, bool saveToFile) {
	bool b = shortestPathsAlgorithm->shortestPathsAlgorithm(firstVertex, lastVertex);

	if (b) {
		//istnieje co najmniej jedna najkrotsza sciezka
		KnapsackProblemAlgorithm knapsackProblemAlgorithm = KnapsackProblemAlgorithm(shortestPathsAlgorithm, CAPACITY_OF_KNAPSACK);
		knapsackProblemAlgorithm.findBestEscapeRoute();
		if (saveToFile)
			knapsackProblemAlgorithm.bestRouteDetails(firstVertex, lastVertex, "finalResults.txt");
	}
	else {
		//nie istnieje najkrotsza sciezka
		if (saveToFile)	//przy liczeniu czasow nie chcemy nic zapisywac do pliku
			writeErrorToFile("finalResults.txt", firstVertex, lastVertex);
	}
}

//zapis nieznalezienia sciezki
void writeErrorToFile(string fN, int firstVertex, int lastVertex) {
	ofstream myFile(fN);

	if (myFile.is_open()) {
		myFile << "There is not shortest path between vertices " << firstVertex << " and " << lastVertex << ".";
	}
	else {
		cout << "Unable to open a file " + fN << endl;
		char c;
		cin >> c;
	}
}

void showHelp() {
	std::string line;
	std::string code = setlocale(LC_CTYPE, "");
	std::ifstream myfile;
	myfile.open("help.txt");
	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			std::cout << line << '\n';
		}
		myfile.close();
	}
	else std::cout << "Unable to open file";
}