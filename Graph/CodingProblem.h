#pragma once
#include "GraphList.h"
#include "GraphMatrix.h"

// a mother vertex: is a vertex v such that all other vertices in G can be reached by a path from v.
int findMother(GraphList &g)
{
	auto path = g.depthFirstSearchAllVertex();
	int v = path.back();

	// if every vertex reachable from v than v is mother, if not no mother exist in this graph
	std::vector<bool> visited(g.getVertices());
	path.clear();
	g.depthFirstSearchUtil(v, visited, path);
	for (auto it_visited = visited.cbegin(); it_visited != visited.cend(); ++it_visited)
	{
		if (*it_visited == false)
			return -1;
	}
	return 0;
}

// Transitive Closure of a Graph using DFS
// Given a directed graph, find out if a vertex v is reachable from another vertex u for all vertex pairs(u, v) in the given graph
void DFSTransitiveClosure(GraphMatrix &tc, GraphList &g, int start, int finish)
{
	tc.addEdge(start, finish);

	for (auto it = g.cbegin(finish); it != g.cend(finish); ++it)
	{
		if (tc[start][*it] == false)
			DFSTransitiveClosure(tc, g, start, *it);
	}
}
void transitiveClosure(GraphList &g)
{
	GraphMatrix tc(g.getVertices(), true);

	for (int i = 0; i < g.getVertices(); ++i)
		DFSTransitiveClosure(tc, g, i, i);

	tc.print();
}