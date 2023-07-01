// Stiven LaVrenov
// CSCI 3110-001
// Project #4
// Due: 06/25/22

#include "wordtree.h"
#include <iostream>

// Constructor
WordTree::WordTree() {
    root = NULL;
}

// Destructor
WordTree::~WordTree() {
    _deleteSubTree(root);
}

// Iteratively searches the word tree for the given word string
void WordTree::findWord(std::string word) {
    TreeNode* temp = root;
    while (temp != NULL) {
        if (temp->value == word) {
            std::cout << "The word '" << word << "' occurs " << temp->count << " time(s) in the text." << '\n' << std::endl;
            return;
        } else if (temp->value < word) {
            temp = temp->right;
        } else {
            temp = temp->left;
        }
    }
    std::cout << "The word " << word << " was not found in the text." << std::endl;
}

// Recursively adds a word to the word tree
void WordTree::addWord(std::string word) {
    for (auto& ch: word)
        ch = tolower(ch);
    _addWord(root, word);
}

void WordTree::_addWord(TreeNode*& node, std::string word) {
    if (node == NULL) {
        node = new TreeNode();
        node->value = word;
        node->left = NULL;
        node->right = NULL;
    }
    if (word < node->value && node->left == NULL) {
        node->left = new TreeNode();
        node->left->value = word;
        node->left->count = 1;
    } else if (word < node->value) {
        _addWord(node->left, word);
    } else if (word > node->value && node->right == NULL) {
        node->right = new TreeNode();
        node->right->value = word;
        node->right->count = 1;
    } else if (word > node->value) {
        _addWord(node->right, word);
    } else {
        node->count++;
    }
}

// Recursively gets the word and word count of all words that are greater
// than or equal to the given threshold
void WordTree::getCounts(int threshold) {
    int count = 0;
    _getCounts(root, threshold, count);
    std::cout << count << " node(s) had words with " << threshold << " or more occurence(s)." << '\n' << std::endl;
}

void WordTree::_getCounts(TreeNode* node, int threshold, int& count) const {
    if (node != NULL) {
        _getCounts(node->left, threshold, count);
        if (node->count >= threshold) {
            std::cout << node->value << "(" << node->count << ")" << std::endl;
            count++;
        }
        _getCounts(node->right, threshold, count);
    }
}

// Recursively destructs the word tree
void WordTree::_deleteSubTree(TreeNode* node) {
    if (node) {
        _deleteSubTree(node->left);
        _deleteSubTree(node->right);
        delete node;
    }
}