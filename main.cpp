#include "Graph.h"
#include "AdjacencyList.h"
#include <memory>
#include <iostream>
#include <unordered_set>
int main() {
    Graph g(std::make_unique<AdjacencyList>(5)); // Create a graph with 5 vertices

    // Add some edges to test bfs

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    
    // Check if the graph is empty
    std::cout << "Is the graph empty? " << (g.isEmpty() ? "Yes" : "No") << std::endl;

    // Print degree of a vertex
    std::cout << "Degree of vertex 0: " << g.getDegree(0) << std::endl;

    // Do breadth-first search starting from vertex 0

    std::cout << "BFS starting from vertex 0: ";
    
    std::unordered_set<int> visited;
    
    g.DFSUtil(0, visited);



    return 0;
}

