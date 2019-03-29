#pragma once
#include <vector>
#include <iostream>

#include "GraphMatrix.h"

class PrimMST
{
public:
	PrimMST(GraphMatrix &gm) : g(gm) , parent(gm.V), 
		key(gm.V), mstSet(gm.V, false){}

	void findMinimumSpanningTree();

	void printMST();
private:
	int minKey();
	std::vector<int> parent;
	std::vector<int> key;
	std::vector<bool> mstSet;
	GraphMatrix g;
};

void PrimMST::findMinimumSpanningTree()
{
	for (auto fill_key = key.begin(); fill_key != key.end(); ++fill_key)
		*fill_key = std::numeric_limits<int>::max();

	key[0] = 0;
	parent[0] = -1;

	for (int count = 0; count < g.V - 1; count++)
	{
		int u = minKey();
		mstSet[u] = true;

		for (int v = 0; v < g.V; v++)
		{
			if (g[u][v] != 0 && !mstSet[v] && g[u][v] < key[v])
			{
				parent[v] = u;
				key[v] = g[u][v];
			}
		}
	}
}

int PrimMST::minKey()
{
	int min = std::numeric_limits<int>::max();
	int min_index = -1;

	for (int i = 0; i < g.V; ++i)
	{
		if (!mstSet[i] && key[i] < min)
		{
			min = key[i];
			min_index = i;
		}
	}
	return min_index;
}

void PrimMST::printMST()
{
	for (int i = 1; i < parent.size(); ++i)
	{
		std::cout << parent[i] << " -> " << i << ": " << g[i][parent[i]] << std::endl;
	}
}