#include "Graph.h"

/*
   addVertex Function:
   Adds a vertex to the graph 
*/
void Graph::addVertex(int addMe) {
	std::map<int, std::vector<int>>::iterator it;
	it = vertices.find(addMe);
	if (it != vertices.end()) {
		std::cout << "Vertex " << addMe << " is already in the graph" << std::endl;
		return;
	}
	std::vector<int> edge;
	vertices.insert(std::pair<int, std::vector<int>>(addMe, edge));
}

/*
   addEdge Function:
   Adds an undirected edge to the graph
*/
void Graph::addEdge(int first, int second) {
	if (first == second) {
		std::cout << "No self edges" << std::endl;
		return;
	}
	std::map<int, std::vector<int>>::iterator it;
	it = vertices.find(first);
	if (it == vertices.end()) {
		std::cout << first << " vertex not found" << std::endl;
		return;
	}
	it = vertices.find(second);
	if (it == vertices.end()) {
		std::cout << second << " vertex not found" << std::endl;
		return;
	}
	vertices[first].push_back(second);
	vertices[second].push_back(first);
}

/*
   print Function:
   Prints the adjacency list of each vertex to show the structure
*/
void Graph::print() {
	for (std::map<int, std::vector<int>>::iterator it = vertices.begin(); it != vertices.end(); ++it) {
		std::cout << it->first << " is connected to these vertices..." << std::endl;
		for (std::vector<int>::iterator vt = it->second.begin(); vt != it->second.end(); ++vt) {
			std::cout << *vt << ", ";	
		}
		std::cout << std::endl;
	}
}

/*
   printBfs Function:
   Prints the vertices discovered by a BFS, starteing at a given vertex
*/
void Graph::printBfs(int startPoint) {

}
