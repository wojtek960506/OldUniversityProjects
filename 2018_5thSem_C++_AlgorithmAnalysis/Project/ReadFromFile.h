#ifndef READFROMFILE_HPP
#define READFROMFILE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Vertex.h"


using namespace std;
#pragma once



class ReadFromFile
{
private:
	int numberOfVertices;	//ilosc wierzcholkow
	int numberOfEdges;		//ilosc krawedzi
	vector<list<int> > adjList;	//lista sasiedztwa
	vector<vertex> vertices;	//informacje o wierzcho³kach
	string fileName;	//nazwa pliku z którego odczytujemy dane


public:
	ReadFromFile();	//domyœlny konstruktor
	~ReadFromFile(); //domyœlny destruktor
	bool readFromFile(string); //odczyt danych z pliku i zapisanie ich do odpowiednich zmiennych
	int getNumberOfVertices();	//pobranie iloœci wierzcho³ków
	int getNumberOfEdges();	//pobranie iloœci krawêdzi
	vector<vertex> getVertices();	//pobranie informacji o wierzcho³kach
	vector<list<int> > getAdjList(); //pobranie listy s¹siedztwa
	void clearEverything();	//czyscimy wszystko
};

#endif