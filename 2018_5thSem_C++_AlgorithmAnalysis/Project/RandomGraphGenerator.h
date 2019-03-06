#ifndef RANDOMGRAPHGENERATOR_HPP
#define RANDOMGRAPHGENERATOR_HPP

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <random>
#include "Vertex.h"

using namespace std;


class RandomGraphGenerator
{
private:
	int numberOfEdges;		//ilosc wierzcholkow
	int numberOfVertices;	//ilosc krawedzi
	int maxVolume;			//maksymalna objetosc lupu w wierzcholku przy losowaniu
	int maxBenefit;			//maksymalna wartosc lupu w wierzcholku przy losowaniu
	vector<list<int> > adjList; //lista sasiedztwa
	vector<vertex> vertices;	//informacje o wszystkich wierzcholkach

public:
	RandomGraphGenerator();	//konstruktor domyœlny
	RandomGraphGenerator(int, int, int, int);	//konstruktor, którym okreslamy ilosc wierzcholkow,
	//ilosc krawedzi oraz maksymalne objetosci i wartosci lupow przy losowaniu
	RandomGraphGenerator(int, int); //konstruktor, w którym okreslamy maksymalne objetosci
	//i wartosci lupow przy losowaniu
	~RandomGraphGenerator(); //domyslny destruktor

	void generateGraph();	//generowanie calkowicie losowego grafu
	void generateSpecialGraph(int);	//generowanie grafu o konkretnej strukturze
	int getNumberOfVertices();	//pobranie ilosci wierzcholkow
	int getNumberOfEdges();	//pobranie ilosci krawedzi
	vector<vertex> getVertices();	//pobranie informacji o wierzcholkach
	vector<list<int> > getAdjList(); //pobranie informacji o krawedziach
	void clearEverything();	//czyscimy wszystko
};

#endif