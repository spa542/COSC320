#include "BinaryTree.h"

/*
 * Default Constructor:
 * Initializes the data for the binary tree
 */
BinaryTree::BinaryTree() {
	root = nullptr;
}

/*
 * Copy Constructor:
 * Does necessary deep copy
 */
BinaryTree::BinaryTree(const BinaryTree& old) {
	root = nullptr;
	copyOver(old.root);
}

/*
 * copyOver Function:
 * Does necessary deep copy and acts as copy constructor
 */
void BinaryTree::copyOver(TreeNode* head) {
	if (head) {
		insert(head->key);
		copyOver(head->left);
		copyOver(head->right);
	}
}

/*
 * Destructor:
 * Does necessary destruction of dynamic memory
 */
BinaryTree::~BinaryTree() {
	DeAllocate(root);	
}

/*
 * DeAllocate Function:
 * Acts as the destructor 
 */
void BinaryTree::DeAllocate(TreeNode* head) {
	if (head) {
		DeAllocate(head->left);
		DeAllocate(head->right);
		delete head;
	}
}

/*
 * Overloaded assignment:
 * Does necessary deep copy off of assignment
 */
BinaryTree& BinaryTree::operator=(const BinaryTree& rhs) {
	if (this == &rhs) {
		return *this;
	}

	DeAllocate(root);
	root = nullptr;
	copyOver(rhs.root);
	
	return *this;
}

/*
 * insert Function:
 * Inserts a new key into the tree
 */
void BinaryTree::insert(int newKey) {
	TreeNode* newNode = new TreeNode();
	newNode->key = newKey;
	newNode->left = nullptr;
	newNode->right = nullptr;
	newNode->parent = nullptr;

	TreeNode* curr = root;
	TreeNode* prev = nullptr;
	while (curr) {
		prev = curr;
		if (newNode->key < curr->key) {
			curr = curr->left;
		} else {
			curr = curr->right;
		}
	}

	if (prev == nullptr) {
		root = newNode;
		return;
	}

	if (newNode->key < prev->key) {
		prev->left = newNode;
	} else {
		prev->right = newNode;
	}
	newNode->parent = prev;
}

/*
 * search Function:
 * Wrapper for search function
 */
int BinaryTree::search(int key) {
	TreeNode* rtn = _search(key);
	if (rtn == nullptr) {
		std::cout << "Key not found or tree is empty, returning -1" << std::endl;
		return -1;
	}
	return rtn->key;
}

/*
 * searchMe Function:
 * Searches for a specified key and returns it's node
 */
BinaryTree::TreeNode* BinaryTree::_search(int key) {
	if (root == nullptr) {
		return nullptr;
	}
	TreeNode* cursor = root;
	while (cursor) {
		if (cursor->key == key) {
			return cursor;
		} else if (cursor->key > key) {
			cursor = cursor->left;
		} else {
			cursor = cursor->right;
		}
	}
	return nullptr;
}

/*
 * minimum Function:
 * Wrapper for minimum function
 */
int BinaryTree::minimum() {
	TreeNode* rtn = _minimum();
	if (rtn == nullptr) {
		std::cout << "Tree is empty, returning -1" << std::endl;
		return -1;
	}
	return rtn->key;
}

/*
 * _minimum Function:
 * Returns the smallest key and returns it's node
 */
BinaryTree::TreeNode* BinaryTree::_minimum() {
	TreeNode* cursor = root;
	if (cursor == nullptr) {
		// tree is empty
		return nullptr;
	}
	while (cursor->left) {
		cursor = cursor->left;
	}
	return cursor;
}

/*
 * maximum Function:
 * Wrapper for maximum function
 */
int BinaryTree::maximum() {
	TreeNode* rtn = _maximum();
	if (rtn == nullptr) {
		std::cout << "Tree is empty, returning -1" << std::endl;
		return -1;
	}
	return rtn->key;
}

/*
 * _maximum Function:
 * Returns the largest key and returns it's node
 */
BinaryTree::TreeNode* BinaryTree::_maximum() {
	TreeNode* cursor = root;
	if (cursor == nullptr) {
		// tree is empty
		return nullptr;
	}
	while (cursor->right) {
		cursor = cursor->right;
	}
	return cursor;
}

/*
 * successor Function:
 * Wrapper for successor function
 */
int BinaryTree::successor(int key) {
	TreeNode* rtn = _successor(key);
	if (rtn == nullptr) {
		std::cout << "Key not found in tree or tree is empty, therefore no successor can be found, returning -1" << std::endl;
		return -1;
	}
	return rtn->key;
}

/*
 * _successor Function:
 * For node with key passed, find and returns it's successor node
 */
BinaryTree::TreeNode* BinaryTree::_successor(int key) {
	TreeNode* newKey = _search(key);
	if (newKey == nullptr) {
		return nullptr;
	}

	if (newKey->right == nullptr) {
		TreeNode* cursor = newKey;
		TreeNode* original = newKey;
		while (cursor->parent) {
			if (cursor->parent->left == cursor) {
				return cursor->parent;
			}
			cursor = cursor->parent;
		}
		return original;
	}

	TreeNode* cursor = newKey->right;
	while (cursor->left) {
		cursor = cursor->left;
	}
	return cursor;
}

/*
 * inorder Function:
 * Wrapper for inorder function
 */
void BinaryTree::inorder() {
	_inorder(root);
	std::cout << std::endl;
}

/*
 * _inorder Function:
 * Prints the keys in ascending order
 */
void BinaryTree::_inorder(TreeNode* head) {
	if (head) {
		_inorder(head->left);
		std::cout << head->key << ", ";
		_inorder(head->right);
	}
}

/*
 * deleteNode Function:
 * Removes a given node from the tree if it exists
 */
void BinaryTree::deleteNode(int delMe) {

}

/*
 * print Function:
 * Wrapper function for print
 */
void BinaryTree::print() {
	_print(root);
	std::cout << std::endl;
}

/*
 * _print Function:
 * Pre order print function
 */
void BinaryTree::_print(TreeNode* head) {
	if (head) {
		std::cout << head->key << ", ";
		_print(head->left);
		_print(head->right);
	}
}
