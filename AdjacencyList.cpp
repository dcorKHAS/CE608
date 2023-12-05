#include "AdjacencyList.h"
#include <iostream>
AdjacencyList::AdjacencyList(int numVertices) : adjList(numVertices), weightList(numVertices) {}





void AdjacencyList::addEdge(int v, int w) {
    adjList[v].push_back(w);
    //adjList[w].push_back(v); // If undirected graph
}

void AdjacencyList::addEdge(int v, int w, double weight) {

	adjList[v].push_back(w);
	weightList[v].push_back(weight);
	//adjList[w].push_back(v); // If undirected graph
	//weightList[w].push_back(weight); // If undirected graph


}


void AdjacencyList::removeEdge(int v, int w) {
    
    //get the index of w in the vector of v

    std::vector<int>::iterator it = std::find(adjList[v].begin(), adjList[v].end(), w);
    
    //remove the element at that index
    adjList[v].erase(it);

    //if weightList is not empty remove the corresponding weight
    if (!weightList[v].empty()) {
        weightList[v].erase(weightList[v].begin() + (it - adjList[v].begin()));
    }

       
    //adjList[w].erase(std::remove(adjList[w].begin(), adjList[w].end(), v), adjList[w].end());

}

const std::vector<int>& AdjacencyList::getNeighbors(int v) const {
    return adjList[v];
}

bool AdjacencyList::hasEdge(int v, int w) const {
    return std::find(adjList[v].begin(), adjList[v].end(), w) != adjList[v].end();
}

int AdjacencyList::getNumVertices() const {
    return adjList.size();
}

int AdjacencyList::getNumEdges() const {
    int count = 0;
    for (const auto& neighbors : adjList) {
        count += neighbors.size();
    }
    return count / 2; // Since each edge is counted twice
}

std::vector<int> AdjacencyList::getVertices() const {
    std::vector<int> vertices;
    for (int i = 0; i < adjList.size(); ++i) {
        vertices.push_back(i);
    }
    return vertices;
}

void AdjacencyList::clear() {
    for (auto& list : adjList) {
        list.clear();
    }
    adjList.clear();
}

double AdjacencyList::getWeight(int i, int j) const {
	//get the index of j in the vector of i
	std::vector<int>::const_iterator it = std::find(adjList[i].begin(), adjList[i].end(), j);

 

	//return the corresponding weight
	return weightList[i][it - adjList[i].begin()];
}




