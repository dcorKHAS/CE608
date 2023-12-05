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
		};

