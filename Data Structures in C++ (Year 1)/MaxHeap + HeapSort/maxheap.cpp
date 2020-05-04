#include "utility.h"	// includes swap(int, int) function

using namespace std;

void maxHeapify(int* v, int n, int i) {
	int max = i, left = 2 * i + 1, right = 2 * i + 2;
	if (left < n && v[left] > v[max])
		max = left;
	if (right < n && v[right] > v[max])
		max = right;

	if (max != i) {
		swap(v[i], v[max]);
		maxHeapify(v, n, max);
	}
}

// converts array v into a max-heap
void buildMaxHeap(int* v, int n) {
	for (int i = (n - 1) / 2; i >= 0; i--)
		maxHeapify(v, n, i);
}

void heapPush(int* v, int& n, int x) {
	int i = n;
	v[n++] = x;
	while (i > 0 && v[(i - 1) / 2] < v[i]) {
		swap(v[i], v[(i - 1) / 2]);
		i = (i - 1) / 2;
	}
}

int heapPop(int* v, int& n) {
	if (n == 0)
		throw "Heap is empty";

	int max = v[0];
	v[0] = v[n - 1];
	n--;
	maxHeapify(v, n, 0);
	return max;
}