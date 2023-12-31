//  Stiven LaVrenov
//  CSCI 3110-001
//  Project #2
//  Due: 06/07/2022

//  This program will calculate and output gas given to vehicles
//  based on gas type and the amount of gas purchased

#include "gaspump.h"
#include <cstdlib>
#include <fstream>
#include <iostream>

//  Variable Declarations
int seed = 0;
int numOfCars = 0;
const int SIZE = 3;

std::string gasType;
double pricePerGallon;

int main() {
    
    //  Open the input file
    std::ifstream inFile;
    inFile.open("gas.txt", std::ios::in);

    inFile >> seed >> numOfCars;

    // Initialize a pointer array for the GasPump class and instantiate each gas type
    GasPump* pump[SIZE];
    for (int i = 0; i < SIZE; i++) {
        inFile >> gasType >> pricePerGallon;
        pump[i] = new GasPump(gasType, pricePerGallon);
    }

    // Set random seed
    srand(seed);

    std::cout << std::fixed;
    std::cout.precision(2);

    // Determine which gasPump to use, how much gas to purchase, and how many gallons were pumped
    for (int i = 1; i < numOfCars+1; i++) {
        int index = rand() % 3;
        double amt = ((rand() % 6) * 5) + 25;
        double gallons = pump[index]->dispenseFuel(amt); // ^^^ that shit

        std::cout << i << " " << pump[index]->returnType() << " " << pump[index]->returnPrice() << " " << amt << " " << gallons << std::endl;
    }

    for (int i = 0; i < SIZE; i++) {
        std::cout << pump[i]->returnType() << " " << pump[i]->returnTotalFuel() << " " << pump[i]->returnTotalAmt() << std::endl;
    }

    // Close the input file
    inFile.close();

    return 0;
}