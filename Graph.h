#ifndef GRAPH_H
#define GRAPH_H

#include "GraphRepresentation.h"
#include <memory>
#include <string>
#include <unordered_set>
class Graph {
public:
    explicit Graph(std::unique_ptr<GraphRepresentation> representation);

    void addEdge(int v, int w);
    void removeEdge(int v, int w);
    bool isConnected() const;
    bool isCyclic() const;
    bool isDirected() const;
    bool isEmpty() const;
    std::string toString() const;
    int getDegree(int v) const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
    
    //Utility methods
    bool isCyclicUtil(int v, std::unordered_set<int>& visited, int parent) const;
    void DFSUtil(int v, std::unordered_set<int>& visited) const;
    //We'll implement this one
    void BFSUtil(int v) const;
    //We'll implement this one
    // ... Other methods ...

private:
    std::unique_ptr<GraphRepresentation> representation;
    bool isDirectedGraph;
};

#endif // GRAPH_H
