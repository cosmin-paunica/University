#include "deque.h"
#include <iostream>

using namespace std;

void pushLeft(Deque& d, int x) {
	DoubleNode* p = new DoubleNode;
	p->info = x;
	p->prev = NULL;
	p->next = d.first;
	if (d.size > 0)
		d.first->prev = p;
	d.first = p;
	if (d.size == 0)
		d.last = p;
	d.size++;
}

void pushRight(Deque& d, int x) {
	DoubleNode* p = new DoubleNode;
	p->info = x;
	p->prev = d.last;
	p->next = NULL;
	if (d.size > 0)
		d.last->next = p;
	d.last = p;
	if (d.size == 0)
		d.first = p;
	d.size++;
}

int popLeft(Deque& d) {
	DoubleNode* p = d.first;
	int toBePopped = -1;
	if (d.size > 0) {
		toBePopped = d.first->info;
		d.first = d.first->next;
		if (d.size == 1)
			d.last = NULL;
		if (d.size > 1)
			d.first->prev = NULL;
		delete p;
		d.size--;
	}
	return toBePopped;
}

int popRight(Deque& d) {
	DoubleNode* p = d.last;
	int toBePopped = -1;
	if (d.size > 0) {
		toBePopped = d.last->info;
		d.last = d.last->prev;
		if (d.size == 1)
			d.first = NULL;
		if (d.size > 1)
			d.last->next = NULL;
		delete p;
	}
	d.size--;
	return toBePopped;
}

void print(Deque d) {
	DoubleNode* p = d.first;
	while (p != NULL) {
		cout << p->info << " ";
		p = p->next;
	}
}