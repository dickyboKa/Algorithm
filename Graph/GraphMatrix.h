#pragma once
#include <vector>
#include <iostream>
#include <algorithm>

class GraphMatrix
{
	
public:
	enum DIRECTION { move_up, move_below, move_right, move_left };

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
	
	void printMinimalSources();

private:
	void dfs(int i, int j, std::vector<std::vector<bool>> &visited);
	std::vector< std::pair<int, int>> sortMatrixByWeightAndGetIndexPair();
	bool moveValid(int i, int j, DIRECTION dir);
	bool directed;
	std::vector<std::vector<int>> graph;
};


void GraphMatrix::printMinimalSources()
{
	auto indexPairs = sortMatrixByWeightAndGetIndexPair();
	std::vector<std::vector<bool>> visited(V, std::vector<bool>(V, false));

	for (auto it = indexPairs.cbegin(); it != indexPairs.cend(); it++)
	{
		if (!visited[it->first][it->second])
		{
			std::cout << it->first << " " << it->second << std::endl;
			dfs(it->first, it->second, visited);
		}
	}
}

std::vector< std::pair<int, int>> GraphMatrix::sortMatrixByWeightAndGetIndexPair()
{
	std::vector<std::pair<int, std::pair<int, int>>> adjacentPairs;

	for (int i = 0; i < graph.size(); i++)
	{
		for (int j = i; j < graph[i].size(); ++j)
		{
			adjacentPairs.push_back(std::make_pair(graph[i][j], std::make_pair(i, j)));
		}
	}

	std::sort(adjacentPairs.begin(), adjacentPairs.end(), std::greater< std::pair<int, std::pair<int, int>>>());

	std::vector<std::pair<int, int>> results;
	for (auto it = adjacentPairs.cbegin(); it != adjacentPairs.cend(); it++)
	{
		results.push_back(std::make_pair(it->second.first, it->second.second));
	}

	return results;
}
void GraphMatrix::dfs(int i, int j, std::vector<std::vector<bool>> &visited)
{
	visited[i][j] = true;

	if (moveValid(i, j, GraphMatrix::DIRECTION::move_below) && !visited[i + 1][j])
		dfs(i + 1, j, visited);


	if (moveValid(i, j, GraphMatrix::DIRECTION::move_right) && !visited[i][j + 1])
		dfs(i, j + 1, visited);

	if (moveValid(i, j, GraphMatrix::DIRECTION::move_up) && !visited[i - 1][j])
		dfs(i - 1, j, visited);

	if (moveValid(i, j, GraphMatrix::DIRECTION::move_left) && !visited[i][j - 1])
		dfs(i, j - 1, visited);
}

bool GraphMatrix::moveValid(int i, int j, DIRECTION dir)
{
	bool result = false;
	switch (dir)
	{
	case GraphMatrix::move_up:
		if (i - 1 >= 0 && graph[i][j] >= graph[i - 1][j])
		{
			result = true;
		}
		break;
	case GraphMatrix::move_below:
		if (i + 1 < V && graph[i][j] >= graph[i + 1][j])
		{
			result = true;
		}
		break;
	case GraphMatrix::move_right:
		if (j + 1 < V && graph[i][j] >= graph[i][j + 1])
		{
			result = true;
		}
		break;
	case GraphMatrix::move_left:
		if (j - 1 >= 0 && graph[i][j] >= graph[i][j - 1])
		{
			result = true;
		}
		break;
	default:
		break;
	}
	return result;
}