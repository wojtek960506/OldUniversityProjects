#include "ReadFromFile.h"



ReadFromFile::ReadFromFile()
{
	numberOfVertices = 0;
	numberOfEdges = 0;
}


ReadFromFile::~ReadFromFile()
{
	//delete volumesTable;
	//delete benefitsTable;
}


bool ReadFromFile::readFromFile(string fN) {
	fileName = fN;

	string line; //just to read lines which are only for better design of text file
	ifstream myfile(fileName);
	if (myfile.is_open())
	{
		myfile >> line; //now we read number of vertices and edges
		myfile >> numberOfVertices >> numberOfEdges;

		myfile >> line; //now we read volume and benefit for each vertex
		for (int i = 0; i < numberOfVertices; i++) { //we fill table with empty lists
			list<int> l = list<int>();
			adjList.push_back(l);
			vertex v;
			myfile >> v.volume >> v.benefit;
			v.number = i;
			vertices.push_back(v);
		}

		myfile >> line; //now we read informations about edges
		for (int i = 0; i < numberOfEdges; i++) { //we fill lists with edges
			int v1, v2;
			myfile >> v1 >> v2;
			
			//our graph is not directed
			if (v1 != v2) {
				adjList[v1].push_back(v2);
				adjList[v2].push_back(v1);
			}
		}
		myfile.close();
		return true;
	}

	else cout << "Unable to open file";
	return false;
}

int ReadFromFile::getNumberOfVertices() {
	return numberOfVertices;
}

int ReadFromFile::getNumberOfEdges() {
	return numberOfEdges;
}

vector<vertex> ReadFromFile::getVertices() {
	return vertices;
}

vector<list<int> > ReadFromFile::getAdjList() {
	return adjList;
}

void ReadFromFile::clearEverything() {
	for (int i = 0; i < adjList.size(); i++) {
		adjList.at(i).clear();
	}
	vertices.clear();
	adjList.clear();
	numberOfEdges = 0;
	numberOfVertices = 0;
}