#include "Graph.h"
#include "AdjacencyList.h"
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <stack>
#include <vector>
#include <unordered_set>
#include <queue>
Graph::Graph(std::unique_ptr<GraphRepresentation> rep) : representation(std::move(rep)), isDirectedGraph(false) {}

void Graph::addEdge(int v, int w) {
    representation->addEdge(v, w);
}


void Graph::addEdge(int v, int w, double weight)
{
	representation->addEdge(v, w, weight);
}
void Graph::removeEdge(int v, int w) {
    representation->removeEdge(v, w);
}

const std::vector<int>& Graph::getNeighbors(int v) const
{   
    //std::cout << "Graph::getNeighbors(int v) const" << std::endl;


	return representation->getNeighbors(v);
}

int Graph::getNumVertices() const
{
	return representation->getNumVertices();
}


bool Graph::isEmpty() const {
    return representation->getNumVertices() == 0;
}


int Graph::getDegree(int v) const {
    return representation->getNeighbors(v).size();
}

bool Graph::isConnected() const {
    if (isEmpty()) {
        return true;
    }

    std::unordered_set<int> visited;
    std::stack<int> stack;
    stack.push(0); // Start from vertex 0

    while (!stack.empty()) {
        int v = stack.top();
        stack.pop();
        if (visited.find(v) == visited.end()) {
            visited.insert(v);
            for (int neighbor : representation->getNeighbors(v)) {
                if (visited.find(neighbor) == visited.end()) {
                    stack.push(neighbor);
                }
            }
        }
    }

    return visited.size() == representation->getNumVertices();
}

bool Graph::isCyclicUtil(int v, std::unordered_set<int>& visited, int parent) const {
    visited.insert(v);
    for (int neighbor : representation->getNeighbors(v)) {
        if (visited.find(neighbor) == visited.end()) {
            if (isCyclicUtil(neighbor, visited, v)) {
                return true;
            }
        }
        else if (neighbor != parent) {
            // If an adjacent vertex is visited and not the parent of the current vertex, then there is a cycle.
            return true;
        }
    }
    return false;
}

bool Graph::isCyclic() const {
    std::unordered_set<int> visited;
    for (int i = 0; i < representation->getNumVertices(); ++i) {
        if (visited.find(i) == visited.end()) {
            if (isCyclicUtil(i, visited, -1)) {
                return true;
            }
        }
    }
    return false;
}

std::string Graph::toString() const {
    std::stringstream ss;
    for (int v = 0; v < representation->getNumVertices(); ++v) {
        for (int w : representation->getNeighbors(v)) {
            ss << v << " -- " << w << "\n";
        }
    }
    return ss.str();
}

void Graph::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file for writing");
    }

    file << toString(); // Using the string representation for saving
    file.close();
}

void Graph::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file for reading");
    }

    representation->clear(); // Clear existing graph data
    int v, w;
    while (file >> v >> w) {
        representation->addEdge(v, w);
    }
    file.close();
}
bool Graph::isDirected() const {
    return isDirectedGraph;
}

void Graph::BFSUtil(int v) const {

    //create a set of visited vertices
    std::unordered_set<int> visited;

    //create a queue
    std::queue<int> queue;

    //add v to queue
	queue.push(v);
    visited.insert(v);
    //loop if queue not empty
    while(!queue.empty()){
        //v = queue.pop
        v = queue.front();

        std::cout<<std::endl << v<<" " << std::endl;

        // Visit all neighbours of v
        for (int neighbor : representation->getNeighbors(v)) {

                //If not visited
                
            if (visited.find(neighbor) == visited.end()) {
					//push into the queue
					queue.push(neighbor);
					//mark as visited
					visited.insert(neighbor);
                    //process the vertex//
                    
                    std::cout << neighbor << " ";
				}
         
        }
		//remove v from queue
		queue.pop();
	}



}

void Graph::DFSUtil(int v, std::unordered_set<int>& visited) const {

    if (visited.find(v) != visited.end()) {
		return;
	}
    
    visited.insert(v);
    std::cout << v << " ";

    for (int neighbor : representation->getNeighbors(v)) {
		DFSUtil(neighbor, visited);
	}


}

double Graph::getWeight(int i, int j) const {

    return representation->getWeight(i, j);

}