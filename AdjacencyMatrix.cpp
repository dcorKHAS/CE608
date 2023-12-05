#include "AdjacencyMatrix.h"
#include <stdexcept>

AdjacencyMatrix::AdjacencyMatrix(int numVertices) : matrix(numVertices, std::vector<bool>(numVertices, false)) {}

void AdjacencyMatrix::addEdge(int v, int w) {
    matrix[v][w] = true;
    matrix[w][v] = true; // If undirected graph
}

void AdjacencyMatrix::removeEdge(int v, int w) {
    matrix[v][w] = false;
    matrix[w][v] = false; // If undirected graph
}

const std::vector<int>& AdjacencyMatrix::getNeighbors(int v) const {
    neighbors.clear();
    for (int i = 0; i < matrix.size(); ++i) {
        if (matrix[v][i]) {
            neighbors.push_back(i);
        }
    }
    return neighbors;
}

bool AdjacencyMatrix::hasEdge(int v, int w) const {
    return matrix[v][w];
}

int AdjacencyMatrix::getNumVertices() const {
    return matrix.size();
}

int AdjacencyMatrix::getNumEdges() const {
    int count = 0;
    for (const auto& row : matrix) {
        count += std::count(row.begin(), row.end(), true);
    }
    return count / 2; // Since each edge is counted twice
}

std::vector<int> AdjacencyMatrix::getVertices() const {
    std::vector<int> vertices(matrix.size());
    for (int i = 0; i < matrix.size(); ++i) {
        vertices[i] = i;
    }
    return vertices;
}

void AdjacencyMatrix::clear() {
    for (auto& row : matrix) {
        std::fill(row.begin(), row.end(), false);
    }
}
