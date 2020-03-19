#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>

struct DoubleNode {
	int info;
	DoubleNode* prev, * next;
};

struct Deque {
	DoubleNode* first = NULL, * last = NULL;
	int size = 0;
};

void pushLeft(Deque& d, int x);
void pushRight(Deque& d, int x);
int popLeft(Deque& d);
int popRight(Deque& d);
void print(Deque d);

#endif