#include<iostream> // cout, endl
#include<stdio.h> // printf
#include"Graph.h" // Graph class
#include<vector> // std::vector
#include<map> // std::map

int main() {

	Graph g;
	
	std::cout << "Inserting vertices..." << std::endl;
	g.addVertex(2);
	g.addVertex(3);
	g.addVertex(5);
	g.addVertex(-2);

	g.print();

	std::cout << "Testing the insert of a vertex that is already inserted..." << std::endl;
	g.addVertex(2);

	std::cout << "Inserting edges..." << std::endl;
	g.addEdge(2, 3);
	g.addEdge(3, 5);
	g.addEdge(-2, 5);

	g.print();

	std::cout << "Testing out adding an edge to itself..." << std::endl;
	g.addEdge(5, 5);

	std::cout << "Testing out adding an edge to vertices that may not be in the map..." << std::endl;
	g.addEdge(5, 0);
	g.addEdge(-2, 10);

	return 0;	
}
