// Stiven LaVrenov
// CSCI 3110-001
// Project #4
// Due: 06/25/22

#include "wordtree.h"
#include <cctype>
#include <fstream>
#include <iostream>

int main() {
    char query;
    std::string word;
    int threshold;
    std::string search;

    // instantiate wordtree object
    WordTree* tree = new WordTree();

    // open and read 'input.txt' and build wordtree with addWord function
    std::ifstream inFile;
    inFile.open("input.txt", std::ios::in);

    while (!inFile.eof()) {
        inFile >> word;
        tree->addWord(word);
    }
    inFile.close();
    std::cout << "Word tree built and loaded" << '\n' << std::endl;

    inFile.open("queries.txt");
    while (!inFile.eof()) {
        inFile >> query;
        if (query == 'C') {
            inFile >> threshold;
            std::cout << "Finding all words with " << threshold << " or more occurence(s):" << std::endl;
            tree->getCounts(threshold);
        } else if (query == 'F') {
            inFile >> search;
            std::cout << "Searching for occurences of the word '" << search << "':" << std::endl;
            tree->findWord(search);
        }
    }
    inFile.close();

    delete tree;
    return 0;
}