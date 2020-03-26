#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_
#include <iostream>
#include <stdio.h>

class BinaryTree {
	private:
		struct TreeNode {
			int key;
			TreeNode* left;
			TreeNode* right;
			TreeNode* parent;
		};

		TreeNode* root;
		void DeAllocate(TreeNode*); // Acts as destructor
		void copyOver(TreeNode*); // Acts as copy constructor
		
		void _print(TreeNode*); // Pre order print function
		void _inorder(TreeNode*); // Prints the binary tree in order
		TreeNode* _search(int); // Searches for a specfied key and returns node
		TreeNode* _minimum(); // Returns the smallest key in the tree
		TreeNode* _maximum(); // Returns the largest key in the tree
		TreeNode* _successor(int); // For node with key passed, find its successor
	public:
		BinaryTree(); // Default Constructor
		BinaryTree(const BinaryTree&); // Copy Constructor
		~BinaryTree(); // Destructor
		BinaryTree& operator=(const BinaryTree&); // Overloaded assignment

		void insert(int); // Inserts a new key into the tree
		void deleteNode(int); // Removes given node from the tree if it exists

		void print(); // Wrapper for print function
		void inorder(); // Wrapper for inorder function
		int search(int); // Wrapper for search function
		int minimum(); // Wrapper for minimum function
		int maximum(); // Wrapper for maximum function
		int successor(int); // Wrapper for successor function
};

#endif
