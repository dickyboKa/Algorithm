#include <vector>
#include <list>
#include <iostream>
#include <iterator>

class GraphList
{
public:
	GraphList(int v) : vertices(v), graph(v), directed(false){};
	GraphList(int v, bool direct) : vertices(v), graph(v), directed(direct) {};

	void addEdge(int u, int v)
	{
		graph[u].push_back(v);
		if (directed)
			return;
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

	int getVertices() { return vertices; }

	auto cbegin(int vertex) { return graph[vertex].cbegin(); }

	auto cend(int vertex) { return graph[vertex].cend(); }

	std::vector<int> breadthFirstSearch(int vectorStart);
	std::vector<int> depthFirstSearch(int vectorStart);
	std::vector<int> depthFirstSearchAllVertex();
private:
	void depthFirstSearchUtil(int vertex, std::vector<bool> &visited, std::vector<int> &path);

	int vertices;
	bool directed;
	std::vector<std::vector<int>> graph;
};


std::vector<int> GraphList::breadthFirstSearch(int vectorStart)
{
	std::vector<bool> visited(vertices);

	std::list<int> queueVertexToGo;
	visited[vectorStart] = true;
	
	queueVertexToGo.push_front(vectorStart);

	std::vector<int> path;
	while (!queueVertexToGo.empty()) 
	{
		int currentlyOnVertex = queueVertexToGo.front();
		// actually we can do anything here for the vertex that already found, but for now just populate it into path array
		path.push_back(currentlyOnVertex);
		queueVertexToGo.pop_front();

		for (auto it_vertices = graph[currentlyOnVertex].cbegin(); 
			it_vertices != graph[currentlyOnVertex].cend(); ++it_vertices)
		{
			if (!visited[*it_vertices])
			{
				visited[*it_vertices] = true;
				queueVertexToGo.push_back(*it_vertices);
			}
		}
	}

	return path;
}


std::vector<int> GraphList::depthFirstSearch(int start)
{
	std::vector<bool> visited(vertices);
	std::vector<int> path;

	depthFirstSearchUtil(start, visited, path);
	return path;
}

std::vector<int> GraphList::depthFirstSearchAllVertex()
{
	std::vector<bool> visited(vertices);
	std::vector<int> path;

	for (int i = 0; i < vertices; ++i)
	{
		if (!visited[i])
			depthFirstSearchUtil(i, visited, path);
	}
	return path;
}

void GraphList::depthFirstSearchUtil(int currentVertextTraverse, std::vector<bool> &visited, std::vector<int> &path)
{
	visited[currentVertextTraverse] = true;
	// actually we can do anything here for the vertex that already found, but for now just populate it into path array
	path.push_back(currentVertextTraverse);

	for (auto it_vertices = graph[currentVertextTraverse].cbegin(); 
		it_vertices != graph[currentVertextTraverse].cend(); ++it_vertices)
	{
		if (!visited[*it_vertices])
		{
			visited[*it_vertices];
			depthFirstSearchUtil(*it_vertices, visited, path);
		}
	}
}
