#pragma once
#include "Graph.h"
class MSTProblem
{
	// Data members
	private:
		Graph * graph;

	// Member functions

public:
		MSTProblem(Graph * graph);
		~MSTProblem();
		double Prim();
		double Kruskal();
		
		//pair_hash function for int
		
struct pair_hash {
			template <class T1, class T2>
			std::size_t operator() (const std::pair<T1, T2> &pair) const {
				return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
			}
		};

};

