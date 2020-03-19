#include "minheap.h"

void swap(int& a, int& b) {
	int aux = a;
	a = b;
	b = aux;
}

void heapSort(int* v, int n) {
	heapify(v, n);

	for (int i = n - 1; i >= 0; i--) {
		swap(v[0], v[i]);
		heapify(v, i);
	}

	for (int i = 0; i < n / 2; i++)
		swap(v[i], v[n - i - 1]);
}