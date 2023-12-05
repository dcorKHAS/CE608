#ifndef EDGELIST_H
#define EDGELIST_H

#include "GraphRepresentation.h"
#include <vector>
#include <utility> // For std::pair

class EdgeList : public GraphRepresentation {
public:
    void addEdge(int v, int w) override;
    void removeEdge(int v, int w) override;
    const std::vector<int>& getNeighbors(int v) const override;
    bool hasEdge(int v, int w) const override;
    int getNumVertices() const override;
    int getNumEdges() const override;
    std::vector<int> getVertices() const override;
    void clear() override;

private:
    std::vector<std::pair<int, int>> edges;
    mutable std::vector<int> neighbors; // For storing neighbors temporarily
};

#endif // EDGELIST_H
