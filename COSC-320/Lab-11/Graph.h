#ifndef _GRAPH_H_
#define _GRAPH_H_
#include<iostream> // cout, endl
#include<map> // map
#include<stdio.h> // printf
#include<vector> // vector
#include<queue> // queue
#include<limits> // Infinity
#include<algorithm> // sort reverse

enum color_t {
	Black, Gray, White
};

class Graph {
	private:
		// Will map an int to a list of its neighbors 
		std::map<int, std::vector<int>> vertices;
		int time;
		std::map<int, int> finish; // Finish time metadata from DFS used for topological sort
		bool isDag;

		void fillMaps(std::map<int, color_t>&, std::map<int, int>&, std::map<int, int>&); // Fills the three metadata maps to default values for the printBfs function
		void DFS_visit(int, std::map<int, color_t>&, std::map<int, int>&, std::map<int, int>&); // Recursive function called that helps the print-DFS function
	public:
		Graph(); // Default Constructor
		void addVertex(int); // adds a vertext to the graph
		void addEdge(int, int); // add an undirected edge to the graph
		void print(); // prints the adjacency list of each vertex, to show the structure
		void printBfs(int); // prints the vertices discovered by a BFS, starting at a given vertex
		void printDfs(); // prints the vertices discovered by a DFS
		void topoPrint(); // Prints the topological sort of the graph by using the finish time metadata
};

#endif
