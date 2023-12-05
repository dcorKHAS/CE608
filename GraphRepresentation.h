#ifndef GRAPHREPRESENTATION_H
#define GRAPHREPRESENTATION_H

#include <vector>

class GraphRepresentation {
public:
    virtual ~GraphRepresentation() {}
    virtual void addEdge(int v, int w) = 0;
    virtual void removeEdge(int v, int w) = 0;
    virtual const std::vector<int>& getNeighbors(int v) const = 0;
    virtual bool hasEdge(int v, int w) const = 0;
    virtual int getNumVertices() const = 0;
    virtual int getNumEdges() const = 0;
    virtual std::vector<int> getVertices() const = 0;
    virtual void clear() = 0;
};

#endif // GRAPHREPRESENTATION_H
