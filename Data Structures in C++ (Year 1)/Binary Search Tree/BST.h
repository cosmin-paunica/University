#pragma once

#include <iostream>

using namespace std;

class BST {
	struct Node {
		int key;
		Node* parent, * left, * right;
	} * root;
	unsigned size;

public:
	BST();

	Node* getRoot();			// returns pointer to root of the tree
	unsigned getSize();			// returns number of elements in tree

	void inorder(Node*);		// prints the items From the subtree
	void preorder(Node*);		// prints the items from the subtree
	Node* search(int, Node*);	// returns a pointer to the node with given key in the subtree, or nullptr
	Node* minimum(Node*);		// returns a pointer to the node with minimum key from the subtree
	Node* maximum(Node*);		// returns a pointer to the node with maximum key from the subtree
	Node* successor(Node*);		// returns a pointer to the first node with key greater than the one in the given node
	Node* successor(int);		// returns a pointer to the first node with key greater than the one given
	Node* predecessor(Node*);	// returns a pointer to the first node with key less than the one in the given node
	Node* predecessor(int);		// returns a pointer to the first node with key less than the one given
	void insert(int);			// inserts an item with given key in tree
	void remove(Node*);			// removes the given node from tree
	void remove(int);			// removes the node with given key from tree

private:
	void transplant(Node*, Node*);	// exchanges two nodes' positions
};
