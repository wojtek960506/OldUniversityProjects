#ifndef SHORTESTPATHALGORITHM_HPP
#define SHORTESTPATHALGORITHM_HPP

#include "ReadFromFile.h"
#include "RandomGraphGenerator.h"
#include <queue>
#include <iomanip>
#include <cstdlib>

class ShortestPathsAlgorithm
{
private:
	vector<vertex> vertices;				//tablica wierzcholkow
	vector< list<int> > adjList;			//lista sasiedztwa
	vector<list<int> > parents;				//lista rodzicow wierzcholkow
	vector<int> levelOfVertices;			//lista odleglosci wierzcholkow od pierwszego wierzcholka
	vector<bool> visited;					//lista odwiedzonych wierzcholkow
	queue<int> verticesQueue;				//kolejka przy wyszukiwaniu najkrotszych sciezek
	vector<int> recursiveVertices;			//wierzcholki odczytane przez rekurencyjne wydobywanie najkrotszych sciezek
	vector< vector<int> > shortestPaths;	//wszystkie najkrotsze sciezki

	int numberOfVertices;					//ilosc wierzcholkow
	int numberOfEdges;						//ilosc krawedzi
	int length = 0;							//dlugosc najkrotszych sciezek
	int numberOfShortestPaths = 0;			//ilosc najkrotszych sciezek
	
public:
	ShortestPathsAlgorithm();	//domyslny konstruktor
	~ShortestPathsAlgorithm();
	ShortestPathsAlgorithm(ReadFromFile*);			//konstruktor, ktory pobiera dane odczytane z pliku
	ShortestPathsAlgorithm(RandomGraphGenerator*);	//konstruktor, ktory pobiera wygenerowane losowo dane
	bool shortestPathsAlgorithm(int, int);			//glowny algorytm do szukania najkrotszych sciezek
	void findShortestPaths(int);	//wywolywana rekurencyjnie funkcja do wyluskania najkrotszych sciezek
	void saveShortestPaths();		//funkcja rekurencyjna oblicza nam raczej niezbyt czytelny ciag cyfr, z ktorego
									//odszyfrowac wszystkie najkrotsze sciezki
	vector<vector<int>> getShortestPaths();	//pobieramy informacje o wszystkich najkrotszych sciezkach
	int getNumberOfVertices();				//pobieramy ilosc wierzcholkow
	int getNumberOfEdges();					//pobieramy ilosc krawedzi
	vector<vertex> getVertices();			//pobieramy informacje o wszystkich wierzcholkach
	vector<list<int> > getAdjList();		//pobieramy liste sasiedztwa
	void clearEverything();					//czyscimy wszystko

	/*//te funkcje posluz¹ do oczyszczenia tych list podczas wywolania konstruktora KnapsackProblemAlgorithm
	vector<list<int> > getParents();		//pobieramy liste rodzicow wierzcholkow
	vector<int> getLevelOfVertices();		//pobieramy liste odleglosci wierzcholkow od pierwszego wierzcholka 
	vector<bool> getVisited();				//pobieramy liste odwiedzonych wierzcholkow
	queue<int> getVerticesQueue();			//pobieramy kolejke przy wyszukiwaniu najkrotszych sciezek
	vector<int> getRecursiveVertices();		//pobieramy wierzcholki odczytane przez rekurencyjne wydobywanie
	*/									//najkrotszych sciezek
	

};

#endif