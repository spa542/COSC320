#include<iostream> // cout, endl
#include<stdio.h> // printf
#include"Graph.h" // Graph class
#include<vector> // std::vector
#include<map> // std::map
#include<fstream> // ifstream
#include<sstream> // istringstream

int main(int argc, char** argv) {
	srand(time(NULL));
	Graph k;
	std::cout << "Testing the input from a file..." << std::endl;
	std::cout << "======================================================" << std::endl;
	int argCount = argc;
	if (argCount != 2) {
		std::perror("Cannot Execute Program: Error Code\n\t --Amount of arguments incorrect");
		exit(1);
	}
	std::ifstream inFile;
	try {
		inFile.open(argv[1]);
	} catch (...) {
		std::perror("Error: File input not found"); // Error Code for incorrect file
		exit(1);
	}
	int* inVert = new int[30]; // No more than 30 vertices for testing purposes
	while (inFile.peek() != EOF) {
		std::string line;
		std::getline(inFile, line);
		std::istringstream iss(line);
		int v, u;
		iss >> v;
		k.addVertex(v);
		while (iss >> u) {
			k.addVertex(u);
			k.addEdge(v, u);	
		}
	}
	std::cout << "Graph that was input..." << std::endl;
	k.print();
	delete [] inVert;
	std::cout << "======================================================" << std::endl;

	Graph g;

	std::cout << "*Print is demonstrated throughout all tests" << std::endl;
	std::cout << "======================================================" << std::endl;
	std::cout << "Inserting vertices..." << std::endl;
	g.addVertex(2);
	g.addVertex(3);
	g.addVertex(5);
	g.addVertex(-2);
	g.print();
	std::cout << "======================================================" << std::endl;

	std::cout << "======================================================" << std::endl;
	std::cout << "Testing the insert of a vertex that is already inserted..." << std::endl;
	g.addVertex(2);
	std::cout << "======================================================" << std::endl;

	std::cout << "======================================================" << std::endl;
	std::cout << "Inserting edges..." << std::endl;
	g.addEdge(2, 3);
	g.addEdge(3, 5);
	g.addEdge(-2, 5);
	g.print();
	std::cout << "======================================================" << std::endl;

	std::cout << "======================================================" << std::endl;
	std::cout << "Testing out adding an edge to itself..." << std::endl;
	g.addEdge(5, 5);
	std::cout << "======================================================" << std::endl;

	std::cout << "======================================================" << std::endl;
	std::cout << "Testing out adding an edge to vertices that may not be in the map..." << std::endl;
	g.addEdge(5, 0);
	g.addEdge(-2, 10);
	std::cout << "======================================================" << std::endl;

	std::cout << "======================================================" << std::endl;
	std::cout << "Testing the Vertex cover print algorithm..." << std::endl;
	Graph l;
	l.addVertex(1);
	l.addVertex(2);
	l.addVertex(3);
	l.addVertex(4);
	l.addVertex(5);
	l.addVertex(6);
	l.addEdge(1, 2);
	l.addEdge(1, 4);
	l.addEdge(1, 5);
	l.addEdge(2, 3);
	l.addEdge(2, 5);
	l.addEdge(3, 4);
	l.addEdge(4, 6);
	l.addEdge(5, 6);
	std::cout << "Current Working graph..." << std::endl;
	l.print();
	std::cout << "Cover set of the graph..." << std::endl;
	l.printCover();
	std::cout << "======================================================" << std::endl;

	std::cout << "======================================================" << std::endl;
	std::cout << "Testing the Vertex cover print randome algorithm..." << std::endl;
	std::cout << "Current Working graph..." << std::endl;
	l.print();
	std::cout << "Cover set of the graph..." << std::endl;
	l.printCoverRandom();
	std::cout << "======================================================" << std::endl;

	// An example of the program throwing an exception for the graph not being a DAG
	// Need to catch an exception reference 
	/*
	try {
		std::cout << "Testing the throwing of and error if the graph is not a dag" << std::endl;
		Graph p;
		p.addVertex(3);
		p.addVertex(4);
		p.addVertex(6);
		p.addVertex(10);
		p.addEdge(3, 4);
		p.addEdge(3, 6);
		p.addEdge(4, 6);
		p.addEdge(6, 10);
		p.addEdge(10, 4);
		p.print();
		p.topoPrint();
	} catch (const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;;
	}
	*/

	return 0;	
}
