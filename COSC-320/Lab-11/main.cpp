#include<iostream> // cout, endl
#include<stdio.h> // printf
#include"Graph.h" // Graph class
#include<vector> // std::vector
#include<map> // std::map
#include<fstream> // ifstream

int main(int argc, char** argv) {
/*
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
	int vertexCount = 0;
	int* inVert = new int[30]; // No more than 30 vertices for testing purposes
	while (inFile.peek() != EOF) {
		for (int i = 0; i < 4; i++) {
			inFile >> inVert[i];
			std::cout << inVert[i] << std::endl;
			vertexCount++;
		}
		for (int i = 0; i < vertexCount; i++) {
			k.addVertex(inVert[i]);
		}
		k.print();
		inFile.ignore(5, '\n');
		for (int i = 0; i < vertexCount; i++) {
			for (int j = 0; inFile.peek() != '-'; j++) {
				int edgeVertex;
				inFile >> edgeVertex; // Must have it so vertices are placed in numeric order
				k.addEdge(inVert[i], edgeVertex);
			}
			inFile.ignore(5, '\n');
		}
		inFile.ignore(5, '\n');
	}
	std::cout << "Graph that was input..." << std::endl;
	k.print();
	delete [] inVert;
	std::cout << "======================================================" << std::endl;
*/
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

	g.addVertex(8);
	g.addVertex(10);
	g.addVertex(-6);
	g.addEdge(-6, 8);
	g.addEdge(-6, 5);
	g.addEdge(-6, 3);
	g.addEdge(8, 10);
	std::cout << "======================================================" << std::endl;
	std::cout << "Testing the printDfs Function..." << std::endl;
	std::cout << "Current working graph..." << std::endl;
	g.print();
	std::cout << "printDfs Doing its work..." << std::endl;
	g.printDfs();
	std::cout << "======================================================" << std::endl;

	std::cout << "======================================================" << std::endl;
	std::cout << "Testing out the topological sort..." << std::endl;
	std::cout << "Current Working graph..." << std::endl;
	Graph h;
	h.addVertex(7);
	h.addVertex(9);
	h.addVertex(2);
	h.addVertex(0);
	h.addVertex(12);
	h.addEdge(7, 9);
	h.addEdge(7, 12);
	h.addEdge(12, 2);
	h.addEdge(2, 0);
	h.print();
	h.topoPrint();
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
