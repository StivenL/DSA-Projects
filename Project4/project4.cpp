// Stiven LaVrenov
// CSCI 3110-001
// Project #4
// Due: 06/25/22

#include "wordtree.h"
#include <cctype>
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    string word;
    char query;
    int threshold;
    string search;

    // instantiate wordtree object
    WordTree* tree = new WordTree();

    // open and read 'input.txt' and build wordtree with addWord function
    ifstream inFile;
    inFile.open("input.txt", ios::in);

    while (!inFile.eof()) {
        inFile >> word;
        tree->addWord(word);
    }
    inFile.close();
    cout << "Word tree built and loaded" << '\n' << endl;

    inFile.open("queries.txt");
    while (!inFile.eof()) {
        inFile >> query;
        if (query == 'C') {
            inFile >> threshold;
            cout << "Finding all words with " << threshold << " or more occurence(s):" << endl;
            tree->getCounts(threshold);
        } else if (query == 'F') {
            inFile >> search;
            cout << "Searching for occurences of the word '" << search << "':" << endl;
            tree->findWord(search);
        }
    }
    inFile.close();

    delete tree;
    return 0;
}