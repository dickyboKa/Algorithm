#include <vector>
#include <list>
#include <iostream>
#include <iterator>

//using vector better cache
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
	// iterable
	auto cbegin(int vertex) { return graph[vertex].cbegin(); }

	auto cend(int vertex) { return graph[vertex].cend(); }

	std::vector<int> breadthFirstSearch(int vectorStart);
	std::vector<int> depthFirstSearch(int vectorStart = 0);
private:
	void depthFirstSearchUtil(int vertex, std::vector<bool> &visited, std::vector<int> &path);

	int vertices;
	bool directed;
	std::vector<std::vector<int>> graph;
};


// return a path that exist
std::vector<int> GraphList::breadthFirstSearch(int vectorStart)
{
	std::vector<bool> visited(vertices);

	std::list<int> queueToCheck;
	// mark start to visited, because we about to visit start
	visited[vectorStart] = true;
	// and put start in queue to check for the path
	queueToCheck.push_front(vectorStart);

	std::vector<int> path;
	while (!queueToCheck.empty()) //while there still vertex to check
	{
		// get vertex that finish traverse, and put it in path
		int vertex = queueToCheck.front();
		// actually we can do anything here for the vertex that already found, but for now just populate it into path array
		path.push_back(vertex);
		queueToCheck.pop_front(); 

		for (auto it = graph[vertex].cbegin(); it != graph[vertex].cend(); ++it)
		{
			if (!visited[*it])
			{
				visited[*it] = true;
				queueToCheck.push_back(*it);
			}
		}
	}

	return path;
}


std::vector<int> GraphList::depthFirstSearch(int start)
{
	std::vector<bool> visited(vertices);
	std::vector<int> path;

	if(start != 0)
		depthFirstSearchUtil(start, visited, path);
	else
	{	// if start is not specified we have to traverse every vertex usefull for disconected graph
		for (int i = 0; i < vertices; ++i)
		{
			if(!visited[i])
				depthFirstSearchUtil(i, visited, path);
		}
	}
	return path;
}

void GraphList::depthFirstSearchUtil(int vertex, std::vector<bool> &visited, std::vector<int> &path)
{
	visited[vertex] = true;
	path.push_back(vertex);

	for (auto it = graph[vertex].cbegin(); it != graph[vertex].cend(); ++it)
	{
		if (!visited[*it])
		{
			visited[*it];
			depthFirstSearchUtil(*it, visited, path);
		}
	}
}
