#include "BST.h"
#include <iostream>

BST::BST() : root(NULL), size(0) {
}

BST::Node* BST::getRoot() {
	return root;
}

unsigned BST::getSize() {
	return size;
}

void BST::inorder(Node* p) {
	if (p != NULL) {
		inorder(p->left);
		std::cout << p->key << " ";
		inorder(p->right);
	}
}

void BST::preorder(Node* p) {
	if (p != NULL) {
		std::cout << p->key << " ";
		preorder(p->left);
		preorder(p->right);
	}
}

BST::Node* BST::search(int key, Node* p) {
	while (p != NULL && p->key != key)
		if (p->key > key)
			p = p->left;
		else
			p = p->right;
	return p;
}

BST::Node* BST::minimum(Node* p) {
	while (p->left != NULL)
		p = p->left;
	return p;
}

BST::Node* BST::maximum(Node* p) {
	while (p->right != NULL)
		p = p->right;
	return p;
}

BST::Node* BST::successor(Node* p) {
	if (p->right != NULL)
		return minimum(p->right);

	Node* q = p->parent;
	while (q != NULL && p == q->right) {
		p = q;
		q = q->parent;
	}
	return q;
}

BST::Node* BST::successor(int key) {
	Node* p = search(key, root);
	if (p == NULL)
		throw "Key not in tree";
	return successor(p);
}

BST::Node* BST::predecessor(Node* p) {
	if (p->left != NULL)
		return maximum(p->right);

	Node* q = p->parent;
	while (q != NULL && p == q->left) {
		p = q;
		q = q->parent;
	}
	return q;
}

BST::Node* BST::predecessor(int key) {
	Node* p = search(key, root);
	if (p == NULL)
		throw "Key not in tree";
	return predecessor(p);
}

void BST::insert(int key) {
	Node* p = root, * q = NULL;
	while (p != NULL) {
		q = p;
		if (p->key > key)
			p = p->left;
		else
			p = p->right;
	}
	p = new Node{ key, q };
	if (q == NULL)
		root = p;		// if the tree was empty
	else if (q->key > key)
		q->left = p;
	else
		q->right = p;
	size++;
}

void BST::remove(Node* p) {
	if (p->left == NULL)
		transplant(p, p->right);
	else if (p->right == NULL)
		transplant(p, p->left);
	else {
		Node* q = minimum(p->right);
		if (q->parent != p) {
			transplant(q, q->right);
			q->right = p->right;
			p->right->parent = q;
		}
		transplant(p, q);
		q->left = p->left;
		p->left->parent = q;
	}
	delete p;
	size--;
}

void BST::remove(int key) {
	Node* p = search(key, root);
	if (p == NULL)
		throw "Key not in table";
	remove(p);
}


void BST::transplant(Node* p, Node* q) {
	if (p == root)
		root = q;
	else if (p == p->parent->left)
		p->parent->left = q;
	else
		p->parent->right = q;

	if (q != NULL)
		q->parent = p->parent;
}