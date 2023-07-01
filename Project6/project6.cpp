// Stiven LaVrenov
// CSCI 3110-001
// Project #6
// Due: 07/31/22

#include "graph.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

int main() {
    ifstream inFile;
    int numVertices, edgeRecords, startingVertex;
    int from, to, weight;
    bool directed;

    inFile.open("graph.txt", ios::in);
    // Header line
    inFile >> numVertices >> edgeRecords >> startingVertex;

    // Initialize graph object
    Graph graph = Graph(numVertices);

    // Populate adjacency list
    while (inFile >> from >> to >> weight >> boolalpha >> directed) {
        graph.addEdge(from, to, weight, directed);
    }
    cout << endl;

    // Find the shortest path
    graph.DijkstraPaths(startingVertex);

    inFile.close();
    return 0;
}