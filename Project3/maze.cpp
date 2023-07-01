// Stiven LaVrenov
// CSCI 3110-001
// Project #3
// Due: 06/19/22

#include "maze.h"
#include <iostream>

// Reads an input file, checks for valid maze dimensions, and creates a maze
Maze::Maze(std::ifstream& inFile) {
    inFile.open("maze.txt");
    Coordinate coord(0, 0);

    inFile >> maxRows >> maxCols;

    if ((maxRows < 2 || maxCols < 2) || (maxRows > 8 || maxCols > 8)) {
        std::cout << "Invalid dimensions." << std::endl;
        exit(0);
    }

    for (int x = 0; x <= maxRows; x++)
            for (int y = 0; y <= maxCols; y++)
                maze[x][y] = 'X';

    while (!inFile.eof()) {
        for (int x = 1; x <= maxRows; x++) {
            for (int y = 1; y <= maxCols; y++) {
                inFile >> maze[x][y];
                if (maze[x][y] == 'O' || maze[x][y] == 'E') {
                    coord.x = x;
                    coord.y = y;
                    coords.push_back(coord);
                }
            }
        }
    }

    inFile.close();
}

// Outputs the current state of the maze
void Maze::Print() {
    std::cout << "Maze State:" << std::endl;
    for (int x = 1; x <= maxRows; x++) {
            for (int y = 1; y <= maxCols; y++)
                std::cout << maze[x][y] << " ";
            std::cout << std::endl;
    }
}

// Returns the starting coorindates for the maze
Coordinate Maze::GetStartPt() {
    return Coordinate(1, 1);
}

// Recursively solves the maze
void Maze::FindExit(int row, int col, bool &found) {
    char north = row-1;
    char south = row+1;
    char east = col-1;
    char west = col+1;

    if (maze[row][col] == 'E') {
        std::cout << "Trying " << row << "," << col << std::endl;
        found = true;
    } else if (maze[row][col] == 'O') {
        std::cout << "Trying " << row << "," << col << std::endl;
        maze[row][col] = '*';
        Print();
        FindExit(south, col, found);

        if (!found) {
            FindExit(north, col, found);
        }
        if (!found) {
            FindExit(row, east, found);
        }
        if (!found) {
            FindExit(row, west, found);
        }
    }
}