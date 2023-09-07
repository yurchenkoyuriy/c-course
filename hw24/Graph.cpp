#include "Graph.h"
#include <unordered_set>
#include <iostream>
#include <algorithm>

GraphAdjList::GraphAdjList(unsigned int Vertixes, ConnectionType type)
	: Graph(Vertixes, type)
{
	m_list.resize(Vertixes);
}

void GraphAdjList::addEdge(int v, int w)
{
	//Check if w is not already in the list of v
	m_list[v].push_back(w);

	if (m_connectionType == ConnectionType::undirected)
	{
		m_list[w].push_back(v);
	}
}

void GraphAdjList::BFS(int vertex)
{
	std::unordered_set<int> visited;
	BFS(vertex, visited);
}

void GraphAdjList::BFS(int vertex, std::unordered_set<int>& visited) const
{
	std::list<int> queue;

	// Mark the current node as visited and enqueue it
	visited.insert(vertex);
	queue.push_back(vertex);

	while (!queue.empty())
	{
		// Dequeue a vertex from queue and print it
		int currentVertex = queue.front();

		queue.pop_front();

		// Get all adjacent vertices
		for (int adjacent : m_list[currentVertex])
		{
			if (!visited.count(adjacent))
			{
				visited.insert(adjacent);
				queue.push_back(adjacent);
			}
		}
	}
}

int GraphAdjList::numberOfNodesInLevel(int vertex, int level) const
{
	int vertexCount{ 0 };

	std::unordered_set<int> visited;
	std::list<vertexType> queue;

	visited.insert(vertex);
	queue.push_back({ vertex, 0 });

	while (!queue.empty())
	{		
		vertexType vertexType = queue.front();
		queue.pop_front();

		if (vertexType.level > level)
		{
			break;
		}

		if (vertexType.level == level)
		{
			vertexCount++;
		}

		vertexType.level += 1;

		for (int adjacent : m_list[vertexType.vertex])
		{
			if (!visited.count(adjacent))
			{
				visited.insert(adjacent);
				queue.push_back({ adjacent, vertexType.level });
			}
		}
	}

	return vertexCount;
}

bool GraphAdjList::isStronglyConnected() const
{
	if (m_connectionType == ConnectionType::undirected)
	{
		return false;
	}

	std::unordered_set<int> visitedVertex;
	BFS(0, visitedVertex);
	
	if (visitedVertex.size() != m_vertixes)
	{
		return false;
	}

	GraphAdjList reversed_graph{ m_vertixes, m_connectionType };

	for (int vertex = 0; vertex < m_vertixes; vertex++)
	{
		for (const int adjacent : m_list[vertex])
		{
			reversed_graph.addEdge(adjacent, vertex);
		}
	}

	std::unordered_set<int> visitedVertexReverse;
	reversed_graph.BFS(0, visitedVertexReverse);
		
	if (visitedVertex.size() != visitedVertexReverse.size())
	{
		return false;
	}
	
	return !std::any_of(visitedVertex.begin(), visitedVertex.end(), [&visitedVertexReverse](const int vertex) {
		return !visitedVertexReverse.count(vertex);
	});
}

GraphAdjMatrix::GraphAdjMatrix(int vertixes, ConnectionType type)
	: Graph(vertixes, type)
{
	m_matrix.resize(vertixes, std::vector<int>(m_vertixes, 0));
};

void GraphAdjMatrix::addEdge(int v, int w)
{
	m_matrix[v][w] = 1;

	if (m_connectionType == ConnectionType::undirected)
	{
		m_matrix[w][v] = 1;
	}
}

void GraphAdjMatrix::DFS(int vertex)
{
	std::unordered_set<int> visited;
	DFSAlgoritm(vertex, visited);
}

void GraphAdjMatrix::DFSAlgoritm(int vertex, std::unordered_set<int>& visited) const
{
	visited.insert(vertex);

	std::cout << vertex << " ";
	
	for (int i = 0; i < m_vertixes; i++)
	{
		if (m_matrix[vertex][i] && !visited.count(i))
		{		
			DFSAlgoritm(i, visited);
		}
	}
}