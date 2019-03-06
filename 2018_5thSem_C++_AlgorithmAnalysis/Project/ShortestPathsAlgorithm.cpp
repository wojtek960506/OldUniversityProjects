#include "ShortestPathsAlgorithm.h"

using namespace std;

ShortestPathsAlgorithm::ShortestPathsAlgorithm(){}

ShortestPathsAlgorithm::~ShortestPathsAlgorithm(){}

ShortestPathsAlgorithm::ShortestPathsAlgorithm(ReadFromFile * rff) {
	vertices = rff->getVertices();
	adjList = rff->getAdjList();
	numberOfVertices = rff->getNumberOfVertices();
	numberOfEdges = rff->getNumberOfEdges();

	for (int i = 0; i < numberOfVertices; i++){
		
		list<int> l = list<int>();
		parents.push_back(l);
		visited.push_back(false);
		levelOfVertices.push_back(0); //jak daleko od pierwszego wierzcholka sa inne wierzcholki
	}

	//czyscimy te listy, bo nie bêd¹ nam ju¿ potrzebne
	rff->clearEverything();
	
}

ShortestPathsAlgorithm::ShortestPathsAlgorithm(RandomGraphGenerator * rgg) {
	adjList = rgg->getAdjList();
	vertices = rgg->getVertices();
	numberOfVertices = rgg->getNumberOfVertices();
	numberOfEdges = rgg->getNumberOfEdges();

	for (int i = 0; i < numberOfVertices; i++){
		list<int> l = list<int>();
		parents.push_back(l);
		visited.push_back(false);
		levelOfVertices.push_back(0); //jak daleko od pierwszego wierzcholka sa inne wierzcholki
	}
	rgg->clearEverything();
}



bool ShortestPathsAlgorithm::shortestPathsAlgorithm(int firstVertex, int lastVertex) {
	if (firstVertex > numberOfVertices - 1 || firstVertex < 0 || lastVertex > numberOfVertices - 1 || lastVertex < 0 || firstVertex == lastVertex)
		return false;

	int currentVertex;
	bool found = false; //zeby sprawdzic czy znalezlismy co najmniej jedna najkrotsza sciezke
	parents[firstVertex].push_back(-1);
	verticesQueue.push(firstVertex);
	visited[firstVertex] = true;

	while (!verticesQueue.empty()) {
		currentVertex = verticesQueue.front(); //bierzemy pierwszy element z kolejki
		verticesQueue.pop();	//usuwamy ten element z kolejki
		if (currentVertex == lastVertex) {	//doszlismy do ostatniego wierzcholka, co oznacza, ze istnieje
											//co najmniej jedna sciezka, ktorej poszukiwalismy
			found = true;
			break;
		}
		//sprawdzamy wszystkie wierzcholki, ktore sa polaczone z danym
		list<int> tempList = adjList[currentVertex];
		for (int tempVertex : tempList) {
			if (!visited[tempVertex]) {
				//currentVertex jest rodzicem weirzcholka, ktory jest w jego liscie sasiedztwa
				parents[tempVertex].push_back(currentVertex);
				//currentVertex is parent of tempVertex, so tempVertex is
				//one level higher than currentVertex
				levelOfVertices[tempVertex] = levelOfVertices[currentVertex]+1;
				length = max(length,levelOfVertices[tempVertex]);
				verticesQueue.push(tempVertex);
				visited[tempVertex] = true; //nie chcemy aby wierzcholek byl ponownie sprawdzany
			}
			//jezeli currentVertex byl tak samo oddalony od rodzicow tempVertexa,
			//ale byl juz sprawdzany to tez przez niego moze przebiegac najkrotsza sciezka 
			else if (	parents[tempVertex].front()>=0 && !(parents[tempVertex].size() == 0) &&
						levelOfVertices[currentVertex] == levelOfVertices[parents[tempVertex].front()])
			{
				parents[tempVertex].push_back(currentVertex);
			}
		}
	}

	if (found) {	
		length = levelOfVertices[lastVertex];	//upewniamy sie, ze dlugosc tej sciezki to odleglosc
												//ostatniego wierzcholka od pierwszego
		findShortestPaths(lastVertex);
		saveShortestPaths();
		return true;	//znalezlismy co najmniej jedna najkrotsza sciezke, wiec zwracamy prawde
	}
	else
		return false;	//nie znalezlismy zadnej najkrotszej sciezki
}

void ShortestPathsAlgorithm::saveShortestPaths() {
	int a = 0;
	for (int i = 0; i < numberOfShortestPaths; i++) {
		vector<int> tempV = vector<int>();
		shortestPaths.push_back(tempV);
	}
	int first = recursiveVertices[0]; //zapisujemy pierwszy (od tylu) element, bo on bêdzie w ka¿dej œcie¿ce
	for (int i = 0; i < recursiveVertices.size(); i++) {
		if (i == 0) //trzeba uniknac wyjscia poza wektor
			shortestPaths[a].push_back(recursiveVertices[i]);
		else {
			if (levelOfVertices[recursiveVertices[i]] > levelOfVertices[recursiveVertices[i - 1]]) {
				++a;
				int tempIndex = i;
				int lvl = levelOfVertices[recursiveVertices[i]]; //level obecnego wierzcholka
				int differenceLvl = length - lvl; //sprawdzamy ile nam brakuje elementów, w œcie¿ce
				int flag = 1; //flaga do wstawienia pierwszego elementu
				while (differenceLvl != 0) {
					if (flag == 1) {
						shortestPaths[a].push_back(first);
						flag = 0;
						--differenceLvl; //wstawilismy jeden z brakujacych elementow
					}
					//musimy jeszcze wstawic wszystkie pozostale ; jezeli w naszej liscie pozyskanej z rekurencji
					//dany wierzcholek jest dalej od poczatku niz jego poprzednik na tej liscie, to znaczy, ¿e
					//musimy uzupelnic nasza sciezke o wierzcholki, ktore byly dla tych sciezek wspolne
					else {
						while (levelOfVertices[recursiveVertices[tempIndex]] != (lvl + differenceLvl)) {
							--tempIndex; //cofamy sie do pierwszego elementu, ktory chcey wstawic
						}
						shortestPaths[a].push_back(recursiveVertices[tempIndex]);
						tempIndex = i; //wracamy do naszego elementu
						--differenceLvl; //znalezlismy kolejny element
					}
				}
				shortestPaths[a].push_back(recursiveVertices[i]);
			}
			else
				shortestPaths[a].push_back(recursiveVertices[i]);
		}
	}
}

//rekurencyjna funkcja do zapisu znalezienia wszystkich najkrotszych sciezek
void ShortestPathsAlgorithm::findShortestPaths(int vNum) {
	list<int> listTemp = parents[vNum];
	recursiveVertices.push_back(vNum);	//umieszczamy wierzcholek na liscie, z ktorej potem bedziemy wyluskiwali
										//wszystkie najkrotsze sciezki
	for (int n : listTemp) {	//przegladamy wszystkich rodzicow danego wierzcholka
		if (n != -1)
			findShortestPaths(n);	//wywolujemy rekurencyjne sprawdzanie
		else {
			//doszlismy do konca sciezki, wiec zwiekszamy ich ilosc najkrotszych sciezek
			++numberOfShortestPaths;
			return;
		}
	}
}

vector<vector<int>> ShortestPathsAlgorithm::getShortestPaths() {
	return shortestPaths;
}

int ShortestPathsAlgorithm::getNumberOfVertices() {
	return numberOfVertices;
}

int ShortestPathsAlgorithm::getNumberOfEdges() {
	return numberOfEdges;
}

vector<vertex> ShortestPathsAlgorithm::getVertices() {
	return vertices;
}

vector<list<int> > ShortestPathsAlgorithm::getAdjList() {
	return adjList;
}

void ShortestPathsAlgorithm::clearEverything() {	
	vertices.clear();
	adjList.clear();
	shortestPaths.clear();
	parents.clear();
	levelOfVertices.clear();
	visited.clear();
	recursiveVertices.clear();
	numberOfShortestPaths = 0;
	numberOfEdges = 0;
	numberOfVertices = 0;
	length = 0;
}

/*
vector<list<int> > ShortestPathsAlgorithm::getParents() {
	return parents;
}

vector<int> ShortestPathsAlgorithm::getLevelOfVertices() {
	return levelOfVertices;
}

vector<bool> ShortestPathsAlgorithm::getVisited() {
	return visited;
}

queue<int> ShortestPathsAlgorithm::getVerticesQueue() {
	return verticesQueue;
}

vector<int> ShortestPathsAlgorithm::getRecursiveVertices() {
	return recursiveVertices;
}
*/