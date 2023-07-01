// Stiven LaVrenov
// CSCI 3110-001
// Project #5
// Due: 07/07/22

#pragma once 
#include <iostream>
#include <string>
#include <queue>
#include <map>
using namespace std;

class Node {
public:
	char character;
	int frequency;
	Node* left;
	Node* right;

	Node(char ch, int freq)
	{
		character = ch;
		frequency = freq;
		left = right = NULL;
	}
};
// Custom comparator class for the priority queue (check: https://en.cppreference.com/w/cpp/container/priority_queue)
class Compare {
public:
	bool operator()(Node* node1,	Node* node2)
	{
		// Defining priority on the basis of frequency
		return node1->frequency > node2->frequency;
	}
};

class HuffmanTree{
    private:
        Node* root;
		priority_queue<Node*,vector<Node*>,Compare> pqueue;
    public:
		HuffmanTree();
		~HuffmanTree();
		void populatePriorityQueue(map<char,int> charMap);
		void generateHuffmanTree();
		void printHuffmanCodes();
    private:
        //include private member functions for printHuffmanCodes method and destructor
		void _deleteSubTree(Node* node);
		void _printHuffmanCodes(Node* node, string code);
};