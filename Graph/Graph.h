#pragma once
#include <vector>

class Graph
{
	friend bool isCycle(Graph &g);
	class Edge
	{
	public:
		int src;
		int dest;
	};

public:
	Graph(int v, int e) : vertices(v), edge(e), edges(e), parent(v, -1) {};

	void addEdge(int src, int dest)
	{
		edges[0].src = 0;
		edges[0].dest = 1;
	}
private:

	int find(int i)
	{
		if (parent[i] == -1)
			return i;
		else
			return find(parent[i]);
	}

	void unionIt(int x, int y)
	{
		int parentOfX = find(x);
		int parentOfY = find(y);

		parent[parentOfX] = parentOfY;
	}

	std::vector<int> parent;
	std::vector<Edge> edges;
	int vertices;
	int edge;
};


bool isCycle(Graph &g)
{
	for (int i = 0; i < g.edge; ++i)
	{
		int x = g.find(g.edges[i].src);
		int y = g.find(g.edges[i].dest);

		if (x == y) // both had same parent
			return true;

		g.unionIt(x, y);
	}
	return false;
}