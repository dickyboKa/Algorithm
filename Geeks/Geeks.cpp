#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include "Graph/GraphList.h"

int main()
{
	GraphList g(4, true);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);
	g.print();

	auto path = g.depthFirstSearch();
	for (auto x : path)
		std::cout << x << " ";
	return 0;
}


