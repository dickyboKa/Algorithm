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

// Find k-cores of an undirected graph
// Given a graph G and an integer K, K-cores of the graph are connected components 
// that are left after all vertices of degree less than k have been removed
bool dfsUtil(GraphList &g, std::vector<bool> &visited, int v, int minDegree, std::vector<int> &vDegrees)
{
	visited[v] = true;
	for (auto it = g.cbegin(v); it != g.cend(v); ++it)
	{
		if (vDegrees[v] < minDegree)
			vDegrees[*it]--;

		if (!visited[*it])
		{
			if (dfsUtil(g, visited, *it, minDegree, vDegrees))
				vDegrees[v]--;
		}

	}
	return vDegrees[v] < minDegree;
}

int findVertexWithMinimumDegree(GraphList &g, std::vector<int> &vDegrees)
{
	int minDegree = std::numeric_limits<int>::max();
	int startVertex = 0;
	for (int i = 0; i < g.getVertices(); ++i)
	{
		vDegrees[i] = g.getDegree(i);
		if (g.getDegree(i) < minDegree)
			startVertex = i;
	}

	return startVertex;
}

void transformGraphToSpecificDegree(GraphList &g, int degree)
{
	GraphList tg(g);
	std::vector<int> vDegrees(g.getVertices(), 0);
	std::vector<bool> visited(g.getVertices(), false);
	int startVertex = findVertexWithMinimumDegree(g, vDegrees);
	dfsUtil(g, visited, startVertex, degree, vDegrees);

	for (int i = 0; i < g.getVertices(); ++i)
	{
		if (!visited[i])
			dfsUtil(g, visited, i, degree, vDegrees);
	}

	for (int v = 0; v < g.getVertices(); v++)
	{
		if (vDegrees[v] >= degree)
		{
			std::cout << "\n[" << v << "]";

			// Traverse adjacency list of v and print only 
			// those adjacent which have vDegree >= k after 
			// BFS. 
			for (auto it = g.cbegin(v); it != g.cend(v); ++it)
				if (vDegrees[*it] >= degree)
					std::cout << " -> " << *it;
		}
	}
}

void findCycleDirected(GraphList &g, int v, std::vector<bool> &visited,
	std::vector<bool> &onStack, bool &hasCyle)
{
	visited[v] = true;
	onStack[v] = true;

	for (auto adj_nodes = g.cbegin(v); adj_nodes != g.cend(v); ++adj_nodes)
	{
		if (!visited[*adj_nodes])
			findCycleDirected(g, *adj_nodes, visited, onStack, hasCyle);
		else if (onStack[*adj_nodes])
		{
			hasCyle = true;
			return;
		}

	}
	onStack[v] = false;
}
bool isDirectedGrapHasCycle(GraphList &g)
{
	bool hasCycle = false;
	int cycleCount = 0;
	std::vector<bool> visited(g.getVertices(), false);
	std::vector<bool> onStack(g.getVertices(), false);

	for (int v = 0; v < g.getVertices(); ++v)
	{
		if (!visited[v])
			findCycleDirected(g, v, visited, onStack, hasCycle);
		if (hasCycle)
		{
			++cycleCount;
			hasCycle = false;
		}
	}
	return cycleCount > 0;
}

void findCycleUndirected(GraphList &g, int v, int parent, std::vector<bool> &visited, bool &hasCyle)
{
	visited[v] = true;

	for (auto adj_nodes = g.cbegin(v); adj_nodes != g.cend(v); ++adj_nodes)
	{
		if (!visited[*adj_nodes])
			findCycleUndirected(g, *adj_nodes, v, visited, hasCyle);
		else if (*adj_nodes != parent)
		{
			hasCyle = true;
			return;
		}

	}
}

bool isUndirectedGraphHasCycle(GraphList &g)
{
	bool hasCycle = false;
	int cycleCount = 0;
	std::vector<bool> visited(g.getVertices(), false);
	for (int v = 0; v < g.getVertices(); ++v)
	{
		if (!visited[v])
			findCycleUndirected(g, v, v, visited, hasCycle);
		if (hasCycle)
		{
			++cycleCount;
			hasCycle = false;
		}
	}
	return cycleCount > 0;
}
