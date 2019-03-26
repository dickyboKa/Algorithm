#pragma once
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
	void depthFirstSearchUtil(int vertex, std::vector<bool> &visited, std::vector<int> &path);

	int getVertices() { return vertices; }
	auto cbegin(int vertex) { return graph[vertex].cbegin(); }
	auto cend(int vertex) { return graph[vertex].cend(); }
private:

	int vertices;
	bool directed;
	std::vector<std::set<int>> graph;
};
