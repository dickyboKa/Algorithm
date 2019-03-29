#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
struct Edge
{
	int src;
	int dest;
	int weight;
};

class Graph
{
	friend bool CheckIfGraphHasCycle(Graph &g);
	friend void KruskalMST(Graph &g);

	struct Subset
	{
		int parent;
		int rank;
	};
public:
	Graph(int V, int E) : vertices(V), edge(E), edges(E), subsets(V)
	{
		for (int v = 0; v < V; v++)
		{
			subsets[v].parent = v;
			subsets[v].rank = 0;
		}
	}

	void addEdge(int src, int dest, int weight = 0)
	{
		edges[src].src = src;
		edges[src].dest = dest;
		edges[src].weight = weight;
	}

private:

	int find(int i)
	{
		if (subsets[i].parent != i)
			subsets[i].parent = find(subsets[i].parent);
		return subsets[i].parent;
	}

	void unionIt(int x, int y)
	{
		int xRoot = find(x);
		int yRoot = find(y);

		if (subsets[xRoot].rank < subsets[yRoot].rank)
			subsets[xRoot].parent = yRoot;
		else if (subsets[yRoot].rank < subsets[xRoot].rank)
			subsets[yRoot].parent = xRoot;
		else
		{
			subsets[xRoot].parent = yRoot;
			subsets[yRoot].rank++;
		}
	}

	std::vector<Edge> edges;
	std::vector<Subset> subsets;
	int vertices;
	int edge;
};

bool isCycle(int parentA, int parentB)
{
	return parentA == parentB;
}

bool CheckIfGraphHasCycle(Graph &g)
{
	for (auto next_edge = g.edges.cbegin(); next_edge != g.edges.cend(); ++next_edge)
	{
		int x = g.find(next_edge->src);
		int y = g.find(next_edge->dest);

		if (isCycle(x, y))
			return true;

		g.unionIt(x, y);
	}
	return false;
}

void print(std::vector<Edge> &edges)
{
	for (auto print_it = edges.cbegin(); print_it != edges.cend(); ++print_it)
	{
		std::cout << print_it->src << " -- " <<
			print_it->dest << " == " << print_it->weight << std::endl;
	}
}

void KruskalMST(Graph &g)
{
	std::sort(g.edges.begin(), g.edges.end(), [](Edge a, Edge b) {
		return a.weight < b.weight;
	});

	std::vector<Edge> result;

	for (auto next_edge = g.edges.cbegin(); next_edge != g.edges.cend(); ++next_edge)
	{
		int x = g.find(next_edge->src);
		int y = g.find(next_edge->dest);
		if (!isCycle(x, y))
		{
			result.push_back(*next_edge);
			g.unionIt(x, y);
		}
	}

	print(result);
}