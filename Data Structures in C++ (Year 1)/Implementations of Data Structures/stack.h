#ifndef STACK_H
#define STACK_H

#include <iostream>

struct SingleNode {
	int info;
	SingleNode* prev;
};

struct Stack {
	SingleNode* top = NULL;
	int size = 0;
};

void push(Stack& s, int x);
int pop(Stack& s);
void print(Stack& s);

#endif