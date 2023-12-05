#include "MSTProblem.h"
#include <queue>
#include <unordered_set>
#include <iostream>
MSTProblem::MSTProblem(Graph* graph)
{
	this->graph = graph;
}

MSTProblem::~MSTProblem()
{
	
}

double MSTProblem::Prim()
{
	//create a set of vertices that are not yet included in MST
	std::unordered_set<int> notIncluded;

	//create a set of vertices that are included in MST
	std::unordered_set<int> included;

	//pick a vertex to start with
	int v = 0;

	//add v to included
	included.insert(v);

	//add all other vertices to notIncluded
	for (int i = 0; i < graph->getNumVertices(); i++) {
		if (i != v) {
			notIncluded.insert(i);
		}
	}

	//create a priority queue of edges without an edge class

	std::priority_queue<std::pair<double, std::pair<int, int>>, std::vector<std::pair<double, std::pair<int, int>>>, std::greater<std::pair<double, std::pair<int, int>>>> pq;
	
	//loop through all edges of v
	for (int neighbor : graph->getNeighbors(v)) {
		//add edge to pq
		pq.push(std::make_pair(graph->getWeight(v, neighbor), std::make_pair(v, neighbor)));
	}

	//create a variable to store the total weight of the MST
	double totalWeight = 0;
	std::cout<<"before prim loop"<<std::endl;
	//loop while notIncluded is not empty
	int count= 0;
	while (!notIncluded.empty()) {

		//print and increment count
		std::cout << notIncluded.size() << std::endl;
		std::cout << count++ << std::endl;
		std::cout << "before extract" << std::endl;
		//get the edge with the smallest weight
		std::pair<double, std::pair<int, int>> edge = pq.top();
		//The above line will create an error when

		std::cout << "after  extract" << std::endl;
		std::cout << "before pop" << std::endl;

		pq.pop();

		std::cout << "after pop" << std::endl;


		//if the edge connects a vertex in included to a vertex in notIncluded
		if (included.find(edge.second.first) != included.end() && notIncluded.find(edge.second.second) != notIncluded.end()) {
			//add the weight of the edge to totalWeight
			totalWeight += edge.first;

			//add the vertex to included
			included.insert(edge.second.second);

			//remove the vertex from notIncluded
			notIncluded.erase(edge.second.second);
			std::cout << "after erase" << std::endl;
			//loop through all edges of the vertex
			for (int neighbor : graph->getNeighbors(edge.second.second)) {
				//if the neighbor is in notIncluded
				if (notIncluded.find(neighbor) != notIncluded.end()) {
					//add the edge to pq
					pq.push(std::make_pair(graph->getWeight(edge.second.second, neighbor), std::make_pair(edge.second.second, neighbor)));
				}
			}
		}
	}

	std::cout<< "after prim loop"<<std::endl;

	return totalWeight;

}