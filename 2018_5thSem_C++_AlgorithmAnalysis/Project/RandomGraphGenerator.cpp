#include "RandomGraphGenerator.h"

RandomGraphGenerator::RandomGraphGenerator(){
	numberOfVertices = 0;
	numberOfEdges = 0;
	maxVolume = 0;
	maxBenefit = 0;
}

RandomGraphGenerator::RandomGraphGenerator(int numOfVert, int numOfEdges, int maxB, int maxV) {
	numberOfVertices = numOfVert;
	numberOfEdges = numOfEdges;
	maxBenefit = maxB;
	maxVolume = maxV;
}

RandomGraphGenerator::RandomGraphGenerator(int maxB, int maxV) {
	maxBenefit = maxB;
	maxVolume = maxV;
}


RandomGraphGenerator::~RandomGraphGenerator() {
	adjList.clear();
	vertices.clear();
}

//generujemy grfaf, w ktorym bedzie duzo najdluzszych sciezek
void RandomGraphGenerator::generateSpecialGraph(int specialLevels) {
	if (specialLevels < 1) return;
	adjList.clear();
	vertices.clear();
	numberOfVertices = 2 * specialLevels + 2;
	numberOfEdges = (specialLevels - 1) * 4 + 4;

	int i;
	for (i = 0; i < numberOfVertices; i++) {
		mt19937 rng;
		rng.seed(random_device()());
		uniform_int_distribution<mt19937::result_type> dist(1, maxVolume);
		mt19937 rng2;
		rng2.seed(random_device()());
		uniform_int_distribution<mt19937::result_type> dist2(1, maxBenefit);
		vertex v;
		v.number = i;
		v.volume = dist(rng);
		v.benefit = dist2(rng2);
		vertices.push_back(v);

		list<int> l = list<int>(); //kazdy wierzcholek ma swoje miejsce w tej tablicy
		adjList.push_back(l);
	}
	
	adjList[0].push_back(1);
	adjList[0].push_back(2);
	adjList[numberOfVertices - 1].push_back(numberOfVertices - 2);
	adjList[numberOfVertices - 1].push_back(numberOfVertices - 3);

	//dodajemy polaczenia miedzy levelami sasiednimi. na danym levelu sa dwa wierzcholki
	for (i = 1; i <= specialLevels; i++) {
		//ten po lewej
		adjList[2 * i - 1].push_back(2 * i - 2);
		adjList[2 * i - 1].push_back(2 * i + 1);
		//ten po prawej
		adjList[2 * i].push_back(2 * i - 2);
		adjList[2 * i].push_back(2 * i + 1);

		if (i != 1) {
			//ten po lewej
			adjList[2 * i - 1].push_back(2 * i - 3);
			//ten po prawej
			adjList[2 * i].push_back(2 * i - 3);
		}

		if (i != specialLevels) {
			//ten po lewej
			adjList[2 * i - 1].push_back(2 * i + 2);
			//ten po prawej
			adjList[2 * i].push_back(2 * i + 2);
		}
	}
		
}

void RandomGraphGenerator::generateGraph() {
	int i;
	for (i = 0; i < numberOfVertices; i++) {
		mt19937 rng;
		rng.seed(random_device()());
		uniform_int_distribution<mt19937::result_type> dist(1, maxVolume);
		mt19937 rng2;
		rng2.seed(random_device()());
		uniform_int_distribution<mt19937::result_type> dist2(1, maxBenefit);
		vertex v;
		v.number = i;
		v.volume = dist(rng);
		v.benefit = dist2(rng2);
		vertices.push_back(v);

		list<int> l = list<int>(); //kazdy wierzcholek ma swoje miejsce w tej tablicy
		adjList.push_back(l);
	}
	i = 0;
	while (i!=numberOfEdges) {
		int v1, v2;
		mt19937 rng;
		rng.seed(random_device()());
		uniform_int_distribution<mt19937::result_type> v(0, numberOfVertices-1);
		v1 = v(rng);
		v2 = v(rng);

		//nasz graf jest nieskierowany ; sprawdzamy czy juz dana krawedz sie nie pojawila
		if (v1 != v2 && !(find(adjList[v1].begin(), adjList[v1].end(), v2) != adjList[v1].end())
			&& !(find(adjList[v2].begin(), adjList[v2].end(), v1) != adjList[v2].end())) {
			adjList[v1].push_back(v2);
			adjList[v2].push_back(v1);
			i++;
		}
	}
}

/*void RandomGraphGenerator::resetValues(int numOfVert, int numOfEdges, int maxB, int maxV) {
	numberOfVertices = numOfVert;
	numberOfEdges = numOfEdges;
	maxBenefit = maxB;
	maxVolume = maxV;
}*/

int RandomGraphGenerator::getNumberOfVertices() {
	return numberOfVertices;
}

int RandomGraphGenerator::getNumberOfEdges() {
	return numberOfEdges;
}

vector<vertex> RandomGraphGenerator::getVertices() {
	return vertices;
}

vector<list<int> > RandomGraphGenerator::getAdjList() {
	return adjList;
}

void RandomGraphGenerator::clearEverything() {
	for (int i = 0; i < adjList.size(); i++) {
		adjList.at(i).clear();
	}
	vertices.clear();
	adjList.clear();
	maxBenefit = 0;
	maxVolume = 0;
	numberOfEdges = 0;
	numberOfVertices = 0;
}