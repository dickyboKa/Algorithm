#include <vector>
#include <list>
#include <iostream>

//using vector better cache
class GraphList
{
public:
	GraphList(int vertexSize) : graph(vertexSize) {};

	void addEdge(int u, int v)
	{
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	void print()
	{
		for (int v = 0; v < graph.size(); ++v)
		{
			std::cout << std::endl << "Adjacency list of vertex "
				<< v << std::endl << "head ";
			for (auto x : graph[v])
				std::cout << "->" << x;
			std::cout << std::endl;
		}
	}
private:
	std::vector<std::vector<int>> graph;
};