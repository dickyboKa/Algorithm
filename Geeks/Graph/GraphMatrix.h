#include <vector>
#include <iostream>

class GraphMatrix
{
public:
	GraphMatrix(int vertexSize) : graph(vertexSize) 
	{
		// creating 2d array
		for (int v = 0; v < vertexSize; ++v)
			graph[v].resize(vertexSize);
	};

	void addEdge(int u, int v)
	{
		graph[u][v] = 1;
		graph[v][u] = 1;
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
private:
	std::vector<std::vector<int>> graph;
};