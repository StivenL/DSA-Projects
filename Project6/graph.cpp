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

// Parameterized constructor
Graph::Graph(int numV) {
    numVertices = numV;
}

// Adds edges to the adjacency list, adjacent
void Graph::addEdge(int from, int to, double weight, bool directed) {    
    if (directed) {
        std::cout << "Edge " << from << ", " << to << ", " << weight << std::endl;
        Endpoint ep(to, weight);
        if (adjacent.size() == from) {
            std::list<Endpoint> epList;
            epList.push_back(ep);
            adjacent.push_back(epList);
        } else {
            adjacent[from].push_back(ep);
        }
    } else {
        Endpoint ep(to, weight);
        Endpoint np(from, weight);
        if (adjacent.size() == from) {
            std::cout << "Edge " << from << ", " << to << ", " << weight << std::endl;
            std::list<Endpoint> epList;
            epList.push_back(ep);
            adjacent.push_back(epList);
        } else {
            std::cout << "Edge " << from << ", " << to << ", " << weight << std::endl;
            adjacent[from].push_back(ep);
        }

        if (adjacent.size() == to) {
            std::cout << "Edge " << to << ", " << from << ", " << weight << std::endl;
            std::list<Endpoint> epList;
            epList.push_back(np);
            adjacent.push_back(epList);
        } else {
            std::cout << "Edge " << to << ", " << from << ", " << weight << std::endl;
            adjacent[to].push_back(np);
        }
    }
}

// Finds the shortest path in the adjacency list with the given starting index
void Graph::DijkstraPaths(int startingVertex) {
    double inf = std::numeric_limits<double>::infinity();

    std::vector<PathNode> shortestPath;

    for (int i = 0; i < adjacent.size(); i++) {
        PathNode node;
        node.cost = inf;
        node.prev = -1;
        shortestPath.push_back(node);
    }

    shortestPath[startingVertex].cost = 0;

    std::set<std::pair<int, int>> path;
    path.insert(std::make_pair(shortestPath[startingVertex].cost, startingVertex));

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

    std::cout << "Shortest paths: " << std::endl;
    int i = 0;
    for (auto node: shortestPath) {
        std::cout << i << " cost: " << node.cost << "    prev: " << node.prev << std::endl;
        i++;
    }
}
