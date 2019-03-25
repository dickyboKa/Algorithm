#include <iostream>
#include "Graph/GraphList.h"

int main()
{
	int V = 5;
	GraphList g(V);

	g.addEdge(0, 1);
	g.addEdge(0, 4);
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(1, 4);
	g.addEdge(2, 3);
	g.addEdge(3, 4);

	g.print();

	// Search the given edge in the graph 
	g.searchEdge(2, 1);
	g.searchEdge(0, 3);
	return 0;
}


