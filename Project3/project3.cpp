// Stiven LaVrenov
// CSCI 3110-001
// Project #3
// Due: 06/19/22

// This program will generate a maze with a valid given input file, and
// recursively solve the maze, returning whether it could find the exit or not

#include "maze.h"
#include <cstdlib>
#include <fstream>
#include <iostream>

int main() {
    srand(1000);

    bool found = false;
    std::ifstream inFile;

    Maze maze = Maze(inFile);

    maze.Print();
    Coordinate start = maze.GetStartPt();
    std::cout << "Starting Position: " << start.x << "," << start.y << std::endl;

    maze.FindExit(start.x, start.y, found);

    if (found) {
        std::cout << "Exit Found" << std::endl;
    } else {
        std::cout << "No Exit" << std::endl;
    }
}