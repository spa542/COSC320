#include "RBTree.h"

RBTree::TreeNode* const RBTree::nil = new TreeNode({0, BLACK, nullptr, nullptr, nullptr});

/*
 * Default Constructor:
 * Initializes the data for the binary tree
 */
RBTree::RBTree() {
	root = nil;
}

/*
 * Copy Constructor:
 * Does necessary deep copy
 */
RBTree::RBTree(const RBTree& old) {
	root = nil;
	copyOver(old.root);
}

/*
 * copyOver Function:
 * Does necessary deep copy and acts as copy constructor
 */
void RBTree::copyOver(TreeNode* head) {
	if (head != nil) {
		insert(head->key);
		copyOver(head->left);
		copyOver(head->right);
	}
}

/*
 * Destructor:
 * Does necessary destruction of dynamic memory
 */
RBTree::~RBTree() {
	DeAllocate(root);
}

/*
 * DeAllocate Function:
 * Acts as the destructor 
 */
void RBTree::DeAllocate(TreeNode* head) {
	if (head != nil) {
		DeAllocate(head->left);
		DeAllocate(head->right);
		delete head;
	}
}

/*
 * Overloaded assignment:
 * Does necessary deep copy off of assignment
 */
RBTree& RBTree::operator=(const RBTree& rhs) {
	if (this == &rhs) {
		return *this;
	}

	DeAllocate(root);
	root = nil;
	copyOver(rhs.root);
	
	return *this;
}

/*
 * insert Function:
 * Inserts a new key into the tree
 */
void RBTree::insert(int newKey) {
	TreeNode* z = new TreeNode();
	z->key = newKey;
	if (root == nil) {
		root = z;
		z->parent = nil;
	} else {
		TreeNode* y = nil;
		TreeNode* x = root;
		while (x != nil) {
			y = x;
			if (z->key < x->key) {
				x = x->left;
			} else {
				x = x->right;
			}
		}
		if (z->key < y->key) {
			y->left = z;
		} else {
			y->right = z;
		}
		z->parent = y;
	}
	z->left = nil;
	z->right = nil;
	z->color = RED;
	rbInsertFixUp(z);
}

/*
   rbInsertFixUp Function:
   Fixes violations in tree after insert
*/
void RBTree::rbInsertFixUp(TreeNode* z) {
	while (z->parent->color == RED) {
		if (z->parent == z->parent->parent->left) {
			TreeNode* y =  z->parent->parent->right;
			if (y->color == RED) {
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			} else {
				if (z == z->parent->right) {
					z = z->parent;
					leftRotate(z);
				}
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				rightRotate(z->parent->parent);
			}
		} else {
			TreeNode* y = z->parent->parent->left;
			if (y->color == RED) {
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			} else { 
				if (z == z->parent->left) {
					z = z->parent;
					rightRotate(z);
				}
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				leftRotate(z->parent->parent);
			}
		}
	}
	root->color = BLACK;
}

/*
 * search Function:
 * Wrapper for search function
 */
int RBTree::search(int key) {
	TreeNode* rtn = _search(key);
	if (rtn == nullptr) {
		std::cout << "Key not found or tree is empty, returning -1" << std::endl;
		return -1;
	}
	return rtn->key;
}

/*
 * _search Function:
 * Searches for a specified key and returns it's node
 */
RBTree::TreeNode* RBTree::_search(int key) {
	if (root == nil) {
		return nullptr;
	}
	TreeNode* cursor = root;
	while (cursor != nil) {
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
int RBTree::minimum() {
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
RBTree::TreeNode* RBTree::_minimum() {
	TreeNode* cursor = root;
	if (cursor == nil) {
		// tree is empty
		return nullptr;
	}
	while (cursor->left != nil) {
		cursor = cursor->left;
	}
	return cursor;
}

/*
 * maximum Function:
 * Wrapper for maximum function
 */
int RBTree::maximum() {
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
RBTree::TreeNode* RBTree::_maximum() {
	TreeNode* cursor = root;
	if (cursor == nil) {
		// tree is empty
		return nullptr;
	}
	while (cursor->right != nil) {
		cursor = cursor->right;
	}
	return cursor;
}

/*
 * successor Function:
 * Wrapper for successor function
 */
int RBTree::successor(int key) {
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
RBTree::TreeNode* RBTree::_successor(int key) {
	TreeNode* newKey = _search(key);
	if (newKey == nullptr) {
		return nullptr;
	}

	if (newKey->right == nil) {
		TreeNode* cursor = newKey;
		TreeNode* original = newKey;
		while (cursor->parent != nil) {
			if (cursor->parent->left == cursor) {
				return cursor->parent;
			}
			cursor = cursor->parent;
		}
		return original;
	}

	TreeNode* cursor = newKey->right;
	while (cursor->left != nil) {
		cursor = cursor->left;
	}
	return cursor;
}

/*
 * inorder Function:
 * Wrapper for inorder function
 */
void RBTree::inorder() {
	_inorder(root);
	std::cout << std::endl;
}

/*
 * _inorder Function:
 * Prints the keys in ascending order
 */
void RBTree::_inorder(TreeNode* head) {
	if (head != nil) {
		_inorder(head->left);
		std::cout << head->key << " (" << head->color << ")"  << ", ";
		_inorder(head->right);
	}
}

/*
 * deleteNode Function:
 * Removes a given node from the tree if it exists
 */
void RBTree::deleteNode(int delMe) {
	TreeNode* z = _search(delMe);
	if (z == nullptr) {
		std::cout << "Node to be deleted could not be found" << std::endl;
		return;
	}
	TreeNode* y = z;
	TreeNode* x;
	color_t yOriginalColor = y->color;
	if (z->left == nil) {
		x = z->right;
		rbTransplant(z, z->right);
	} else if (z->right == nil) {
		x = z->left;
		rbTransplant(z, z->left);
	} else {
		TreeNode* cursor = z->right;
		while (cursor->left != nil) {
			cursor = cursor->left;
		}
		y = cursor;
		yOriginalColor = y->color;
		x = y->right;
		if (y->parent == z) {
			x->parent = y;
		} else {
			rbTransplant(y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		rbTransplant(z, y);
		y->left = z->left;
		y->left->parent = y;
		y->color = z->color;
	}
	if (yOriginalColor == BLACK) {
		rbDeleteFixUp(x);
	}
}

/*
   rbDeleteFixUp Function:
   Fixes up violations in tree after deletion
*/
void RBTree::rbDeleteFixUp(TreeNode* x) {
	while (x != root && x->color == BLACK) {
		if (x == x->parent->left) {
			TreeNode* w = x->parent->right;
			if (w->color == RED) {
				w->color = BLACK;
				x->parent->color = RED;
				leftRotate(x->parent);
				w = x->parent->right;
			}
			if (w->left->color == BLACK && w->right->color == BLACK) {
				w->color = RED;
				x = x->parent;
			} else {
				if (w->right->color == BLACK) {
					w->left->color = BLACK;
					w->color = RED;
					rightRotate(w);
					w = x->parent->right;
				}
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->right->color = BLACK;
				leftRotate(x->parent);
				x = root;
			}
		} else {
			TreeNode* w = x->parent->left;
			if (w->color == RED) {
				w->color = BLACK;
				x->parent->color = RED;
				rightRotate(x->parent);
				w = x->parent->left;
			}
			if (w->right->color == BLACK && w->left->color == BLACK) {
				w->color = RED;
				x = x->parent;
			} else {
				if (w->left->color == BLACK) {
					w->right->color = BLACK;
					w->color = RED;
					leftRotate(w);
					w = x->parent->left;
				}
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->left->color = BLACK;
				rightRotate(x->parent);
				x = root;
			}
		}
	}
	x->color = BLACK;
}

/*
 * transplant Function:
 * Replace a subtree (first parameter) with another subtree (second parameter)
 */
void RBTree::rbTransplant(TreeNode* replace, TreeNode* insert) {
	if (replace == root && replace->parent == nil) {
		root = insert;
	} else if (replace->parent->right == replace) {
		replace->parent->right = insert;
	} else {
		replace->parent->left = insert;
	}
	
	if (insert != nil) {
		insert->parent = replace->parent;
	}
}


/*
 * print Function:
 * Wrapper function for print
 */
void RBTree::print() {
	_print(root);
	std::cout << std::endl;
}

/*
 * _print Function:
 * Pre order print function
 */
void RBTree::_print(TreeNode* head) {
	if (head != nil) {
		std::cout << head->key << " (" << head->color << ")" << ", ";
		_print(head->left);
		_print(head->right);
	}
}

/*
   leftRotate Function:
   Left rotates the current subtree
*/
void RBTree::leftRotate(TreeNode* x) {
	TreeNode* y = x->right;
	x->right = y->left;
	if (y->left != nil) {
		y->left->parent = x;
	}
	y->parent = x->parent;
	if (x->parent == nil) {
		root = y;
	} else if (x == x->parent->left) {
		x->parent->left = y;
	} else {
		x->parent->right = y;
	}
		y->left = x;
		x->parent = y;
}

/*
   rightRotate Function:
   Right rotates the current subree
*/
void RBTree::rightRotate(TreeNode* x) {
	TreeNode* y = x->left;
	x->left = y->right;
	if (y->right != nil) {
		y->right->parent = x;
	}
	y->parent = x->parent;
	if (x->parent == nil) {
		root = y;
	} else if (x == x->parent->right) {
		x->parent->right = y;
	} else {
		x->parent->left = y;
	}
		y->right = x;
		x->parent = y;
}
