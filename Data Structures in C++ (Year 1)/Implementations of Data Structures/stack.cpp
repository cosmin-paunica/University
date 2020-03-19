#include "stack.h"
#include <iostream>

using namespace std;

void push(Stack& s, int x) {
	SingleNode* p = new SingleNode;
	p->info = x;
	p->prev = s.top;
	s.top = p;
	s.size++;
}

int pop(Stack& s) {
	SingleNode* p = s.top;
	int to_be_popped = -1;
	if (s.size > 0) {
		to_be_popped = s.top->info;
		s.top = s.top->prev;
		delete p;
		s.size--;
	}
	return to_be_popped;
}

void print(Stack& s) {
	SingleNode* p = s.top;
	while (p != NULL) {
		cout << p->info << " ";
		p = p->prev;
	}
	cout << endl;
}