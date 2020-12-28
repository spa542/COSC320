#ifndef _RBTree_H_
#define _RBTree_H_
#include <iostream>
#include <stdio.h>

enum color_t {
	RED, BLACK
};

class RBTree {
	private:
		struct TreeNode {
			int key;
			color_t color;
			TreeNode* left;
			TreeNode* right;
			TreeNode* parent;
		};

		TreeNode* root;
		static TreeNode* const nil;

		void DeAllocate(TreeNode*); // Acts as destructor
		void copyOver(TreeNode*); // Acts as copy constructor

		void rbTransplant(TreeNode*, TreeNode*); // Replace subtree with other subtree
		void leftRotate(TreeNode*); // Left rotates the current subtree
		void rightRotate(TreeNode*); // Right rotates the current subtree
		void rbInsertFixUp(TreeNode*); // Fixes up violations in tree after insert
		void rbDeleteFixUp(TreeNode*); // Fixes up violations in tree after deletion
		
		void _print(TreeNode*); // Pre order print function
		void _inorder(TreeNode*); // Prints the binary tree in order
		TreeNode* _search(int); // Searches for a specfied key and returns node
		TreeNode* _minimum(); // Returns the smallest key in the tree
		TreeNode* _maximum(); // Returns the largest key in the tree
		TreeNode* _successor(int); // For node with key passed, find its successor
	public:
		RBTree(); // Default Constructor
		RBTree(const RBTree&); // Copy Constructor
		~RBTree(); // Destructor
		RBTree& operator=(const RBTree&); // Overloaded assignment

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
