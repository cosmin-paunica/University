#include "minheap.h"	// see Data Structures in C++ (Year 1) / Implementations of Data Structures /
#include "utility.h"	// swap
#include <iostream>


void heapSort(int* v, int n) {
	buildMinHeap(v, n);

	int len = n;
	for (int i = n - 1; i >= 0; i--) {
		swap(v[0], v[i]);
		len--;
		minHeapify(v, len, 0);
	}

	for (int i = 0; i < n / 2; i++)
		swap(v[i], v[n - i - 1]);
}