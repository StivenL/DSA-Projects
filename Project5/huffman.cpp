// Stiven LaVrenov
// CSCI 3110-001
// Project #5
// Due: 07/07/22

#include "huffman.h"
#include <string>
#include <iterator>
#include <iomanip>
#include <iostream>
using namespace std;

// Constructs empty HuffmanTree
HuffmanTree::HuffmanTree() {
    root = NULL;
}

// Default Destructor
HuffmanTree::~HuffmanTree() {
    _deleteSubTree(root);
}

// Recursive helper function for destructor
void HuffmanTree::_deleteSubTree(Node* node) {
    if (node) {
        _deleteSubTree(node->left);
        _deleteSubTree(node->right);
        delete node;
    }
}

// Populates the priority queue given a map
// of characters and their frequencies
void HuffmanTree::populatePriorityQueue(map<char, int> charMap) {
    for (auto item : charMap) {
        Node* newNode = new Node(item.first, item.second);
        pqueue.push(newNode);
    }
}

// Builds the Huffman tree with the filled pqueue
void HuffmanTree::generateHuffmanTree() {
    Node *left, *right;
    while (pqueue.size() != 1) {
        // pop top 2 nodes as LEFT and RIGHT
        left = pqueue.top();
        pqueue.pop();

        right = pqueue.top();
        pqueue.pop();

        // create new node (-, sum of freq of LEFT & RIGHT)
        Node* intermediate = new Node('-', left->frequency+right->frequency);

        // set new node LEFT to LEFT and RIGHT to RIGHT ???
        intermediate->left = left;
        intermediate->right = right;

        // push back new node to pqueue??
        pqueue.push(intermediate);
    }
    // set root as top of pqueue
    root = pqueue.top();
}

// Prints the characters and codes in the Huffman tree
void HuffmanTree::printHuffmanCodes() {
    string code = "";
    cout << "Character " << setw(20) << " Huffman Codes" << endl;
    _printHuffmanCodes(root, code);
}

// Recursive helper function to traverse Huffman tree
void HuffmanTree::_printHuffmanCodes(Node* node, string code) {
    if (node->left) {
        _printHuffmanCodes(node->left, code+"0");
    }
    if (node->right) {
        _printHuffmanCodes(node->right, code+"1");
    }
    if (!node->left && !node->right) {
        cout << setw(17) << node->character << left << code << endl;
    }
}