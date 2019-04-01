#pragma once
#include <vector>
#include <iostream>
#include "GraphMatrix.h"

class DijkstraSP
{
public:
	DijkstraSP(GraphMatrix &gm) : g(gm), dist(gm.V), sptSet(gm.V, false) {}

	void findShortestPath(int src);

	void printShortestPath();
private:
	int minDistance();
	std::vector<int> dist;
	std::vector<bool> sptSet;
	GraphMatrix g;
};

void DijkstraSP::findShortestPath(int src)
{
	for (auto fill_key = dist.begin(); fill_key != dist.end(); ++fill_key)
		*fill_key = std::numeric_limits<int>::max();

	dist[src] = 0;

	for (int count = 0; count < g.V - 1; count++)
	{
		int u = minDistance();
		sptSet[u] = true;

		for (int v = 0; v < g.V; v++)
		{
			if (g[u][v] != 0 && !sptSet[v] && dist[u] != std::numeric_limits<int>::max() 
				&& dist[u] + g[u][v] < dist[v])
			{
				dist[v] = dist[u] + g[u][v];
				//std::cout << dist[v] << std::endl;
			}
		}
	}
}

int DijkstraSP::minDistance()
{
	int min = std::numeric_limits<int>::max();
	int min_index = -1;

	for (int i = 0; i < g.V; ++i)
	{
		if (!sptSet[i] && dist[i] < min)
		{
			min = dist[i];
			min_index = i;
		}
	}
	return min_index;
}

void DijkstraSP::printShortestPath()
{
	printf("Vertex   Distance from Source\n");
	for (int i = 0; i < g.V; i++)
		std::cout << i << "\t" << dist[i] << std::endl;
}