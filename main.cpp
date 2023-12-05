#include "Graph.h"
#include "AdjacencyList.h"
#include <memory>
#include <iostream>

int main() {
    Graph g(std::make_unique<AdjacencyList>(5)); // Create a graph with 5 vertices

    // Add some edges
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 0);

    // Check if the graph is empty
    std::cout << "Is the graph empty? " << (g.isEmpty() ? "Yes" : "No") << std::endl;

    // Print degree of a vertex
    std::cout << "Degree of vertex 0: " << g.getDegree(0) << std::endl;

    // Implement other functionalities and tests as needed

    return 0;
}
