#include "minheap.h"
#include "utility.h"	// includes swap(int, int) function
#include <iostream>


void heapSort(int* v, int n) {
	buildMinHeap(v, n);

	int len = n;
	for (int i = n - 1; i >= 0; i--) {
		swap(v[0], v[i]);
		len--;
		minHeapify(v, len, 0);
	}
}