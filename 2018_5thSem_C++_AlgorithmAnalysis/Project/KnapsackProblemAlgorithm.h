	

#ifndef KNAPSACKPROBLEMALGORITHM_HPP
#define KNAPSACKPROBLEMALGORITHM_HPP

#include "ShortestPathsAlgorithm.h"
#include <algorithm>
#include <fstream>

#pragma once
class KnapsackProblemAlgorithm
{
private:
	vector<vertex> vertices;				//tablica wierzcholkow
	vector< list<int> > adjList;			//lista sasiedztwa
	vector< vector<int> > shortestPaths;	//wszystkie najkrotsze sciezki
	vector< vector<int> > whereToRob;		//miejsca w ktorych ma robowac i jakie zyski
	vector< int > theBestRobbery;			//najlepsza opcja rabunku
	
	int numberOfVertices;					//ilosc wierzcholkow
	int numberOfEdges;						//ilosc krawedzi
	int capacityOfKnapsack;					//pojemnosc plecaka

public:
	KnapsackProblemAlgorithm();	//domyslny konstruktor
	~KnapsackProblemAlgorithm();	//domyslny destruktor
	//konstruktor przejmujacy informacje o grafie i najkrotszych sciezkach oraz pojemnosci
	KnapsackProblemAlgorithm(ShortestPathsAlgorithm*,int);	//plecaka
	void findBestEscapeRoute();	//znajdujemy najlepsza droge ucieczki
	void checkBestBenefit(vector<vertex>,vector<int>, int index);	
	void bestRouteDetails(int,int, string);	//zapisujemy wynik do pliku
private:
	//pomocnicza funkcja do odczytu, ktore miasta naleyz napasc
	void whatIsIn(string, vector<int> *, int);	
};

#endif