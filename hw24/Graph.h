#pragma once
#include <list>
#include <vector>
#include <unordered_set>

struct vertexType
{
	int vertex;
	int level;
};

class Graph
{
public:
	enum class ConnectionType
	{
		undirected,
		directed
	};

	Graph(int vertixes, ConnectionType type = ConnectionType::undirected)
		: m_vertixes(vertixes), m_connectionType(type) {}

	virtual void addEdge(int v, int w) = 0;

	virtual void BFS(int vertex = 0) {};
	virtual void DFS(int vertex = 0) {};

protected:
	unsigned int m_vertixes;
	ConnectionType m_connectionType;
};

class GraphAdjList : public Graph
{
public:
	GraphAdjList(unsigned int vertixes, ConnectionType type = ConnectionType::undirected);
	void addEdge(int v, int w) override;

	void BFS(int vertex = 0) override;
	void BFS(int vertex, std::unordered_set<int>& visited) const;

	int numberOfNodesInLevel(int vertex, int level) const;
	bool isStronglyConnected() const;

private:
	std::vector<std::list<int> > m_list;
};

class GraphAdjMatrix : public Graph
{
public:
	GraphAdjMatrix(int vertixes, ConnectionType type = ConnectionType::undirected);
	
	void addEdge(int v, int w) override;
	void DFS(int vertex = 0) override;
	void DFSAlgoritm(int vertex, std::unordered_set<int>& visited) const;

private:
	std::vector<std::vector<int>> m_matrix;
};