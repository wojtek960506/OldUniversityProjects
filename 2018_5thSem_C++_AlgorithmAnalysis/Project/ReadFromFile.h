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
	vector<vertex> vertices;	//informacje o wierzcho�kach
	string fileName;	//nazwa pliku z kt�rego odczytujemy dane


public:
	ReadFromFile();	//domy�lny konstruktor
	~ReadFromFile(); //domy�lny destruktor
	bool readFromFile(string); //odczyt danych z pliku i zapisanie ich do odpowiednich zmiennych
	int getNumberOfVertices();	//pobranie ilo�ci wierzcho�k�w
	int getNumberOfEdges();	//pobranie ilo�ci kraw�dzi
	vector<vertex> getVertices();	//pobranie informacji o wierzcho�kach
	vector<list<int> > getAdjList(); //pobranie listy s�siedztwa
	void clearEverything();	//czyscimy wszystko
};

#endif