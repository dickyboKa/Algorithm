#include <iostream>
#include <vector>
#include "Graph/Graph.h"

int main()
{
	/* Let us create following graph
		 0
		|  \
		|    \
		1-----2 */
	int V = 3, E = 3;
	Graph graph(V, E);

	graph.addEdge(0, 1);
	graph.addEdge(1, 2);
	graph.addEdge(0, 2);

	if (isCycle(graph))
		std::cout << "graph contains cycle";
	else
		std::cout << "graph doesn't contain cycle";
	return 0;
}


