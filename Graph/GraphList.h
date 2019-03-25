#include <vector>
#include <list>
#include <iostream>
#include <iterator>
#include <set>


class GraphList
{
public:
	GraphList(int v) : vertices(v), graph(v), directed(false) {};
	GraphList(int v, bool direct) : vertices(v), graph(v), directed(direct) {};

	void addEdge(int u, int v);
	void print();
	void searchEdge(int src, int dest);
	std::vector<int> breadthFirstSearch(int vectorStart);
	std::vector<int> depthFirstSearch(int vectorStart);
	std::vector<int> depthFirstSearchAllVertex();
	// a mother vertex: is a vertex v such that all other vertices in G can be reached by a path from v.
	int findMother();

	int getVertices() { return vertices; }
	auto cbegin(int vertex) { return graph[vertex].cbegin(); }
	auto cend(int vertex) { return graph[vertex].cend(); }
private:
	void depthFirstSearchUtil(int vertex, std::vector<bool> &visited, std::vector<int> &path);

	int vertices;
	bool directed;
	std::vector<std::set<int>> graph;
};
