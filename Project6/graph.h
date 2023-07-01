// Stiven LaVrenov
// CSCI 3110-001
// Project #6
// Due: 07/31/22

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <limits>

struct PathNode {								// Use to determine shortest path
	double cost;								// Path cost from source vertex to this vertex
	int prev;									// Vertex preceding this vertex in the shortest path
};

struct Endpoint {								// Represents edge endpoint
	int to;										// To vertex
	double weight;								// Edge weight
	Endpoint(int vertex2, double wt) :			// Endpoint constructor: to, weight
		to{vertex2}, weight{wt} {};				// initialized with initialization list
};

class Graph
{
public:
	Graph(int);									// Contructor - Param(s): Number of vertices
	void addEdge(int, int, double, bool);		// Add edge to adjacency list - Param(s): From vertex, To vertex, Weight, Directed edge?
	void DijkstraPaths(int);					// Computes/Outputs single source shortest paths - Param: source vertex				
private:
	int numVertices;							// Number of vertices in graph
	std::vector<std::list<Endpoint>> adjacent;	// Adjacency list for vertices
};

#endif