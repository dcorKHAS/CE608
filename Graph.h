#ifndef GRAPH_H
#define GRAPH_H

#include "GraphRepresentation.h"
#include <memory>
#include <string>
#include <unordered_set>
class Graph {
public:
    explicit Graph(std::unique_ptr<GraphRepresentation> representation);
    //explicit means that the constructor can only be called explicitly
    //which means that you can't do something like this:
    //Graph g = new Graph();
    //You have to do this:
    //Graph g(new Graph());
    //or this:
    //Graph g = Graph(new Graph());
    //or this:
    //Graph g = std::make_unique<Graph>(new Graph());
    //or this:
    //Graph g(std::make_unique<Graph>());
    

    void addEdge(int v, int w);
    void addEdge(int v, int w, double weight);
    void removeEdge(int v, int w);
    bool isConnected() const;
    bool isCyclic() const;
    bool isDirected() const;
    bool isEmpty() const;
    std::string toString() const;
    int getDegree(int v) const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
    double getWeight(int v, int w) const;
    int getNumVertices() const;
    const std::vector<int>& getNeighbors(int v) const;


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
