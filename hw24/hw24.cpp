#include <iostream>
#include "Graph.h"

#define TIME_LOG_ENABLED
int getTime() { return 1; }

int main()
{
	GraphAdjList graph(11);

	graph.addEdge(0, 1);
	graph.addEdge(0, 2);
	graph.addEdge(0, 3);
	graph.addEdge(1, 4);
	graph.addEdge(2, 5);
	graph.addEdge(2, 6);
	graph.addEdge(3, 7);
	graph.addEdge(4, 8);
	graph.addEdge(5, 9);
	graph.addEdge(7, 10);
	graph.addEdge(6, 9);
	graph.addEdge(1, 9);
	graph.addEdge(1, 3);

	std::cout << "Vertex on level 1: " << graph.numberOfNodesInLevel(0, 0) << "\n";
	std::cout << "Vertex on level 2: " << graph.numberOfNodesInLevel(0, 1) << "\n";
	std::cout << "Vertex on level 3: " << graph.numberOfNodesInLevel(0, 2) << "\n";
	std::cout << "Vertex on level 4: " << graph.numberOfNodesInLevel(0, 3) << "\n";
	std::cout << "Vertex on level 5: " << graph.numberOfNodesInLevel(0, 4) << "\n";

	GraphAdjList graph2(8, Graph::ConnectionType::directed);

	graph2.addEdge(0, 1);
	graph2.addEdge(1, 2);
	graph2.addEdge(1, 3);
	graph2.addEdge(2, 4);
	graph2.addEdge(3, 5);
	graph2.addEdge(4, 6);
	graph2.addEdge(5, 7);
	graph2.addEdge(7, 1);
	graph2.addEdge(6, 0);

	std::cout << "Strongly connected: " << graph2.isStronglyConnected() << "\n";
		
	std::cout << "DFS for directed graph\n";
	GraphAdjMatrix mgraph(11, Graph::ConnectionType::directed);
	mgraph.addEdge(0, 1);
	mgraph.addEdge(0, 2);
	mgraph.addEdge(0, 3);
	mgraph.addEdge(1, 4);
	mgraph.addEdge(2, 5);
	mgraph.addEdge(2, 6);
	mgraph.addEdge(3, 7);
	mgraph.addEdge(4, 8);
	mgraph.addEdge(5, 9);
	mgraph.addEdge(7, 10);
	mgraph.addEdge(6, 9);
	mgraph.addEdge(1, 9);
	mgraph.addEdge(1, 3);
	mgraph.DFS();

	std::cout << std::endl;
	
	std::cout << "DFS for undirected graph\n";
	GraphAdjMatrix mgraph2(11, Graph::ConnectionType::undirected);
	mgraph2.addEdge(0, 1);
	mgraph2.addEdge(0, 2);
	mgraph2.addEdge(0, 3);
	mgraph2.addEdge(1, 4);
	mgraph2.addEdge(2, 5);
	mgraph2.addEdge(2, 6);
	mgraph2.addEdge(3, 7);
	mgraph2.addEdge(4, 8);
	mgraph2.addEdge(5, 9);
	mgraph2.addEdge(7, 10);
	mgraph2.addEdge(6, 9);
	mgraph2.addEdge(1, 9);
	mgraph2.addEdge(1, 3);
	mgraph2.DFS();
	

#ifdef TIME_LOG_ENABLED
	int startTime = getTime();
#endif

	graph.BFS();

#ifdef TIME_LOG_ENABLED
	int endTime = getTime();
	int diff = endTime - startTime;
	std::cout << "\n" << "Time used for BFS: " << diff << "\n";
#endif

}