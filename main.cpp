#include "Graph.h"
#include "AdjacencyList.h"
#include "AdjacencyMatrix.h"
#include <memory>
#include <iostream>
#include <unordered_set>
#include "MSTProblem.h"
int main() {


    //Graph g(std::make_unique<AdjacencyList>(5)); // Create a graph with 5 vertices using adjacency matrix representation
    //Graph g(std::make_unique<AdjacencyList>(5));
    Graph g(std::make_unique<AdjacencyMatrix>(5));

    // Add some edges to test bfs
    g.addEdge(0, 1, 5.0);
    g.addEdge(1, 0, 5.0);
    g.addEdge(0, 2,4.5);
    g.addEdge(2, 0, 4.5);
    g.addEdge(3, 1, 3.5);
    g.addEdge(1, 3, 3.5);
    g.addEdge(2, 4, 6.0);
    g.addEdge(4, 2, 6.0);

    //create mst instance and call mst function
    MSTProblem mst(&g);
    std::cout << "MST weight: " << mst.Prim() << std::endl;

    std::cout << "MST weight: " << mst.Kruskal() << std::endl;




    return 0;
}

