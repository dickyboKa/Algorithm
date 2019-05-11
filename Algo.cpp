#include <iostream>
#include <vector>
#include "Graph/GraphList.h"
#include "Graph/CodingProblem.h"

int main()
{
	// Create a graph given in the above diagram 
	GraphList g(4, true);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(0, 3);
	g.addEdge(2, 0);
	g.addEdge(2, 1);
	g.addEdge(1, 3);


	int start = 2; int destination = 3;

	std::cout << countPath(start, destination, g) << std::endl;
}

