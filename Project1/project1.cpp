//  Stiven LaVrenov
//  CSCI 3110-001
//  Project #1
//  Due: 05/24/22

//  This program will read from a nums.txt file, dynamically allocate memory
//  and calculate the average of the given array at the size increase intervals

#include <fstream>
#include <iostream>

int num;
int size = 0;
int count = 0;
double increase = 1.0;

//  This function will create a new dynamic array if one doesn't already exist
//  and increase the size of the array by a given increase value
int *allocateArray(int *numArray, int *size, double increase) {
    if (numArray == NULL) {
        numArray = new int[*size];
    } else {
        int newSize = *size * increase;

        int *tempArray = new int[newSize];

        for (int i = 0; i < newSize; i++)
            tempArray[i] = numArray[i];

        *size = newSize;
        delete [] numArray;
        numArray = tempArray;
    }

    return numArray;
}

//  This function will calculate the average for all numbers in numArray
double calcAvg(int *numArray, int count) {
    float sum = 0.0;
    double avg = 0.0;
    
    for (int i = 0; i < size; i++) {
        sum += numArray[i];
    }
    avg = sum / count;
    return avg;
}

int main() {
    std::ifstream inFile;    // Create input file
    std::ofstream outFile;   // Create output file

    inFile.open("nums.txt", std::ios::in);
    outFile.open("out.txt", std::ios::out);

    inFile >> size >> increase;
    increase++;         // easier multiplication for sizing

    // size validation | 100 =< size =< 350
    if ((size < 100 || size > 350) || size % 50 != 0) {
        std::cout << "Error" << std::endl;
        exit(0);
    }

    int *numArray = NULL;
    numArray = allocateArray(numArray, &size, increase);

    std::cout << size << std::endl;
    outFile << size << std::endl;
    while (!inFile.eof()) {
        inFile >> num;
        numArray[count] = num;
        count++;
        if (count == size) {
            std::cout << size << " " << calcAvg(numArray, count) << std::endl;
            outFile << size << " " << calcAvg(numArray, count) << std::endl;
            numArray = allocateArray(numArray, &size, increase);
        }
    }

    std::cout << size << " " << count << " " << calcAvg(numArray, count) << std::endl;
    outFile << size << " " << count << " " << calcAvg(numArray, count) << std::endl;

    inFile.close();
    outFile.close();

    delete [] numArray;
    return 0;
}