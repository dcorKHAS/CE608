#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

#include "GraphRepresentation.h"
#include <vector>
#include <algorithm>

class AdjacencyList : public GraphRepresentation {
public:
    explicit AdjacencyList(int numVertices);

    void addEdge(int v, int w) override;
    void removeEdge(int v, int w) override;
    const std::vector<int>& getNeighbors(int v) const override;
    bool hasEdge(int v, int w) const override;
    int getNumVertices() const override;
    int getNumEdges() const override;
    std::vector<int> getVertices() const override;
    void clear() override;

private:
    std::vector<std::vector<int>> adjList;
};

#endif // ADJACENCYLIST_H
