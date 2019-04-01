#pragma once
#include <vector>
#include <iostream>

class GraphMatrix
{
public:
	GraphMatrix(int vertexSize) : graph(vertexSize), directed(false), V(vertexSize)
	{
		// creating 2d array
		for (int v = 0; v < vertexSize; ++v)
			graph[v].resize(vertexSize);
	};

	GraphMatrix(int vertexSize, bool direct) : graph(vertexSize), directed(direct), V(vertexSize)
	{
		// creating 2d array
		for (int v = 0; v < vertexSize; ++v)
			graph[v].resize(vertexSize);
	};

	GraphMatrix(int vertexSize, std::vector<std::vector<int>> inputGraph) : V(vertexSize), graph(inputGraph) {};

	void addEdge(int u, int v, int weight = 0)
	{
		graph[u][v] = weight;
		if (directed)
			return;
		graph[v][u] = weight;
	}

	void print()
	{
		std::cout << "  ";
		for (int u = 0; u < graph.size(); ++u)
			std::cout << u << " ";
		std::cout << std::endl;
		for (int v = 0; v < graph.size(); ++v)
		{
			std::cout << v << " ";
			for (auto x : graph[v])
				std::cout << x << " ";
			std::cout << std::endl;
		}
	}
	int V;
	auto operator[](int i) { return graph[i]; }
private:
	bool directed;
	std::vector<std::vector<int>> graph;
};