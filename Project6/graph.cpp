// Stiven LaVrenov
// CSCI 3110-001
// Project #6
// Due: 07/31/22

#include "graph.h"
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>

using namespace std;

// Parameterized constructor
Graph::Graph(int numV) {
    numVertices = numV;
}

// Adds edges to the adjacency list, adjacent
void Graph::addEdge(int from, int to, double weight, bool directed) {    
    if (directed) {
        cout << "Edge " << from << ", " << to << ", " << weight << endl;
        Endpoint ep(to, weight);
        if (adjacent.size() == from) {
            list<Endpoint> epList;
            epList.push_back(ep);
            adjacent.push_back(epList);
        } else {
            adjacent[from].push_back(ep);
        }
    } else {
        Endpoint ep(to, weight);
        Endpoint np(from, weight);
        if (adjacent.size() == from) {
            cout << "Edge " << from << ", " << to << ", " << weight << endl;
            list<Endpoint> epList;
            epList.push_back(ep);
            adjacent.push_back(epList);
        } else {
            cout << "Edge " << from << ", " << to << ", " << weight << endl;
            adjacent[from].push_back(ep);
        }

        if (adjacent.size() == to) {
            cout << "Edge " << to << ", " << from << ", " << weight << endl;
            list<Endpoint> epList;
            epList.push_back(np);
            adjacent.push_back(epList);
        } else {
            cout << "Edge " << to << ", " << from << ", " << weight << endl;
            adjacent[to].push_back(np);
        }
    }
}

// Finds the shortest path in the adjacency list with the given starting index
void Graph::DijkstraPaths(int startingVertex) {
    double inf = std::numeric_limits<double>::infinity();

    vector<PathNode> shortestPath;

    for (int i = 0; i < adjacent.size(); i++) {
        PathNode node;
        node.cost = inf;
        node.prev = -1;
        shortestPath.push_back(node);
    }

    shortestPath[startingVertex].cost = 0;

    set<pair<int, int>> path;
    path.insert(make_pair(shortestPath[startingVertex].cost, startingVertex));

    while (!path.empty()) {
        int u = path.begin()->second;
        path.erase(path.begin());
        for (auto elem: adjacent[u]) {
            if (shortestPath[elem.to].cost > shortestPath[u].cost + elem.weight) {
                path.erase({shortestPath[elem.to].cost, elem.to});
                shortestPath[elem.to].cost = {shortestPath[u].cost + elem.weight};
                shortestPath[elem.to].prev = u;
                path.insert({shortestPath[elem.to].cost, elem.to});
            }
        }
    }

    cout << "Shortest paths: " << endl;
    int i = 0;
    for (auto node: shortestPath) {
        cout << i << " cost: " << node.cost << "    prev: " << node.prev << endl;
        i++;
    }
}
