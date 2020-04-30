#include "Graph.h"

/*
   Default Constructor
   Initializes boolean value
*/
Graph::Graph() {
	isDag = true;
}

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
   Prints the vertices discovered by a BFS, starting at a given vertex
*/
void Graph::printBfs(int s) {
	std::queue<int> q;
	std::map<int, color_t> colors;
	std::map<int, int> distance;
	std::map<int, int> parents;
	fillMaps(colors, distance, parents);
	
	colors[s] = Gray;
	distance[s] = 0;
	parents[s] = std::numeric_limits<int>::max();

	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (std::vector<int>::iterator it = vertices[u].begin(); it != vertices[u].end(); ++it) {
			if (colors[*it] == White) {
				colors[*it] = Gray;
				distance[*it] = distance[u] + 1;
				parents[*it] = u;
				q.push(*it);
			}
		}
		colors[u] = Black;
	}

	int i = 0;
	std::map<int, color_t>::iterator c = colors.begin();
	std::map<int, int>::iterator d = distance.begin();
	std::map<int, int>::iterator p = parents.begin();
	std::cout << "==================================================" << std::endl;
	std::cout << "We started at " << s << std::endl;
	std::cout << "Black = 0, Gray = 1, White = 2" << std::endl;
	for (; c != colors.end(); ++c, ++d, ++p, i++) {
		std::cout << "==================================================" << std::endl;
		std::cout << "Vertex: " << c->first << std::endl;
		std::cout << "Color: " << (c->second == 0 ? "Black" : (c->second == 1 ? "Gray" : "White")) << std::endl;
		std::cout << "Distance from Element " << s <<  ": " << d->second << std::endl;
		std::cout << "Parent Element: " << p->second << std::endl;
		std::cout << "==================================================" << std::endl;
	}
}

/*
   fillMaps Function:
   Fills the three metadata maps to default values for the printBfs function
*/
void Graph::fillMaps(std::map<int, color_t>& c, std::map<int, int>& d, std::map<int, int>& p) {
	std::map<int, std::vector<int>>::iterator main;
	for (main = vertices.begin(); main != vertices.end(); ++main) {
		c.insert(std::pair<int, color_t>(main->first, White));
		d.insert(std::pair<int, int>(main->first, std::numeric_limits<int>::max()));
		p.insert(std::pair<int, int>(main->first, std::numeric_limits<int>::max()));
	}
}

/*
   printDfs Function:
   Prints the vertices discovered by a DFS
*/
void Graph::printDfs() {
	std::map<int, color_t> colors;
	std::map<int, int> distance;
	std::map<int, int> parents;
	fillMaps(colors, distance, parents);
	
	for (std::map<int, std::vector<int>>::iterator main = vertices.begin(); main != vertices.end(); ++main) {
		finish.insert(std::pair<int, int>(main->first, std::numeric_limits<int>::max()));
	}

	time = 0;

	for (std::map<int, std::vector<int>>::iterator it = vertices.begin(); it != vertices.end(); ++it) {
		if (colors[it->first] == White) {
			DFS_visit(it->first, colors, distance, parents);
		}
	}

	
	std::map<int, color_t>::iterator c = colors.begin();
	std::map<int, int>::iterator d = distance.begin();
	std::map<int, int>::iterator p = parents.begin();
	std::map<int, int>::iterator f = finish.begin();
	std::cout << "==================================================" << std::endl;
	std::cout << "Black = 0, Gray = 1, White = 2" << std::endl;
	for (; c != colors.end(); ++c, ++d, ++p, ++f) {
		std::cout << "==================================================" << std::endl;
		std::cout << "Vertex: " << c->first << std::endl;
		std::cout << "Color: " << (c->second == 0 ? "Black" : (c->second == 1 ? "Gray" : "White")) << std::endl;
		std::cout << "Discovery/Finish Time: " << d->second << "/" << f->second << std::endl;
		std::cout << "Parent Element: " << p->second << std::endl;
		std::cout << "==================================================" << std::endl;
	}
}

/*
   DFS-visit Function:
   Recursive function called that helps the print-DFS function
*/
void Graph::DFS_visit(int u, std::map<int, color_t>& c, std::map<int, int>& d, std::map<int, int>& p) {
	time++;
	d[u] = time; // discovery time
	c[u] = Gray;
	for (std::vector<int>::iterator it = vertices[u].begin(); it != vertices[u].end(); ++it) {
		if (c[*it] == White) { 
			p[*it] = u;
			DFS_visit(*it, c, d, p);
		} 
		if (c[*it] == Gray) {
			isDag = false;
		}
	}
	c[u] = Black;
	time++;
	finish[u] = time; // finish time
}

/*
   topoPrint Function:
   Prints the topological sort of the graph by using the finish metadate from DFS
*/
void Graph::topoPrint() {
	printDfs(); // Must make sure that Dfs has not already been run or will create finish times twice
	if (!isDag) {
		throw std::runtime_error("Not a DAG graph, cannot perform topoPrint function");
	}
	std::vector<std::pair<int, int>> vect;
	for (std::map<int, int>::iterator it = finish.begin(); it != finish.end(); ++it) {
		vect.push_back(std::pair<int, int>(it->second, it->first));
	}
	std::sort(vect.begin(), vect.end());
	std::reverse(vect.begin(), vect.end());

	std::cout << "Topological sort of the elements" << std::endl;
	std::cout << "FinishVal/Vertex" << std::endl;
	std::cout << "============================================" << std::endl;
	for (std::vector<std::pair<int, int>>::iterator it = vect.begin(); it != vect.end(); ++it) {
		std::cout << it->first << "/" << it->second << ", ";	
	}
	std::cout << std::endl;
	std::cout << "============================================" << std::endl;
}

/*
   SCCprint Function:
   Prints the strongly connected componenets of the graph
*/
void Graph::SCCprint() {
	printDfs();
	Graph tmp;
	for (std::map<int, std::vector<int>>::iterator it = vertices.begin(); it != vertices.end(); ++it) {
		tmp.addVertex(it->first);
	}
	for (std::map<int, std::vector<int>>::iterator it = vertices.begin(); it != vertices.end(); ++it) {
		for (std::vector<int>::iterator i = it->second.begin(); i != it->second.end(); ++i) {
			tmp.addEdge(*i, it->first);
		}
	}

	std::vector<std::pair<int, int>> vect;
	for (std::map<int, int>::iterator it = finish.begin(); it != finish.end(); ++it) {
		vect.push_back(std::pair<int, int>(it->second, it->first));
	}
	std::sort(vect.begin(), vect.end());
	std::reverse(vect.begin(), vect.end());

	tmp.SCCdfs(vect); // Calls the dfs using the descending finish times of the previous dfs search
}

/*
   SCCdfs Function:
   Modified DFS function that will compute the strongly connected components based on the descending order of finish times
*/
void Graph::SCCdfs(std::vector<std::pair<int, int>> vect) {
	std::map<int, color_t> colors;
	for (std::vector<std::pair<int, int>>::iterator it = vect.begin(); it != vect.end(); ++it) {
		colors.insert(std::make_pair(it->second, White));
	}

	std::cout << "Strongly Connected Components (Printed groups line by line)" << std::endl;
	for (std::vector<std::pair<int, int>>::iterator it = vect.begin(); it != vect.end(); ++it) {
		if (colors[it->second] == White) {
			SCCdfs_visit(it->second, colors);
			std::cout << std::endl;
		}
	}
}

/*
   SCCdfs_visit Function:
   Modified recursive DFS_visit function that tracks and prints the strongly connected components of the graph
*/
void Graph::SCCdfs_visit(int u, std::map<int, color_t>& c) {
	c[u] = Gray;
	for (std::vector<int>::iterator it = vertices[u].begin(); it != vertices[u].end(); ++it) {
		if (c[*it] == White) { 
			SCCdfs_visit(*it, c);
		} 
	}
	c[u] = Black;
	std::cout << u << " ";
}

/*
   printCover Function:
   Prints a vertex cover for a graph (accurate within 2 times the true min cover)
*/
void Graph::printCover() {
	std::map<int, std::vector<int>> copyVertices = vertices;
	std::vector<int> S;
	std::map<int, std::string> isCovered;

	for (std::map<int, std::vector<int>>::iterator it = copyVertices.begin(); it != copyVertices.end(); ++it) {
		isCovered.insert(std::pair<int, std::string>(it->first, "Uncovered"));		
	}

	for (std::map<int, std::vector<int>>::iterator it = copyVertices.begin(); it != copyVertices.end(); ++it) {
		if (isCovered[it->first] == "Uncovered") {
			for (std::vector<int>::iterator i = it->second.begin(); i != it->second.end(); ++i) {
				if (isCovered[*i] == "Uncovered") {
					S.push_back(*i);
					isCovered[*i] = "Covered";
				}
			}
		}
	}
	std::cout << "Cover List of Edges" << std::endl;
	for (std::vector<int>::iterator it = S.begin(); it != S.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

/*
   printCoverRandom Function:
   Prints the vertex cover for a graph (accurate within 2 times the true min cover using random choice of vertices)
*/
void Graph::printCoverRandom() {
	std::map<int, std::vector<int>> copyVertices = vertices;
	std::vector<int> S;
	std::map<int, std::string> isCovered;

	for (std::map<int, std::vector<int>>::iterator it = copyVertices.begin(); it != copyVertices.end(); ++it) {
		isCovered.insert(std::pair<int, std::string>(it->first, "Uncovered"));		
	}

	std::vector<int> randomVert;
	for (std::map<int, std::vector<int>>::iterator it = copyVertices.begin(); it != copyVertices.end(); ++it) {
		randomVert.push_back(it->first);	
	}
	std::random_shuffle(randomVert.begin(), randomVert.end());
	std::cout << "Random shuffle vertices" << std::endl;
	for (auto i = randomVert.begin(); i != randomVert.end(); ++i) {
		std::cout << *i << " ";
	}
	std::cout << std::endl;

	for (std::vector<int>::iterator it = randomVert.begin(); it != randomVert.end(); ++it) {
		if (isCovered[*it] == "Uncovered") {
			for (std::vector<int>::iterator i = copyVertices[*it].begin(); i != copyVertices[*it].end(); ++i) {
				if (isCovered[*i] == "Uncovered") {
					S.push_back(*i);
					isCovered[*i] = "Covered";
				}
			}
		}
	}
	std::cout << "Cover List of Edges" << std::endl;
	for (std::vector<int>::iterator it = S.begin(); it != S.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
