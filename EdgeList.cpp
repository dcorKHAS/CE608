#include "EdgeList.h"
#include <algorithm>
#include <unordered_set>

void EdgeList::addEdge(int v, int w) {
    edges.emplace_back(v, w);
    edges.emplace_back(w, v); // If undirected graph
}

void EdgeList::removeEdge(int v, int w) {
    edges.erase(std::remove(edges.begin(), edges.end(), std::make_pair(v, w)), edges.end());
    edges.erase(std::remove(edges.begin(), edges.end(), std::make_pair(w, v)), edges.end()); // If undirected graph
}

const std::vector<int>& EdgeList::getNeighbors(int v) const {
    neighbors.clear();
    for (const auto& edge : edges) {
        if (edge.first == v) {
            neighbors.push_back(edge.second);
        }
    }
    return neighbors;
}

bool EdgeList::hasEdge(int v, int w) const {
    return std::find(edges.begin(), edges.end(), std::make_pair(v, w)) != edges.end();
}

int EdgeList::getNumVertices() const {
    std::unordered_set<int> uniqueVertices;
    for (const auto& edge : edges) {
        uniqueVertices.insert(edge.first);
        uniqueVertices.insert(edge.second);
    }
    return uniqueVertices.size();
}

int EdgeList::getNumEdges() const {
    return edges.size() / 2; // Since each edge is counted twice
}

std::vector<int> EdgeList::getVertices() const {
    std::unordered_set<int> uniqueVertices;
    for (const auto& edge : edges) {
        uniqueVertices.insert(edge.first);
        uniqueVertices.insert(edge.second);
    }
    return std::vector<int>(uniqueVertices.begin(), uniqueVertices.end());
}

void EdgeList::clear() {
    edges.clear();
}
