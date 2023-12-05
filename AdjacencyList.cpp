#include "AdjacencyList.h"

AdjacencyList::AdjacencyList(int numVertices) : adjList(numVertices) {}

void AdjacencyList::addEdge(int v, int w) {
    adjList[v].push_back(w);
    adjList[w].push_back(v); // If undirected graph
}

void AdjacencyList::removeEdge(int v, int w) {
    adjList[v].erase(std::remove(adjList[v].begin(), adjList[v].end(), w), adjList[v].end());
    adjList[w].erase(std::remove(adjList[w].begin(), adjList[w].end(), v), adjList[w].end());
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
