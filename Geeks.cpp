#include <iostream>
#include <vector>
#include "Graph/GraphList.h"
#include "Graph/CodingProblem.h"

int main()
{

	GraphList g(6, true);
	g.addEdge(5, 2);
	g.addEdge(5, 0);
	g.addEdge(4, 0);
	g.addEdge(4, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 1);
	g.print();
	auto r = topologicalSort(g);
	std::cout << std::endl;
	for (auto x : r)
		std::cout << x << " ";
	return 0;
}


