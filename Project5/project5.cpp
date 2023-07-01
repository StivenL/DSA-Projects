// Stiven LaVrenov
// CSCI 3110-001
// Project #5
// Due: 07/07/22

#include "huffman.h"
#include <map>
#include <queue>
#include <fstream>
#include <iterator>
#include <iomanip>
#include <iostream>

int main() {
    char ch;
    std::ifstream inFile;
    std::map<char, int> charMap;

    HuffmanTree* huffTree = new HuffmanTree();

    inFile.open("input.txt", std::ios::in);
    std::cout << "Input text file: ";
    while (inFile >> std::noskipws >> ch) {
        std::cout << ch;
        if (charMap.find(ch) != charMap.end()) {
            charMap[ch]++;
        } else {
            charMap.insert(std::make_pair(ch, 1));
        }
    }
    std::cout << std::endl;

    huffTree->populatePriorityQueue(charMap);
    huffTree->generateHuffmanTree();
    huffTree->printHuffmanCodes();

    inFile.close();

    delete huffTree;
    return 0;
}