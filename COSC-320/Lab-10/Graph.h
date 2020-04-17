#ifndef _GRAPH_H_
#define _GRAPH_H_
#include<iostream>
#include<map>
#include<stdio.h>
#include<vector>

class Graph {
	private:
		// Will map an int to a list of its neighbors 
		std::map<int, std::vector<int>> vertices;

	public:
		void addVertex(int); // adds a vertext to the graph
		void addEdge(int, int); // add an undirected edge to the graph
		void print(); // prints the adjacency list of each vertex, to show the structure
		void printBfs(int); // prints the vertices discovered by a BFS, starting at a given vertex
};

#endif
