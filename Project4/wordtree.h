// Stiven LaVrenov
// CSCI 3110-001
// Project #4
// Due: 06/25/22

#ifndef WORDTREE_H
#define WORDTREE_H

#include<iostream>
#include<string>
using namespace std;

class WordTree
{
   private:
      struct TreeNode
      {
         string value;        // The value in the node
         TreeNode *left;      // Pointer to left child node
         TreeNode *right;   	// Pointer to right child node
         int count;				// Instance count of value
      };

      TreeNode *root;         // Pointer to the root node
      
      // Private member functions - all are recursive
      void _addWord(TreeNode*& node, string word);			      // reference to pointer to node, and word to be added
      void _deleteSubTree(TreeNode* node);            // pointer to node
      void _getCounts(TreeNode* node, int threshold, int& count) const;   // pointer to node, int threshold
      // reference to int that accumulates nodes that meet the query
      
   public:
      // Constructor
      WordTree();
         
      // Destructor - invokes helper function
      ~WordTree();
         
      // public functions via which the tree operations are called (hides tree's root/implementation) 
      void addWord(string word);
      void findWord(string word);
      void getCounts(int threshold);
};
#endif
