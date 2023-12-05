#ifndef ADJACENCYMATRIX_H
#define ADJACENCYMATRIX_H

#include "GraphRepresentation.h"
#include <vector>

class AdjacencyMatrix : public GraphRepresentation {
public:
    explicit AdjacencyMatrix(int numVertices);

    void addEdge(int v, int w) override;
    void removeEdge(int v, int w) override;
    const std::vector<int>& getNeighbors(int v) const override;
    bool hasEdge(int v, int w) const override;
    int getNumVertices() const override;
    int getNumEdges() const override;
    std::vector<int> getVertices() const override;
    void clear() override;

private:
    std::vector<std::vector<bool>> matrix;
    mutable std::vector<int> neighbors; // For storing neighbors temporarily
};

#endif // ADJACENCYMATRIX_H
