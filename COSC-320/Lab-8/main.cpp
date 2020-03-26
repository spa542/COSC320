#include "BinaryTree.h"

int main() {
	
	BinaryTree b;
	std::cout << "==============================================" << std::endl;
	std::cout << "Testing Insert Function: " << std::endl;
	std::cout << "Inserting in this order, 5,7,1,3,4,12,11" << std::endl;
	b.insert(5);
	b.insert(7);
	b.insert(1);
	b.insert(3);
	b.insert(4);
	b.insert(12);
	b.insert(11);
	std::cout << "Output in ascending order for values inserted..." << std::endl;
	b.inorder();
	std::cout << "Output in pre order format for values inserted..." << std::endl;
	b.print();
	std::cout << "==============================================" << std::endl;

	std::cout << "==============================================" << std::endl;
	std::cout << "Testing copy constructor..." << std::endl;
	std::cout << "Current working tree..." << std::endl;
	b.inorder();
	std::cout << "Should be the same tree..." << std::endl;
	BinaryTree t(b);
	t.inorder();
	std::cout << "Testing overloaded assignment operator..." << std::endl;
	std::cout << "Current working tree..." << std::endl;
	t.inorder();
	std::cout << "Should be the same tree..." << std::endl;
	BinaryTree s = t;
	s.inorder();
	std::cout << "==============================================" << std::endl;

	std::cout << "==============================================" << std::endl;
	std::cout << "Testing Search Function: " << std::endl;
	std::cout << "Current working tree..." << std::endl;
	b.inorder();
	std::cout << "Searching for 4... this is what is returned..." << std::endl;
	int rtnVal1 = b.search(4);
	std::cout << rtnVal1 << std::endl;
	std::cout << "Searching for 21... this is what is returned..." << std::endl;
	int rtnVal2 = b.search(21);
	std::cout << rtnVal2 << std::endl;
	std::cout << "==============================================" << std::endl;

	std::cout << "==============================================" << std::endl;
	std::cout << "Testing Minimum and Maximum Function: " << std::endl;
	std::cout << "Current Working tree..." << std::endl;
	b.inorder();
	std::cout << "The minimum of this tree is..." << b.minimum() << std::endl;
	std::cout << "The maximum of this tree is..." << b.maximum() << std::endl;
	BinaryTree c;
	std::cout << "Testing functions on an empty tree..." << std::endl;
	std::cout << "The minimum of this tree is..." << c.minimum() << std::endl;
	std::cout << "The maximum of this tree is..." << c.maximum() << std::endl;
	std::cout << "==============================================" << std::endl;

	std::cout << "==============================================" << std::endl;
	std::cout << "Testing Successor Function: " << std::endl;
	std::cout << "Current Working tree..." << std::endl;
	b.inorder();
	std::cout << "Successor of 7 is..." << b.successor(7) << std::endl;
	std::cout << "Successor of 1 is..." << b.successor(1) << std::endl;
	std::cout << "Successor of 12 is..." << b.successor(12) << std::endl;
	std::cout << "Testing on an empty tree..." << std::endl;
	std::cout << "Successor of 3 is..." << c.successor(3) << std::endl;
	std::cout << "Testing on a one element tree..." << std::endl;
	c.insert(5);
	std::cout << "Current Working tree..." << std::endl;
	c.inorder();
	std::cout << "Successor of 5 is..." << c.successor(5) << std::endl;
	std::cout << "==============================================" << std::endl;

	return 0;
}
