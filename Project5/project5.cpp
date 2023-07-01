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
using namespace std;

int main() {
    char ch;
    ifstream inFile;
    map<char, int> charMap;

    HuffmanTree* huffTree = new HuffmanTree();

    inFile.open("input.txt", ios::in);
    cout << "Input text file: ";
    while (inFile >> noskipws >> ch) {
        cout << ch;
        if (charMap.find(ch) != charMap.end()) {
            charMap[ch]++;
        } else {
            charMap.insert(make_pair(ch, 1));
        }
    }
    cout << endl;

    huffTree->populatePriorityQueue(charMap);
    huffTree->generateHuffmanTree();
    huffTree->printHuffmanCodes();

    inFile.close();

    delete huffTree;
    return 0;
}