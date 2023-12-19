#include "MSTProblem.h"
#include <queue>
#include <unordered_set>
#include <iostream>


class UnionFind {
private:
	std::vector<int> parent;
	std::vector<int> rank;

public:
	UnionFind(int size) : parent(size), rank(size, 0) {
		for (int i = 0; i < size; i++) {
			parent[i] = i;
		}
	}

	int find(int x) {
		if (parent[x] != x) {
			parent[x] = find(parent[x]);
		}
		return parent[x];
	}

	void unite(int x, int y) {
		int rootX = find(x);
		int rootY = find(y);

		if (rootX != rootY) {
			if (rank[rootX] < rank[rootY]) {
				parent[rootX] = rootY;
			}
			else if (rank[rootX] > rank[rootY]) {
				parent[rootY] = rootX;
			}
			else {
				parent[rootY] = rootX;
				rank[rootX]++;
			}
		}
	}

	bool connected(int x, int y) {
		return find(x) == find(y);
	}
};


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

	//create a container to hold the edges that are included in the MST
std::unordered_set<std::pair<int, int>, pair_hash> includedEdges;

	//create a variable to store the total weight of the MST
	double totalWeight = 0;
	//loop while notIncluded is not empty
	int count= 0;
	while (!notIncluded.empty()) {

		//get the edge with the smallest weight
		std::pair<double, std::pair<int, int>> edge = pq.top();
				
		pq.pop();

		

		//if the edge connects a vertex in included to a vertex in notIncluded
		if (included.find(edge.second.first) != included.end() && notIncluded.find(edge.second.second) != notIncluded.end()) {
			//add the weight of the edge to totalWeight
			totalWeight += edge.first;


			//add the vertex to included
			included.insert(edge.second.second);

			//add the edge to includedEdges
			includedEdges.insert(edge.second);

			//remove the vertex from notIncluded
			notIncluded.erase(edge.second.second);
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

	//print out the edges in the MST
for (std::pair<int, int> edge : includedEdges) {
		std::cout << edge.first << " " << edge.second << std::endl;
	}

	
	return totalWeight;

}

double MSTProblem::Kruskal()
{	//create a container to hold the edges that are included in the MST
std::unordered_set<std::pair<int, int>, pair_hash> includedEdges;
	//create a binary heap of edges using the priority queue class

	std::priority_queue<std::pair<double, std::pair<int, int>>, std::vector<std::pair<double, std::pair<int, int>>>, std::greater<std::pair<double, std::pair<int, int>>>> pq;

	//fill the priority queue with all edges
	for (int i = 0; i < graph->getNumVertices(); i++) {
		for (int neighbor : graph->getNeighbors(i)) {
			pq.push(std::make_pair(graph->getWeight(i, neighbor), std::make_pair(i, neighbor)));
		}
	}

	
	//create a union find data structure
UnionFind uf(graph->getNumVertices());

//extract the edges from the priority queue one at a time
double totalWeight = 0;

while (!pq.empty()) {
	std::pair<double, std::pair<int, int>> edge = pq.top();
	pq.pop();

	//if the edge connects two vertices that are not already connected
	if (!uf.connected(edge.second.first, edge.second.second)) {
		//add the weight of the edge to totalWeight
		totalWeight += edge.first;

		//connect the two vertices
		uf.unite(edge.second.first, edge.second.second);

	//add the edge to includedEdges
	includedEdges.insert(edge.second);

	}

	
}

//print out the edges in the MST
for (std::pair<int, int> edge : includedEdges) {
	std::cout << edge.first << " " << edge.second << std::endl;
}
return totalWeight;
}