#include "utility.h"	// swap

using namespace std;

void minHeapify(int* v, int n, int i) {
	int min = i, left = 2 * i + 1, right = 2 * i + 2;
	if (left < n && v[left] < v[min])
		min = left;
	if (right < n && v[right] < v[min])
		min = right;

	if (min != i) {
		swap(v[i], v[min]);
		minHeapify(v, n, min);
	}
}

// converts array v into a min-heap
void buildMinHeap(int* v, int n) {
	for (int i = (n - 1) / 2; i >= 0; i--)
		minHeapify(v, n, i);
}

void heapPush(int* v, int& n, int x) {
	int i = n;
	v[n++] = x;
	while (i > 0 && v[(i - 1) / 2] > v[i]) {
		swap(v[i], v[(i - 1) / 2]);
		i = (i - 1) / 2;
	}
}

int heapPop(int* v, int& n) {
	if (n == 0)
		throw "Heap is empty";

	int min = v[0];
	v[0] = v[n - 1];
	n--;
	minHeapify(v, n, 0);
	return min;
}